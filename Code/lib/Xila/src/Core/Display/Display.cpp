///
/// @file Display.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

// -- Constructors

///
/// @brief Construct a new Xila_Class::Display_Class::Display_Class object
///
Display_Class::Display_Class()

{
}

///
/// @brief Destroy the Xila_Class::Display_Display_Class::Display_Class object
///
Display_Class::~Display_Class()
{
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
Module_Class::Result_Type Display_Class::Load_Registry()
{
    File Temporary_File = Xila.Drive.Open(Registry("Display"));
    DynamicJsonDocument Display_Registry(256);
    if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        Log_Error("Failed to load display registry.");
        return Error;
    }
    Temporary_File.close();
    if (strcmp("Display", Display_Registry["Registry"] | "") != 0)
    {
        Log_Error("Failed to load display registry.");
        return Error;
    }
    Set_Standby_Time(Display_Registry["Standby Time"] | Default_Display_Standby_Time);
    Set_Brightness(Display_Registry["Brightness"] | Default_Display_Brightness);
    return Success;
}

///
/// @brief Save display registry
///
/// @return Result_Type
Module_Class::Result_Type Display_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive.Open(Registry("Display"), FILE_WRITE);
    DynamicJsonDocument Display_Registry(256);
    Display_Registry["Registry"] = "Display";
    Display_Registry["Brightness"] = Brightness;
    Display_Registry["Standby Time"] = Standby_Time;
    if (serializeJson(Display_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        Log_Error("Failed to save display registry.");
        return Error;
    }
    Temporary_File.close();
    return Success;
}
