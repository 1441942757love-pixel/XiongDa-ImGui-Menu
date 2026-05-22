AimCount = 0;
Cloud.PlayerCount = 0;
Cloud.BotCount = 0;
Cloud.被瞄准对象数量 = 0;

// 游戏数据一系列
Cloud.Uworld = White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.libUE4 + 0xDE49DE8) + 0x810) + 0x78);
Cloud.Uleve = White->read<uintptr_t>(Cloud.Uworld + 0x30);
Cloud.Arrayaddr = White->read<uintptr_t>(Cloud.Uleve + 0xA0);
Cloud.Count = White->read<int>(Cloud.Uleve + 0xA8);
Cloud.Matrixs = White->read<uintptr_t>(White->read<uintptr_t>(Cloud.libUE4 + 0xDE1DE50) + 0x20) + 0x270;//矩阵

// 自身一系类
Cloud.Oneself = White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.libUE4 + 0xDE49DE8) + 0x810) + 0x78) + 0x38)+ 0x78)+0x30) + 0x2698);
Cloud.MyTeam = White->read<int>(Cloud.Oneself + 0x928);
Cloud.MyWeapon = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Oneself + 0x2328) + 0x558) + 0x840) + 0x178);
White->read(White->read<uintptr_t>(Cloud.Oneself + 0x1b0) + 0x1c0, &Cloud.MyPos, 12);

memset(Cloud.matrix, 0, 16);
White->read(Cloud.Matrixs, &Cloud.matrix, 16 * 4);

// 自身fov，开火，开镜，雷达旋转值
Cloud.Fov = White->read<float>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Oneself + 0x46a0) + 0x4d0) + 0x4b0);//printf("\n%d\n",Cloud.Fov);
Cloud.IsFiring = White->read<int>(Cloud.Oneself + 0x1688);//开火
Cloud.IsAiming = White->read<int>(Cloud.Oneself + 0x1069);//开镜
//printf("\n%d\n",Cloud.IsAiming);//看输出
Cloud.angle = White->read<float>(Cloud.Oneself + 0xd8) - 90; 
Cloud.zsdz = White->read<uintptr_t>(Cloud.Oneself + 0xf80);//自身动作
//Cloud.zsdz = White->read<uintptr_t>(Cloud.Oneself + 0x918);//自身uid
long int rw1 = White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Oneself + 0x348) + 0x30) + 0x388);
Cloud.自身包 = White->read<int>(rw1 + 0x1C4);
Cloud.自身头 = White->read<int>(rw1 + 0x1FC);
Cloud.自身甲 = White->read<int>(rw1 + 0x234);


for (int i = 0; i < Cloud.Count; i ++) {
Cloud.Objaddr = White->read<uintptr_t>(Cloud.Arrayaddr + 8 * i);

if (Cloud.Oneself == Cloud.Objaddr || Cloud.Objaddr <= 0x10000000 || Cloud.Objaddr % 4 != 0 || Cloud.Objaddr >= 0x10000000000)
continue;

uintptr_t object = White->read<uintptr_t>(Cloud.Objaddr + 0x1b0);
if (object <= 0xffff || object == 0 || object <= 0x10000000 || object % 4 != 0 || object >= 0x10000000000)
continue;


if (White->read<float>(Cloud.Objaddr + 0x2970) != 479.5) {
GetClassName(wz.wuziName, White->read<uintptr_t>(White->read<uintptr_t>(Cloud.libUE4 + 0xD877440) + 0x110), White->read<int>(Cloud.Objaddr + 0x18));
White->read(object + 0x1c0, &wz.Pos, 12);
GetDistance(wz.Pos, Cloud.MyPos, &wz.Distance);
WorldToScreen(&wz.ScreenPos, &wz.camera, &wz.w, wz.Pos);



} else {




// 倒地不绘制
// if (DrawIo[32] && Cloud.Health <= 0)
// continue;
// 人机判断
Cloud.人机 = White->read<int>(Cloud.Objaddr +  0x9e9);
if (Cloud.人机 == 16842753) Cloud.IsBot = 1; else Cloud.IsBot = 0;
//if (Cloud.人机 == 1) Cloud.IsBot = 1; else Cloud.IsBot = 0;
// 人机不绘制
if (DrawIo[17] && Cloud.IsBot == 1) 
continue;


// 死亡不绘制
int State = White->read<int>(Cloud.Objaddr + 0xddc);
if (State == 1 || State == 1)
continue;

// 自身队伍不绘制
Cloud.TeamID = White->read<int>(Cloud.Objaddr + 0x928);
if (Cloud.TeamID == Cloud.MyTeam || Cloud.TeamID < 1)
continue;

// 血量百分比大于百分之100不绘制
Cloud.Health = (White->read<float>(Cloud.Objaddr + 0xDc0) / White->read<float>(Cloud.Objaddr + 0xDc4)) * 100;
if (Cloud.Health > 100)
continue;





White->read(object + 0x1c0, &Cloud.Pos, 12); //读取坐标
GetDistance(Cloud.Pos, Cloud.MyPos, &Cloud.Distance); //用坐标计算出距离
矩阵(&Cloud.ScreenPos, &Cloud.camera, &Cloud.w, Cloud.Pos);

Cloud.被瞄数据 = White->read<float>(Cloud.Objaddr + 0xd8);
//Cloud.被瞄数据 = White->read<float>(Cloud.Objaddr + 0xb70);//0x2dc0    0x648   0xb70

//White->read(object + 0xc3c, &Cloud.Predict, sizeof(Cloud.Predict)); // 载具向量
White->read(object + 0x260, &Cloud.Predict, sizeof(Cloud.Predict)); // 敌人向量
//int 测试 = White->read<int>(Cloud.Objaddr + 0xf9c);
//printf("\n%d\n",测试);

// 头甲包
long int rw = White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x348) + 0x30) + 0x388);
Cloud.敌人包 = White->read<int>(rw + 0x1C4);
Cloud.敌人头 = White->read<int>(rw + 0x1FC);
Cloud.敌人甲 = White->read<int>(rw + 0x234);
 
// 动作，手持，当前子弹，最大子弹
Cloud.Act = White->read<uintptr_t>(Cloud.Objaddr + 0xf80);
Cloud.Weapon = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x2328) + 0x558) + 0x840) + 0x178);
//Cloud.dqzd = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x2328)+ 0x558)+0xed8);
//Cloud.zdmax = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x2328)+ 0x558)+0xef8);

// 名字   
getUTF8(Cloud.PlayerName, White->read<uintptr_t>(Cloud.Objaddr + 0x8f0));

// 骨骼
Cloud.Mesh = White->read<uintptr_t>(Cloud.Objaddr + 0x498);
Cloud.Human = Cloud.Mesh + 0x1b0;
Cloud.Bone = White->read<uintptr_t>(Cloud.Mesh + 0x878)+0x30;


FTransform meshtrans = getBone(Cloud.Human);
FMatrix c2wMatrix = TransformToMatrix(meshtrans);

float MaxHealth = White->read<float>(Cloud.Objaddr + 0xdc4);
/* 头部 */
FTransform headtrans;
if(MaxHealth<=150)
headtrans = getBone(Cloud.Bone + 5 * 48);
else
headtrans = getBone(Cloud.Bone + 5 * 48);
FMatrix boneMatrix = TransformToMatrix(headtrans);
Cloud.Head.Pos = MarixToVector(MatrixMulti(boneMatrix, c2wMatrix));
Cloud.Head.Pos.z += 7; /* 脖子长度 */
Cloud.Head.ScreenPos = WorldToScreen(Cloud.Head.Pos, Cloud.matrix, Cloud.camera);

/* 胸部 */
FTransform chesttrans;
if(MaxHealth<=150)
chesttrans = getBone(Cloud.Bone + 4 * 48);
else
chesttrans = getBone(Cloud.Bone + 4 * 48);
FMatrix boneMatrix1 = TransformToMatrix(chesttrans);
Cloud.Chest.Pos = MarixToVector(MatrixMulti(boneMatrix1, c2wMatrix));
Cloud.Chest.ScreenPos = WorldToScreen(Cloud.Chest.Pos, Cloud.matrix, Cloud.camera);

/* 盆骨 */
FTransform Pelvistrans;
if(MaxHealth<=150)
 Pelvistrans= getBone(Cloud.Bone + 0 * 48);
 else
 Pelvistrans= getBone(Cloud.Bone + 0 * 48);
FMatrix boneMatrix2 = TransformToMatrix(Pelvistrans);
Cloud.Pelvis.Pos = MarixToVector(MatrixMulti(boneMatrix2, c2wMatrix));
Cloud.Pelvis.ScreenPos = WorldToScreen(Cloud.Pelvis.Pos, Cloud.matrix, Cloud.camera);

/* 左肩膀 */
FTransform lshtrans;
if(MaxHealth<=150)
lshtrans = getBone(Cloud.Bone + 11 * 48);
else 
lshtrans = getBone(Cloud.Bone + 13 * 48);
FMatrix boneMatrix3 = TransformToMatrix(lshtrans);
Cloud.Left_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix3, c2wMatrix));
Cloud.Left_Shoulder.ScreenPos = WorldToScreen(Cloud.Left_Shoulder.Pos, Cloud.matrix, Cloud.camera);

/* 右肩膀 */
FTransform rshtrans;
if(MaxHealth<=150)
rshtrans = getBone(Cloud.Bone + 32 * 48);
else
rshtrans = getBone(Cloud.Bone + 34 * 48);
FMatrix boneMatrix4 = TransformToMatrix(rshtrans);
Cloud.Right_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix4, c2wMatrix));
Cloud.Right_Shoulder.ScreenPos = WorldToScreen(Cloud.Right_Shoulder.Pos, Cloud.matrix, Cloud.camera);

/* 左手肘 */
FTransform lelbtrans;
if(MaxHealth<=150)
lelbtrans = getBone(Cloud.Bone + 12 * 48);
else
lelbtrans = getBone(Cloud.Bone + 14 * 48);
FMatrix boneMatrix5 = TransformToMatrix(lelbtrans);
Cloud.Left_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix5, c2wMatrix));
Cloud.Left_Elbow.ScreenPos = WorldToScreen(Cloud.Left_Elbow.Pos, Cloud.matrix, Cloud.camera);

/* 右手肘 */
FTransform relbtrans;
if(MaxHealth<=150)
 relbtrans = getBone(Cloud.Bone + 33 * 48);
else
 relbtrans = getBone(Cloud.Bone + 35 * 48);
FMatrix boneMatrix6 = TransformToMatrix(relbtrans);
Cloud.Right_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix6, c2wMatrix));
Cloud.Right_Elbow.ScreenPos = WorldToScreen(Cloud.Right_Elbow.Pos, Cloud.matrix, Cloud.camera);

/* 左手腕 */
FTransform lwtrans;
if(MaxHealth<=150)
 lwtrans = getBone(Cloud.Bone + 63 * 48);
else
 lwtrans = getBone(Cloud.Bone + 16 * 48);
FMatrix boneMatrix7 = TransformToMatrix(lwtrans);
Cloud.Left_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix7, c2wMatrix));
Cloud.Left_Wrist.ScreenPos = WorldToScreen(Cloud.Left_Wrist.Pos, Cloud.matrix, Cloud.camera);

/* 右手腕 */
FTransform rwtrans;
if(MaxHealth<=150)
 rwtrans = getBone(Cloud.Bone + 62 * 48);
else
 rwtrans = getBone(Cloud.Bone + 37 * 48);
FMatrix boneMatrix8 = TransformToMatrix(rwtrans);
Cloud.Right_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix8, c2wMatrix));
Cloud.Right_Wrist.ScreenPos = WorldToScreen(Cloud.Right_Wrist.Pos, Cloud.matrix, Cloud.camera);

/* 左大腿 */
FTransform Llshtrans;
if(MaxHealth<=150)
 Llshtrans = getBone(Cloud.Bone + 52 * 48);
else
 Llshtrans = getBone(Cloud.Bone + 54 * 48);
FMatrix boneMatrix9 = TransformToMatrix(Llshtrans);
Cloud.Left_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix9, c2wMatrix));
Cloud.Left_Thigh.ScreenPos = WorldToScreen(Cloud.Left_Thigh.Pos, Cloud.matrix, Cloud.camera);

/* 右大腿 */
FTransform Lrshtrans;
if(MaxHealth<=150)
 Lrshtrans = getBone(Cloud.Bone + 56 * 48);
else
 Lrshtrans = getBone(Cloud.Bone + 58 * 48);
FMatrix boneMatrix10 = TransformToMatrix(Lrshtrans);
Cloud.Right_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix10, c2wMatrix));
Cloud.Right_Thigh.ScreenPos = WorldToScreen(Cloud.Right_Thigh.Pos, Cloud.matrix, Cloud.camera);

/* 左膝盖 */
FTransform Llelbtrans;
if(MaxHealth<=150)
 Llelbtrans = getBone(Cloud.Bone + 53 * 48);
else
 Llelbtrans = getBone(Cloud.Bone + 55 * 48);
FMatrix boneMatrix11 = TransformToMatrix(Llelbtrans);
Cloud.Left_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix11, c2wMatrix));
Cloud.Left_Knee.ScreenPos = WorldToScreen(Cloud.Left_Knee.Pos, Cloud.matrix, Cloud.camera);

/* 右膝盖 */
FTransform Lrelbtrans;
if(MaxHealth<=150)
 Lrelbtrans = getBone(Cloud.Bone + 57 * 48);
else
 Lrelbtrans = getBone(Cloud.Bone + 59 * 48);
FMatrix boneMatrix12 = TransformToMatrix(Lrelbtrans);
Cloud.Right_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix12, c2wMatrix));
Cloud.Right_Knee.ScreenPos = WorldToScreen(Cloud.Right_Knee.Pos, Cloud.matrix, Cloud.camera);

/* 左脚腕 */
FTransform Llwtrans;
if(MaxHealth<=150)
 Llwtrans = getBone(Cloud.Bone + 54 * 48);
else
 Llwtrans = getBone(Cloud.Bone + 56 * 48);
FMatrix boneMatrix13 = TransformToMatrix(Llwtrans);
Cloud.Left_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix13, c2wMatrix));
Cloud.Left_Ankle.ScreenPos = WorldToScreen(Cloud.Left_Ankle.Pos, Cloud.matrix, Cloud.camera);

/* 右脚腕 */
FTransform Lrwtrans;
if(MaxHealth<=150)
 Lrwtrans = getBone(Cloud.Bone + 58* 48);
else
 Lrwtrans = getBone(Cloud.Bone + 60 * 48);
FMatrix boneMatrix14 = TransformToMatrix(Lrwtrans);
Cloud.Right_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix14, c2wMatrix));
Cloud.Right_Ankle.ScreenPos = WorldToScreen(Cloud.Right_Ankle.Pos, Cloud.matrix, Cloud.camera);

//usleep(1);
// 统计人数
if (Cloud.IsBot) Cloud.BotCount++; else Cloud.PlayerCount++;






//---------------------------------------------------




// 雷达点
if (DrawIo[7] && Cloud.TotalUp) {
// 不旋转的雷达
float radius = Cloud.Distance/NumIo[16];
Vec2 Radar = rotateCoord(Cloud.angle, (Cloud.MyPos.x - Cloud.Pos.x) / (Cloud.Distance / radius), (Cloud.MyPos.y -Cloud.Pos.y) / (Cloud.Distance / radius)); // 旋转的雷达
string ld;
string ai;


ImColor color;
if (Cloud.IsBot == 1) {
color = ImColor(255, 255, 255);//假人背景色白色
if (draw_style[2] == 0) {
ai += to_string((int) Cloud.Health);//显示血量假人
} else if (draw_style[2] == 1) {
ai += to_string((int)Cloud.Distance);//显示距离假人
} else if (draw_style[2] == 2) {
ai += to_string((int)Cloud.TeamID);//显示队伍编号假人
}
} else {
color = ImColor(arr[Cloud.TeamID]);//背景色跟随血量颜色
if (draw_style[2] == 0) {
ld += to_string((int) Cloud.Health);//显示血量真人
} else if (draw_style[2] == 1) {
ld += to_string((int)Cloud.Distance);//显示距离真人
} else if (draw_style[2] == 2) {
ld += to_string((int)Cloud.TeamID);//显示队伍编号真人
}
}

auto textSize_ld = ImGui::CalcTextSize(ld.c_str());
auto textSize_ai = ImGui::CalcTextSize(ai.c_str());
// 计算圆形的中心位置
ImVec2 centerPos = ImVec2(NumIo[1] + Radar.x, NumIo[2] + Radar.y);
ImVec2 textPos = ImVec2(centerPos.x - textSize_ld.x / 3.4f, centerPos.y - textSize_ld.y / 3.5f);
ImVec2 textPos1 = ImVec2(centerPos.x - textSize_ai.x / 3.4f, centerPos.y - textSize_ai.y / 3.5f);

ImGui::GetForegroundDrawList()->AddCircleFilled(centerPos, 20, color);
ImGui::GetForegroundDrawList()->AddCircle(centerPos, 21, ImColor(0, 0, 0), 0, 2);
ImGui::GetForegroundDrawList()->AddText(NULL, 21, textPos, ImColor(0, 0, 0), ld.c_str());
ImGui::GetForegroundDrawList()->AddText(NULL, 21, textPos1, ImColor(0, 0, 0), ai.c_str());

}








float 屏幕判断;
if (screen_x < screen_y) {
屏幕判断 = screen_x;
} else {
屏幕判断 = screen_y;
}
// 超出屏幕不绘制
if (Cloud.w < 0 || Cloud.w > 屏幕判断)
continue;



if (DrawIo[20] && ((DrawIo[31] && !Cloud.IsBot) || !DrawIo[31]) && ((DrawIo[32] && Cloud.Health > 0) || !DrawIo[32])) {
strcpy(Aim[AimCount].Name, Cloud.PlayerName);
Aim[AimCount].dwbh = Cloud.TeamID;
Aim[AimCount].WodDistance = Cloud.Distance;
Aim[AimCount].AimMovement = Cloud.Predict;



if (DrawIo[35]) {
int 上边, 右边, 左边, 下边; 
左边  = Cloud.Head.ScreenPos.x - Cloud.w * 0.6;//左边
上边  = Cloud.Head.ScreenPos.y - Cloud.w / 4;//上边
右边 = Cloud.Head.ScreenPos.x + Cloud.w * 0.6;//右边
下边 = Cloud.Head.ScreenPos.y + ((右边 - 左边) * 1.88);//下边
float 范围x = 扩大范围x;
float 范围y = 扩大范围y;
目标x轴 = (右边 - 左边) / (1.85 / 范围x);//用于计算x范围
目标y轴 = (下边 - 上边) / (1.7 / 范围y);//用于计算y范围
//printf("\n%d\n",width);

Aim[AimCount].ScreenDistance = sqrt(pow(0,2) + pow(screen_x / 2 - Cloud.Pelvis.ScreenPos.x, 2));
Aim[AimCount].ScreenDistance1 = sqrt(pow(0,2) + pow(screen_y / 2 - Cloud.Pelvis.ScreenPos.y - 30, 2));

if (NumIo[8] == 1.0){
Aim[AimCount].ObjAim = Cloud.Head.Pos;
} else if (NumIo[8] == 2.0){
Aim[AimCount].ObjAim = Cloud.Chest.Pos;
} else if (NumIo[8] == 3.0){
Aim[AimCount].ObjAim = Cloud.Pelvis.Pos; 
} else {
Aim[AimCount].ObjAim = Cloud.Head.Pos;
}
} else {
if (NumIo[8] == 1.0){
Aim[AimCount].ObjAim = Cloud.Head.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - Cloud.Head.ScreenPos.x, 2) + pow(screen_y / 2 - Cloud.Head.ScreenPos.y, 2));
} else if (NumIo[8] == 2.0){
Aim[AimCount].ObjAim = Cloud.Chest.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - Cloud.Chest.ScreenPos.x, 2) + pow(screen_y / 2 - Cloud.Chest.ScreenPos.y, 2));
} else if (NumIo[8] == 3.0){
Aim[AimCount].ObjAim = Cloud.Pelvis.Pos; 
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - Cloud.Pelvis.ScreenPos.x, 2) + pow(screen_y / 2 - Cloud.Pelvis.ScreenPos.y, 2));
} else {
Aim[AimCount].ObjAim = Cloud.Head.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - Cloud.Head.ScreenPos.x, 2) + pow(screen_y / 2 - Cloud.Head.ScreenPos.y, 2));
}
}
AimCount++;
}





// 背敌
if (DrawIo[8]) {
tm = 120.f/255.f;
float cameras = Cloud.matrix[3] * Cloud.Pos.x + Cloud.matrix[7] * Cloud.Pos.y + Cloud.matrix[11] * Cloud.Pos.z + Cloud.matrix[15]; 
if (!Cloud.IsBot) {
OffScreen(Cloud.ScreenPos, cameras, ImColor(arr[Cloud.TeamID%length]), NumIo[3] + 20 + Cloud.Distance * 0.3);
} else {
OffScreen(Cloud.ScreenPos, cameras, ImColor(255, 255, 255, 255), NumIo[3] + 20 + Cloud.Distance * 0.3);
}
}

// 距离



float top, right, left, bottom, top1; 


left  = Cloud.Head.ScreenPos.x - Cloud.w * 0.6;//左边
right = Cloud.Head.ScreenPos.x + Cloud.w * 0.6;//右边
top  = Cloud.Head.ScreenPos.y - Cloud.w / 4;//上边
bottom = Cloud.Head.ScreenPos.y + ((right - left) * 1.88);//下边
/*
if (DrawIo[35]) {
float 方框自瞄;
float width = (right - left) * 0.62;
if (width < 40) {
方框自瞄 = 40;
} else {
方框自瞄 = width;
}
框内范围 = std::min(方框自瞄, 方框自瞄);
}
*/
//方框
if (DrawIo[1]) {
float Linesize = 900 / (Cloud.Distance + 10);
if (draw_style[0] == 0)
{
if (Cloud.IsBot) {
Draw->AddRect({left, top}, {right, bottom}, 绘制颜色[2], 0, 0, 绘制粗细[2]); 
} else {  
Draw->AddRect({left, top}, {right, bottom}, 绘制颜色[1], 0, 0, 绘制粗细[1]);
}
}
if (draw_style[0] == 1)
{
if (Cloud.IsBot) {
Draw->AddRect({left, top}, {left, top + Linesize}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  
    Draw->AddRect({left, top}, {left + Linesize * 0.4f, top}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({left, bottom}, {left, bottom - Linesize}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  
    Draw->AddRect({left, bottom}, {left + Linesize * 0.4f, bottom}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({right, top}, {right - Linesize * 0.4f, top}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({right, top}, {right, top + Linesize}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  
    Draw->AddRect({right, bottom}, {right - Linesize * 0.4f, bottom}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({right, bottom}, {right, bottom - Linesize}, 绘制颜色[2], 0, 0, 绘制粗细[2]);  
} else {
Draw->AddRect({left, top}, {left, top + Linesize}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  
    Draw->AddRect({left, top}, {left + Linesize * 0.4f, top}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({left, bottom}, {left, bottom - Linesize}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  
    Draw->AddRect({left, bottom}, {left + Linesize * 0.4f, bottom}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({right, top}, {right - Linesize * 0.4f, top}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({right, top}, {right, top + Linesize}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  
    Draw->AddRect({right, bottom}, {right - Linesize * 0.4f, bottom}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  // 缩短水平线
    Draw->AddRect({right, bottom}, {right, bottom - Linesize}, 绘制颜色[1], 0, 0, 绘制粗细[2]);  
}
}
}






if (DrawIo[5]) {
string 距离;
距离 += to_string((int) Cloud.Distance);
距离 += " m";
DrawTf.绘制字体描边(25, Cloud.Head.ScreenPos.x - 20, bottom + 15, ImVec4{1.0f, 1.0f, 1.0f, 1.0f},  距离.c_str());
}


// 射线
if (DrawIo[2]) {
float 射线_y = 73;
if (Cloud.IsBot) {
Draw->AddLine({screen_x / 2 , 射线_y}, {Cloud.Head.ScreenPos.x, Cloud.Head.ScreenPos.y}, 绘制颜色[6], 绘制粗细[4]);  
} else {
Draw->AddLine({screen_x / 2 , 射线_y}, {Cloud.Head.ScreenPos.x, Cloud.Head.ScreenPos.y}, 绘制颜色[5], 绘制粗细[3]);  
}
}

// 骨骼
if (DrawIo[3]) {
/*
Draw->AddCircle({Cloud.Head.ScreenPos.x, Cloud.Head.ScreenPos.y}, Cloud.w / 6, 绘制颜色[7], 100);
DrawBone({Cloud.Head.ScreenPos.x, Cloud.Head.ScreenPos.y}, {Cloud.Chest.ScreenPos.x, Cloud.Chest.ScreenPos.y});
DrawBone({Cloud.Chest.ScreenPos.x, Cloud.Chest.ScreenPos.y}, {Cloud.Pelvis.ScreenPos.x, Cloud.Pelvis.ScreenPos.y});
DrawBone({Cloud.Chest.ScreenPos.x, Cloud.Chest.ScreenPos.y}, {Cloud.Left_Shoulder.ScreenPos.x, Cloud.Left_Shoulder.ScreenPos.y});
DrawBone({Cloud.Chest.ScreenPos.x, Cloud.Chest.ScreenPos.y}, {Cloud.Right_Shoulder.ScreenPos.x, Cloud.Right_Shoulder.ScreenPos.y});
DrawBone({Cloud.Left_Shoulder.ScreenPos.x, Cloud.Left_Shoulder.ScreenPos.y}, {Cloud.Left_Elbow.ScreenPos.x, Cloud.Left_Elbow.ScreenPos.y});
DrawBone({Cloud.Right_Shoulder.ScreenPos.x, Cloud.Right_Shoulder.ScreenPos.y},{Cloud.Right_Elbow.ScreenPos.x, Cloud.Right_Elbow.ScreenPos.y});
DrawBone({Cloud.Left_Elbow.ScreenPos.x, Cloud.Left_Elbow.ScreenPos.y}, {Cloud.Left_Wrist.ScreenPos.x, Cloud.Left_Wrist.ScreenPos.y});
DrawBone({Cloud.Right_Elbow.ScreenPos.x, Cloud.Right_Elbow.ScreenPos.y}, {Cloud.Right_Wrist.ScreenPos.x, Cloud.Right_Wrist.ScreenPos.y});
DrawBone({Cloud.Pelvis.ScreenPos.x, Cloud.Pelvis.ScreenPos.y}, {Cloud.Left_Thigh.ScreenPos.x, Cloud.Left_Thigh.ScreenPos.y});
DrawBone({Cloud.Pelvis.ScreenPos.x, Cloud.Pelvis.ScreenPos.y}, {Cloud.Right_Thigh.ScreenPos.x, Cloud.Right_Thigh.ScreenPos.y});
DrawBone({Cloud.Left_Thigh.ScreenPos.x, Cloud.Left_Thigh.ScreenPos.y}, {Cloud.Left_Knee.ScreenPos.x, Cloud.Left_Knee.ScreenPos.y});
DrawBone({Cloud.Right_Thigh.ScreenPos.x, Cloud.Right_Thigh.ScreenPos.y}, {Cloud.Right_Knee.ScreenPos.x, Cloud.Right_Knee.ScreenPos.y});
DrawBone({Cloud.Left_Knee.ScreenPos.x, Cloud.Left_Knee.ScreenPos.y}, {Cloud.Left_Ankle.ScreenPos.x, Cloud.Left_Ankle.ScreenPos.y});
DrawBone({Cloud.Right_Knee.ScreenPos.x, Cloud.Right_Knee.ScreenPos.y}, {Cloud.Right_Ankle.ScreenPos.x, Cloud.Right_Ankle.ScreenPos.y});
*/
}

// 血量&名字
if (DrawIo[6]) {
if (!Cloud.IsBot) {
DrawHealth({Cloud.Head.ScreenPos.x, top }, Cloud.w * 2, Cloud.Health, Cloud.TeamID, Cloud.PlayerName);
} else {
DrawHealth({Cloud.Head.ScreenPos.x, top }, Cloud.w * 2, Cloud.Health, Cloud.TeamID, "AI");
}
}

// 手持
if (DrawIo[10]) {
string s;
s += 文本手持(Cloud.Weapon);
//s += "/";
//s += to_string((int)Cloud.zdmax);
auto textSize = ImGui::GetFont()->CalcTextSizeA(25, FLT_MAX, -1, s.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, 26.f, { Cloud.Head.ScreenPos.x - (textSize.x / 2) - 1, top - 45 - (textSize.y / 2) - 11}, ImColor(192,192,192,255), s.c_str());
ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, { Cloud.Head.ScreenPos.x - (textSize.x / 2), top - 45 - (textSize.y / 2) - 10}, ImColor(255,235,0,255), s.c_str());

}
/*
if (DrawIo[666])
{
string s;
s += to_string((int)Cloud.Weapon);
auto textSize = ImGui::GetFont()->CalcTextSizeA(25, FLT_MAX, -1, s.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, { Cloud.Head.ScreenPos.x - (textSize.x / 2), top - 45 - (textSize.y / 2) - 15 }, ImColor(255,255,255,255), s.c_str());

}
*/




if (DrawIo[19]) {
/*
string s;
s += tou(Cloud.敌人头);
//s += "\n";
s += jia(Cloud.敌人甲);
//s += "\n";
//s += bao(Cloud.敌人包);
auto textSize = ImGui::GetFont()->CalcTextSizeA(25, FLT_MAX, -1, s.c_str(), NULL, NULL); 
ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, { Cloud.Head.ScreenPos.x - (textSize.x / 2) + 0, top - 45 - (textSize.y / 2) - 10 }, ImColor(255,255,255,255), s.c_str());
*/
}

} //人物绘制结束





if (wz.w > 0){
白云云(载具, 0, 400);
白云云(宝箱, 1, 150);
白云云(物资箱, 2, 150);
白云云(武器箱, 3, 150);
白云云(药品箱, 4, 150);
白云云(信函箱, 5, 150);
白云云(姥爷物资, 6, 150);
白云云(狗子, 7, 150);
 
白云云(金插, 8, 120);
白云云(信号枪_, 9, 200);
白云云(盒子空投, 10, 150);
白云云(药品, 11, 150);
白云云(手枪, 12, 150);
白云云(步枪, 13, 150);
白云云(冲锋枪, 14, 150);
白云云(狙击枪, 15, 150);
白云云(霰弹枪, 16, 150);
白云云(子弹, 17, 150);
白云云(弹夹, 18, 150);
白云云(枪口, 19, 150);
白云云(瞄准镜, 20, 150);






if (DrawIo[14]) {
string name;
string name1;
string name2;
name += "手榴弹" + to_string((int)wz.Distance) + "M\n";
name1 += "燃烧瓶" + to_string((int)wz.Distance) + "M\n";
//name2 += "烟雾弹" + to_string((int)wz.Distance) + "M\n";
if (strstr(wz.wuziName, "BP_Grenade_Shoulei_C")) {
ImVec2 textSize = ImGui::CalcTextSize(name.c_str());
ImVec2 textPos = { wz.ScreenPos.x, wz.ScreenPos.y };
ImVec2 rectMin = { textPos.x - 30, textPos.y - 11 };
ImVec2 rectMax = { textPos.x - 25 + (textSize.x * 0.74) , textPos.y + textSize.y - 20 };
Draw->AddRect(rectMin, rectMax, ImColor(255, 0, 0), 7.5, 0, 2);
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 0, 0), name.c_str());
} else if (strstr(wz.wuziName, "BP_Grenade_Burn_C") || strstr(wz.wuziName, "ProjBurn_BP_C")) {
ImVec2 textSize = ImGui::CalcTextSize(name.c_str());
ImVec2 textPos = { wz.ScreenPos.x, wz.ScreenPos.y };
ImVec2 rectMin = { textPos.x - 30, textPos.y - 11 };
ImVec2 rectMax = { textPos.x - 25 + (textSize.x * 0.74) , textPos.y + textSize.y - 20 };
Draw->AddRect(rectMin, rectMax, ImColor(255, 255, 0), 7.5, 0, 2);
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 255, 0), name1.c_str());
} 
}

if (Cloud.IsFiring == 1)
continue;

if (DrawIo[15]) {
string name;
name += wz.wuziName;
auto textSize = ImGui::CalcTextSize(name.c_str(),0, 20);
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(0, 255, 0), name.c_str());
}




if (DrawIo[18]) {
string name;
name += "盒子 " + to_string((int)wz.Distance) + "M\n";
if (strstr(wz.wuziName, "XTPlayerDeadInventoryBox_C")  || strstr(wz.wuziName, "PickUpListWrapperActor") /* || strstr(wz.wuziName, "ckUpListWrapperActor") */ ) {

ImVec2 textSize = ImGui::CalcTextSize(name.c_str());
ImVec2 textPos = { wz.ScreenPos.x, wz.ScreenPos.y };
ImVec2 rectMin = { textPos.x - 30, textPos.y - 11 };
ImVec2 rectMax = { textPos.x - 25 + (textSize.x * 0.74) , textPos.y + textSize.y - 20 };

Draw->AddRect(rectMin, rectMax, ImColor(255, 255, 255), 7.5, 0, 2);

Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 255, 255), name.c_str());
}
}

if (DrawIo[16]) {
string name;
name += "信号枪" + to_string((int)wz.Distance) + "米\n";
if (strstr(wz.wuziName, "BP_Pistol_Flaregun")) {
ImVec2 textSize = ImGui::CalcTextSize(name.c_str());
ImVec2 textPos = { wz.ScreenPos.x, wz.ScreenPos.y };
ImVec2 rectMin = { textPos.x - 30, textPos.y - 11 };
ImVec2 rectMax = { textPos.x - 25 + (textSize.x * 0.74) , textPos.y + textSize.y - 20 };
Draw->AddRect(rectMin, rectMax, ImColor(255, 100, 100), 7.5, 0, 2);
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 100, 100), name.c_str());
}
}


if (物资[1] || 物资[2])
{
string name;
name += "已开";
if (strstr(wz.wuziName, "PlayerDeadInventoryBox_C")) {
ImVec2 textSize = ImGui::CalcTextSize(name.c_str());
ImVec2 textPos = { wz.ScreenPos.x, wz.ScreenPos.y };
ImVec2 rectMin = { textPos.x - 30, textPos.y - 11 };
ImVec2 rectMax = { textPos.x - 25 + (textSize.x * 0.74) , textPos.y + textSize.y - 20 };
Draw->AddRect(rectMin, rectMax, ImColor(255, 100, 100), 7.5, 0, 2);
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 100, 100), name.c_str());
}

}


/*
if ((White->read<int>(White->read<uintptr_t>(Cloud.Objaddr + 0XAD8)) > 0 && White->read<int>(White->read<uintptr_t>(Cloud.Objaddr + 0XAD8)) < 1000)) {
// Aimatdistance用来计算范围，只绘制屏幕中心为圆点半径100内的盒内物资，太多会很卡
float Aimatdistance = sqrt(pow(screen_x/2 - wz.ScreenPos.x, 2) + pow(screen_y/2 - wz.ScreenPos.y, 2));
if (Aimatdistance < 100 && Gmin == -1) {
// 搞根射线，不然老对不准盒子
ImGui::GetForegroundDrawList()->AddLine({screen_x / 2, screen_y / 2}, {wz.ScreenPos.x, wz.ScreenPos.y}, ImColor(255,255,0,255), 3.0f);
int 盒内物资数量 = White->read<int>(Cloud.Objaddr + 0xad8);//这个不知道
long int 物资数组 = White->read<uintptr_t>(Cloud.Objaddr + 0x880) + 0x4;
int 文本高度 = 50;
for (int i = 0; i < 盒内物资数量; i++) {
int 物资地址ID = White->read<int>(物资数组 + 0x38 * i);
int 物资地址数量 = White->read<int>((物资数组 + 0x38 * i) + 0x14);
// 这里我是直接打印的物资id测试，正常直接调用函数GetItems(物资地址ID)就行了
std::string name = to_string(物资地址ID);
name+= "[" + to_string(物资地址数量) + "]";
auto textSize = ImGui::CalcTextSize(name.c_str(), 0, 30);
文本高度 += 25;
DrawTf.绘制字体描边(25, wz.ScreenPos.x - textSize.x/2, wz.ScreenPos.y - 文本高度, ImVec4{1.0f, 1.0f, 0.0f, 1.0f},  name.c_str());
}
}
}
*/



}

/*
{
//static float szck;
ImVec4 currentColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
// 设置窗口透明度
ImGui::SetNextWindowBgAlpha(0.4f); // 完全透明
  // 设置窗口位置
ImGui::SetNextWindowPos(ImVec2(50 + 550, 10));
// 创建窗口
ImGui::SetNextWindowSize(ImVec2(300,100));
ImGui::Begin("RecordingTimeWindow", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar);
ImGui::TextColored(ImColor(255,255,255,225),"准心x : %.5f", Cloud.准心);
//ImGui::TextColored(ImColor(255,255,255,225),"准心y : %d", gg2);
ImGui::End();
}
*/

} //总循环
MaxPlayerCount = AimCount;
Cloud.TotalUp = Cloud.PlayerCount + Cloud.BotCount;