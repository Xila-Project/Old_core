///
/// @file Display.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Display/Display.hpp"

#include "Core/Core.hpp"

using namespace Xila_Namespace;

Display_Type Display;

// - Methods

Result_Type Display_Class::Start()
{
    if (Load_Registry() != Result_Type::Success)
    {
        if (Create_Registry() != Result_Type::Success)
        {
            return Result_Type::Error;
        }
    }
    this->Wake_Up();
    if (this->Initialize() != Result_Type::Success)
    {
        return Result_Type::Error;
    }
    Set_Brightness(Default_Display_Brightness);
    Set_Standby_Time(Default_Display_Standby_Time);
    return Result_Type::Success;
};

Result_Type Display_Class::Stop()
{
    this->Sleep();
    return Save_Registry();
}


// -- Object's base class

uint16_t Display_Class::Get_Horizontal_Definition()
{
    return Display_Horizontal_Definition;
}

uint16_t Display_Class::Get_Vertical_Definition()
{
    return Display_Vertical_Definition;
}


void Display_Class::Set_Standby_Time(uint16_t Standby_Time)
{
    this->Standby_Time = Standby_Time;
}

uint16_t Display_Class::Get_Standby_Time()
{
    return Standby_Time;
}

///
/// @brief Load display registry
///
/// @return Xila_Class::Success or Xila_Class::Error
Result_Type Display_Class::Load_Registry()
{
    using namespace Xila;

    File_Type Temporary_File = Drive.Open(Registry("Display"));

    StaticJsonDocument<256> Display_Registry;
    if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.Close();
        Log_Error("Failed to load display registry.");
        return Result_Type::Error;
    }
    Temporary_File.Close();
    if (strcmp("Display", Display_Registry["Registry"] | "") != 0)
    {
        Log_Error("Failed to load display registry.");
        return Result_Type::Error;
    }
    Set_Standby_Time(Display_Registry["Standby Time"] | Default_Display_Standby_Time);
    Set_Brightness(Display_Registry["Brightness"] | Default_Display_Brightness);
    return Result_Type::Success;
}

/// @brief Save display registry
///
/// @return Result_Type
Result_Type Display_Class::Save_Registry()
{
    File_Type Temporary_File = Drive.Open(Registry("Display"), true);
    StaticJsonDocument<256> Display_Registry;
    
    if (!Temporary_File || deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok || strcmp("Display", Display_Registry["Registry"] | "") != 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    
    Display_Registry["Brightness"] = Brightness;
    Display_Registry["Standby Time"] = Standby_Time;

    if (serializeJson(Display_Registry, Temporary_File) == 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    return Result_Type::Success;
}

Result_Type Display_Class::Create_Registry()
{
    StaticJsonDocument<256> Display_Registry;
    Display_Registry["Registry"] = "Display";
    
    File_Type Temporary_File = Drive.Open(Registry("Display"), true);
    if (!Temporary_File || serializeJson(Display_Registry, Temporary_File) == 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    return Result_Type::Success;
}