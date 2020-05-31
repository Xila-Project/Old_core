#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include "Arduino.h"
#include <FS.h>

class Sound_Class
{
private:
    const int opcodeCount = 17;
    const int dacTableStart1 = 2048 - 512;
    const int dacTableStart2 = dacTableStart1 - 512;
    const int totalSampleWords = 2048 - 512 - (opcodeCount + 1); //1518 * 2 = 3036 samples for mono
    const int totalSamples = totalSampleWords * 2;
    const int indexAddress = opcodeCount;
    const int bufferStart = indexAddress + 1;
    
    long currentSample = 0;
    int lastFilledWord = 0;

    const int Index_Adress = opcodeCount;

    uint32_t Sample_Count;
    uint32_t Sample_Rate;

    File File_Music;

    byte Stereo, Byte_Per_Sample;

    uint32_t Size;

    TaskHandle_t Sound_Socket_Handle;
    Sound_Class* Current_Instance_Pointer;    

    int8_t Volume;

    uint8_t Next_Sample();

    friend void Fill_Samples();
    void Fill_Buffer();

    void Get_Informations();

    void Start_ULP();
    void Stop_ULP();

public:
    Sound_Class();
    ~Sound_Class();

    static Sound_Class* Current_Instance_Pointer;

    void Set_Volume(uint8_t Volume_To_Set);
    void Play(File& File_To_Play);
};

void Fill_Samples(void *pvParameters); //method of the class externalized due to the non-support of method in freertos

#endif