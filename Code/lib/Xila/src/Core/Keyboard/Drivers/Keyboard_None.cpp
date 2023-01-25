#if Keyboard_Hardware == Keyboard_Hardware_None


#include "Core/Core.hpp"

using namespace Xila_Namespace::Input;

#include <PS2Keyboard.h>

PS2Keyboard PS2_Keyboard();

///
/// @brief Construct a new Input_Class::Input_Class object
///
Input_Class::Input_Class()
    : Layout(Default_Keyboard_Layout),
      Data_Pin(Default_Keyboard_Data_Pin),
      Clock_Pin(Default_Keyboard_Clock_Pin)
{
}

///
/// @brief Initialize the communication with the keyboard.
///
void Input_Class::Begin()
{
    switch (Layout)
    {
    case American:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_US);
        break;
    case German:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_German);
        break;
    case French:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_French);
        break;
    case Spanish:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_Spanish);
        break;
    case Italian:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_Italian);
        break;
    case English:
        PS2Keyboard::begin(Data_Pin, Clock_Pin, PS2Keymap_UK);
        break;
    }
}

///
/// @brief Read character from the keyboard.
///
/// @return unsigned char Input character.
unsigned char Input_Class::Read()
{
    return PS2Keyboard::read();
}

///
/// @brief Check if any character is availble.
///
/// @return uint8_t The amount of character available in the buffer.
uint8_t Input_Class::Available()
{
    return PS2Keyboard::available();
}

///
/// @brief Read character from the keyboard.
///
/// @return uint8_t The amount of character available in the buffer.
uint8_t Input_Class::Read_Raw()
{
    return PS2Keyboard::readScanCode();
}

///
/// @brief Clear the character buffer.
///
void Input_Class::Clear()
{
    PS2Keyboard::clear();
}

#endif