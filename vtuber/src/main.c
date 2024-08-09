#include "Window.h"

int main()
{
    WindowInit();

    while (WindowUpdate());
    
    WindowDeinit();

    return 0;
}