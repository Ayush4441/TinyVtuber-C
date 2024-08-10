#include "Stream.h"
#include "Avatar.h"
#include "Vocal.h"
#include "Util.h"
#include "raylib.h"
#include "raymath.h"

#define SCREEN_CENTER (Vector2) {GetScreenWidth()/2, GetScreenHeight()/2}

Avatar_State Default_NoBlink, Default_Blink, Speak_NoBlink, Speak_Blink;
Avatar_State CurrentState;

Timer Blink_Timer, BlinkTimeOut_Timer;

float Avatar_Scale = 0.5;
Vector2 Avatar_Size = {500, 500}, Avatar_Center = {125, 125};
Vector2 Avatar_OriginalPos;

bool ShouldOpenEyes = true; // Indicates if the eyes should be open

void InitStream() 
{
    // Start the blink timer
    StartTimer(&Blink_Timer, 2.5, false);

    Avatar_OriginalPos = Vector2Subtract(SCREEN_CENTER, Avatar_Center);

    Default_NoBlink.texture = LoadTexture("Assets/Image/Character/DefaultClosed.png");
    Default_Blink.texture = LoadTexture("Assets/Image/Character/DefaultBlink.png");

    Speak_NoBlink.texture = LoadTexture("Assets/Image/Character/DefaultOpenMouth.png");
    Speak_Blink.texture = LoadTexture("Assets/Image/Character/DefaultOpenBlink.png");

    Default_NoBlink.Offset = (Vector2){0, 0};
    Default_Blink.Offset = (Vector2){0, 0};
    Speak_NoBlink.Offset = (Vector2){0, -5};
    Speak_Blink.Offset = (Vector2){0, -5};
}

void DrawStream()
{
    ClearBackground(GREEN);

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

void DeinitStream()
{
    UnloadTexture(Default_NoBlink.texture);
    UnloadTexture(Default_Blink.texture);
    UnloadTexture(Speak_NoBlink.texture);
    UnloadTexture(Speak_Blink.texture);
}

void OnSpeak(){}
void OnSilent(){}
