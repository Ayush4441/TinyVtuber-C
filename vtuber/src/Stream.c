#include "Stream.h"

#include "Vocal.h"
#include "raylib.h"

void OnSpeak();
void OnSilent();

void InitStream()
{

}

void DrawStream()
{
    ClearBackground(GREEN);

    DrawFPS(0, 0);
    DrawRectangle(32, 32, 64, 64, Current_Vocal_State == REACHED_TH ? WHITE : GRAY);

    DrawText(Current_Vocal_State == REACHED_TH ? "Is Speaking" : "Is Silent", 128, 128, 2, BLACK);
}

void OnSpeak(){}
void OnSilent(){}