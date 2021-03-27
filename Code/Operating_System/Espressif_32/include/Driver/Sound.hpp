#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include "Arduino.h"
#include "Configuration.hpp"

#define SD_IMPL 0
#include "Audio.h"

#include <FS.h>



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

    const static uint8_t Left_Channel = 0;
    const static uint8_t Right_Channel = 1;
    const static uint8_t Custom_Channel = 2;

    uint8_t Custom_Pin;

    Audio Audio_Driver;

    // Metadata
  
    File Music_File;
    
    fs::FS* File_System;

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


    static Sound_Class *Instance_Pointer;



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

    void Set_Output_Channel(uint8_t Number_Output_Channel);

    void Set_Volume(uint16_t); // volume between 0 and 255
    uint8_t Get_Volume();

    void Set_File_System(fs::FS& File_System);

    void Set_Balance(uint8_t);
 
    uint8_t Play(File& File_To_Play);
    uint8_t Play(const char* File_Path_Or_Host, const char* User = "", const char* Password = "");

    uint8_t Resume();
    void Pause();
    void Mute();
    void Stop();

    uint8_t Get_State();

    /**
     * @brief A function that set current time of playing file.
     * @param Time Time to set in millisecond.
     */
    void Set_Current_Time(uint32_t Time);

    /**
     * @brief A function that return the current file playing time.
     * @return Current file playling time in millisecond.
     */
    uint32_t Get_Current_Time();

    /**
     * @brief A function that return the current file playing total time.
     * @return Current file playing total time in millisecond.
     */
    uint32_t Get_Total_Time();

    void Set_Offset_Time(int16_t Time);




    /**
     * @brief Function that tone.
     * @param Frequency Frequency to tone
     * @param Duration Duration to tone (empty or 0 to infinite tone)
     * @param Pin Pin to tone (left empty to play on default output pin)
     * @details Function that tone and block music playing
    */
    void Tone(uint16_t const &Frequency, uint32_t const &Duration = 0, uint8_t const &Pin = 0xFF);

    void No_Tone(uint8_t const &Pin = 0xFF); // no tone (0xFF default pins)

    void Loop();

    friend void audio_eof_mp3(const char*);
};

void audio_eof_mp3(const char* Informations)
{
    Sound_Class::Instance_Pointer->Stop();
}

#endif