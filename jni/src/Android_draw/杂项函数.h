// 一些计算和辅助函数，堆放在main里面太碍眼，又没什么好放的地方，所以便统一放在这里
uintptr_t libUE41;




void 白云云(const function<string(const string&)> itemFunction, int drawIoIndex, int maxDistance, int fontSize = 30) {
string name;
name = itemFunction(wz.wuziName);
if (物资[drawIoIndex] &&!name.empty()) {
if (wz.Distance < maxDistance) {
name += "[";
name += to_string((int)wz.Distance);
name += "米]";
auto textSize = ImGui::CalcTextSize(name.c_str(), 0, fontSize);
ImGui::GetForegroundDrawList()->AddText(NULL, fontSize, { wz.ScreenPos.x - (textSize.x / 2), wz.ScreenPos.y }, 物资颜色[drawIoIndex], name.c_str());
}
}
}


// 绘制头像
void DrawLogo(ImTextureID ID,ImVec2 center, float size) {
ImGui::SetCursorPos({size*2, size*2});
ImGui::GetWindowDrawList()->AddImageRounded(ID,ImVec2(center.x - size, center.y - size), ImVec2(center.x + size, center.y + size), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), 999);
}


// 计算骨骼
FTransform getBone(uintptr_t addr) {
FTransform transform;
White->read(addr, reinterpret_cast<void*>(&transform), 4 * 11);
return transform;
}


// 计算距离
void GetDistance(Vec3 Object, Vec3 Self, float *Distance) {
float DistanceX = pow(Object.x - Self.x, 2);
float DistanceY = pow(Object.y - Self.y, 2);
float DistanceZ = pow(Object.z - Self.z, 2);
*Distance = sqrt(DistanceX + DistanceY + DistanceZ) * 0.01f;
}



class FRotator
{
public:
    FRotator() :Pitch(0.f), Yaw(0.f), Roll(0.f) {

    }
    FRotator(float _Pitch, float _Yaw, float _Roll) : Pitch(_Pitch), Yaw(_Yaw), Roll(_Roll)
    {

    }
    ~FRotator()
    {

    }
    float Pitch;
    float Yaw;
    float Roll;
    inline FRotator Clamp()
    {

        if (Pitch > 180)
        {
            Pitch -= 360;
        }
        else
        {
            if (Pitch < -180)
            {
                Pitch += 360;
            }
        }
        if (Yaw > 180)
        {
            Yaw -= 360;
        }
        else {
            if (Yaw < -180)
            {
                Yaw += 360;
            }
        }
        if (Pitch > 89)
        {
            Pitch = 89;
        }
        if (Pitch < -89)
        {
            Pitch = -89;
        }
        while (Yaw < 180)
        {
            Yaw += 360;
        }
        while (Yaw > 180)
        {
            Yaw -= 360;
        }
        Roll = 0;
        return FRotator(Pitch, Yaw, Roll);
    }
    inline float Length()
    {
        return sqrtf(Pitch * Pitch + Yaw * Yaw + Roll * Roll);
    }
    FRotator operator+(FRotator v) {
        return FRotator(Pitch + v.Pitch, Yaw + v.Yaw, Roll + v.Roll);
    }
    FRotator operator-(FRotator v) {
        return FRotator(Pitch - v.Pitch, Yaw - v.Yaw, Roll - v.Roll);
    }
};

// 计算雷达的旋转量
Vec2 rotateCoord(float angle, float objRadar_x, float objRadar_y) {
Vec2 radarCoordinate;
float s = sin(angle * PI / 180);
float c = cos(angle * PI / 180);
radarCoordinate.x = objRadar_x * c + objRadar_y * s;
radarCoordinate.y = -objRadar_x * s + objRadar_y * c;
return radarCoordinate;
}
//俯仰角计算
Vec2 角度计算(Vec3 Enemy, Vec3 RealPerson) {
    float x = RealPerson.x - Enemy.x;
    float y = RealPerson.y - Enemy.y;
    float z = RealPerson.z - Enemy.z;
    Vec2 radarCoordinate;
	radarCoordinate.x = atan2(y,x)*180/3.141592653589793238;
	radarCoordinate.y = atan2(z,sqrt(x*x+y*y)) * 180 / 3.141592653589793238;
	return radarCoordinate;
}







// 物资类名
void GetClassName(char *Name, long int address, int id) {
long int ClassNameadd = White->read<uintptr_t>(address + (id / 0x4000) * 0x8);
long int ClassNameaddr = White->read<uintptr_t>(ClassNameadd + (id % 0x4000) * 0x8);
White->read(ClassNameaddr + 0xC, Name, 64);
}

// 玩家名字
void getUTF8(UTF8 * buf, long namepy) {
UTF16 buf16[16] = { 0 };
White->read(namepy, buf16, 28);
UTF16 *pTempUTF16 = buf16;
UTF8 *pTempUTF8 = buf;
UTF8 *pUTF8End = pTempUTF8 + 32;
while (pTempUTF16 < pTempUTF16 + 28) {
if (*pTempUTF16 <= 0x007F && pTempUTF8 + 1 < pUTF8End) {
*pTempUTF8++ = (UTF8) * pTempUTF16;
} else if (*pTempUTF16 >= 0x0080 && *pTempUTF16 <= 0x07FF && pTempUTF8 + 2 < pUTF8End) {
*pTempUTF8++ = (*pTempUTF16 >> 6) | 0xC0;
*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
} else if (*pTempUTF16 >= 0x0800 && *pTempUTF16 <= 0xFFFF && pTempUTF8 + 3 < pUTF8End) {
*pTempUTF8++ = (*pTempUTF16 >> 12) | 0xE0;
*pTempUTF8++ = ((*pTempUTF16 >> 6) & 0x3F) | 0x80;
*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
} else {
break;
}
pTempUTF16++;
}
}

// WorldToScreen系类函数，将游戏三维坐标转化为屏幕二维坐标
Vec2 WorldIsScreen(Vec3 obj, float ViewW) {
float x = screen_x/2 + (Cloud.matrix[0] * obj.x + Cloud.matrix[4] * obj.y + Cloud.matrix[8] * obj.z + Cloud.matrix[12]) / ViewW * screen_x/2;
float y = screen_y/2 - (Cloud.matrix[1] * obj.x + Cloud.matrix[5] * obj.y + Cloud.matrix[9] * obj.z + Cloud.matrix[13]) / ViewW * screen_y/2;
return Vec2(x, y);
}
Vec2 WorldToScreen(Vec3 obj, float a[16], float b) {
Vec2 bscreen;
float camear = Cloud.matrix[3] * obj.x + Cloud.matrix[7] * obj.y + Cloud.matrix[11] * obj.z + Cloud.matrix[15];
bscreen.x = screen_x/2 + (Cloud.matrix[0] * obj.x + Cloud.matrix[4] * obj.y + Cloud.matrix[8] * obj.z + Cloud.matrix[12]) / camear * screen_x/2;
bscreen.y = screen_y/2 - (Cloud.matrix[1] * obj.x + Cloud.matrix[5] * obj.y + Cloud.matrix[9] * obj.z + Cloud.matrix[13]) / camear * screen_y/2;
return bscreen;
}
void WorldToScreen(Vec2 *bscreen, float *camea, float *w, Vec3 obj) {
float camear = Cloud.matrix[3] * obj.x + Cloud.matrix[7] * obj.y + Cloud.matrix[11] * obj.z + Cloud.matrix[15];
*camea = camear;
bscreen->x = screen_x/2 + (Cloud.matrix[0] * obj.x + Cloud.matrix[4] * obj.y + Cloud.matrix[8] * obj.z + Cloud.matrix[12]) / camear * screen_x/2;
bscreen->y = screen_y/2 - (Cloud.matrix[1] * obj.x + Cloud.matrix[5] * obj.y + Cloud.matrix[9] * obj.z + Cloud.matrix[13]) / camear * screen_y/2;
float bscreenZ = screen_y/2 - (Cloud.matrix[1] * obj.x + Cloud.matrix[5] * obj.y + Cloud.matrix[9] * (obj.z + 165) + Cloud.matrix[13]) / camear * screen_y/2;
float bscreenz = bscreen->y - bscreenZ;
*w = (bscreen->y - bscreenZ) / 2;
}

void 矩阵(Vec2 *bscreen, float *camea, float *w, Vec3 obj) {
float camear = Cloud.matrix[3] * obj.x + Cloud.matrix[7] * obj.y + Cloud.matrix[11] * obj.z + Cloud.matrix[15];
*camea = camear;
bscreen->x = screen_x/2 + (Cloud.matrix[0] * obj.x + Cloud.matrix[4] * obj.y + Cloud.matrix[8] * obj.z + Cloud.matrix[12]) / camear * screen_x/2;
bscreen->y = screen_y/2 - (Cloud.matrix[1] * obj.x + Cloud.matrix[5] * obj.y + Cloud.matrix[9] * obj.z + Cloud.matrix[13]) / camear * screen_y/2;
float bscreenZ = screen_y/2 - (Cloud.matrix[1] * obj.x + Cloud.matrix[5] * obj.y + Cloud.matrix[9] * (obj.z + 165) + Cloud.matrix[13]) / camear * screen_y/2;
float bscreenz = bscreen->y - bscreenZ;
*w = (bscreen->y - bscreenZ) / 2;
}



// 绘制骨骼函数
void DrawBone(ImVec2 start, ImVec2 end) {
if (!isnan(start.x) && !isnan(start.y) && !isnan(end.x) && !isnan(end.x)) {
double dx = start.x - end.x;
double dy = start.y - end.y;
if (sqrt(dx * dx + dy * dy) > 100)
return;
if (Cloud.IsBot) {
ImGui::GetForegroundDrawList()->AddLine(start, end, 绘制颜色[8], 绘制粗细[5]);
} else {
ImGui::GetForegroundDrawList()->AddLine(start, end, 绘制颜色[7], 绘制粗细[6]);
}
}
}



// 载入游戏数据
int GetBase() {
if (draw_style[10] == 0) {

const char* game_package_names[] = {"com.tencent.ig", "com.rekoo.pubgm", "com.pubg.krmobile", "com.vng.pubgmobile"};
size_t game_count = sizeof(game_package_names) / sizeof(game_package_names[0]);
for(size_t i = 0; i < game_count; i++) {
Cloud.pid = White->GetPid((char*)game_package_names[i]);
if (Cloud.pid > 0 && Cloud.pid < 100000) {
White->init_pid(Cloud.pid);
break;
}
}
if (Cloud.pid <= 0) {
printf("\nPUBG未启动\n");
return 0;
}
Cloud.libUE4 = White->getModuleBase("libUE4.so");


链接了 = true;

} else if (draw_style[10] == 1) {

Cloud.pid = White->GetPid("com.tencent.tmgp.pubgmhd"); //获取pid
if (Cloud.pid > 0 && Cloud.pid < 100000) //判断防止获取错误
White->init_pid(Cloud.pid);
else {
printf("\n和平精英未启动\n");
return 0;
}
Cloud.libUE4 = White->getModuleBase("libUE4.so"); //获取模块头即ue4地址
链接了 = true;
}

return 1;
}


FILE *numSave = nullptr;

// 保存参数
void NumIoSave(const char *name) {
if (numSave == nullptr) {
string SaveFile = "/data";
SaveFile += "/";
SaveFile += name;
numSave = fopen(SaveFile.c_str(), "wb+");
}
fseek(numSave, 0, SEEK_SET);
fwrite(DrawIo, sizeof(bool) * 50, 1, numSave);
fwrite(NumIo, sizeof(float) * 50, 1, numSave);
fwrite(draw_style, sizeof(float) * 40, 1, numSave);
fwrite(&绘制粗细, sizeof(float) * 16, 1, numSave);
fwrite(&绘制颜色, sizeof(ImColor) * 16, 1, numSave);
fwrite(&物资, sizeof(bool) * 50, 1, numSave);
fwrite(&物资颜色, sizeof(ImColor) * 50, 1, numSave);
fflush(numSave);
fsync(fileno(numSave));
}

// 读取保存的参数
void NumIoLoad(const char *name) {
if (numSave == nullptr) {
string SaveFile = "/data";
SaveFile += "/";
SaveFile += name;
numSave = fopen(SaveFile.c_str(), "rb+");
}
if (numSave != nullptr) {
fseek(numSave, 0, SEEK_SET);
fread(DrawIo, sizeof(bool) * 50, 1, numSave);
fread(NumIo, sizeof(float) * 50, 1, numSave);
fread(draw_style, sizeof(float) * 40, 1, numSave);
fread(&绘制粗细, sizeof(float) * 16, 1, numSave);
fread(&绘制颜色, sizeof(ImColor) * 16, 1, numSave);
fread(&物资, sizeof(bool) * 50, 1, numSave);
fread(&物资颜色, sizeof(ImColor) * 50, 1, numSave);
} else {
CleanData();
}
}


// 音量键隐藏
void 音量键隐藏() {
DIR *dir = opendir("/dev/input/");
if (dir == NULL) {
printf("未找到输入设备\n");
exit(1);
}
struct dirent *ptr = NULL;
int count = 0;
while ((ptr = readdir(dir))!= NULL) {
if (strstr(ptr->d_name, "event"))
count++;
}

if (count == 0) return;

int *fdArray = (int *)malloc(count * sizeof(int));

for (int i = 0; i < count; i++) {
char temp[128];
sprintf(temp, "/dev/input/event%d", i);
fdArray[i] = open(temp, O_RDWR | O_NONBLOCK);
}

struct input_event ev;

while (1) {
for (int i = 0; i < count; i++) {
memset(&ev, 0, sizeof(ev));
read(fdArray[i], &ev, sizeof(ev));
if (ev.type == EV_KEY && ev.code == KEY_VOLUMEDOWN && ev.value == 1) {
开关 = false;
}
if (ev.type == EV_KEY && ev.code == KEY_VOLUMEUP && ev.value == 1) {
开关 = true;
}

usleep(1350);
}
usleep(500);
}
usleep(1500);
}






// 血量绘制函数
void DrawHealth(Vec2 box, float w, float iHealth, uint32_t TeamID, char* name) {
float cornerRadius = 7.0f; 
float x = box.x;
float y = box.y;

float 差值;
// if (TeamID > 99) TeamID = TeamID/2;
if (TeamID > 9) 差值 = 3; else 差值 = 0;
char TeamText[50];
sprintf(TeamText, "%d.%s", TeamID, name); 
char Teamid[50];
sprintf(Teamid, "%d", TeamID); 

ImColor 联赛health = iHealth == 100.0f ? ImColor(255, 255, 255, 155) :
                   iHealth >= 75.0f ? ImColor(255, 255, 255, 255) :
                   iHealth >= 50.0f ? ImColor(255, 150, 150, 255) :
                   iHealth >= 25.0f ? ImColor(255, 80, 80, 255) :
                                      ImColor(255, 0, 0, 255);
ImColor 圆环health = (iHealth <= 100.0f && iHealth >= 85.0f) ? ImColor(0, 255, 0, 255) :
              (iHealth <= 85.0f && iHealth >= 70.0f) ? ImColor(190, 255, 0, 255) :
              (iHealth <= 70.0f && iHealth >= 55.0f) ? ImColor(230, 255, 0, 255) :
              (iHealth <= 55.0f && iHealth >= 40.0f) ? ImColor(255, 170, 0, 255) :
              (iHealth <= 40.0f && iHealth >= 25.0f) ? ImColor(255, 130, 0, 255) :
              (iHealth <= 25.0f && iHealth >= 10.0f) ? ImColor(255, 90, 0, 255) :
              (iHealth <= 10.0f && iHealth >= 0.0f) ? ImColor(255, 0, 0, 255) :
              ImColor(0, 0, 0, 255); // 默认颜色，以防 iHealth 超出预期范围

// 彩色绘图
if (DrawIo[6] && draw_style[1] == 0) {
ImGui::GetBackgroundDrawList()->AddRect({x - 50, y - 20}, {x + 50, y - 5}, ImColor(0,0,0,255), cornerRadius);
if (iHealth > 0)
ImGui::GetBackgroundDrawList()->AddRectFilled({x - 49, y - 19}, {x - 49 + (iHealth * 99 / 100), y - 6},ImColor(arr[TeamID % length]), cornerRadius);
auto textSize_信息 = ImGui::GetFont()->CalcTextSizeA(27, FLT_MAX, -1, TeamText, NULL, NULL);
DrawTf.绘制字体描边(27, x - (textSize_信息.x / 2), box.y - 33 - (textSize_信息.y / 2), ImVec4{255,255,255,255}, TeamText);//队伍ID

// 联赛绘图
} else if (DrawIo[6] && draw_style[1] == 1) {
auto textSize_id = ImGui::GetFont()->CalcTextSizeA(23, FLT_MAX, -1, Teamid, NULL, NULL);
ImGui::GetBackgroundDrawList()->AddRectFilled({x - 75 , y - (43 )}, {(x-60-差值) + textSize_id.x , y - (17 )}, ImColor(arr[TeamID % length]), 0); //队伍

tm = 123;
ImGui::GetBackgroundDrawList()->AddRectFilled({(x-60-差值) + textSize_id.x , y - (43 )}, {x + 75 , y - (17 )}, ImColor(arr[TeamID % length]), 0); //名字
tm = 255;
ImVec2 triangle[3] = {ImVec2(x - 7, y - 11), ImVec2(x, y - 2), ImVec2(x + 7, y - 11)};
ImGui::GetBackgroundDrawList()->AddTriangleFilled(triangle[0], triangle[1], triangle[2], ImColor(arr[TeamID % length])
);

if (iHealth > 0)
ImGui::GetBackgroundDrawList()->AddRectFilled({x - (75 ), y - (17 )}, {x - (75 ) + (iHealth * 150 / 100), y - 11}, 联赛health, 0);
else 
ImGui::GetBackgroundDrawList()->AddRectFilled({x - (75 ), y - (17 )}, {x + (75 ), y - 11}, ImColor(255, 0, 0, 255), 0);

DrawTf.绘制字体描边(23, x - 67.5f - 差值, y - 29 - (textSize_id.y / 2), ImVec4{255,255,255,255}, Teamid);//队伍ID
auto textSize_信息 = ImGui::GetFont()->CalcTextSizeA(23, FLT_MAX, -1, name, NULL, NULL);
DrawTf.绘制字体描边(23, (x-53) + textSize_id.x, y - 29 - (textSize_信息.y / 2), ImVec4{255,255,255,255}, name);//名字

// 圆环绘图
} else if (DrawIo[6] && draw_style[1] == 2) {
string 血量 = to_string((int)iHealth);
auto textSize1 = ImGui::GetFont()->CalcTextSizeA((25), FLT_MAX, -1, 血量.c_str(), NULL, NULL); 

if (iHealth > 0) {
圆环(ImVec2(x, y - 75), 25.0f, 圆环health, 10.0f, 100, iHealth);
ImGui::GetForegroundDrawList()->AddText(NULL, (25), ImVec2(x - (textSize1.x / 2), y - 75 - (textSize1.y / 2)), 圆环health, 血量.c_str());
} else {
圆环(ImVec2(x, y - 75), 25.0f, 圆环health, 10.0f, 100, 100);
}


auto textSize_信息 = ImGui::GetFont()->CalcTextSizeA(27, FLT_MAX, -1, TeamText, NULL, NULL);
DrawTf.绘制字体描边(27, x - (textSize_信息.x / 2), box.y - 19 - (textSize_信息.y / 2), ImVec4{255,255,255,255}, TeamText);//队伍ID
}
}












void 自瞄图片() {
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 65); //圆角
ImGui::SetNextWindowSize(ImVec2(130, 130)); //窗口大小
ImGui::Begin("AimbotWindow", NULL, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize);
ImVec2 image_size = ImVec2(110, 110);
ImVec2 window_pos = ImGui::GetWindowPos(); 
ImVec2 window_center = ImVec2(window_pos.x + ImGui::GetWindowWidth() / 2, window_pos.y + ImGui::GetWindowHeight() / 2);

static float rotation_angle = 0.0f;
float cos_a = cosf(rotation_angle * 3.14159265358979323846 / 180.0f);
float sin_a = sinf(rotation_angle * 3.14159265358979323846 / 180.0f);
ImVec2 ul = ImVec2(-image_size.x * 0.5f, -image_size.y * 0.5f);
ImVec2 ur = ImVec2(image_size.x * 0.5f, -image_size.y * 0.5f);
ImVec2 br = ImVec2(image_size.x * 0.5f, image_size.y * 0.5f);
ImVec2 bl = ImVec2(-image_size.x * 0.5f, image_size.y * 0.5f);
ImVec2 rotated_ul = ImVec2(ul.x * cos_a - ul.y * sin_a, ul.x * sin_a + ul.y * cos_a) + window_center;
ImVec2 rotated_ur = ImVec2(ur.x * cos_a - ur.y * sin_a, ur.x * sin_a + ur.y * cos_a) + window_center;
ImVec2 rotated_br = ImVec2(br.x * cos_a - br.y * sin_a, br.x * sin_a + br.y * cos_a) + window_center;
ImVec2 rotated_bl = ImVec2(bl.x * cos_a - bl.y * sin_a, bl.x * sin_a + bl.y * cos_a) + window_center;
if (DrawIo[20]) 
rotation_angle -= 2.0f * speed;
ImGui::GetWindowDrawList()->AddImageQuad(aim_png, rotated_ul, rotated_ur, rotated_br, rotated_bl);
static bool Active = false;
if (state(Active)) {
DrawIo[20] = !DrawIo[20];
}

ImGui::End();
ImGui::PopStyleVar();//恢复圆角
}


