#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>

extern bool IsFocused;

//Init Window
void WindowInit();

//Call this function if you want to close
void ShutDown();

//Update the Window (Where the draw calls takes place), return true if running else false.
bool WindowUpdate();

//Deinit Window
void WindowDeinit();

void Window_Active();

void Window_Deactive();

#endif