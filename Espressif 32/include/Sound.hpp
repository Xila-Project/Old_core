#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include "Arduino.h"
#include "Configuration.hpp"

#include <FS.h>

#include <esp32/ulp.h>
#include <driver/rtc_io.h>
#include <driver/dac.h>
#include <soc/rtc.h>
#include <math.h>

class Sound_Class
{
protected:
    const int opcodeCount = 17;
    const int dacTableStart1 = 2048 - 512;
    const int dacTableStart2 = dacTableStart1 - 512;
    int totalSampleWords; //1518 * 2 = 3036 samples for mono
    int totalSamples;
    const int Index_Adress = opcodeCount;
    const int bufferStart = Index_Adress + 1;

    const ulp_insn_t Stop_Program[1] = {I_HALT()};

    uint32_t Sample_Frequency;

    uint32_t Byte_Per_Second;
    uint8_t Byte_Per_Block;
    uint8_t Bits_Per_Sample;

    uint32_t rtc_8md256_period;

    File Music_File;
    uint8_t *Buffer_To_Play;
    uint32_t Buffer_Size;

    // Metadata
    uint32_t File_Size;
    uint8_t Channel_Number;

    byte Stereo, Byte_Per_Sample;

    uint32_t Size;

    TaskHandle_t Sound_Task_Handle;
    static Sound_Class *Instance_Pointer;

    int8_t Volume;

    uint8_t Next_Sample();

    void Fill_Buffer();

    uint8_t Get_Metadata();

    uint8_t Start_ULP();
    void Stop_ULP();

    static void Sound_Task(void *);

public:
    Sound_Class();
    ~Sound_Class();

    void Set_Volume(uint8_t);
    uint8_t Get_Volume();
    uint8_t Play(File &File_To_Play);
    uint8_t Play(uint8_t *Samples, const uint32_t &Buffer_Size, const uint32_t &Sample_Frequency = 44100);
    uint8_t Play();
    void Pause();
    void Seek(uint32_t Time);

    void Mute();
    void Stop();
    void Tone(uint16_t const &, uint32_t const &);
};

#endif