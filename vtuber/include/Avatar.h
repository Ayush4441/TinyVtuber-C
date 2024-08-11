#ifndef AVATAR_H
#define AVATAR_H

#include "raylib.h"

typedef struct
{
    Texture texture;
    Vector2 Offset;
} Avatar_State;

void Avatar_Init();
void Avatar_Draw();
void Avatar_Update();
void Avatar_Deinit();

#endif