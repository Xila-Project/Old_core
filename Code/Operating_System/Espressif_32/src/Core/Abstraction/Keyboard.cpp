#include "Core/Core.hpp"

#include <PS2Keyboard.h>

PS2Keyboard PS2_Keyboard();

Xila_Class::Keyboard_Class::Keyboard_Class()
    : Layout(Default_Keyboard_Layout),
      Data_Pin(Default_Keyboard_Data_Pin),
      Clock_Pin(Default_Keyboard_Clock_Pin)
{
}

Xila_Class::Event Xila_Class::Keyboard_Class::Load_Registry()
{
    Verbose_Print_Line("Load keyboard registry");
    // Currently no parameters are stored for keyboard

    File Temporary_File = Xila.Drive.Open(Keyboard_Registry_Path);
    DynamicJsonDocument Keyboard_Registry(256);
    if (deserializeJson(Keyboard_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    if (strcmp(Keyboard_Registry["Registry"], "Keyboard") != 0)
    {
        return Error;
    }
    Data_Pin = Keyboard_Registry["Data Pin"] | Default_Keyboard_Data_Pin;
    Serial.println(Data_Pin);
    Clock_Pin = Keyboard_Registry["Clock Pin"] | Default_Keyboard_Clock_Pin;
    Serial.println(Clock_Pin);
    Layout = Keyboard_Registry["Keymap"] | Default_Keyboard_Layout;
    Serial.println(Layout);
    Begin();
    return Success;
}

Xila_Class::Event Xila_Class::Keyboard_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive.Open(Keyboard_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Keyboard_Registry(256);
    Keyboard_Registry["Data Pin"] = Data_Pin;
    Keyboard_Registry["Clock Pin"] = Clock_Pin;
    Keyboard_Registry["Key Map"] = Layout;
    if (serializeJson(Keyboard_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    return Success;
}

void Xila_Class::Keyboard_Class::Begin()
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