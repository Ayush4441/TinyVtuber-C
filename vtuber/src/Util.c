#include "Util.h"

#include "raylib.h"

void StartTimer(Timer *timer, double lifetime, bool oneShot)
{
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
    timer->oneShot = oneShot;
}

bool TimerDone(Timer *timer)
{
    if(GetElapsed(timer) >= timer->lifeTime)
    {
        if(!timer->oneShot)
            timer->startTime = GetTime();  //Repeat
        
        return true;
    }

    return false;
}

double GetElapsed(Timer *timer)
{
    return GetTime() - timer->startTime;
}