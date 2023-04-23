 /// @file Audio_Stream.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 17-04-2023
 /// 
 /// @copyright Copyright (c) 2023

#include "Core/Sound/Audio_Stream.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Audio_Types;

#include "AudioTools.h"

// - Methods

Audio_Stream_Class::Audio_Stream_Class() : Audio_Stream_Pointer(NULL)
{}

Audio_Stream_Class::~Audio_Stream_Class()
{}

size_t Audio_Stream_Class::readBytes(uint8_t *Buffer, size_t Length)
{
    if (Is_Valid())
        return Get_Pointer()->readBytes(Buffer, Length);
    else
        return 0;
}

size_t Audio_Stream_Class::write(const uint8_t *Buffer, size_t Length)
{
    if (Is_Valid())
        return Get_Pointer()->write(Buffer, Length);
    else
        return 0;
}

size_t Audio_Stream_Class::write(uint8_t Byte)
{
    if (Is_Valid())
        return Get_Pointer()->write(Byte);
    else
        return 0;
}

int Audio_Stream_Class::Available_For_Write()
{
    if (Is_Valid())
        return Get_Pointer()->availableForWrite();
    else
        return 0;
}

void Audio_Stream_Class::Write_Silence(Size_Type Length)
{
    if (Is_Valid())
        Get_Pointer()->writeSilence(Length);
}

void Audio_Stream_Class::Flush()
{
    if (Is_Valid())
        Get_Pointer()->flush();
}

Result_Type Audio_Stream_Class::Begin()
{
    return Set_Pointer(new AudioStream());
}

void Audio_Stream_Class::End()
{
    if (Is_Valid())
        Get_Pointer()->end();
}

bool Audio_Stream_Class::Is_Valid()
{
    if (Get_Pointer() == NULL)
        return false;
    else
        return Get_Pointer()->isValid();
}