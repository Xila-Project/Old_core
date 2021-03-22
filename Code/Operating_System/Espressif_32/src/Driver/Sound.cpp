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

Sound_Class *Sound_Class::Instance_Pointer = NULL;

Sound_Class::Sound_Class()
    : Custom_Pin(0xFF)
{
    if (Instance_Pointer != NULL)
    {
        delete this;
    }
    Instance_Pointer = this;
    Sound_Task_Handle = NULL;
    Audio_Driver.setInternalDAC(true);
    Audio_Driver.setBalance(0);
    Audio_Driver.setVolume(21);
}

Sound_Class::~Sound_Class()
{
    Instance_Pointer = NULL;
}

void Sound_Class::Set_File_System(fs::FS &File_System)
{
    this->File_System = &File_System;
}

void Sound_Class::Set_Volume(uint8_t Volume_To_Set)
{
    Volume_To_Set *= 22;
    Volume_To_Set /= 256;
    Serial.println(Volume_To_Set);
    Audio_Driver.setVolume(Volume_To_Set);
}

uint8_t Sound_Class::Get_Volume()
{
    return (Audio_Driver.getVolume() * 256) / 22;
}

uint8_t Sound_Class::Play(const char *File_Path_Or_Host, const char *User, const char *Password)
{
    if (File_Path_Or_Host[0] == '\0')
    {
        return false;
    }
    else if (File_Path_Or_Host[0] == '/')
    {
        Verbose_Print_Line("Play from sd");
        if (Audio_Driver.connecttoFS(*File_System, File_Path_Or_Host) != true)
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

void Sound_Class::Set_Balance(uint8_t Balance_To_Set)
{
    Audio_Driver.setBalance(Balance_To_Set);
}

uint8_t Sound_Class::Get_State()
{
    return Audio_Driver.isRunning();
}

uint32_t Sound_Class::Get_Current_Time()
{
    return Audio_Driver.getAudioCurrentTime();
}

uint32_t Sound_Class::Get_Total_Time()
{
    return Audio_Driver.getAudioFileDuration();
}

void Sound_Class::Set_Current_Time(uint32_t Time)
{
    Audio_Driver.setFilePos(0);
    Audio_Driver.setTimeOffset(Time);
}

void Sound_Class::Set_Offset_Time(int16_t Time)
{
    Audio_Driver.setTimeOffset(Time);
}

void Sound_Class::Tone(uint16_t const &Frequency, uint32_t const &Duration, uint8_t const &Pin)
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
        vTaskDelay(pdMS_TO_TICKS(Duration));
        No_Tone();
    }
}

void Sound_Class::No_Tone(uint8_t const &Pin)
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

uint8_t Sound_Class::Play(File &File_To_Play)
{
    Serial_Print_Line("Play sound");

    if (!File_To_Play)
    {
        Serial_Print_Line("Cannot open file");
        return Failed_To_Open_File;
    }

    Music_File = File_To_Play;

    if (Audio_Driver.connecttoFS(*File_System, File_To_Play.name()) != true)
    {
        return Failed_To_Open_File;
    }

    if (xTaskCreatePinnedToCore(Sound_Task, "Sound driver", Memory_Chunk(4), NULL, DRIVER_TASK_PRIORITY, &Sound_Task_Handle, SYSTEM_CORE) != pdPASS)
    {

        return Failed_To_Create_Task;
    }

    return Success;
}

uint8_t Sound_Class::Resume()
{
    if (!Audio_Driver.isRunning())
    {
        Audio_Driver.pauseResume();
        if (Sound_Task_Handle != NULL)
        {
            vTaskResume(Sound_Task_Handle);
        }
        
    }
    return true;
}

void Sound_Class::Pause()
{
    if (Audio_Driver.isRunning())
    {
        Audio_Driver.pauseResume();
        if (Sound_Task_Handle != NULL)
        {
            vTaskSuspend(Sound_Task_Handle);
        }
        
    }
}

void Sound_Class::Stop()
{
    Serial_Print_Line("Stop");
    Audio_Driver.stopSong();
    if (Sound_Task_Handle != NULL)
    {
        vTaskDelete(Sound_Task_Handle);
    }
    Sound_Task_Handle = NULL;
}

void Sound_Class::Mute()
{
    Audio_Driver.setVolume(0);
}

void Sound_Class::Sound_Task(void *pvParameters)
{
    (void)pvParameters;
    Instance_Pointer->Sound_Loop();
}

void Sound_Class::Sound_Loop()
{
    while (1)
    {
        Audio_Driver.loop();
    }
}