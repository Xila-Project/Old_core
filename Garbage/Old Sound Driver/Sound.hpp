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

#define LEFT_CHANNEL 0
#define RIGHT_CHANNEL 1
#define CUSTOM_CHANNEL 2

#if DEBUG_MODE == 1
#define Serial_Print(x) Serial.print(F(x))
#define Serial_Print_Line(x) Serial.println(F(x))
#else
#define Serial_Print(x)
#define Serial_Print_Line(x)
#endif

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

    uint32_t Data_Size;

    uint32_t Start_Time; // start time in millis
    uint32_t Pause_Time; // Pause time in millis
    uint32_t Total_Time;

    File Music_File;
    uint8_t *Buffer_To_Play; // pointer to the buffer to play
    uint32_t Buffer_Size;




    // Metadata
    uint32_t File_Size;
    uint8_t Channel_Number;

    byte Stereo, Byte_Per_Sample;

    uint8_t Custom_Pin;

    uint32_t Size;

    uint8_t State;


    enum State
    {
        Stopped,
        Playing,
        Paused
    };

    // 0 : stopped
    // 1 : playing
    // 2 : paused
    // 3 : tone

    uint8_t Mode;

    // 0 : SD file mode
    // 1 : Buffer mode
    // 2 : Tone

    TaskHandle_t Sound_Task_Handle;
    static Sound_Class *Instance_Pointer;

    uint16_t Volume;

    uint8_t Next_Sample();

    void Fill_Buffer();

    uint8_t Get_Metadata();

    uint8_t Start_ULP();
    void Stop_ULP();

    static void Sound_Task(void *);

public:
        enum Event
    {
        Success = 1,
        Failed_To_Get_RTC_Period,
        Failed_To_Open_File,
        Failed_To_Get_Metadata,
        Failed_To_Load_ULP_Program,
        Failed_To_Create_Task,
        Not_RIFF_Compliant,
        Not_WAVE_Compliant,
        Incompatible_Block_ID,
        Not_A_PCM_File,
        Unsupported_Bit_Depth,
        Unsupported_Sampling_Rate,
        Unsupported_Channel_Number,
    };


    Sound_Class();
    ~Sound_Class();

    void Set_Volume(uint8_t);
    uint8_t Get_Volume();
    uint8_t Play(File &File_To_Play);
    uint8_t Play(uint8_t *Samples, const uint32_t &Buffer_Size, const uint32_t &Sample_Frequency = 44100);
    uint8_t Resume();
    void Pause();

    uint8_t Get_State();

    /**
     * @brief A function that set current time of playing file.
     * @param Time Time to set in millisecond.
     */
    void Set_Time(uint32_t Time);

    /**
     * @brief A function that return the current file playing time.
     * @return Current file playling time in millisecond.
     */
    uint32_t Get_Time();

    /**
     * @brief A function that return the current file playing total time.
     * @return Current file playing total time in millisecond.
     */
    uint32_t Get_Total_Time();

    void Mute();
    void Stop();

    /**
     * @brief Function that tone.
     * @param Frequency Frequency to tone
     * @param Duration Duration to tone (empty or 0 to infinite tone)
     * @param Pin Pin to tone (left empty to play on default output pin)
     * @details Function that tone and block music playing
    */
    void Tone(uint16_t const &Frequency, uint32_t const &Duration = 0, uint8_t const &Pin = 0xFF);

    void No_Tone(uint8_t const &Pin = 0xFF); // no tone (0xFF default pins)
};

#endif