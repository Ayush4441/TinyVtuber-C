#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include "raylib.h"
#include <stddef.h>

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

/**************************************************************************/
/*!
  @brief    Convert float value to a string.
  @param    f               Floating point value to convert.
  @param    S               Buffer large enough to hold result string with nul.
  @param    n               sizeof(S).
  @param    digitsAfterDP   Number of digits to include after the decimal point,
                            can be negative to make digits before the decimal
                            point be 0, e.g. -1 means first digit before is 0.
  @returns                  S.
  @note     If the resulting string is longer than n-1 characters, the remaining
            characters are discarded and not stored in S.
  @note     In many architectures, a float value is a 4-byte value with a 23-bit
            mantissa, which is good for accurately representing 5 to 6
            significant digits.
*/
/**************************************************************************/
char* F2Str(float f, char* S, size_t n, int digitsAfterDP);
#endif