#include "Settings.h"
#include "rini/rini.h"
#include "extras-c/app_dir.h"
#include "extras-c/resource_dir.h"
#include "Window.h"

#include "Util.h"

#define RINI_IMPLEMENTATION

uint16_t Window_Width = 1240, Window_Height = 786;
char* WindowTitle = "TINY VTUBER";
uint16_t TargetFPS = 60;

float Vocal_Threshold = 0.3;
Color BG_Color_OnFocus = LIGHTGRAY, BG_Color_OnUnFocus = BLANK;

Vector2 Avatar_Size = {500, 500}, Avatar_Center = {125, 125};
float Avatar_Scale = 0.5;

bool SmallWindow = true;

rini_config config;
char string[32];

void SaveSettings()
{
    if(&config == NULL)
        config = rini_load_config("config.ini");
    
    rini_set_config_value(&config, "Window_Width", Window_Width, "The Width of the Window.");
    rini_set_config_value(&config, "Window_Height", Window_Height, "The Height of the Window.");
    rini_set_config_value_text(&config, "WindowTitle", WindowTitle, "The Title of the Screen.");

    rini_set_config_value(&config, "TargetFPS", TargetFPS, "Set the Target FPS you want.");

    rini_set_config_value_text(&config, "Vocal_Threshold", F2Str(Vocal_Threshold, string, 34, 2), "The Threshold for your Audio Input.");
    string[0] = '\0';
    
    rini_set_config_value(&config, "BG_Color_OnFocus", ColorToInt(BG_Color_OnFocus), "Background Color When The Window is in focus.");
    rini_set_config_value(&config, "BG_Color_OnUnFocus", ColorToInt(BG_Color_OnUnFocus), "Background Color When The Window is not in focus.");
    
    rini_set_config_value_text(&config, "Avatar_Size.x", F2Str(Avatar_Size.x, string, 32, 2), "The Width of Avatar Character.");
    string[0] = '\0';
    rini_set_config_value_text(&config, "Avatar_Size.y", F2Str(Avatar_Size.y, string, 32, 2), "The Height of Avatar Character.");
    string[0] = '\0';

    rini_set_config_value_text(&config, "Avatar_Center.x", F2Str(Avatar_Center.x, string, 32, 2), "The X for your Avatar's Center.");
    string[0] = '\0';
    rini_set_config_value_text(&config, "Avatar_Center.y", F2Str(Avatar_Center.y, string, 32, 2), "The Y for your Avatar's Center.");
    string[0] = '\0';

    rini_set_config_value_text(&config, "Avatar_Scale", F2Str(Avatar_Scale, string, 32, 4), "The Scale of your Avatar Character");
    string[0] = '\0';

    rini_set_config_value(&config, "SmallWindow", SmallWindow, "Is your Window Size is same as your Character Size?");

    const char *ini_header = "#\n"
       "# Config file to configure your TinyVtuber-C"
       "#\n";

    rini_save_config(config, "config.ini", ini_header);

    rini_unload_config(&config);
}

void LoadSettings()
{
    // if(!SearchAndSetResourceDir("Assets"))
    // {
    //     TraceLog(LOG_ERROR, "Not Able Find Assets Dir.");
    //     ShutDown();
    // }

    config = rini_load_config("config.ini");
    
    if(&config == NULL)
    {
        TraceLog(LOG_INFO, "No config.ini found, creating a new one");
        SaveSettings();
        return;
    }

    Window_Width    =   rini_get_config_value(config, "Window_Width");
    Window_Height   =   rini_get_config_value(config, "Window_Height");
    WindowTitle     =   (char*) rini_get_config_value_text(config, "WindowTitle");
    TargetFPS       =   rini_get_config_value(config, "TargetFPS");

    Vocal_Threshold     =   TextToFloat(rini_get_config_value_text(config, "Vocal_Threshold"));
    BG_Color_OnFocus    =   GetColor(rini_get_config_value(config, "BG_Color_OnFocus"));
    BG_Color_OnUnFocus  =   GetColor(rini_get_config_value(config, "BG_Color_OnUnFocus"));

    Avatar_Size.x       =   TextToFloat(rini_get_config_value_text(config, "Avatar_Size.x"));
    Avatar_Size.y       =   TextToFloat(rini_get_config_value_text(config, "Avatar_Size.y"));
    Avatar_Center.x     =   TextToFloat(rini_get_config_value_text(config, "Avatar_Center.x"));
    Avatar_Center.y     =   TextToFloat(rini_get_config_value_text(config, "Avatar_Center.y"));
    Avatar_Scale        =   TextToFloat(rini_get_config_value_text(config, "Avatar_Scale"));

    SmallWindow    =   rini_get_config_value(config, "SmallWindow");

    rini_unload_config(&config);
}