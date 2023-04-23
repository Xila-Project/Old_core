/// @file I2S_Stream.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-04-2023
///
/// @copyright Copyright (c) 2023

#include "Core/Sound/I2S_Stream.hpp"
#include "AudioTools.h"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Audio_Types;

Result_Type I2S_Stream_Class::Begin()
{
    return Begin(Communication_Type::Transmit);
}

Result_Type I2S_Stream_Class::Begin(Communication_Type Mode, int Channels, int Sample_Rate, int Bits_Per_Sample)
{
    if (Set_Pointer(new I2SStream()) != Result_Type::Success)
        return Result_Type::Error;   


    audio_tools::I2SConfig Configuration;

    switch (Mode)
    {
    case Communication_Type::Transmit:
        Configuration = Get_Pointer()->defaultConfig(TX_MODE);
        break;
    case Communication_Type::Receive:
        Configuration = Get_Pointer()->defaultConfig(RX_MODE);
        break;
    case Communication_Type::Receive_Transmit:
        Configuration = Get_Pointer()->defaultConfig(RXTX_MODE);
        break;
    default:
        Configuration = Get_Pointer()->defaultConfig(UNDEFINED_MODE);
        break;
    }

    Configuration.channels = Channels;
    Configuration.sample_rate = Sample_Rate;
    Configuration.bits_per_sample = Bits_Per_Sample;
}

void I2S_Stream_Class::End()
{
    if (!Is_Valid())
        return;

    Get_Pointer()->end();
    delete Get_Pointer();
    Clear_Pointer();
}

