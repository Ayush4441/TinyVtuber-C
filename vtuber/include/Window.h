#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>

//Init Window
void WindowInit();

//Call this function if you want to close
void ShutDown();

//Update the Window (Where the draw calls takes place), return true if running else false.
bool WindowUpdate();

//Deinit Window
void WindowDeinit();

#endif