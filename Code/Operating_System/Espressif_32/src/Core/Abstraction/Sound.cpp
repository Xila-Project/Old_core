/**
 * @file Display.cpp
 * @brief Xila's display driver source file.
 * @authors bitluni - Alix ANNERAUD
 * @copyright MIT License
 * @version 0.1.0
 * @date 21/05/2020
 * @details Xila display driver, used by the core and softwares to display things.
 * @section License
 * 
 * Copyright (c) 2020 Alix ANNERAUD
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
*/

#include "Core/Core.hpp"

#include "Audio.h"

Audio Audio_Driver;

///
/// @brief Construct a new Xila_Class::Sound_Class::Sound_Class object
///
Xila_Class::Sound_Class::Sound_Class()
    : Custom_Pin(0xFF)
{
    Audio_Driver.setInternalDAC(true);
    Audio_Driver.setBalance(0);
    Audio_Driver.setVolume(21);
}

///
/// @brief Destroy the Xila_Class::Sound_Class::Sound_Class object
///
Xila_Class::Sound_Class::~Sound_Class()
{
    Instance_Pointer = NULL;
}

///
/// @brief
///
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Sound_Class::Load_Registry()
{
    File Temporary_File = Xila.Drive.open(Sound_Registry_Path);
    DynamicJsonDocument Sound_Registry(256);
    if (deserializeJson(Sound_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Error;
    }
    Set_Volume(Sound_Registry["Volume"]);
    Temporary_File.close();
    return Success;
}

Xila_Class::Event Xila_Class::Sound_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive.open(Sound_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Sound_Registry(256);
    Sound_Registry["Volume"] = Get_Volume();
    if (serializeJson(Sound_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    return Success;
}

void audio_eof_mp3(const char *Informations)
{
    Xila.Sound.Stop();
}

void Xila_Class::Sound_Class::Set_Volume(uint16_t Volume_To_Set)
{
    Volume_To_Set *= 22;
    Serial.println(Volume_To_Set);
    Volume_To_Set = Volume_To_Set >> 8;
    Serial.println(Volume_To_Set);
    Audio_Driver.setVolume(Volume_To_Set);
}

uint8_t Xila_Class::Sound_Class::Get_Volume()
{
    return (Audio_Driver.getVolume() * 256) / 22;
}

uint8_t Xila_Class::Sound_Class::Play(const char *File_Path_Or_Host, const char *User, const char *Password)
{
    if (File_Path_Or_Host[0] == '\0')
    {
        return false;
    }
    else if (File_Path_Or_Host[0] == '/')
    {
        Verbose_Print_Line("Play from sd");
        if (Audio_Driver.connecttoFS(Xila.Drive, File_Path_Or_Host) != true)
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
    return true;
}

void Xila_Class::Sound_Class::Set_Balance(uint8_t Balance_To_Set)
{
    Audio_Driver.setBalance(Balance_To_Set);
}

uint8_t Xila_Class::Sound_Class::Get_State()
{
    return Audio_Driver.isRunning();
}

/**
 * @brief A function that return the current file playing time.
 *    
 * @return Current file playling time in seconds.
 */
uint32_t Xila_Class::Sound_Class::Get_Current_Time()
{
    return Audio_Driver.getAudioCurrentTime();
}

/**
 * @brief A method that return total playing time.
 * 
 * @return uint32_t Total time in seconds of current playing file.
 */
uint32_t Xila_Class::Sound_Class::Get_Total_Time()
{
    return Audio_Driver.getAudioFileDuration();
}

/**
 * @brief A function that set current time of playing file.
 *
 * @param Time Time to set in millisecond.
 */
void Xila_Class::Sound_Class::Set_Current_Time(uint32_t Time)
{
    Audio_Driver.setFilePos(0);
    Audio_Driver.setTimeOffset(Time);
}

/**
 * @brief A method that set offset time.
 * 
 * @param Time Offset time in second.
 */
void Xila_Class::Sound_Class::Set_Offset_Time(int16_t Time)
{
    Audio_Driver.setTimeOffset(Time);
}

/**
 * @brief Function that tone.
 *
 * @param Frequency Frequency to tone
 * @param Duration Duration to tone (empty or 0 to infinite tone)
 * @param Pin Pin to tone (left empty to play on default output pin)
  *
 * @details Function that tone and block music playing
 */
void Xila_Class::Sound_Class::Tone(uint16_t const &Frequency, uint32_t const &Duration, uint8_t const &Pin)
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
        Xila.Task.Delay(Duration);
        No_Tone();
    }
}

/**
 * @brief 
 * 
 * @param Pin 
 */
void Xila_Class::Sound_Class::No_Tone(uint8_t const &Pin)
{
    if (Pin == 0xFF)
    {
        ledcWrite(Left_Channel, 0);
        ledcWrite(Right_Channel, 0);
        ledcDetachPin(25);
        ledcDetachPin(26);
    }
    else
    {
        ledcWrite(Custom_Channel, 0);
        ledcDetachPin(Custom_Pin);
    }
}

uint8_t Xila_Class::Sound_Class::Play(File &File_To_Play)
{
    Verbose_Print_Line("Play sound");

    if (!File_To_Play)
    {
        Verbose_Print_Line("Cannot open file");
        return Failed_To_Open_File;
    }

    Music_File = File_To_Play;

    if (Audio_Driver.connecttoFS(Xila.Drive, File_To_Play.name()) != true)
    {
        return Failed_To_Open_File;
    }

    return Success;
}

uint8_t Xila_Class::Sound_Class::Resume()
{
    if (!Audio_Driver.isRunning())
    {
        Audio_Driver.pauseResume();
    }
    return true;
}

void Xila_Class::Sound_Class::Pause()
{
    if (Audio_Driver.isRunning())
    {
        Audio_Driver.pauseResume();
    }
}

///
/// @brief
///
void Xila_Class::Sound_Class::Stop()
{
    Verbose_Print_Line("Stop");
    Audio_Driver.stopSong();
}

void Xila_Class::Sound_Class::Mute()
{
    Audio_Driver.setVolume(0);
}

void Xila_Class::Sound_Class::Task(void*)
{
    while (1)
    {
        Audio_Driver.loop();
        Xila.Task.Delay(10);
    }
}
