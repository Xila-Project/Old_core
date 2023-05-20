/// @file Keyboard_PS2.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 24-01-2023
///
/// @copyright Copyright (c) 2023

#ifdef Xila_Keyboard_Hardware_PS2

#include "Keyboard/Keyboard.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Keyboard_Types;

#include <PS2Keyboard.h>

PS2Keyboard PS2_Keyboard();

Keyboard_Class::Keyboard_Class()
    : Layout(Layout_Type::American),
      Data_Pin(Default_Keyboard_Data_Pin),
      Clock_Pin(Default_Keyboard_Clock_Pin)
{
}

void Keyboard_Class::Begin()
{
    switch (Layout)
    {
    case Layout_Type::American:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_US);
        break;
    case Layout_Type::German:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_German);
        break;
    case Layout_Type::French:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_French);
        break;
    case Layout_Type::Spanish:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_Spanish);
        break;
    case Layout_Type::Italian:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_Italian);
        break;
    case Layout_Type::English:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_UK);
        break;
    }
}

unsigned char Keyboard_Class::Read()
{
    return PS2Keyboard::read();
}

uint8_t Keyboard_Class::Available()
{
    return PS2Keyboard::available();
}

uint8_t Keyboard_Class::Read_Raw()
{
    return PS2Keyboard::readScanCode();
}

void Keyboard_Class::Clear()
{
    PS2Keyboard::clear();
}

#endif