///
 /// @file Keyboard.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 24-01-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#include "Core/Core.hpp"
#include "Core/Keyboard/Keyboard.hpp"

using namespace Xila_Namespace;

Input_Type Keyboard();

/// @brief Load keyboard registry.
///
/// @return Result_Type
Result_Type Input_Class::Load_Registry()
{
    using namespace Xila;

    File Temporary_File = Drive.Open(Registry("Keyboard"));
    DynamicJsonDocument Keyboard_Registry(512);
    if (deserializeJson(Keyboard_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Result_Type::Error;
    }
    Temporary_File.close();
    if (strcmp("Keyboard", Keyboard_Registry["Registry"] | "") != 0)
    {
        return Result_Type::Error;
    }
    Data_Pin = Keyboard_Registry["Data Pin"] | Default_Keyboard_Data_Pin;
    Clock_Pin = Keyboard_Registry["Clock Pin"] | Default_Keyboard_Clock_Pin;
    Layout = Keyboard_Registry["Layout"] | Default_Keyboard_Layout;

    Begin();
    return Result_Type::Success;
}

/// @brief Save keyboard registry.
///
/// @return Result_Type
Result_Type Input_Class::Save_Registry()
{
    using namespace Xila;

    File Temporary_File = Drive.Open(Registry("Keyboard"), FILE_WRITE);
    DynamicJsonDocument Keyboard_Registry(512);
    Keyboard_Registry["Registry"] = "Keyboard";
    Keyboard_Registry["Data Pin"] = Data_Pin;
    Keyboard_Registry["Clock Pin"] = Clock_Pin;
    Keyboard_Registry["Layout"] = Layout;
    if (serializeJson(Keyboard_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Result_Type::Error;
    }
    Temporary_File.close();
    return Result_Type::Success;
}