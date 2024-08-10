#include "Window.h"
#include "Config.h"
#include "Avatar.h"

#include "raylib.h"

bool ShouldShutdown = false;

void WindowInit()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    Avatar_Init();
}

void ShutDown()
{
    ShouldShutdown = true;
}

bool WindowUpdate()
{
    BeginDrawing();

    Avatar_GUI_Draw();

    EndDrawing();

    return !(WindowShouldClose() || ShouldShutdown);
}

void WindowDeinit()
{
    Avatar_Deinit();

    CloseWindow();
}
