#include "Util.h"

#include <stdlib.h>
#include <stdio.h>

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

bool IsVector2InRect(Vector2 point, Rectangle rect)
{
    return 
    (
        point.x >= rect.x && point.x <= rect.x + rect.width &&
        point.y >= rect.y && point.y <= rect.y + rect.height
    );
}

bool IsVector2InBound(Vector2 point, Vector2 bound, int width, int height)
{
    return 
    (
        point.x >= bound.x && point.x <= bound.x + width &&
        point.y >= bound.y && point.y <= bound.y + height
    );
}

char* F2Str(float f, char* S, size_t n, int digitsAfterDP) 
{
    if (digitsAfterDP == 0)
        snprintf(S, n, "%d", (int) (f + (f < 0 ? -0.5 : 0.5)));

    else if (digitsAfterDP < 0) 
    {
        int i;
        for (i = 0; i < -digitsAfterDP && abs(f) >= 10; i++) f /= 10;
        
        char fmt[10]; // "%d%02d"
        sprintf(fmt, "%%d%%0%dd", i);
        snprintf(S, n, fmt, (int) (f + (f < 0 ? -0.5 : 0.5)), 0);

    }
    else
    {
        int M = (int) f;
        f = abs(f - (float) M);
        
        for (int i = digitsAfterDP; i > 0; i--) f *= 10;
        
        int E = (int) (f + 0.5);
        char fmt[10]; // "%d.%05d"
        sprintf(fmt, "%%d.%%0%dd", digitsAfterDP);
        snprintf(S, n, fmt, M, E);
    }

    return(S);
}