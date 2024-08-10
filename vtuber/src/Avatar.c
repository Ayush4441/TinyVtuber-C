#include "Avatar.h"
#include "raylib.h"

#include "Vocal.h"
#include "Stream.h"

int CurrentMode = STREAM_MODE;

void Avatar_Init()
{
    SetupVocal();
}

void Avatar_GUI_Draw()
{
    switch (CurrentMode)
    {
        case STREAM_MODE:
            DrawStream();
            break;
    
        default:
            return;
    }
}

void Avatar_SwitchToMode(int Mode)
{
    //
}

void Avatar_Deinit()
{
    DeinitVocal();
}