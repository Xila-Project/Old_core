#include "Core/Core.hpp"

#include <PS2Keyboard.h>

PS2Keyboard PS2_Keyboard();

Xila_Class::Keyboard_Class::Keyboard_Class()
    : Key_Map(American),
      Data_Pin(Default_Keyboard_Data),
      Clock_Pin(Default_Keyboard_Clock)
{
}

Xila_Class::Event Xila_Class::Keyboard_Class::Load_Registry()
{
    // Currently no parameters are stored for keyboard

    File Temporary_File = Xila.Drive.open(Keyboard_Registry_Path);
    DynamicJsonDocument Keyboard_Registry(256);
    if (deserializeJson(Keyboard_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Error;
    }
    Data_Pin = Keyboard_Registry["Data Pin"];
    Clock_Pin = Keyboard_Registry["Clock Pin"];
    Key_Map = Keyboard_Registry["Key Map"];
    Temporary_File.close();

    return Success;
}

Xila_Class::Event Xila_Class::Keyboard_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive.open(Keyboard_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Keyboard_Registry(256);
    Keyboard_Registry["Data Pin"] = Data_Pin;
    Keyboard_Registry["Clock Pin"] = Clock_Pin;
    Keyboard_Registry["Key Map"] = Key_Map;
    if (serializeJson(Keyboard_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    return Success;
    return Success;
}

void Xila_Class::Keyboard_Class::Begin()
{
    switch (Key_Map)
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

unsigned char Xila_Class::Keyboard_Class::Read()
{
    return PS2Keyboard::read();
}

uint8_t Xila_Class::Keyboard_Class::Available()
{
    return PS2Keyboard::available();
}

uint8_t Xila_Class::Keyboard_Class::Read_Raw()
{
    return PS2Keyboard::readScanCode();
}

void Xila_Class::Keyboard_Class::Clear()
{
    PS2Keyboard::clear();
}