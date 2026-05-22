#include "Struct.h"
#include <cstdio>
#include <cstdlib>
#include <random>
struct AimStruct {
Vec3 ObjAim;  
Vec3 AimMovement;  
float ScreenDistance = 0;
float ScreenDistance1 = 0;
float WodDistance = 0; 
int dwbh;
char Name[32];
};

#ifdef AIMBOT_SEPARATED

using namespace std;

extern AimStruct Aim[100]; // 自瞄结构
extern int AimCount;
extern float zm_x, zm_y;
extern int MaxPlayerCount;
extern int Gmin;
extern bool IsAimLongAim;
extern char AimName[32];
extern int dwid;
extern Vec2 vpvp;
extern float fwjl;
extern bool DrawIo[50];
extern float NumIo[50];

// 初始化随机数生成器
std::mt19937 generator(static_cast<unsigned int>(time(0)));
std::uniform_int_distribution<int> distribution_offset(-40, 40); // 定义偏移范围，例如±80像素

float GetPitch(float Fov) 
{
if (Fov > 75 && Fov <= 130)  // 不开镜
{
return 0.6f * NumIo[14];
}
else if (Fov == 70 || Fov == 75)// 机瞄 ，侧瞄
{ 
return 2.5f * NumIo[14];   
}
else if (Fov == 55 || Fov == 60)// 红点 ，全息
{
return 2.5f * NumIo[14];
}   
else if ((int)Fov == 44)// 2倍
{
return 5.1f * NumIo[14];
}
else if ((int)Fov == 26)// 3倍
{
return 7.1f * NumIo[14];
}
else if ((int)Fov == 20)// 4倍
{
return 8.4f * NumIo[14];
}
else if ((int)Fov == 13)// 6倍
{   
return 13.9f * NumIo[14];
}
return 2.5f * NumIo[14];   // 8倍
}


float GetWeaponId(int WeaponId) {
switch (WeaponId) {
//突击步枪
case 101008:
return 1.2; // M762
break;
case 101001:
return 1.1; // AKM
break;
case 101004:
return 0.8; // M416
break;
case 101003:
return 0.8; // SCAR-L
break;
case 101002:
return 0.85; // M16A4
break;
case 101009:
return 1.05; // Mk47
break;
case 101006:
return 0.75; // AUG
break;
case 101005:
return 1.05; // Groza
break;
case 101010:
return 1.15; // G36C
break;
case 101007:
return 0.95; // QBZ
break;
case 101011:
return 1.0; // AC-VAL
break;
case 101012:
return 0.90; // 蜜獾突击步枪
break;
//机关枪
case 105001:
return 1.3; // M249
break;
case 105002:
return 1.3; // DP-28

case 105010:
return 0.6; // MG3
break;
case 1050101:
return 0.6; // 破损MG3
break;
case 1050102:
return 0.6; // 修复MG3
break;
case 1050103:
return 0.6; // 完好MG3
break;
case 1050104:
return 0.6; // 改进MG3
break;
case 1050105:
return 0.6; // 精致MG3
break;

break;
//冲锋枪
case 102001:
return 0.6; // UZI
break;
case 102003:
return 0.6; // Vector
break;
case 100103:
return 0.65; // PP-19
break;
case 102007:
return 0.6; // MP5K
break;
case 102002:
return 0.6; // UMP 5
break;
case 102004:
return 0.6; // 汤姆逊
break;
case 102005:
return 0.6; // 野牛
break;
case 103001:
return 0; // 98k
break;
case 103004:
return 0; // sks
break;
case 103005:
return 0.5; // vss
break;
case 103012:
return 0; // amr
break;
case 103015:
return 0; // m200
break;

case 103007:
return 0.65; // 妹控
break;
case 1030071:
return 0.65; // 破损妹控
break;
case 1030072:
return 0.65; // 修复妹控
break;
case 1030073:
return 0.65; // 完好妹控
break;
case 1030074:
return 0.65; // 改进妹控
break;
case 1030075:
return 0.65; // 精致妹控
break;

case 102105:
return 0; // 妹控
break;
case 1021051:
return 0; // 破损P90
break;
case 1021052:
return 0; // 修复P90
break;
case 1021053:
return 0; // 完好P90
break;
case 1021054:
return 0; // 改进P90
break;
case 1021055:
return 0; // 精致P90
break;


default:
return 0.95; // 未收录
break;
}
return 1.0; // 未获取
}

float getScopeAcc(int Scope){
switch (Scope) {
case 0:
return 1.0f;
break;
case 1:
return .98f;
break;
case 2:
return .95f;
break;
case 3:
return .94f;
break;
case 4:
return .92f;
break;
case 5:
return .9f;
break;
case 6:
return .88f;
break;
case 7:
return .86f;
break;
case 8:
return .85f;
break;
default:
return .9f;
break;
}
}


// 遍历自瞄对象
int findminat() {
float 加大范围 = 0;
float min = NumIo[3] + 加大范围;
float DistanceMin = 400;
int minAt = 999;
for (int i = 0; i < MaxPlayerCount; i++) {
if (IsAimLongAim) {
if (strcmp(Aim[i].Name, AimName) == 0 &&Aim[i].dwbh == dwid) {
minAt = i;
}
} else {
if (DrawIo[35]) {
float mb = 0;//目标
float minx = 目标x轴;
float miny = 目标y轴;
if (Aim[i].ScreenDistance < minx&&Aim[i].ScreenDistance1 < miny) {
if (DrawIo[30]) {
strcpy(AimName, Aim[i].Name);
dwid = Aim[i].dwbh;
}
扩大范围x = 10;
扩大范围y = 10;
mb = Aim[i].ScreenDistance;
mb = Aim[i].ScreenDistance1;
//Aim[i].ScreenDistance = Aim[i].ScreenDistance1;
minAt = i;
} else {
扩大范围x = 1;
扩大范围y = 1;
}
} else {
if (Aim[i].ScreenDistance < min) {
if (DrawIo[30]) {
strcpy(AimName, Aim[i].Name);
dwid = Aim[i].dwbh;
}
加大范围 = 0;
min = Aim[i].ScreenDistance;
minAt = i;

} else {
加大范围 = 800;
}
}
}



}
if (minAt == 999) {
Gmin = -1;
IsAimLongAim = false;
return -1;
}
Gmin = minAt;

Aim[minAt].WodDistance;
if (DrawIo[30]) {
IsAimLongAim = true;
}
return minAt;
}




void AimBotAuto() {

// 自瞄线程



 double ScreenX, ScreenY;
// 分辨率(竖屏)PS:滑屏用的坐标是竖屏状态下的

if (screen_x < screen_y) {
ScreenX = screen_x;
ScreenY = screen_y;
} else {
ScreenX = screen_y;
ScreenY = screen_x;
}
int 补偿;


double ScrXH = ScreenX / 2;
// 一半屏幕X

double ScrYH = ScreenY / 2;
// 一半屏幕X



Vec3 obj;


while (1) {




if (Cloud.IsAiming != 1)
{
usleep(NumIo[28] * 800);
} else {
usleep(NumIo[9] * 800);
}
//ImGuiIO& iooi = ImGui::GetIO();

if (!DrawIo[20]) {
// 抬起
Touch_Up(6);
continue;
}
findminat();
// 获取目标

if(Cloud.IsAiming == 0&&abs(Aim[Gmin].WodDistance) >= NumIo[25])
Gmin =-1;
if (Gmin == -1)
{
// 抬起
Touch_Up(6);
continue;
}

findminat();
// 获取目标


float FlyTime1;
float FlyTime = Aim[Gmin].WodDistance / NumIo[11];
if (Aim[Gmin].WodDistance < 35&&Cloud.IsAiming == 1) {
FlyTime1 = 45 / NumIo[11];
} else {
FlyTime1 = Aim[Gmin].WodDistance / NumIo[11];
}
float DropM = 540.0f * FlyTime * FlyTime;
// 下坠
  
obj.x = Aim[Gmin].ObjAim.x + (Aim[Gmin].AimMovement.x * FlyTime1 * NumIo[22]);
obj.y = Aim[Gmin].ObjAim.y + (Aim[Gmin].AimMovement.y * FlyTime*NumIo[22]);
obj.z = Aim[Gmin].ObjAim.z + (Aim[Gmin].AimMovement.z * FlyTime*NumIo[22]) + DropM;
float 趴下;
if (Cloud.zsdz == 32 || Cloud.zsdz == 544 || Cloud.zsdz == 672) {
趴下 = 0.5;
} else {
趴下 = 1.0;
}
if (Cloud.IsFiring == 1) 
obj.z -= Aim[Gmin].WodDistance * NumIo[14] * 趴下 * GetWeaponId(Cloud.MyWeapon);

float cameras = Cloud.matrix[3] * obj.x + Cloud.matrix[7] * obj.y + Cloud.matrix[11] * obj.z + Cloud.matrix[15];
vpvp = WorldIsScreen(obj, cameras);  

zm_y = vpvp.x; 
zm_x = ScreenX - vpvp.y;



isDown = true;
if (Cloud.IsFiring != 1) {
IsAimLongAim = false;
if (isDown) {
int random_offset_x = distribution_offset(generator);
int random_offset_y = distribution_offset(generator);
// 应用随机偏移量
int final_x = NumIo[5] + random_offset_x;
int final_y = NumIo[6] + random_offset_y;
tx = final_x;
ty = final_y;

//tx = NumIo[5];
//ty = NumIo[6];
// 恢复变量

Touch_Up(6);
Touch_Up(6);
isDown = false;
}
continue;
}






float Acc = getScopeAcc((int)(90 / Cloud.Fov));
usleep(80);
 
if (zm_x > ScrXH) {
TargetX = -(ScrXH - zm_x) / 25 * Acc;
if (TargetX + ScrXH > ScrXH * 2 || zm_x < ScrXH) {
TargetX = 0;
}
}
else if (zm_x < ScrXH) {
TargetX = (zm_x - ScrXH) / 25 * Acc; 
if (TargetX + ScrXH < 0) {
TargetX = 0;
}
}

if (zm_y > ScrYH) {
TargetY = -(ScrYH - zm_y) / 25 * Acc;  
if (TargetY + ScrYH > ScrYH * 2 || zm_y < ScrYH) {
TargetY * 0;
}
} else if (zm_y < ScrYH) {
TargetY = (zm_y - ScrYH) / 25 * Acc;  
if (TargetY + ScrYH < 0) {
TargetY * 0;
}
}

usleep(10);
//printf("\n%.5f\n",TargetX);
//isDown = true;




float 腰射速度;
if (Cloud.IsAiming == 1) {
if (zm_x > ScrXH&&TargetX > 0.88) {
//tx -= (TargetX * 0.0888888);//下压
tx -= 0.6;//下压
}
腰射速度 = 0.888;
} else {
腰射速度 = 0.666;
}
usleep(10);
tx += (TargetX * NumIo[4] * 腰射速度);
ty += (TargetY * NumIo[4] * 腰射速度) * 1.3;
usleep(10);
//---------------------------------------------------

//---------------------------------------------------
 
}
}

#endif