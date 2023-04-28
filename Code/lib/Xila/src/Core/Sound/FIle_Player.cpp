/// @file FIle_Player.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 28-04-2023
///
/// @copyright Copyright (c) 2023

#include "Core/Sound/File_Player.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Sound_Types;

File_Player_Class::File_Player_Class(Decoder_Type &Decoder)
    : Encoded_Stream(&Decoder),
      Decoder(Decoder)
{
}

File_Player_Class::File_Player_Class(File_Type &Input_File, AudioStream &Output_Stream, Decoder_Type &Decoder)
    : Encoded_Stream(&Output_Stream, &Decoder),
      Decoder(Decoder),
      Stream_Copier(Encoded_Stream, Input_File),
      Input_File(Input_File)
{
    Encoded_Stream.setNotifyAudioChange(Output_Stream);
}

File_Player_Class::~File_Player_Class()
{
}

/// @brief Set the player time.
/// @param Time Time in seconds.
void File_Player_Class::Set_Time(uint32_t Time)
{
    Input_File.Seek((30 * Get_Sample_Rate() * Get_Channels() * (Get_Bits_Per_Sample() / 8)) + 44);
}

/// @brief Set the player time.
/// @param Time Time
void File_Player_Class::Set_Time(Time_Type Time)
{
    Set_Time(Time.Get_Seconds() + (Time.Get_Minutes() * 60) + (Time.Get_Hours() * 60 * 60));
}

/// @brief Get the player current time.
/// @return Time_Type Current time in seconds.
uint32_t File_Player_Class::Get_Time()
{
    if (Get_Sample_Rate() == 0 || Get_Channels() == 0 || Get_Bits_Per_Sample() == 0)
        return 0;

    return (Input_File.Get_Position() - 44) / (Get_Sample_Rate() * Get_Channels() * (Get_Bits_Per_Sample() / 8));
}

uint32_t File_Player_Class::Get_Total_Time()
{
    if (Get_Sample_Rate() == 0 || Get_Channels() == 0 || Get_Bits_Per_Sample() == 0)
        return 0;

    return (Input_File.Get_Size() - 44) / (Get_Sample_Rate() * Get_Channels() * (Get_Bits_Per_Sample() / 8));
}

void File_Player_Class::Start()
{
    Encoded_Stream.begin();
}

void File_Player_Class::Stop()
{
    Encoded_Stream.end();
    Stream_Copier.end();
}

Size_Type File_Player_Class::Loop()
{
    return Stream_Copier.copy();
}

void File_Player_Class::Set_Input_Stream(Stream &Input_Stream)
{
}

void File_Player_Class::Set_Output_Stream(AudioStream &Output_Stream)
{
}

uint32_t File_Player_Class::Get_Sample_Rate()
{
    return Decoder.audioInfo().sample_rate;
}

Byte_Type File_Player_Class::Get_Bits_Per_Sample()
{
    return Decoder.audioInfo().bits_per_sample;
}

Byte_Type File_Player_Class::Get_Channels()
{
    return Decoder.audioInfo().channels;
}