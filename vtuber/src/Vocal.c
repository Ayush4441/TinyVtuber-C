#include "Vocal.h"
#include "MiniAudio\miniaudio.h"
#include "Settings.h"
#include <stdio.h>

#define MINIAUDIO_IMPLEMENTATION

int Current_Vocal_State = DIDNOT_REACHED_TH;

ma_context context;
ma_device_config deviceConfig;
ma_device device;

void Vocal_Callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    const float* capturedData = (const float*)pInput;

    for (ma_uint32 i = 0; i < frameCount; i++) 
    {
        if (capturedData[i] > Vocal_Threshold) 
        {
            Current_Vocal_State = REACHED_TH;
            return;
        }
    }

    Current_Vocal_State = DIDNOT_REACHED_TH;
}

void SetupVocal()
{
    if (ma_context_init(NULL, 0, NULL, &context) != MA_SUCCESS) 
    {
        printf("Failed to initialize context.\n");
        return;
    }

    deviceConfig = ma_device_config_init(ma_device_type_capture);
    deviceConfig.capture.format = ma_format_f32;  // 32-bit float audio format
    deviceConfig.capture.channels = 1;            // Mono audio
    deviceConfig.sampleRate = 44100;              // Sample rate (44.1 kHz)
    deviceConfig.dataCallback = Vocal_Callback;   // Set the callback

    if (ma_device_init(&context, &deviceConfig, &device) != MA_SUCCESS) 
    {
        printf("Failed to initialize capture device.\n");
        ma_context_uninit(&context);
        return;
    }

    if (ma_device_start(&device) != MA_SUCCESS) 
    {
        printf("Failed to start capture device.\n");
        ma_device_uninit(&device);
        ma_context_uninit(&context);
        return;
    }
}

void DeinitVocal()
{
    ma_device_uninit(&device);
    ma_context_uninit(&context);
}
