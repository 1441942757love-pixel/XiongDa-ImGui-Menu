#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <draw.h>
#include <TouchHelper.h>
#include <thread>        // [新增] 必须包含线程库 //
#include <sys/stat.h>



// --- [修复点] 强行读取 8 字节的 64 位地址函数 ---
// 找到 main.cpp 里的 ForceRead64 并修改掩码 [cite: 2026-03-24]
long ForceRead64(long addr) {
    long res = 0;
    if (driver->read(addr, &res, 8)) {
        // [修改] 必须用 12 个 F (0xFFFFFFFFFFFFLL)，否则读出来的指针是错的 [cite: 2026-03-24]
        return res & 0xFFFFFFFFFFFFLL; 
    }
    return 0;
}



// 检查进程是否在运行 [cite: 2026-03-24]
bool is_game_alive(int target_pid) {
    if (target_pid <= 0) return false;
    char path[64];
    sprintf(path, "/proc/%d", target_pid);
    return (access(path, F_OK) == 0); // 文件夹存在即活着 [cite: 2025-11-26]
}


// 手动补全 Byte 写入函数
void WriteByte(long addr, unsigned char value) {
    // 调用驱动类的 write 成员，写入长度设为 1 字节
    driver->write(addr, &value, 1); 
}



// 专门寻找权限为 rw-p 的模块基址，对应 Lua 里的 "Cd" 段
// 增强版：支持按序号获取指定权限的段基址
// 增强版：通过 index 参数精准锁定第 N 个 rw-p 段
// 放入 main.cpp 顶部，替换旧的函数 [cite: 2026-03-26]
long getModuleDataBase(const char* module_name) {
    long addr = 0;
    char filename[64], line[1024];
    snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return 0;

    while (fgets(line, sizeof(line), fp)) {
        // 关键：必须同时包含模块名且权限为 rw-p (可读写)
        if (strstr(line, module_name) && strstr(line, "rw-p")) {
            sscanf(line, "%lx-%*lx", &addr);
            printf("\033[32;1m[系统] 成功锁定 %s 的可写数据段: 0x%lX\033[0m\n", module_name, addr);
            break; 
        }
    }
    fclose(fp);
    return addr;
}







// --- [修复点] 适配 64 位游戏的 ReadPoint ---
long ReadPoint(long base, std::initializer_list<long> offsets) {
    long addr = ForceRead64(base); // 第一层跳转
    for (long offset : offsets) {
        if (addr == 0) return 0;
        addr = ForceRead64(addr + offset); // 后续层级跳转
    }
    return addr;
}