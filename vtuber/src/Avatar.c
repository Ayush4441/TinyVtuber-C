#include "Avatar.h"
#include "raylib.h"
#include "raygui/raygui.h"
#include "Vocal.h"
#include "Util.h"
#include "Window.h"
#include "raymath.h"
#include "Settings.h"

#define SCREEN_CENTER (Vector2) {GetScreenWidth()/2, GetScreenHeight()/2}

Avatar_State Default_NoBlink, Default_Blink, Speak_NoBlink, Speak_Blink;
Avatar_State CurrentState;

Timer Blink_Timer, BlinkTimeOut_Timer;

Vector2 Avatar_OriginalPos;

bool ShouldOpenEyes = true;

Vector2 MousePos = { -100.0f, -100.0f }, dragOffset;

Font DefaultFont;

void MoveAvatar();

void Avatar_Init()
{
    DefaultFont = LoadFont("Assets/Fonts/monogram.ttf");
    GuiSetFont(DefaultFont);

    SetupVocal();

    StartTimer(&Blink_Timer, 2.5, false);

    Default_NoBlink.texture = LoadTexture("Assets/Image/Character/Default_NoBlink.png");
    Default_Blink.texture = LoadTexture("Assets/Image/Character/Default_Blink.png");

    Speak_NoBlink.texture = LoadTexture("Assets/Image/Character/Speak_NoBlink.png");
    Speak_Blink.texture = LoadTexture("Assets/Image/Character/Speak_Blink.png");

    Default_NoBlink.Offset = (Vector2){0, 0};
    Default_Blink.Offset = (Vector2){0, 0};
    Speak_NoBlink.Offset = (Vector2){0, -5};
    Speak_Blink.Offset = (Vector2){0, -5};

    SetWindowMinSize(Avatar_Size.x, Avatar_Size.y);

    if(SmallWindow)
        SetWindowSize(Avatar_Size.x, Avatar_Size.y);

    Avatar_OriginalPos = Vector2Subtract(SCREEN_CENTER, Avatar_Center);
}

void Avatar_Draw()
{
    ClearBackground(IsFocused ? BG_Color_OnFocus : BG_Color_OnUnFocus);

    if(TimerDone(&Blink_Timer))
    {
        StartTimer(&BlinkTimeOut_Timer, 0.5, true);
        ShouldOpenEyes = false;
    }

    if (TimerDone(&BlinkTimeOut_Timer))
        ShouldOpenEyes = true;
    
    if(Current_Vocal_State == REACHED_TH)
        CurrentState = ShouldOpenEyes ? Speak_NoBlink : Speak_Blink;
    else
        CurrentState = ShouldOpenEyes ? Default_NoBlink : Default_Blink;
    
    DrawTextureEx(CurrentState.texture, Vector2Add(Avatar_OriginalPos, CurrentState.Offset), 0, Avatar_Scale, WHITE);
}

void Avatar_Update()
{
    MoveAvatar();
}

void MoveAvatar()
{
    MousePos = GetMousePosition();

    if(IsVector2InBound(MousePos, Avatar_OriginalPos, Avatar_Size.x, Avatar_Size.y))
    {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);

        if(IsGestureDetected(GESTURE_HOLD))
            SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);

        if(IsGestureDetected(GESTURE_DRAG))
        {
            Vector2 dragOffset = GetGestureDragVector();

            dragOffset = Vector2Scale(dragOffset, 3.0f);

            Avatar_OriginalPos = Vector2Add(Avatar_OriginalPos, dragOffset);
        }
    }
    else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void Avatar_Deinit()
{
    DeinitVocal();

    UnloadTexture(Default_NoBlink.texture);
    UnloadTexture(Default_Blink.texture);
    UnloadTexture(Speak_NoBlink.texture);
    UnloadTexture(Speak_Blink.texture);
}
