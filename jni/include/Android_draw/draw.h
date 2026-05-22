//
// Created by 泓清 on 2022/8/26.
//
#ifndef NATIVESURFACE_DRAW_H
#define NATIVESURFACE_DRAW_H

#include <timer.h>
#include <sys/stat.h>
#include "Struct.h"
#include "native_surface/ANativeWindowCreator.h"
#include <imgui_internal.h>
#include "imgui_impl_android.h"
#include "imgui_impl_vulkan.h"
#include "Android_vulkan/VulkanGraphics.h"
// namespace

using namespace std;
using namespace std::chrono_literals;
struct Screen {
    float ScreenX;
    float ScreenY;
};


extern VulkanGraphics VK;
extern ANativeWindow *native_window;


extern int Orientation;

extern int screen_x, screen_y;
extern android::ANativeWindowCreator::DisplayInfo displayInfo;


extern int init_vulkan(int _screen_x, int _screen_y, bool flp, bool log = false);
void screen_config();
void ImGui_init();
void shutdown();
void OffScreen(Vec2 Obj, float camear, ImColor color, float Radius);
void VK_Begin();
void VK_End();


#endif //NATIVESURFACE_DRAW_H
