#include "Core/Core.hpp"

#include "PS2Kbd.h"

PS2Kbd PS2_Keyboard(DEFAULT_KEYBOARD_DATA, DEFAULT_KEYBOARD_CLOCK);

Xila_Event Xila_Class::Keyboard_Class::Save_Registry()
{
  // Currently no parameters are stored for keyboard
  return Success;
}

Xila_Event Xila_Class::Keyboard_Class::Load_Registry()
{
  // Currently no parameters are stored for keyboard
  return Success;
}


void Xila_Class::Keyboard_Class::Begin()
{
    PS2_Keyboard.begin();
}

unsigned char Xila_Class::Keyboard_Class::Read()
{
    return PS2_Keyboard.read();
}

uint8_t Xila_Class::Keyboard_Class::Available()
{
    return PS2_Keyboard.available();
}

unsigned char Xila_Class::Keyboard_Class::Read_Raw()
{
    return PS2_Keyboard.readRaw();
}

unsigned char Xila_Class::Keyboard_Class::Available_Raw()
{
    return PS2_Keyboard.availableRaw();
}

uint8_t Xila_Class::Keyboard_Class::Get_Modifiers()
{
    return PS2_Keyboard.getModifiers();
}

void Xila_Class::Keyboard_Class::Clear_Buffers()
{
    PS2_Keyboard.clearBuffers();
}