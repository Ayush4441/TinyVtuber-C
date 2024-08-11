#include "Settings.h"

uint16_t Window_Width = 1240, Window_Height = 786;
char* WindowTitle = "TINY VTUBER";
uint16_t TargetFPS = 60;

float Vocal_Threshold = 0.5;
Color BG_Color_OnFocus = LIGHTGRAY, BG_Color_OnUnFocus = BLANK;

Vector2 Avatar_Size = {500, 500}, Avatar_Center = {125, 125};

bool SmallWindow = true;