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
#define Xila_Default_Sound_Volume 1
#endif

#ifndef Xila_Sound_Default_Maximum_Volume
#define Xila_Sound_Default_Maximum_Volume 1
#endif

#include "AudioTools.h"
#include "Sound/Sound.hpp"
#include "Drive/Drive.hpp"
#include "Log/Log.hpp"

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

#if defined(Xila_Sound_Default_I2S_Word_Select_Pin) && defined(Xila_Sound_Default_I2S_Clock_Pin) && defined(Xila_Sound_Default_I2S_Data_Pin)
    {
        auto Configuration = I2S_Output_Stream.Get_Default_Configuration();
        Configuration.Set_Word_Select_Clock_Pin(Xila_Sound_Default_I2S_Word_Select_Pin);
        Configuration.Set_Bit_Clock_Pin(Xila_Sound_Default_I2S_Clock_Pin);
        Configuration.Set_Data_Pin(Xila_Sound_Default_I2S_Data_Pin);
        Configuration.Set_Master_Clock_Pin(-1); // ! : Temporary fix for arduino-audio-tools (commit 69a0e5a).

        Configuration.Set_Sample_Rate(44100);
        Configuration.Set_Channel_Count(1);
        Configuration.Set_Bits_Per_Sample(16);

        if (I2S_Output_Stream.Begin(Configuration) != Result_Type::Success)
            return Result_Type::Error;

       Volume_Stream.Begin(Configuration);
        Set_Volume(Xila_Default_Sound_Volume);
    }
#endif

    return Result_Type::Success;
}

Result_Type Sound_Class::Stop()
{
    // Mixer.end();
    // Volume_Stream.end();
    //  I2S_Output_Stream.End();

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

Real_Type Sound_Class::Get_Volume()
{
    return Volume_Stream.Get_Volume() / Xila_Sound_Default_Maximum_Volume;
}

Sound_Types::Stream_Type& Sound_Class::Get_Current_Output_Stream()
{
    return Volume_Stream;
}

// - - Setters

void Sound_Class::Set_Volume(Real_Type Volume)
{
    Volume_Stream.Set_Volume(Volume * Xila_Sound_Default_Maximum_Volume);
}