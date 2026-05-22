void 连点() {
bool 按下 = false;
double tx = draw_style[20], ty = draw_style[21];
while (1) {
ImGuiIO& iooi = ImGui::GetIO();
if (DrawIo[48] || DrawIo[49]) {
//printf("MouseDown[0]: %d\n", iooi.MouseDown[0]);
if (iooi.MouseDown[0] &&
iooi.MousePos.x <= draw_style[21] + (draw_style[24] * 0.5) &&
iooi.MousePos.y <= screen_y - draw_style[20] + (draw_style[24] * 0.5) &&
iooi.MousePos.x >= draw_style[21] - (draw_style[24] * 0.5) &&
iooi.MousePos.y >= screen_y - draw_style[20] - (draw_style[24] * 0.5)) {
按下 = true;
/*
if (按下) {
printf("\n122\n");
}
*/
while (按下 && iooi.MouseDown[0]) {
usleep(draw_style[25] * 10000);
int random_offset_x = distribution_offset(generator);
int random_offset_y = distribution_offset(generator);
int final_x = draw_style[22] + (random_offset_x * 0.5);
int final_y = draw_style[23] + (random_offset_y * 0.5);
tx = final_x, ty = final_y;
usleep(draw_style[25] * 10000);
tx += 0, ty += 0;
if (!NumIo[10])
Touch_Down(8, (int)tx, (int)ty);
else
Touch_Down(8, screen_y - (int)tx, screen_x - (int)ty);
按下 = false;
Touch_Up(8);
}
按下 = false;
Touch_Up(8);
}
}
}
}