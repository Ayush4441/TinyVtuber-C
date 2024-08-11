#include "Util.h"

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