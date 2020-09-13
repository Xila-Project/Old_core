#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include "Arduino.h"
#include <FS.h>

#define INSTANCE_POINTER Sound_Class::Instance_Pointer


class Sound_Class
{
protected:
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

    File Music_File;

    byte Stereo, Byte_Per_Sample;

    uint32_t Size;

    TaskHandle_t Sound_Socket_Handle;
    static Sound_Class* Instance_Pointer;    

    int8_t Volume;

    uint8_t Next_Sample();

    friend void Fill_Samples();
    void Fill_Buffer();

    void Get_Metadata();

    void Start_ULP();
    void Stop_ULP();
    
    friend void Sound_Task(void*);

public:
    Sound_Class();
    ~Sound_Class();


    void Set_Volume(uint8_t);
    uint8_t Get_Volume();
    void Play(File&);
    void Mute();
    void Tone(uint16_t const&, uint32_t const&);

};



void Sound_Task(void*); //method of the class externalized due to the non-support of method in freertos

#endif