/*///
/// @file Sound.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 21-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Sound_Hpp_Included
#define Sound_Hpp_Included

#include "../Module.hpp"

//==============================================================================//

///
/// @brief Sound class API
///
class Sound_Class : public Module_Class
{
{
public:
    Sound_Class();
    ~Sound_Class();

    void Set_Channels(uint8_t Channels);

    void Set_Volume(uint8_t Volume);
    uint8_t Get_Volume();

    uint8_t Play(File &File_To_Play);
    uint8_t Play(const char *File_Path_Or_Host, const char *User = "", const char *Password = "");

    void Set_Loop(bool Loop);

    uint32_t Get_File_Size();
    uint32_t Get_File_Position();
    bool Set_File_Position(uint32_t Position);
    bool Set_File_Seek(const float Speed);

    uint32_t Get_Sample_Rate();
    uint8_t Get_Bit_Resolution();
    uint8_t Get_Channels();
    uint32_t Get_Bit_Rate();

    void Set_Tone(int8_t Gain_Low_Pass, int8_t Gain_Band_Pass, int8_t Gain_High_Pass);

    void Set_Output(uint8_t Output);

    ///
    /// @brief Output DAC.
    ///
    enum : uint8_t
    {
        Internal_DAC = 0, ///< Internal DAC.
        External_DAC      ///< External DAC.
    };

    void Resume();
    void Pause();
    void Mute();
    void Stop();

    void Set_Current_Time(uint16_t Time);
    uint32_t Get_Current_Time();
    uint32_t Get_Duration();

    bool Set_Pinout(uint8_t Bit_Clock_Pin, uint8_t Frame_Clock_Pin, uint8_t Data_Out_Pin, uint8_t Data_In_Pin = (-1));
    void Set_Balance(int8_t Balance = 0);

    uint32_t Get_Total_Time();

    void Set_Time_Offset(int16_t Time);
    uint8_t Get_State();

    void Tone(uint16_t Frequency, uint32_t Duration = 0, uint8_t Pin = 0xFF);
    void No_Tone(uint8_t Pin = 0xFF); // no tone (0xFF default pins)

    static void Task(void *);

    ///
    /// @brief Sound class event type.
    ///
    enum Event
    {
        Failed_To_Get_RTC_Period,   ///< Failed to get ULP processor frequency.
        Failed_To_Open_File,        ///< Failed to open file.
        Failed_To_Get_Metadata,     ///< Failed to read file metadata (corrupted).
        Failed_To_Load_ULP_Program, ///< Failed to load program into ULP.
        Failed_To_Create_Task,      ///< Failed to create sound task.
        Not_RIFF_Compliant,         ///< Invalid metadata (RIFF).
        Not_WAVE_Compliant,         ///< Invalid metadata (WAVE).
        Incompatible_Block_ID,      ///< Incompatible bloc ID.
        Not_A_PCM_File,             ///< Failed to read a non PCM file.
        Unsupported_Bit_Depth,      ///< Unsupported bit depth.
        Unsupported_Sampling_Rate,  ///< Unsupported sampling rate.
        Unsupported_Channel_Number, ///< Unsupported channel number.
    };

    ///
    /// @brief Playing state.
    ///
    enum State
    {
        Stopped, ///< Stopped (no file loaded, no task running)
        Playing, ///< Currently playing.
        Paused   ///< Paused play.
    };

    friend void audio_eof_mp3(const char *);

    // -- Friendship
    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

    ///
    /// @brief Channel enumeration.
    ///
    enum Channels
    {
        Left_Channel = 0,  ///< Left channel only.
        Right_Channel = 1, ///< Right channel only.
        Custom_Channel = 2 ///< Custom channel.
    };

protected:
    // -- Attributes -- //

    ///
    /// @brief Sound task handle.
    ///
    Xila_Class::Task_Handle Task_Handle;

    ///
    /// @brief Custom pin to tone.
    ///
    uint8_t Custom_Pin;

    ///
    /// @brief Music file.
    ///
    File Music_File;

    ///
    /// @brief Custom data pin.
    ///
    uint8_t Data_Pin;

    ///
    /// @brief Custom word select pin.
    ///
    uint8_t Word_Select_Pin;

    ///
    /// @brief Custom clock pin.
    ///
    uint8_t Clock_Pin;

    uint8_t Output;

    // -- Methods -- //
    Result_Type Save_Registry();
    Result_Type Load_Registry();

    void Begin();

};

#endif*/