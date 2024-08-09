#ifndef AVATAR_H
#define AVATAR_H

typedef enum
{
    GUI_MODE = 0,
    STREAM_MODE
}Mode;

void Avatar_GUI_Draw();
void Avatar_SwitchGUI(int Mode);

#endif