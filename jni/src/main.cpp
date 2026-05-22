#include <draw.h>
#include <TouchHelper.h>
#include <unistd.h>
#include <thread>        // [新增] 必须包含线程库
#include "imgui.h"
#include "RT.h"  //
#include <sys/stat.h>
#include "qiang.h" 
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/uio.h>
#include <elf.h>

// --- 全局变量区 ---
bool DrawIo[50]; 
bool running = true;
long il2cppBase = 0;
float HighJumpMult = 1.0f; // [新增] 高跳倍数，默认 1.0 [cite: 2026-03-26]
float OriginalJump = 0.0f; // [新增] 用于存储游戏默认的跳跃高度 


float MoveSpeedMult = 1.0f;     // [新增] 移速倍数 [cite: 2026-03-26]
float OriginalMoveSpeed = 0.0f;  // [新增] 存储游戏原始移速 [cite: 2026-03-26]



// 在 long il2cppBase = 0; 下方加入这一行
const char* targetPackage = "com.joym.xiongdakuaipao"; 



// 远程主动调用核心函数 (仅限 ARM64) [cite: 2026-03-26]
#include <dirent.h> // 用于遍历线程 [cite: 2026-03-24]

// [新增] 寻找游戏主线程 TID 的函数 [cite: 2026-03-26]
int find_main_thread(int pid) {
    char task_path[64];
    sprintf(task_path, "/proc/%d/task", pid);
    DIR* dir = opendir(task_path);
    if (!dir) return pid;
    struct dirent* entry;
    int main_tid = pid; // 默认返回 PID
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            main_tid = atoi(entry->d_name); // 通常第一个找到的有效子任务就是主线程
            break;
        }
    }
    closedir(dir);
    return main_tid;
}

// [重构] 强制寄存器劫持调用 [cite: 2026-03-26, 2026-03-28]
long InvokeRemote(int process_pid, long funcAddr, long arg1, long arg2 = 0) {
    int tid = find_main_thread(process_pid); // 锁定主线程，解决“调用无反应”的关键 [cite: 2026-03-26]
    struct user_pt_regs regs, old_regs;
    struct iovec iov;
    iov.iov_base = &regs;
    iov.iov_len = sizeof(regs);

    if (ptrace(PTRACE_ATTACH, tid, NULL, NULL) < 0) return -1;
    waitpid(tid, NULL, WUNTRACED);

    ptrace(PTRACE_GETREGSET, tid, NT_PRSTATUS, &iov);
    old_regs = regs;

    // 强制对齐 SP (堆栈指针)，防止函数内部崩溃 [cite: 2026-03-26]
    regs.sp = (regs.sp & ~(0xF)); 
    regs.regs[0] = arg1; // X0 = this
    regs.regs[1] = arg2; // X1 = index/count
    regs.pc = funcAddr;  // 跳转到函数入口
    regs.regs[30] = 0;   // LR = 0 触发中断 [cite: 2026-03-28]

    ptrace(PTRACE_SETREGSET, tid, NT_PRSTATUS, &iov);
    ptrace(PTRACE_CONT, tid, NULL, NULL);
    
    // 增加超时等待机制，防止死等
    int status;
    waitpid(tid, &status, WUNTRACED); 

    // 恢复现场
    iov.iov_base = &old_regs;
    ptrace(PTRACE_SETREGSET, tid, NT_PRSTATUS, &iov);
    ptrace(PTRACE_DETACH, tid, NULL, NULL);

    return 0;
}





/*void Execute_PreciseVipReward() {
    if (pid <= 0 || il2cppBase <= 0) return;

    
    long itemID_ptr = ReadPoint(il2cppBase + 0x5CEB8, {0x858, 0x30, 0x40, 0x18, 0x48});
    if (itemID_ptr > 0) {
        WriteDword(itemID_ptr + 0x10, 1); // 将物品 ID 改为 1 [cite: 2026-03-28]
        printf("\033[32;1m[步骤1] 物品 ID 已修改为 1\033[0m\n");
    } else {
        printf("\033[33;1m[失败] 找不到 itemID 链路，请点开奖励详情页。\033[0m\n");
        return; 
    }

    
    long vipInstance = ReadPoint(il2cppBase + 0x5CEB8, {0x858, 0x30, 0x0});

    if (vipInstance > 0) {
        printf("\033[32;1m[步骤2] 锁定 VipData 实例: 0x%lX\033[0m\n", vipInstance);

        
        // 修正后的 InvokeRemote 会自动寻找主线程进行“夺舍”调用
        InvokeRemote(pid, il2cppBase + 0x1F1CF8C, vipInstance);
        
        printf("\033[32;1m[成功] 劫持指令已下发至主线程！\033[0m\n");
    } else {
        printf("\033[31;1m[错误] VipData 实例未找到，链路断在 0x30 或 0x0。\033[0m\n");
    }
}*/








// --- [修复点] 独立线程运行修改逻辑 ---
void MemoryThread() {
    bool has_printed_connected = false;
    int check_timer = 0; 

    while (running) {
        // --- 1. 掉线监控 --- [cite: 2026-03-24]
        if (pid > 0 && !is_game_alive(pid)) {
            pid = 0; il2cppBase = 0; has_printed_connected = false;
            OriginalJump = 0.0f; OriginalMoveSpeed = 0.0f;
            printf("\033[31;1m[系统] 游戏已退出，状态重置...\033[0m\n");
        }

        // --- 2. 搜寻 PID ---
        if (pid <= 0) {
            getPID((char*)targetPackage);
            if (pid <= 0) { usleep(1000000); continue; }
        }

        // --- 3. 锁定基址 --- [cite: 2026-03-26]
        if (pid > 0 && il2cppBase == 0) {
            il2cppBase = getModuleDataBase("libil2cpp.so"); 
            if (il2cppBase > 0) {
                printf("\033[32;1m[系统] 锁定基址: 0x%lX, 正在下放修改...\033[0m\n", il2cppBase);
            }
        }

        // --- 4. 核心逻辑与实时验证 --- [cite: 2026-03-26]
        if (il2cppBase > 0) {
            // 每 20 次循环（约 0.2 秒）验证一次地基是否漂移
            if (check_timer++ >= 20) {
                long verify = ReadPoint(il2cppBase + 0x53F80, {0x20, 0x308, 0x30});
                if (verify == 0) {
                    il2cppBase = 0; // 发现漂移，强制触发重连
                    check_timer = 0;
                    continue;
                }
                check_timer = 0;
                if (!has_printed_connected) {
                    printf("\033[32;1m[系统] 验证成功，功能已实时同步！\033[0m\n");
                    has_printed_connected = true;
                }
            }

            // --- 功能执行区 --- [cite: 2026-03-26]
            long jumpBase = ReadPoint(il2cppBase + 0x53F80, {0x20, 0x308, 0x30});
            if (jumpBase > 0) {
                // 无敌
                if (DrawIo[1]) WriteFloat(jumpBase + 0xAC, 999999.0f); 
                
                // 高跳 (1.0x 自动校准逻辑) [cite: 2026-03-26]
                long aj = ReadPoint(il2cppBase + 0x53F80, {0x20, 0x308, 0x30});
            if (aj > 0) {
                long fJ = aj + 0x50;
                // [关键] 如果 OriginalJump 是 0，说明是新局，抓取一次真实的原始值 [cite: 2026-03-26]
                if (OriginalJump == 0.0f) {
                    driver->read(fJ, &OriginalJump, 4); 
                } else {
                    // [核心] 永远基于第一次抓到的固定值进行计算，不再二次读取 [cite: 2026-03-26]
                    WriteFloat(fJ, OriginalJump * HighJumpMult); 
                }
            }

            // 无重力 [cite: 2026-03-25]
            long a2 = ReadPoint(il2cppBase + 0x4FDE0, {0x308, 0x908, 0x0});
            if (a2 > 0 && DrawIo[2]) WriteFloat(a2 + 0x54, 0.0f);

            // 硬币/分数/距离 [cite: 2026-03-25, 2026-03-26]
            long a345 = ReadPoint(il2cppBase + 0x3F198, {0x8D8, 0x858, 0x60});
            if (a345 > 0) {
                if (DrawIo[3]) WriteDword(a345 + 0x144, 9999999);
                if (DrawIo[4]) WriteFloat(a345 + 0x140, 2147483647.0f);
                if (DrawIo[5]) WriteFloat(a345 + 0x148, 2147483647.0f);
            }

            // 移速 (1.0x 自动校准逻辑) [cite: 2026-03-26]
            long am = ReadPoint(il2cppBase + 0x41140, {0x48, 0xB8, 0x0});
            if (am > 0) {
                long fM = am + 0x30;
                // 同理，只在最开始抓取一次 [cite: 2026-03-26]
                if (OriginalMoveSpeed == 0.0f) {
                    driver->read(fM, &OriginalMoveSpeed, 4);
                } else {
                    WriteFloat(fM, OriginalMoveSpeed * MoveSpeedMult);
                }
            }
            
            //物品id
           /*if (DrawIo[6]) {
                long vipAddr = ReadPoint(il2cppBase + 0x5CEB8, {0x858, 0x30, 0x40, 0x18, 0x48});
                if (vipAddr > 0) {
                    // 最终偏移 0x10，类型为 Dword (int)，修改值为 1 [cite: 2026-03-28]
                    WriteDword(vipAddr + 0x10, 1);
                }
            }*/
        }
        usleep(10000); // 100Hz 刷新率
    }
  }
}




//移速类型floatlibil2cpp.so:data[4] + 0x41140 -> + 0x48 -> + 0xB8 -> + 0x0 -> + 0x30

//距离 Float libil2cpp.so:data[4] + 0x3F198 -> + 0x8D8 -> + 0x858 -> + 0x60 -> + 0x148


//分数float  libil2cpp.so:data[4] + 0x3F198 -> + 0x8D8 -> + 0x858 -> + 0x60 -> + 0x140

//硬币Dword libil2cpp.so:data[4] + 0x3F198 -> + 0x8D8 -> + 0x858 -> + 0x60 -> + 0x144

//无重力libil2cpp.so+ 0x4FDE0 -> + 0x308 -> + 0x908 -> + 0x0 -> + 0x54

//libil2cpp.so + 0x53F80 -> + 0x20 -> + 0x308 -> + 0x30 -> + 0xAC




void Draw_Qiang_Menu() {
       ImGui::SetNextWindowSize(ImVec2(900, 600), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Qiang U3D 专用内核", &running)) {
        ImGui::Text("游戏: 熊大快跑");
        const char* status_text = "等待游戏开启...";
        ImVec4 status_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // 默认红色

    if (pid > 0) {
    if (il2cppBase > 0) {
        status_text = "已连接并就绪";
        status_color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // 成功绿色
    } else {
        status_text = "已找到进程，正在初始化内存...";
        status_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // 黄色警告
    }
}
        ImGui::TextColored(status_color, "状态: %s", status_text);
        
       
        // --- 仿图布局：双列显示 [cite: 2026-03-25] ---
        ImGui::Columns(2, NULL, false); // 开启 2 列，不显示分割线
        ImGui::SetColumnWidth(0, 275);  // 设置第一列宽度
        
        // 第一列第一个：无敌
        ImGui::Checkbox("无敌", &DrawIo[1]); 
        ImGui::Checkbox("局内大量硬币", &DrawIo[3]);
        ImGui::Checkbox("局内大量分数", &DrawIo[4]);
        ImGui::Checkbox("局内大量距离", &DrawIo[5]); 
        
        ImGui::NextColumn(); // 切换到第二列
        
        // 第二列第一个：无重力 (放在无敌右边)
        ImGui::Checkbox("无重力", &DrawIo[2]); 
        
        
          // 2. 高跳滑动条布局 (文字在左，滑动条在右) [cite: 2026-03-26]
       ImGui::Text("高跳"); ImGui::SameLine(); 
        ImGui::PushItemWidth(120);
        ImGui::SliderFloat("##HJump", &HighJumpMult, 1.0f, 10.0f, "%.1fx");
        ImGui::PopItemWidth(); 

        ImGui::Text("移速"); ImGui::SameLine(); 
        ImGui::PushItemWidth(120);
        ImGui::SliderFloat("##MSpeed", &MoveSpeedMult, 1.0f, 10.0f, "%.1fx");
        ImGui::PopItemWidth(); 
        
                // --- 菜单按钮部分 --- [cite: 2026-03-26]
        ImGui::Separator();
        if (ImGui::Button("【黑科技】强领 1 号物品奖励", ImVec2(-1, 80))) {
           // Execute_PreciseVipReward();
        }
        ImGui::Separator();

        
        
       /* if (ImGui::Button("寄存器劫持：强领 2000 奖励", ImVec2(-1, 80))) {
            Execute_FinalSuperVip();
        }*/

        

        ImGui::Columns(1); // 回到单列布局
        
        float fps = ImGui::GetIO().Framerate;
        ImGui::Text("绘制耗时: %.3f ms (%.1f FPS)", 1000.0f / fps, fps);

        if (ImGui::Button("彻底退出后台", ImVec2(-1, 60))) running = false;
    }
    ImGui::End();
}

int main() {
    screen_config(); 
    float screen_max = (screen_y > screen_x ? screen_y : screen_x);
    init_vulkan(screen_max, screen_max, false, false);
    ImGui_init();
    TouchScreenHandle();

    // --- [关键] 启动独立修改线程 ---
    std::thread(MemoryThread).detach();

    while (running) {
        VK_Begin();
        Draw_Qiang_Menu();
        VK_End();
        usleep(2000);
        
    }

    shutdown();
    return 0;
}
