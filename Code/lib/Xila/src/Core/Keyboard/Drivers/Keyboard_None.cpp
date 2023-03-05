///
 /// @file Keyboard_None.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 04-03-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#ifdef Xila_Keyboard_Hardware_None

#include "Core/Keyboard/Keyboard.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Keyboard_Types;

///
/// @brief Construct a new Keyboard_Class::Keyboard_Class object
///
Keyboard_Class::Keyboard_Class()
{
}

///
/// @brief Initialize the communication with the keyboard.
///
void Keyboard_Class::Begin()
{
}

///
/// @brief Read character from the keyboard.
///
/// @return unsigned char Input character.
unsigned char Keyboard_Class::Read()
{
    return '\0';
}

///
/// @brief Check if any character is availble.
///
/// @return uint8_t The amount of character available in the buffer.
uint8_t Keyboard_Class::Available()
{
    return false;
}

///
/// @brief Read character from the keyboard.
///
/// @return uint8_t The amount of character available in the buffer.
uint8_t Keyboard_Class::Read_Raw()
{
    return '\0';
}

///
/// @brief Clear the character buffer.
///
void Keyboard_Class::Clear()
{
}

#endif