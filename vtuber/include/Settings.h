#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdint.h>
#include "raylib.h"

extern uint16_t Window_Width, Window_Height;
extern char* WindowTitle;
extern uint16_t TargetFPS;

extern float Vocal_Threshold;
extern Color BG_Color_OnFocus, BG_Color_OnUnFocus;

extern Vector2 Avatar_Size, Avatar_Center;

extern bool SmallWindow;

#endif