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

#include "Driver/Sound.hpp"

Sound_Class *Sound_Class::Instance_Pointer = NULL;

Sound_Class::Sound_Class()
    : Sample_Frequency(44100),
      rtc_8md256_period(0),
      Volume(0)
{
    if (Instance_Pointer != NULL)
    {
        delete this;
    }

    Instance_Pointer = this;
}

Sound_Class::~Sound_Class()
{
    Instance_Pointer = NULL;
}

void Sound_Class::Set_Volume(uint8_t Volume_To_Set)
{
    Volume = Volume_To_Set;
}

uint8_t Sound_Class::Get_Volume()
{
    return Volume;
}

uint8_t Sound_Class::Get_State()
{
    return State;
}

uint8_t Sound_Class::Get_Metadata()
{
    char Temporary_Char_Array_1[] = "RIFF";
    char Temporary_Char_Array_2[5];

    // RIFF constant : 4 bytes
    Music_File.seek(0);
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    if (memcmp(Temporary_Char_Array_1, Temporary_Char_Array_2, 4) != 0)
    {
        Serial.println(F("Not RIFF Compliant"));
        return 0;
    }

    // File size : 4 bytes
    Music_File.seek(0x04);
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    File_Size = (uint32_t)Temporary_Char_Array_2[0] | (uint32_t)Temporary_Char_Array_2[1] << 8 | (uint32_t)Temporary_Char_Array_2[2] << 16 | (uint32_t)Temporary_Char_Array_2[3] << 24;

    // Wave constant: 4 bytes
    Music_File.seek(0x08);
    strcpy(Temporary_Char_Array_1, "WAVE");
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    if (memcmp(Temporary_Char_Array_1, Temporary_Char_Array_2, 4) != 0)
    {
        Serial.println(F("Not WAVE compliant"));
        return 0;
    }

    // Format descriptor : 4 bytes
    Music_File.seek(0x0C);
    strcpy(Temporary_Char_Array_1, "fmt");
    Temporary_Char_Array_1[3] = 0x20;
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    if (memcmp(Temporary_Char_Array_1, Temporary_Char_Array_2, 4) != 0)
    {
        Serial.println(F("Unrecognized format block ID"));
        return 0;
    }

    // Block size : 4 bytes
    /*Music_File.seek(0x10);
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    Block_Size = (uint32_t)Temporary_Char_Array_2[0] | (uint32_t)Temporary_Char_Array_2[1] << 8 | (uint32_t)Temporary_Char_Array_2[2] << 16 | (uint32_t)Temporary_Char_Array_2[3] << 24;
    Serial.println(Block_Size);*/

    // Audio format (PCM, etc.) : 2 bytes
    Music_File.seek(0x14);
    if (Music_File.read() != 0x01)
    {
        Serial.println(F("Not a PCM file"));
        return 0;
    }

    // Channel number: 2 bytes
    Music_File.seek(0x16);
    Channel_Number = Music_File.read();

    // Sample frequency : 4 bytes
    Music_File.seek(0x18);
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    Sample_Frequency = (uint32_t)Temporary_Char_Array_2[0] | (uint32_t)Temporary_Char_Array_2[1] << 8 | (uint32_t)Temporary_Char_Array_2[2] << 16 | (uint32_t)Temporary_Char_Array_2[3] << 24;
    Serial.println(Sample_Frequency);

    // Byte per sec : 4 bytes
    Music_File.seek(0x1C);
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    Byte_Per_Second = (uint32_t)Temporary_Char_Array_2[0] | (uint32_t)Temporary_Char_Array_2[1] << 8 | (uint32_t)Temporary_Char_Array_2[2] << 16 | (uint32_t)Temporary_Char_Array_2[3] << 24;
    Serial.println(Byte_Per_Second);

    // Byte per bloc : 2 bytes
    Music_File.seek(0x20);
    Byte_Per_Block = Music_File.read();
    Serial.println(Byte_Per_Block);

    // Bits per sample : 2 byte
    Music_File.seek(0x22);
    Bits_Per_Sample = Music_File.read();
    Serial.println(Bits_Per_Sample);

    // Data block ID : 4 bytes
    Music_File.seek(0x24);
    strcpy(Temporary_Char_Array_1, "data");
    Music_File.readBytes(Temporary_Char_Array_2, 4);
    if (memcmp(Temporary_Char_Array_1, Temporary_Char_Array_2, 4) == 0)
    {
    }

    // Datablock size : 4 bytes
    Music_File.seek(0x28);

    // Data block:
    Music_File.seek(0x2C);

    return 1;
}

void Sound_Class::Set_Time(uint32_t Time)
{
    if (State == Stopped || Mode == 1)
    {
        return;
    }

    Pause();

    Music_File.seek(44 + (Byte_Per_Second * (Time / 1000)));

    Resume();
}

uint32_t Sound_Class::Get_Time()
{
    if (State == Stopped || Mode == 1)
    {
        return 0;
    }
    return millis() - Start_Time;
}

uint32_t Sound_Class::Get_Total_Time()
{
    if (State == Stopped || Mode != 0)
    {
        return 0;
    }
    return (((Music_File.size() - 44) / Byte_Per_Second) * 1000);
}

void Sound_Class::Tone(uint16_t const &Frequency, uint32_t const &Duration, uint8_t const &Pin)
{
    if (State == Playing)
    {
        return;
    }

    if (Pin == 0xFF)
    {
        ledcAttachPin(25, LEFT_CHANNEL);
        ledcAttachPin(26, RIGHT_CHANNEL);
        ledcWriteTone(LEFT_CHANNEL, Frequency);
        ledcWriteTone(RIGHT_CHANNEL, Frequency);
    }
    else
    {
        ledcAttachPin(Pin, CUSTOM_CHANNEL);
        ledcWriteTone(CUSTOM_CHANNEL, Frequency);
    }

    State = Playing;
    Mode = 3;

    if (Duration != 0)
    {
        vTaskDelay(pdMS_TO_TICKS(Duration));
        No_Tone();
        No_Tone();
    }
}

void Sound_Class::No_Tone(uint8_t const &Pin)
{
    if (Pin == 0xFF)
    {
        ledcWrite(LEFT_CHANNEL, 0);
        ledcWrite(RIGHT_CHANNEL, 0);
        ledcDetachPin(25);
        ledcDetachPin(26);
    }
    else
    {
        ledcWrite(CUSTOM_CHANNEL, 0);
        ledcDetachPin(Custom_Pin);
    }
}

uint8_t Sound_Class::Play(File &File_To_Play)
{
    Serial.println(F("Play sound"));
    Buffer_To_Play = NULL;
    if (!File_To_Play)
    {
        Serial.println(F("Cannot open file"));
        return 0;
    }

    Music_File = File_To_Play;

    if (!Get_Metadata())
    {
        Serial.println(F("Cannot get metadata"));
        return 0;
    }
    if (!Start_ULP())
    {
        Serial.println(F("Cannot start ulp"));
        return 0;
    }
    return 1;
}

uint8_t Sound_Class::Play(uint8_t *Samples, const uint32_t &Buffer_Size, const uint32_t &Sample_Frequency)
{
    if (State == Stopped)
    {
        Stop();
    }
    this->Sample_Frequency = Sample_Frequency;
    this->Buffer_To_Play = Samples;
    this->Buffer_Size = Buffer_Size;
    Channel_Number = 1;

    return Start_ULP();
}

uint8_t Sound_Class::Resume()
{
    if (State == Stopped)
    {
        return false;
    }

    vTaskResume(Sound_Task_Handle);

    State = Playing;

    return true;
}

void Sound_Class::Pause()
{
    if (State == Stopped)
    {
        return;
    }

    vTaskSuspend(Sound_Task_Handle);

    State = Paused;

    dac_output_disable(DAC_CHANNEL_1);
    dac_output_disable(DAC_CHANNEL_2);
}

uint8_t Sound_Class::Start_ULP()
{
    if (rtc_8md256_period == 0)
    {
        rtc_8md256_period = rtc_clk_cal(RTC_CAL_8MD256, 1000);
        if (rtc_8md256_period == 0) // if still 0 (avoid divide by 0)
        {
            return 0;
        }
    }

    uint32_t rtc_fast_freq_hz = 1000000ULL * (1 << RTC_CLK_CAL_FRACT) * 256 / rtc_8md256_period;

    //initialize DACs
    dac_output_enable(DAC_CHANNEL_1);
    dac_output_enable(DAC_CHANNEL_2);
    dac_output_voltage(DAC_CHANNEL_1, 128);
    dac_output_voltage(DAC_CHANNEL_2, 128);

    int retAddress1 = 13;
    int retAddress2 = 13;

    Serial.print("Real RTC clock : ");
    Serial.println(rtc_fast_freq_hz);

    if (Bits_Per_Sample != 8)
    {
        // Currently only support unsigned 8 bits samples
        return 0;
    }

    if (Channel_Number == 1)
    {
        int Delay_Time = (rtc_fast_freq_hz / Sample_Frequency) - 84;
        if (Delay_Time < 0)
        {
            Serial.println("Sampling rate too high");
            return 0;
        }
        Serial.println(F("mono"));
        totalSampleWords = 2048 - 512 - (opcodeCount + 1);
        totalSamples = totalSampleWords * 2;
        const ulp_insn_t Play_Program[] = {

            //reset offset register
            I_MOVI(R3, 0),
            //delay to get the right sampling rate
            I_DELAY(Delay_Time), // 6 + dt
            //reset sample index
            I_MOVI(R0, 0), // 6
            //write the index back to memory for the main cpu
            I_ST(R0, R3, Index_Adress), // 8
            //divide index by two since we store two samples in each dword
            I_RSHI(R2, R0, 1), // 6
            //load the samples
            I_LD(R1, R2, bufferStart), // 8
            //get if odd or even sample
            I_ANDI(R2, R0, 1), // 6
            //multiply by 8
            I_LSHI(R2, R2, 3), // 6
            //shift the bits to have the right sample in the lower 8 bits
            I_RSHR(R1, R1, R2), // 6
            //mask the lower 8 bits
            I_ANDI(R1, R1, 255), // 6
            //multiply by 2
            I_LSHI(R1, R1, 1), // 6
            //add start position
            I_ADDI(R1, R1, dacTableStart1), // 6
            //jump to the dac opcode
            I_BXR(R1), // 4
            //here we get back from writing a sample
            //increment the sample index
            I_ADDI(R0, R0, 1), // 6
            //if reached end of the buffer, jump relative to index reset
            I_BGE(-13, (uint32_t)totalSamples), // 4
            //wait to get the right sample rate (2 cycles more to compensate the index reset)
            I_DELAY((unsigned int)Delay_Time + 2), // 8 + dt
            //if not, jump absolute to where index is written to memory
            I_BXI(3) // 4
            // write io and jump back another 12 + 4
        };

        size_t Size = sizeof(Play_Program) / sizeof(ulp_insn_t);
        ulp_process_macros_and_load(0, Play_Program, &Size);

        //create DAC opcode tables
        for (int i = 0; i < 256; i++)
        {
            RTC_SLOW_MEM[dacTableStart1 + i * 2] = 0x1D4C0121 | (i << 10); //dac0
            RTC_SLOW_MEM[dacTableStart1 + 1 + i * 2] = 0x80000000 + retAddress1 * 4;
        }
    }
    else if (Channel_Number == 2)
    {

        int Delay_Time = (rtc_fast_freq_hz / Sample_Frequency) - 100;
        Serial.println(Delay_Time);
        if (Delay_Time < 0)
        {
            Serial.println("Sampling rate too high");
            return 0;
        }
        Serial.println(F("stereo"));
        totalSampleWords = 2048 - 512 - 512 - (opcodeCount + 1);
        totalSamples = totalSampleWords * 2;
        retAddress1 = 9;

        const ulp_insn_t Play_Program[] = {
            //reset offset register
            I_MOVI(R3, 0),
            //delay to get the right sampling rate
            I_DELAY(Delay_Time), // 6 + dt
            //reset sample index
            I_MOVI(R0, 0), // 6
            //write the index back to memory for the main cpu
            I_ST(R0, R3, Index_Adress), // 8
            //load the samples
            I_LD(R1, R0, bufferStart), // 8
            //mask the lower 8 bits
            I_ANDI(R2, R1, 255), // 6
            //multiply by 2
            I_LSHI(R2, R2, 1), // 6
            //add start position
            I_ADDI(R2, R2, dacTableStart1), // 6
            //jump to the dac opcode
            I_BXR(R2), // 4
            //back from first dac
            //mask the upper 8 bits
            I_ANDI(R1, R1, 0xff00), // 6
            //shift the upper bits to right and multiply by 2
            I_RSHI(R1, R1, 8 - 1), // 6
            //add start position of second dac table
            I_ADDI(R1, R1, dacTableStart2), // 6
            //jump to the dac opcode
            I_BXR(R1), // 4
            I_ADDI(R0, R0, 1), // 6
            //if reached end of the buffer, jump relative to index reset
            I_BGE(-13, (uint32_t)totalSampleWords), // 4
            //wait to get the right sample rate (2 cycles more to compensate the index reset)
            I_DELAY((unsigned int)Delay_Time + 2), // 8 + dt
            //if not, jump absolute to where index is written to memory
            I_BXI(3)};

        size_t Size = sizeof(Play_Program) / sizeof(ulp_insn_t);
        ulp_process_macros_and_load(0, Play_Program, &Size);

        //create DAC opcode tables
        for (int i = 0; i < 256; i++)
        {
            RTC_SLOW_MEM[dacTableStart1 + i * 2] = 0x1D4C0121 | (i << 10); //dac1
            RTC_SLOW_MEM[dacTableStart1 + 1 + i * 2] = 0x80000000 + retAddress1 * 4;
            RTC_SLOW_MEM[dacTableStart2 + i * 2] = 0x1D4C0122 | (i << 10); //dac2
            RTC_SLOW_MEM[dacTableStart2 + 1 + i * 2] = 0x80000000 + retAddress2 * 4;
        }

        //  this is how to get the opcodes
        //  for(int i = 0; i < size; i++)
        //    Serial.println(RTC_SLOW_MEM[i], HEX);

        //set all samples to 128 (silence)
        for (int i = 0; i < totalSampleWords; i++)
        {
            RTC_SLOW_MEM[bufferStart + i] = 0x8080;
        }
        //start
        RTC_SLOW_MEM[Index_Adress] = 0;
        ulp_run(0);

        while (RTC_SLOW_MEM[Index_Adress] == 0)
        {
            vTaskDelay(pdMS_TO_TICKS(1));
        }
    }
    else
    {
        return 0;
        // dont support more than 2 channel
    }

    xTaskCreatePinnedToCore(Sound_Class::Sound_Task, "Sound Driver", 1024 * 6, NULL, DRIVER_TASK_PRIORITY, &Sound_Task_Handle, SYSTEM_CORE);

    return 1;
}

void Sound_Class::Stop()
{
    if (State == Stopped)
    {
        return;
    }

    Serial.println(F("Stop"));
    for (int i = 0; i < totalSampleWords; i++) //mute dac
    {
        RTC_SLOW_MEM[bufferStart + i] = 0x8080;
    }
    size_t Size = sizeof(Stop_Program) / sizeof(ulp_insn_t);
    ulp_process_macros_and_load(0, Stop_Program, &Size);
    ulp_run(0);

    Mute();

    if (Mode == 0)
    {
        Music_File.close();
    }

    Mode = 0;
    State = Stopped;

    vTaskDelete(Sound_Task_Handle);
}

void Sound_Class::Mute()
{
    dac_output_disable(DAC_CHANNEL_1);
    dac_output_disable(DAC_CHANNEL_2);
}

void Sound_Class::Sound_Task(void *pvParameters)
{
    (void)pvParameters;
    uint16_t Location = 0;
    int16_t Last_Filled_Word = 0;
    bool End = false;

    while (1)
    {
        if (Instance_Pointer->Mode == 1) //play from buffer
        {
            Serial.println(F("play from buffer"));
            while (1)
            {
                /*Current_Sample = RTC_SLOW_MEM[Instance_Pointer->Index_Adress] & 0xffff;
                Current_Word = Current_Sample >> 1;
                while (Instance_Pointer->Last_Filled_Word != Current_Word)
                {
                    uint16_t Word = (uint8_t)(int)Buffer[Location++] + Instance_Pointer->Volume;
                    Word |= ((uint8_t)(int)Buffer[Location++] + Instance_Pointer->Volume) << 8;
                    RTC_SLOW_MEM[Instance_Pointer->bufferStart + Instance_Pointer->Last_Filled_Word] = Word;
                    Instance_Pointer->Last_Filled_Word++;
                    if (Instance_Pointer->Last_Filled_Word == Instance_Pointer->totalSampleWords)
                    {
                        Remaining_Samples = Instance_Pointer->Music_File.available();
                        if (Remaining_Samples < 3036)
                        {
                            Instance_Pointer->Music_File.read(Buffer, Remaining_Samples);
                            for (; Remaining_Samples < 3036; Location++)
                            {
                            }
                            vTaskDelay(pdMS_TO_TICKS(10));
                            Instance_Pointer->Stop_ULP();
                        }
                        else
                        {
                            Instance_Pointer->Music_File.read(Buffer, 3036);
                        }
                        Instance_Po)inter->Last_Filled_Word = 0;
                    }
                }*/
            }
        }
        else if (Instance_Pointer->Mode == 0) // play from file
        {
            if (Instance_Pointer->Bits_Per_Sample == 8) // 8 bit from sd
            {
                Serial.println(F("8 bit"));
                uint8_t Buffer[Instance_Pointer->totalSampleWords * 2];
                Instance_Pointer->Music_File.read(Buffer, sizeof(Buffer));
                while (1)
                {
                    int Current_Sample = RTC_SLOW_MEM[Instance_Pointer->Index_Adress] & 0xffff;
                    int Current_Word = Current_Sample >> 1;
                    while (Last_Filled_Word != Current_Word)
                    {
                        uint16_t Word = (uint16_t)Buffer[Location++];
                        Word |= (uint16_t)Buffer[Location++] << 8;
                        RTC_SLOW_MEM[Instance_Pointer->bufferStart + Last_Filled_Word] = Word;
                        Last_Filled_Word++;
                        if (Last_Filled_Word == Instance_Pointer->totalSampleWords) // need to refresh buffer
                        {
                            if (End == true)
                            {
                                Instance_Pointer->Stop();
                            }
                            Last_Filled_Word = 0;
                            Location = 0;
                            if (Instance_Pointer->Music_File.available() <= sizeof(Buffer))
                            {
                                Instance_Pointer->Music_File.read(Buffer, Instance_Pointer->Music_File.available());
                                End = true;
                            }
                            else
                            {
                                Instance_Pointer->Music_File.read(Buffer, sizeof(Buffer));
                            }
                        }
                    }
                    vTaskDelay(pdMS_TO_TICKS(5));
                }
            }
            else
            {
                Serial.println(F("Unsupported bit res"));
                vTaskDelete(NULL);
            }
        }
    }
}