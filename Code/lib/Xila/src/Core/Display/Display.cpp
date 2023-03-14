///
/// @file Display.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Default_Display_Brightness
    #define Default_Display_Brightness 100
#endif
#ifndef Default_Display_Standby_Time
    #define Default_Display_Standby_Time 30000
#endif

#include "Core/Display/Display.hpp"
#include "Core/Drive/Drive.hpp"
#include "Core/System/System.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;

Display_Type Xila_Namespace::Display;

// - Methods

Result_Type Display_Class::Start()
{
    Log_Information("Display", "Start display module...");
    // - Define default values
    this->Brightness = Default_Display_Brightness;
    this->Standby_Time = Default_Display_Standby_Time;

    // - Load registry
    if (this->Load_Registry() != Result_Type::Success)
    {
        // - If the registry doesn't exist, create it.
        if(this->Create_Registry() != Result_Type::Success)
        {
            return Result_Type::Error;
        }
    }

    // - Initialize display
    if (this->Initialize() != Result_Type::Success)
    {
        return Result_Type::Error;
    }
    this->Wake_Up();

    // - Apply values.
    this->Set_Brightness(this->Get_Brightness());
    this->Set_Standby_Time(this->Get_Standby_Time());

    return Result_Type::Success;
};

Result_Type Display_Class::Stop()
{
    this->Sleep();
    return Save_Registry();
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
    File_Type Temporary_File = Drive.Open(Registry("Display"));

    StaticJsonDocument<256> Display_Registry;
    if (!Temporary_File || deserializeJson(Display_Registry, Temporary_File) || strcmp("Display", Display_Registry["Registry"] | "") != 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();

    Set_Standby_Time(Display_Registry["Standby time"] | Get_Standby_Time());
    Set_Brightness(Display_Registry["Brightness"] | Get_Brightness());

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
    Display_Registry["Standby time"] = Standby_Time;

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