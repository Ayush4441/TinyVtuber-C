#ifndef AVATAR_H
#define AVATAR_H

#include "raylib.h"

typedef enum
{
    GUI_MODE = 0,
    STREAM_MODE
}Mode;

typedef struct
{
    Texture texture;
    Vector2 Offset;
} Avatar_State;

void Avatar_Init();
void Avatar_GUI_Draw();
void Avatar_SwitchToMode(int Mode);
void Avatar_Deinit();

#endif