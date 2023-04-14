/// @file Keyboard.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 24-01-2023
///
/// @copyright Copyright (c) 2023

#include "Core/Keyboard/Keyboard.hpp"
#include "Core/Drive/Drive.hpp"

// - Constants
#ifndef Xila_Keyboard_Default_Layout
#define Xila_Keyboard_Default_Layout Layout_Type::American
#endif

// - Import namespaces
using namespace Xila_Namespace;
using namespace Xila_Namespace::Keyboard_Types;

Keyboard_Type Xila_Namespace::Keyboard;




Result_Type Keyboard_Class::Load_Registry()
{

    File_Type Temporary_File = Drive.Open(Registry("Keyboard"));
    StaticJsonDocument<256> Keyboard_Registry;
    if (deserializeJson(Keyboard_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    if (strcmp("Keyboard", Keyboard_Registry["Registry"] | "") != 0)
    {
        return Result_Type::Error;
    }
    // Data_Pin = Keyboard_Registry["Data Pin"] | Default_Keyboard_Data_Pin;
    // Clock_Pin = Keyboard_Registry["Clock Pin"] | Default_Keyboard_Clock_Pin;
    // Layout = static_cast<Layout_Type>(Keyboard_Registry["Layout"] | static_cast<uint8_t>(Xila_Keyboard_Default_Layout));

    // Begin();
    return Result_Type::Success;
}




Result_Type Keyboard_Class::Save_Registry()
{
    File_Type Temporary_File = Drive.Open(Registry("Keyboard"), true);
    StaticJsonDocument<256> Keyboard_Registry;
    Keyboard_Registry["Registry"] = "Keyboard";
    Keyboard_Registry["Data Pin"] = Data_Pin;
    Keyboard_Registry["Clock Pin"] = Clock_Pin;
    Keyboard_Registry["Layout"] = static_cast<Byte_Type>(Layout);
    if (serializeJson(Keyboard_Registry, Temporary_File) == 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    return Result_Type::Success;
}