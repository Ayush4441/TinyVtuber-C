#include "Window.h"
#include "Settings.h"
#include "Avatar.h"

#include "raylib.h"

bool ShouldShutdown = false, IsFocused, hasChangedFocus = false;

void CheckForFocus();

void WindowInit()
{
    SetTraceLogLevel(LOG_ALL);

    // LoadSettings();  TODO, FIX LOADING SETTINGS

    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);

    InitWindow(Window_Width, Window_Height, WindowTitle);

    SetWindowState(FLAG_WINDOW_TOPMOST);

    SetWindowFocused();

    SetTargetFPS(TargetFPS);

    Avatar_Init();
}

void ShutDown()
{
    ShouldShutdown = true;
}

bool WindowUpdate()
{
        CheckForFocus();

        Avatar_Update();

    BeginDrawing();

        Avatar_Draw();

    EndDrawing();

    return !(WindowShouldClose() || ShouldShutdown);
}

void WindowDeinit()
{
    Window_Deactive();

    Avatar_Deinit();

    CloseWindow();

    // SaveSettings();  TODO, FIX SAVING SETTINGS
}

void Window_Active()
{
    ClearWindowState(FLAG_WINDOW_UNDECORATED);
    ClearWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
}

void Window_Deactive()
{
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);   
}

void CheckForFocus()
{
    if(IsWindowFocused())
        Window_Active();
    else
        Window_Deactive();
}