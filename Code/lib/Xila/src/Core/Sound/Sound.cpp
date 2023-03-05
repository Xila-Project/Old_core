///
/// @file Sound.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila sound abstraction layer source file.
/// @version 0.1.0
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Xila_Default_Sound_Volume
    #define Xila_Default_Sound_Volume 255
#endif

#include "Core/Sound/Sound.hpp"
#include "Core/Drive/Drive.hpp"

using namespace Xila_Namespace;

Sound_Type Xila_Namespace::Sound;

Result_Type Sound_Class::Start()
{
    Log_Information("Sound", "Starting sound module...");
    
    this->Set_Volume(Xila_Default_Sound_Volume);

    if (this->Load_Registry() != Result_Type::Success)
    {
        return this->Create_Registry();
    }
    return Result_Type::Success;
}

Result_Type Sound_Class::Stop()
{
    return this->Save_Registry();
}

Result_Type Sound_Class::Create_Registry()
{
    return Result_Type::Success;
}

///
/// @brief A method that load sound registry.
///
/// @return Result_Type
///
Result_Type Sound_Class::Load_Registry()
{
    /*
    File_Type Temporary_File = Drive.Open(Registry("Sound"));
    DynamicJsonDocument Sound_Registry(256);
    if (deserializeJson(Sound_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    if (strcmp("Sound", Sound_Registry["Registry"] | "") != 0)
    {
        return Result_Type::Error;
    }
    Output = Sound_Registry["Output"] | Default_Sound_Output;
    if (Output == Internal_DAC)
    {
        // Audio_Driver.setInternalDAC();
        Output = Internal_DAC;
    }
    else
    {
        // Audio_Driver.setInternalDAC(false);
        Output = External_DAC;
        Clock_Pin = Sound_Registry["Clock Pin"] | Default_I2S_Clock_Pin;
        Word_Select_Pin = Sound_Registry["Word Select Pin"] | Default_I2S_Word_Select_Pin;
        Data_Pin = Sound_Registry["Data Pin"] | Default_I2S_Data_Pin;
        //Audio_Driver.setPinout(Clock_Pin, Word_Select_Pin, Data_Pin);
        Set_Channels(2);
    }
    Set_Volume(Sound_Registry["Volume"] | Default_Sound_Volume);
    */
    return Result_Type::Success;
}

///
/// @brief Save sound registry.
///
/// @return Result_Type
Result_Type Sound_Class::Save_Registry()
{
    /*
    DynamicJsonDocument Sound_Registry(512);
    Sound_Registry["Registry"] = "Sound";
    Sound_Registry["Volume"] = Get_Volume();
    Sound_Registry["Output"] = Output;
    Sound_Registry["Clock Pin"] = Clock_Pin;
    Sound_Registry["Word Select Pin"] = Word_Select_Pin;
    Sound_Registry["Data Pin"] = Data_Pin;
    File_Type Temporary_File = Drive.Open(Registry("Sound"), true);
    if (serializeJson(Sound_Registry, Temporary_File) == 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    */
    return Result_Type::Success;
}

///
/// @brief A weak function that automatically stop sound play when file end.
///
/// @param Informations
void audio_eof_mp3(const char *Informations)
{
    // Sound.Stop();
}

///
/// @brief A method that set volume.
///
/// @param Volume_To_Set Volume level to set (0 - 255).
void Sound_Class::Set_Volume(uint8_t Volume_To_Set)
{
    Volume_To_Set = ((21 * Volume_To_Set) / 255);
    // Audio_Driver.setVolume(Volume_To_Set);
}

///
/// @brief A method that return current volume level.
///
/// @return uint8_t Current volume level (0 - 255)
uint8_t Sound_Class::Get_Volume()
{
    return 0;
    // return ((Audio_Driver.getVolume() * 255) / 21);
}

///
/// @brief A method that play sound from host or file.
///
/// @param File_Path_Or_Host File path or host url to play.
/// @param User Username if the host require authentication.
/// @param Password Password if the host require authentication.
/// @return true if succeed to play file.
/// @return false if failed to play file.
uint8_t Sound_Class::Play(const char *File_Path_Or_Host, const char *User, const char *Password)
{
    /*
    if (File_Path_Or_Host[0] == '\0')
    {
        return false;
    }
    else if (File_Path_Or_Host[0] == '/')
    {
        if (Audio_Driver.connecttoFS(Audio_Drive, File_Path_Or_Host) != true)
        {
            return false;
        }
    }
    else
    {
        if (Audio_Driver.connecttohost(File_Path_Or_Host, User, Password) != true)
        {
            return false;
        }
    }
    */
    return true;
}

///
/// @brief A method that set balance.
///
/// @param Balance Balance level (between -16 and 16).
void Sound_Class::Set_Balance(int8_t Balance)
{
    // Audio_Driver.setBalance(Balance);
}

///
/// @brief A method that return current playing state.
///
/// @return true if audio is playing.
/// @return false if audio is not playing.
uint8_t Sound_Class::Get_State()
{
    return 0;
    // return Audio_Driver.isRunning();
}

///
/// @brief A method that set equalizer.
///
/// @param Gain_Low_Pass Gain low pass.
/// @param Gain_Band_Pass Gain band pass.
/// @param Gain_High_Pass Gain high pass.
void Sound_Class::Set_Tone(int8_t Gain_Low_Pass, int8_t Gain_Band_Pass, int8_t Gain_High_Pass)
{
    // Audio_Driver.setTone(Gain_Low_Pass, Gain_Band_Pass, Gain_High_Pass);
}

///
/// @brief A method that return current time.
///
/// @return uint32_t Current playing time in seconds.
uint32_t Sound_Class::Get_Current_Time()
{
    return 0;
    // return Audio_Driver.getAudioCurrentTime();
}

///
/// @brief A method that set output.
///
/// @param Output Sound_Class::Internal_DAC / External_DAC
void Sound_Class::Set_Output(uint8_t Output)
{
    /*
    if (Output == Internal_DAC)
    {
        Audio_Driver.setInternalDAC(true);
    }
    else
    {
        Audio_Driver.setInternalDAC(false);
    }
    */
}

///
/// @brief A method that return file duration.
///
/// @return uint32_t Total playing time in seconds.
uint32_t Sound_Class::Get_Duration()
{
    return 0;
    /*
    return Audio_Driver.getAudioFileDuration();
    */
}

///
/// @brief A method that return total playing time.
///
/// @return uint32_t Total playing time seconds.
uint32_t Sound_Class::Get_Total_Time()
{
    return 0;
    // return Audio_Driver.getTotalPlayingTime();
}

///
/// @brief A method that set current playing time.
///
/// @param Time Current playing time in seconds.
void Sound_Class::Set_Current_Time(uint16_t Time)
{
    // Audio_Driver.setAudioPlayPosition(Time);
}

///
/// @brief A method that set time offset.
///
/// @param Time Time offset in seconds.
void Sound_Class::Set_Time_Offset(int16_t Time)
{
    // Audio_Driver.setTimeOffset(Time);
}

///
/// @brief A method that generate a tone.
///
/// @param Frequency Frequency of the tone.
/// @param Duration Duration of the tone.
/// @param Pin Output pin of the tone.
void Sound_Class::Tone(uint16_t Frequency, uint32_t Duration, uint8_t Pin)
{

    if (Pin == 0xFF)
    {
        ledcAttachPin(25, Left_Channel);
        ledcAttachPin(26, Right_Channel);
        ledcWriteTone(Left_Channel, Frequency);
        ledcWriteTone(Right_Channel, Frequency);
    }
    else
    {
        ledcAttachPin(Pin, Custom_Channel);
        ledcWriteTone(Custom_Channel, Frequency);
        Custom_Pin = Pin;
    }

    if (Duration != 0)
    {
        Task_Type::Delay_Static(Duration);
        No_Tone();
    }
}

///
/// @brief A method that disable tone on pin.
///
/// @param Pin Pin that disable tone.
void Sound_Class::No_Tone(uint8_t Pin)
{
    if (Pin == 0xFF)
    {
        ledcDetachPin(25);
        ledcDetachPin(26);
    }
    else
    {
        ledcDetachPin(Custom_Pin);
    }
}

///
/// @brief A method that play from file.
///
/// @param File_To_Play File to play instance.
/// @return uint8_t
uint8_t Sound_Class::Play(File_Type &File_To_Play)
{
    /*
    if (!File_To_Play)
    {
        return Failed_To_Open_File;
    }

    Music_File = File_To_Play;

    if (Audio_Driver.connecttoFS(Audio_Drive, File_To_Play.name()) != true)
    {
        return Failed_To_Open_File;
    }
    return Result_Type::Success;
    */
    return 0;
}

///
/// @brief A method that set loop of the current playing file.
///
/// @param Loop true to enable or false to disable loop.
void Sound_Class::Set_Loop(bool Loop)
{

    // Audio_Driver.setFileLoop(Loop);
}

///
/// @brief A method that return file size.
///
/// @return uint32_t File size in bytes.
uint32_t Sound_Class::Get_File_Size()
{
    return 0;
    // return Audio_Driver.getFileSize();
}

///
/// @brief A method that return current file position.
///
/// @return uint32_t File position in bytes.
uint32_t Sound_Class::Get_File_Position()
{
    return 0;
    // return Audio_Driver.getFilePos();
}

///
/// @brief A method that set current file position.
///
/// @param Position File position in bytes.
/// @return true if succeed to set file position.
/// @return false if failed to set file position.
bool Sound_Class::Set_File_Position(uint32_t Position)
{
    return true;
    // return Audio_Driver.setFilePos(Position);
}

///
bool Sound_Class::Set_File_Seek(const float Speed)
{
    return true;
    // return Audio_Driver.audioFileSeek(Speed);
}

///
/// @brief A method that return current sample rate
///
/// @return uint32_t
uint32_t Sound_Class::Get_Sample_Rate()
{
    return 0;
    // return Audio_Driver.getSampleRate();
}

///
/// @brief A method that set bit resolution of current playing file / host.
///
/// @return uint8_t Bit resolution.
uint8_t Sound_Class::Get_Bit_Resolution()
{
    return 0;
    // return Audio_Driver.getBitsPerSample();
}

///
/// @brief A method that return the number of channels.
///
/// @return uint8_t Number of channels (1 for mono, 2 for stereo).
uint8_t Sound_Class::Get_Channels()
{
    return 0;
    // return Audio_Driver.getChannels();
}

///
/// @brief A method that return current bit rate of current playing file.
///
/// @return uint32_t Current playing file bit rate.
uint32_t Sound_Class::Get_Bit_Rate()
{
    return 0;
    // return Audio_Driver.getBitRate();
}

///
/// @brief A method that set number of channels.
///
/// @param Channels 1 for mono and 2 for stereo sound.
void Sound_Class::Set_Channels(uint8_t Channels)
{
    /*
    if (Channels > 1)
    {
        Audio_Driver.forceMono(false);
    }
    else
    {
        Audio_Driver.forceMono(true);
    }
    */
}

///
/// @brief Resume playback.
///
void Sound_Class::Resume()
{
    /* if (!Audio_Driver.isRunning())
     {
         Audio_Driver.pauseResume();
     }
     */
}

///
/// @brief Pause playback.
///
void Sound_Class::Pause()
{
    /*
    if (Audio_Driver.isRunning())
    {
        Audio_Driver.pauseResume();
    }
    */
}

///
/// @brief Stop playback.
///
void Sound_Class::Break()
{
    // Audio_Driver.stopSong();
}

///
/// @brief Mute playback.
///
void Sound_Class::Mute()
{

    // Audio_Driver.setVolume(0);
}

///
/// @brief Set pinout of external DAC.
///
/// @param Bit_Clock_Pin Bit clock pin.
/// @param Frame_Clock_Pin Frame clock pin.
/// @param Data_Out_Pin Data out pin.
/// @param Data_In_Pin Data in pin.
/// @return true if the operation succeed.
/// @return false if the operation failed.
bool Sound_Class::Set_Pinout(uint8_t Bit_Clock_Pin, uint8_t Frame_Clock_Pin, uint8_t Data_Out_Pin, uint8_t Data_In_Pin)
{
    return true;
    // return Audio_Driver.setPinout(Bit_Clock_Pin, Frame_Clock_Pin, Data_Out_Pin, Data_In_Pin);
}

///
/// @brief Audio driver task.
///
void Sound_Class::Task(void *)
{
    /*
    while (1)
    {
        Audio_Driver.loop();
        if (Audio_Driver.isRunning() == false)
        {
            Task_Type::Delay_Static(50);
        }
    }
    */
}