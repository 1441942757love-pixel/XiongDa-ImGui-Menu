#ifndef STRUCT_H
#define STRUCT_H
#include <Function.h>
#include <sys/types.h>


struct Data {
pid_t pid = -1;
int Count,PlayerCount,BotCount,TotalUp;
uintptr_t libUE4;
int 被瞄准对象数量 = 0;
float 被瞄数据;
uintptr_t Gname,Uworld,Matrixs,Uleve,Arrayaddr,Oneself;
uintptr_t Objaddr,Object,Mesh,Human,Bone;
float matrix[16]; // 游戏矩阵
float Fov; // 自身fov
int IsFiring; // 开火判断
int IsAiming; // 开镜判断
int MyWeapon; // 自身手持
int zdsd;//自身子弹速度
int MyTeam; // 自身队伍
int zsdz;//自身动作
float w; // 人物宽度
Vec3 Pos; // 敌人坐标
Vec3 MyPos; // 自身坐标
Vec2 ScreenPos; // 屏幕坐标
Vec3 Predict; // 移动向量
float camera; // 人物相机
int Act; // 动作
int TeamID; // 队伍
int Weapon; // 手持
int Wuqi;//手持武器
int dqzd; // 当前子弹
int zdmax; // 最大子弹
int 敌人头; // 敌人头
int 敌人甲; // 敌人甲
int 敌人包; // 敌人包
int 自身头; // 自身头
int 自身甲; // 自身甲
int 自身包; // 自身包
bool IsBot; // 人机判断
int 人机;
float Health; // 血量百分比
float Distance; // 距离
//float Wuqi;//手持武器
char PlayerName[64]; // 玩家名称
float angle; // 雷达旋转值
int 盒内物资数量;
int 物资数组;
//int 准心; // 敌人坐标





BoneStruct Head;   
BoneStruct Chest;
BoneStruct Pelvis;
BoneStruct Left_Shoulder;
BoneStruct Right_Shoulder;
BoneStruct Left_Elbow;
BoneStruct Right_Elbow;
BoneStruct Left_Wrist;
BoneStruct Right_Wrist;
BoneStruct Left_Thigh;
BoneStruct Right_Thigh;
BoneStruct Left_Knee;
BoneStruct Right_Knee;
BoneStruct Left_Ankle;
BoneStruct Right_Ankle;
};



struct WuziData{
float w; // 宽度
Vec3 Pos; // 世界坐标
Vec2 ScreenPos; // 屏幕坐标
float camera; // 相机
float Distance; // 距离
char wuziName[128]; // 类名
};

struct 盒内1 {
//uintptr_t 盒子数组;
//int 物资数组;
int 盒内数量 = 0; // 盒内物资数量
//int 遍历盒内数量 = 0;
int 盒内数量计算;
int 箱子id;
int 物资id;
};
struct 预警1 {
float 距离;
std::string 名字;
std::string 瞄准武器;
};

extern 预警1 预警[100]; // 自瞄结构
extern 盒内1 盒内;
extern Data cloud;
extern WuziData wz;

  
#endif
