/// @file FIle_Player.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 28-04-2023
///
/// @copyright Copyright (c) 2023

#include "Sound/File_Player.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Sound_Types;

File_Player_Class::File_Player_Class(Drive_Types::File_Type &Input_File, Sound_Types::Stream_Type &Output_Stream, Decoder_Type &Decoder)
    : Stream_Type(Encoded_Stream),
      Encoded_Stream(&(AudioStream &)Output_Stream, &(AudioDecoder &)Decoder),
      Decoder(&Decoder),
      Input_File(Input_File),
      Stream_Copier(Encoded_Stream, this->Input_File)
{
    Encoded_Stream.setNotifyAudioChange(Output_Stream);
}

File_Player_Class::File_Player_Class()
    : Stream_Type(Encoded_Stream),
    Decoder(NULL)
{

}

void File_Player_Class::Set_Decoder(Decoder_Type &Decoder)
{
    this->Decoder = &Decoder;
    Encoded_Stream.setDecoder(&(AudioDecoder &)Decoder);
}

void File_Player_Class::Set_Output_Stream(Sound_Types::Stream_Type &Output_Stream)
{
    Encoded_Stream.setOutput(&(AudioStream &)Output_Stream);
    Encoded_Stream.setNotifyAudioChange(Output_Stream);
}

void File_Player_Class::Set(Drive_Types::File_Type &Input_File, Sound_Types::Stream_Type &Output_Stream, Decoder_Type &Decoder)
{
    Encoded_Stream.setOutput(&(AudioStream &)Output_Stream);
    Encoded_Stream.setDecoder(&(AudioDecoder &)Decoder);
    this->Decoder = &Decoder;
    this->Input_File = Input_File;
    Encoded_Stream.setNotifyAudioChange(Output_Stream);
    Stream_Copier.end();
    Stream_Copier.begin(Encoded_Stream, this->Input_File);
}

void File_Player_Class::Set_File(Drive_Types::File_Type &Input_File)
{
    if (!Input_File.Is_Valid())
        return;
    this->Input_File = Input_File;
    Stream_Copier.end();
    Stream_Copier.begin(Encoded_Stream, this->Input_File);
}

/// @brief Set the player time.
/// @param Time Time in seconds.
void File_Player_Class::Set_Time(uint32_t Time)
{
    Input_File.Seek((Time * Get_Sample_Rate() * Get_Channels() * (Get_Bits_Per_Sample() / 8)) + 44);
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

Result_Type File_Player_Class::Begin()
{
    return (Result_Type)Encoded_Stream.begin();
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

int File_Player_Class::Get_Sample_Rate()
{
    return Decoder->Get_Configuration().Get_Sample_Rate();
}

int File_Player_Class::Get_Bits_Per_Sample()
{
    return Decoder->Get_Configuration().Get_Bits_Per_Sample();
}

int File_Player_Class::Get_Channels()
{
    return Decoder->Get_Configuration().Get_Channel_Count();
}