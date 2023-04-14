/// @file Keyboard_None.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 04-03-2023
///
/// @copyright Copyright (c) 2023

#ifdef Xila_Keyboard_Hardware_None

#include "Core/Keyboard/Keyboard.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Keyboard_Types;

Keyboard_Class::Keyboard_Class()
{
}

void Keyboard_Class::Begin()
{
}

unsigned char Keyboard_Class::Read()
{
    return '\0';
}

uint8_t Keyboard_Class::Available()
{
    return false;
}

uint8_t Keyboard_Class::Read_Raw()
{
    return '\0';
}

void Keyboard_Class::Clear()
{
}

#endif