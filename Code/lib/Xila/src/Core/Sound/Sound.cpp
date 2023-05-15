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

#include "AudioTools.h"
#include "Core/Sound/Sound.hpp"
#include "Core/Drive/Drive.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Sound_Types;

Sound_Type Xila_Namespace::Sound;

Sound_Class::Sound_Class() : I2S_Output_Stream(),
                             Volume_Stream(I2S_Output_Stream) //,
                                                              //    Mixer(Volume_Stream, 4)
{
}

Result_Type Sound_Class::Start()
{
    Log_Information("Sound", "Starting sound module...");

    if (this->Load_Registry() != Result_Type::Success)
    {
        return this->Create_Registry();
    }

    {
        auto Configuration = I2S_Output_Stream.Get_Default_Configuration();
        Configuration.Set_Word_Select_Clock_Pin(35);
        Configuration.Set_Bit_Clock_Pin(36);
        Configuration.Set_Data_Pin(37);

        //  Configuration.sample_rate = 44100;
        //  Configuration.channels = 1;
        //  Configuration.bits_per_sample = 16;

        if (I2S_Output_Stream.Begin(Configuration) != Result_Type::Success)
            return Result_Type::Error;
    
    }
    {
        auto Configuration = Volume_Stream.Get_Default_Configuration();
        Volume_Stream.Begin(Configuration);
        Configuration.Set_Volume(0.5);

    }
    //  Mixer.begin();

    //    Set_Volume(Xila_Default_Sound_Volume);

    return Result_Type::Success;
}

Result_Type Sound_Class::Stop()
{
    // Mixer.end();
    // Volume_Stream.end();
    I2S_Output_Stream.End();

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
    Drive_Types::File_Type Temporary_File = Drive.Open(Registry("Sound"));
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
    Drive_Types::File_Type Temporary_File = Drive.Open(Registry("Sound"), true);
    if (serializeJson(Sound_Registry, Temporary_File) == 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    */
    return Result_Type::Success;
}

// - - Getters

Byte_Type Sound_Class::Get_Volume()
{
    return static_cast<Byte_Type>(Volume_Stream.Get_Volume() * 255);
}

Sound_Types::Stream_Type &Sound_Class::Get_Current_Output_Stream()
{
    return I2S_Output_Stream;
}

// - - Setters

void Sound_Class::Set_Volume(Byte_Type Volume)
{
    //  Log_Verbose("Sound", "Set volume: %d", Volume);
    //  Log_Verbose("Sound", "Set volume res: %f", static_cast<float>(Volume) / 255);
    //  Volume_Stream.setVolume(static_cast<float>(Volume) / 255);
}