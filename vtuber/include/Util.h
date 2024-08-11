#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include "raylib.h"

typedef struct 
{
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
    bool oneShot;       // If true then it will not repeat once reached done Finishing it's Lifetime
} Timer;

//  Create Start a new Timer, Assign Time in seconds and if it's will run only once ?
void StartTimer(Timer *timer, double lifetime, bool oneShot);

//  Check if the time has reached it's Lifetime
bool TimerDone(Timer *timer);

//  Get Timer's Elapsed Time
double GetElapsed(Timer *timer);

bool IsVector2InRect(Vector2 point, Rectangle rect);
bool IsVector2InBound(Vector2 point, Vector2 bound, int width, int height);
#endif