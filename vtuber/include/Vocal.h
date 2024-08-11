#ifndef VOCAL_H
#define VOCAL_H

typedef enum
{
    REACHED_TH = 0,
    DIDNOT_REACHED_TH = -1
} VOCAL_STATE;

extern int Current_Vocal_State;

void SetupVocal();
void UpdateVocal();
void DeinitVocal();

#endif