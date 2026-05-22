AimCount = 0;
Cloud.PlayerCount = 0;
Cloud.BotCount = 0;

// 游戏数据一系列

Cloud.libUE4 = White->getModuleBase("libUE4.so"); //获取模块头即ue4地址
//libUE4.so+0xFA054B0+0xF8+0x1E0
//隔层 0x118
//遍历 0x10
//0x10*i）+0x118
Cloud.Uworld = White->read<uintptr_t>(Cloud.libUE4 + 0xFFA2D38);
Cloud.Uleve = White->read<uintptr_t>(Cloud.Uworld + 0x90);
Cloud.Arrayaddr = White->read<uintptr_t>(Cloud.Uleve + 0xA0);
Cloud.Count = White->read<int>(Cloud.Uleve + 0xA8);

// 自身一系类
Cloud.Oneself = White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.libUE4 + 0xFFA2D38) + 0x98) + 0x88) + 0x30) + 0x2f88);
Cloud.MyTeam = White->read<int>(Cloud.Oneself + 0xa98);
Cloud.MyWeapon = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Oneself + 0x2dc0) + 0x648) + 0xb70);
White->read(White->read<uintptr_t>(Cloud.Oneself + 0x278) + 0x1F0, &Cloud.MyPos, 12);
memset(Cloud.matrix, 0, 16); //初始化矩阵数组
Cloud.Matrixs = White->read<uintptr_t>(White->read<uintptr_t>(Cloud.libUE4 + 0xFF76B28) + 0x20) + 0x270; 
White->read(Cloud.Matrixs, &Cloud.matrix, 16 * 4);

// 自身fov，开火，开镜，雷达旋转值
Cloud.Fov = White->read<float>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Oneself + 0x4e08) + 0x5e0) + 0x5c0);
Cloud.IsFiring = White->read<int>(Cloud.Oneself + 0x2010);
Cloud.IsAiming = White->read<int>(Cloud.Oneself + 0x1518);
//printf("\n%d\n",Cloud.IsAiming);
Cloud.angle = White->read<float>(Cloud.Oneself + 0xd8) - 90; 
//Cloud.zsdz = White->read<uintptr_t>(Cloud.Oneself + 0x13e8);//自身动作



for (int i = 0; i < Cloud.Count; i ++) {
Cloud.Objaddr = White->read<uintptr_t>(Cloud.Arrayaddr + 8 * i);

if (Cloud.Oneself == Cloud.Objaddr || Cloud.Objaddr <= 0x10000000 || Cloud.Objaddr % 4 != 0 || Cloud.Objaddr >= 0x10000000000)
continue;

uintptr_t object = White->read<uintptr_t>(Cloud.Objaddr + 0x278);
if (object <= 0xffff || object == 0 || object <= 0x10000000 || object % 4 != 0 || object >= 0x10000000000)
continue;


if (White->read<float>(Cloud.Objaddr + 0x3140) != 479.5) {
GetClassName(wz.wuziName, White->read<uintptr_t>(Cloud.libUE4 + 0xF9C45B8), White->read<int>(Cloud.Objaddr + 0x18));
White->read(object + 0x1F0, &wz.Pos, 12);
GetDistance(wz.Pos, Cloud.MyPos, &wz.Distance);
WorldToScreen(&wz.ScreenPos, &wz.camera, &wz.w, wz.Pos);
} else {

// 倒地不绘制
// if (DrawIo[32] && Cloud.Health <= 0)
// continue;

// 人机判断
if (White->read<int>(Cloud.Objaddr +  0xab4)) Cloud.IsBot = 1; else Cloud.IsBot = 0;

// 人机不绘制
if (DrawIo[17] && Cloud.IsBot) 
continue;
// 死亡不绘制
int State = White->read<int>(Cloud.Objaddr + 0x13e8);
if (State == 1048576 || State == 1048592 || State == 1048577 || State == 0)
continue;

// 自身队伍不绘制
Cloud.TeamID = White->read<int>(Cloud.Objaddr + 0xa98);
if (Cloud.TeamID == Cloud.MyTeam || Cloud.TeamID < 1)
continue;

// 血量百分比大于百分之100不绘制
Cloud.Health = (White->read<float>(Cloud.Objaddr + 0xe20) / White->read<float>(Cloud.Objaddr + 0xe28)) * 100;
if (Cloud.Health > 100)
continue;


White->read(object + 0x1F0, &Cloud.Pos, 12); //读取坐标
GetDistance(Cloud.Pos, Cloud.MyPos, &Cloud.Distance); //用坐标计算出距离
WorldToScreen(&Cloud.ScreenPos, &Cloud.camera, &Cloud.w, Cloud.Pos); 


// 统计人数
if (Cloud.IsBot) Cloud.BotCount++; else Cloud.PlayerCount++;


// 超出屏幕不绘制
if (Cloud.w < 0 || Cloud.w > screen_x)
continue;
/*
//STExtraVehicleBase* OwnerVehicle;[Offset: 0x1b8, Size: 0x8]
//if (White->read<uintptr_t>(Cloud.Objaddr + 0x1000)) {
White->read(White->read<uintptr_t>(Cloud.Objaddr + 0x1B8) + 0x180, &Cloud.Predict, sizeof(Cloud.Predict)); // 载具向量
//} else {
White->read(object + 0x240, &Cloud.Predict, sizeof(Cloud.Predict)); // 敌人向量
//}
*/
//if (White->read<uintptr_t>(Cloud.Objaddr + 0x1000)) {
White->read(Cloud.Objaddr + 0xf14, &Cloud.Predict, sizeof(Cloud.Predict)); // 载具向量
//} else {
//White->read(object + 0x240, &Cloud.Predict, sizeof(Cloud.Predict)); // 敌人向量
//}
// 头甲包
long int rw = White->read<uintptr_t>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x348) + 0x30) + 0x388);
Cloud.敌人包 = White->read<int>(rw + 0x1C4);
Cloud.敌人头 = White->read<int>(rw + 0x1FC);
Cloud.敌人甲 = White->read<int>(rw + 0x234);
 
// 动作，手持，当前子弹，最大子弹
Cloud.Act = White->read<uintptr_t>(Cloud.Objaddr + 0x13e8);//人物动作
Cloud.Weapon = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x2dc0) + 0x648) + 0xb70);
Cloud.dqzd = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x22B8)+ 0x500)+0xec4);
Cloud.zdmax = White->read<int>(White->read<uintptr_t>(White->read<uintptr_t>(Cloud.Objaddr + 0x22B8)+ 0x500)+0xec0);
// 名字   
getUTF8(Cloud.PlayerName, White->read<uintptr_t>(Cloud.Objaddr + 0xa18));

// 骨骼
Cloud.Mesh = White->read<uintptr_t>(Cloud.Objaddr + 0x5d8);
Cloud.Human = Cloud.Mesh + 0x1e0;
Cloud.Bone = White->read<uintptr_t>(Cloud.Mesh + 0x788) + 0x30;


int BoneCount = White->read<uint64_t>(Cloud.Mesh + 0x788+8);



int p = (BoneCount == 68) ? 33 : 32;
int o = (BoneCount == 68) ? 34 : 33;
int a = (BoneCount == 68) ? 13 : 63;
int b = (BoneCount == 68) ? 35 : 62;
int c = (BoneCount == 68) ? 55 : 52;
int d = (BoneCount == 68) ? 59 : 56;
int e = (BoneCount == 68) ? 56 : 53;
int f = (BoneCount == 68) ? 60 : 57;
int g = (BoneCount == 68) ? 57 : 54;
int h = (BoneCount == 68) ? 61 : 58;

FTransform meshtrans = getBone(Cloud.Human);
FMatrix c2wMatrix = TransformToMatrix(meshtrans);
FTransform headtrans = getBone(Cloud.Bone + 5 * 48);
FMatrix boneMatrix = TransformToMatrix(headtrans);
Cloud.Head.Pos = MarixToVector(MatrixMulti(boneMatrix, c2wMatrix));
Cloud.Head.Pos.z += 7; /* 脖子长度 */
Cloud.Head.ScreenPos = WorldToScreen(Cloud.Head.Pos, Cloud.matrix, Cloud.camera);

/* 胸部 */
FTransform chesttrans = getBone(Cloud.Bone + 4 * 48);
FMatrix boneMatrix1 = TransformToMatrix(chesttrans);
Cloud.Chest.Pos = MarixToVector(MatrixMulti(boneMatrix1, c2wMatrix));
Cloud.Chest.ScreenPos = WorldToScreen(Cloud.Chest.Pos, Cloud.matrix, Cloud.camera);

/* 盆骨 */
FTransform pelvistrans = getBone(Cloud.Bone + 0 * 48);
FMatrix boneMatrix2 = TransformToMatrix(pelvistrans);
Cloud.Pelvis.Pos = MarixToVector(MatrixMulti(boneMatrix2, c2wMatrix));
Cloud.Pelvis.ScreenPos = WorldToScreen(Cloud.Pelvis.Pos, Cloud.matrix, Cloud.camera);

/* 左肩膀 */
FTransform lshtrans = getBone(Cloud.Bone + 11 * 48);
FMatrix boneMatrix3 = TransformToMatrix(lshtrans);
Cloud.Left_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix3, c2wMatrix));
Cloud.Left_Shoulder.ScreenPos = WorldToScreen(Cloud.Left_Shoulder.Pos, Cloud.matrix, Cloud.camera);

/* 右肩膀 */
FTransform rshtrans = getBone(Cloud.Bone + p * 48);
FMatrix boneMatrix4 = TransformToMatrix(rshtrans);
Cloud.Right_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix4, c2wMatrix));
Cloud.Right_Shoulder.ScreenPos = WorldToScreen(Cloud.Right_Shoulder.Pos, Cloud.matrix, Cloud.camera);

/* 左手肘 */
FTransform lelbtrans = getBone(Cloud.Bone + 12 * 48);
FMatrix boneMatrix5 = TransformToMatrix(lelbtrans);
Cloud.Left_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix5, c2wMatrix));
Cloud.Left_Elbow.ScreenPos = WorldToScreen(Cloud.Left_Elbow.Pos, Cloud.matrix, Cloud.camera);

/* 右手肘 */
FTransform relbtrans = getBone(Cloud.Bone + o * 48);
FMatrix boneMatrix6 = TransformToMatrix(relbtrans);
Cloud.Right_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix6, c2wMatrix));
Cloud.Right_Elbow.ScreenPos = WorldToScreen(Cloud.Right_Elbow.Pos, Cloud.matrix, Cloud.camera);

/* 左手腕 */
FTransform lwtrans = getBone(Cloud.Bone + a * 48);
FMatrix boneMatrix7 = TransformToMatrix(lwtrans);
Cloud.Left_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix7, c2wMatrix));
Cloud.Left_Wrist.ScreenPos = WorldToScreen(Cloud.Left_Wrist.Pos, Cloud.matrix, Cloud.camera);

/* 右手腕 */
FTransform rwtrans = getBone(Cloud.Bone + b * 48);
FMatrix boneMatrix8 = TransformToMatrix(rwtrans);
Cloud.Right_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix8, c2wMatrix));
Cloud.Right_Wrist.ScreenPos = WorldToScreen(Cloud.Right_Wrist.Pos, Cloud.matrix, Cloud.camera);

/* 左大腿 */
FTransform Llshtrans = getBone(Cloud.Bone + c * 48);
FMatrix boneMatrix9 = TransformToMatrix(Llshtrans);
Cloud.Left_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix9, c2wMatrix));
Cloud.Left_Thigh.ScreenPos = WorldToScreen(Cloud.Left_Thigh.Pos, Cloud.matrix, Cloud.camera);

/* 右大腿 */
FTransform Lrshtrans = getBone(Cloud.Bone + d * 48);
FMatrix boneMatrix10 = TransformToMatrix(Lrshtrans);
Cloud.Right_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix10, c2wMatrix));
Cloud.Right_Thigh.ScreenPos = WorldToScreen(Cloud.Right_Thigh.Pos, Cloud.matrix, Cloud.camera);

/* 左膝盖 */
FTransform Llelbtrans = getBone(Cloud.Bone + e * 48);
FMatrix boneMatrix11 = TransformToMatrix(Llelbtrans);
Cloud.Left_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix11, c2wMatrix));
Cloud.Left_Knee.ScreenPos = WorldToScreen(Cloud.Left_Knee.Pos, Cloud.matrix, Cloud.camera);

/* 右膝盖 */
FTransform Lrelbtrans = getBone(Cloud.Bone + f * 48);
FMatrix boneMatrix12 = TransformToMatrix(Lrelbtrans);
Cloud.Right_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix12, c2wMatrix));
Cloud.Right_Knee.ScreenPos = WorldToScreen(Cloud.Right_Knee.Pos, Cloud.matrix, Cloud.camera);

/* 左脚腕 */
FTransform Llwtrans = getBone(Cloud.Bone + g * 48);
FMatrix boneMatrix13 = TransformToMatrix(Llwtrans);
Cloud.Left_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix13, c2wMatrix));
Cloud.Left_Ankle.ScreenPos = WorldToScreen(Cloud.Left_Ankle.Pos, Cloud.matrix, Cloud.camera);

/* 右脚腕 */
FTransform Lrwtrans = getBone(Cloud.Bone + h * 48);
FMatrix boneMatrix14 = TransformToMatrix(Lrwtrans);
Cloud.Right_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix14, c2wMatrix));
Cloud.Right_Ankle.ScreenPos = WorldToScreen(Cloud.Right_Ankle.Pos, Cloud.matrix, Cloud.camera);
		




if (DrawIo[20] && ((DrawIo[31] && !Cloud.IsBot) || !DrawIo[31]) && ((DrawIo[32] && Cloud.Health > 0) || !DrawIo[32])) {
strcpy(Aim[AimCount].Name, Cloud.PlayerName);
Aim[AimCount].WodDistance = Cloud.Distance;
Aim[AimCount].AimMovement = Cloud.Predict;
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
AimCount++;
}



//float top, right, left, bottom, top1; 


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



float top, right, left, bottom, top1; 

left  = Cloud.Head.ScreenPos.x - Cloud.w * 0.6;
right = Cloud.Head.ScreenPos.x + Cloud.w * 0.6;

if (!Cloud.Head.Pos.x) {
top1 = Cloud.Pelvis.ScreenPos.y - Cloud.Chest.ScreenPos.y;
} else {
top1 = Cloud.Pelvis.ScreenPos.y - Cloud.Head.ScreenPos.y;
}

top  = Cloud.Pelvis.ScreenPos.y - top1 - Cloud.w / 5;

if (Cloud.Left_Ankle.ScreenPos.y < Cloud.Right_Ankle.ScreenPos.y) {
bottom = Cloud.Right_Ankle.ScreenPos.y + Cloud.w / 10;
} else {
bottom = Cloud.Left_Ankle.ScreenPos.y  + Cloud.w / 10;
}

//方框
if (DrawIo[1]) {
if (Cloud.IsBot) {
Draw->AddRect({left, top}, {right, bottom}, 绘制颜色[2], 0, 0, 绘制粗细[2]); 
Draw->AddRectFilled({left, top}, {right, bottom}, 绘制颜色[4]); 
} else {  
Draw->AddRect({left, top}, {right, bottom}, 绘制颜色[1], 0, 0, 绘制粗细[1]);
Draw->AddRectFilled({left, top}, {right, bottom}, 绘制颜色[3]); 
}
}

// 射线
if (DrawIo[2]) {
float 射线_y;
if (Cloud.IsBot) {
if (draw_style[0] == 0 || draw_style[0] == 1) 射线_y = 73; else if (draw_style[0] == 2) 射线_y = screen_y*0.135f;
Draw->AddLine({screen_x / 2 , 射线_y}, {Cloud.Head.ScreenPos.x, Cloud.Head.ScreenPos.y}, 绘制颜色[6], 绘制粗细[4]);  
} else {
Draw->AddLine({screen_x / 2 , 射线_y}, {Cloud.Head.ScreenPos.x, Cloud.Head.ScreenPos.y}, 绘制颜色[5], 绘制粗细[3]);  
}
}

// 骨骼
if (DrawIo[3]) {
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
}

// 血量&名字
if (DrawIo[6]) {
if (!Cloud.IsBot) {
DrawHealth({Cloud.Head.ScreenPos.x, top }, Cloud.w * 2, Cloud.Health, Cloud.TeamID, Cloud.PlayerName);
} else {
DrawHealth({Cloud.Head.ScreenPos.x, top }, Cloud.w * 2, Cloud.Health, Cloud.TeamID, "私人坤");
}
}

// 手持
//武器id = GetWeapon(Cloud.Weapon);
if (DrawIo[10]) {
string s;
// s += to_string((int)Cloud.dqzd);
// s += "/";
// s += to_string((int)Cloud.zdmax);
auto textSize = ImGui::GetFont()->CalcTextSizeA(25, FLT_MAX, -1, s.c_str(), NULL, NULL); 
ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, { Cloud.Head.ScreenPos.x - (textSize.x / 2), top - 45 - (textSize.y / 2) }, ImColor(255,255,255,255), s.c_str());

float png_y = (draw_style[1] == 2) ? 45 : 0;
// ImGui::GetForegroundDrawList()->AddImage(weapon[武器id/10], {Cloud.Head.ScreenPos.x - 60, top - 80 - png_y}, {Cloud.Head.ScreenPos.x + 60, top - 40 - png_y});
}

// 距离
if (DrawIo[5]) {
string 距离 = to_string((int) Cloud.Distance);
距离 += " m";
auto textSize_距离 = ImGui::GetFont()->CalcTextSizeA((25), FLT_MAX, -1, 距离.c_str(), NULL, NULL);
DrawTf.绘制字体描边(25, Cloud.Pelvis.ScreenPos.x - textSize_距离.x/2, bottom + 15, ImVec4{1.0f, 1.0f, 1.0f, 1.0f},  距离.c_str());
}

// 雷达点
if (DrawIo[7] && Cloud.TotalUp) {
// Vec2 Radar = {(Cloud.MyPos.x - Cloud.Pos.x) / NumIo[16], (Cloud.MyPos.y - Cloud.Pos.y) / NumIo[16]}; // 不旋转的雷达
float radius = Cloud.Distance/NumIo[16];
Vec2 Radar = rotateCoord(Cloud.angle, (Cloud.MyPos.x - Cloud.Pos.x) / (Cloud.Distance / radius), (Cloud.MyPos.y -Cloud.Pos.y) / (Cloud.Distance / radius)); // 旋转的雷达
string ld;
string ai;
// if (NumIo[1] + Radar.x >= NumIo[1] - 100 && NumIo[1] + Radar.x <= NumIo[1] + 100 && NumIo[2] + Radar.y >= NumIo[2] - 100 && NumIo[2] + Radar.y <= NumIo[2] + 100) {

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
// }

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




// {
// string name;
// name += "[";
// name += to_string((int)wz.Distance);
// name += "米]";
// auto textSize = ImGui::CalcTextSize(name.c_str(),0, 20);
// Draw->AddText(NULL, 30,{wz.ScreenPos.x-(textSize.x / 2), wz.ScreenPos.y}, ImColor(0, 258, 0, 255), wz.Name);  
// }



if (DrawIo[14]) {
string name;
string name1;
string name2;
name += "手榴弹[" + to_string((int)wz.Distance) + "米]\n";
name1 += "燃烧瓶[" + to_string((int)wz.Distance) + "米]\n";
name2 += "烟雾弹[" + to_string((int)wz.Distance) + "米]\n";
if (strstr(wz.wuziName, "AttachActor_Ring_BP_C") || strstr(wz.wuziName, "ojGrenade_BP_C")) {
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 0, 0), name.c_str());
Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(255, 0, 0), 12);
} else if (strstr(wz.wuziName, "BP_Grenade_Burn_C") || strstr(wz.wuziName, "ProjBurn_BP_C")) {
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 255, 0), name1.c_str());
Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(255, 0, 0), 12);
} else if (strstr(wz.wuziName, "BP_Grenade_Smoke_C")) {
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(0, 255, 0), name2.c_str());
Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(0, 255, 0), 12);
}


if (strstr(wz.wuziName, "BP_Grenade_Shoulei_C") || strstr(wz.wuziName, "BP_Grenade_Burn_C")) {
if (wz.Distance < 10) {
// 在屏幕中间绘制一个附近有手雷的文本
string guistr = "附近有投掷物";
Draw->AddText(NULL, 70, {screen_x/2 -160, screen_y  -900}, ImColor(255, 0, 0), guistr.c_str());
}
}
}
if (DrawIo[15]) {
string name;
name += wz.wuziName;
auto textSize = ImGui::CalcTextSize(name.c_str(),0, 20);
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(0, 255, 0), name.c_str());
//            }
}
}


if (DrawIo[16]) {
string name;
name += "信号枪[" + to_string((int)wz.Distance) + "米]\n";
if (strstr(wz.wuziName, "BP_Pistol_Flaregun_Wrapper_C")) {
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 0, 0), name.c_str());
Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(255, 0, 0), 12);
}
}

if (DrawIo[18]) {
string name;
name += "盒子[" + to_string((int)wz.Distance) + "米]\n";
if (strstr(wz.wuziName, "_PlayerDeadListWrapper_C") /* || strstr(wz.wuziName, "ckUpListWrapperActor") || strstr(wz.wuziName, "ckUpListWrapperActor") */ ) {
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 255, 255), name.c_str());
//Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(255, 0, 0), 12);
}
}

if (DrawIo[19]) {
string name;
name += "内鬼[" + to_string((int)wz.Distance) + "米]\n";
if (strstr(wz.wuziName, "_PlayerPawn_Impostors_C") /* || strstr(wz.wuziName, "ckUpListWrapperActor") || strstr(wz.wuziName, "ckUpListWrapperActor") */ ) {
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 255, 255), name.c_str());
//Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(255, 0, 0), 12);
}
}

//---------------------------------------------------巡查提醒
{
static float szck;
ImVec4 currentColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
// 设置窗口透明度
ImGui::SetNextWindowBgAlpha(0.4f); // 完全透明
  // 设置窗口位置
ImGui::SetNextWindowPos(ImVec2(10 + 550, 10));
// 创建窗口
if (szck == 1) {
ImGui::SetNextWindowSize(ImVec2(300,100));
} else {
ImGui::SetNextWindowSize(ImVec2(250,100));
}
ImGui::Begin("RecordingTimeWindow", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar);

int file_count = 0;
DIR *dir;
struct dirent *entry;
const char *folder_path = "/data/user/0/com.tencent.tmgp.pubgmhd/files/ano_tmp/custom_cache/";
dir = opendir(folder_path);
if (dir) {
while ((entry = readdir(dir)) != NULL) {
if (entry->d_type == DT_REG) { // 检查是否为常规文件
ImGui::TextColored(currentColor,"提醒已经巡查 低调打完");
szck = 1;
file_count++;    	        
}
}
closedir(dir); // 关闭目录
if (file_count == 0) {
ImGui::TextColored(ImColor(255,255,255,225),"暂未发现巡查信息");
szck = 0;
}
} else {
// 处理无法打开目录的情况
ImGui::TextColored(ImColor(255,255,255,225),"暂未发现巡查信息");
szck = 0;
}
ImGui::End();
}
} //总循环
MaxPlayerCount = AimCount;
Cloud.TotalUp = Cloud.PlayerCount + Cloud.BotCount;