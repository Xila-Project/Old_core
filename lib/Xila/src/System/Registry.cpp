 /// @file Registry.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 19-03-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#include "System/System.hpp"
#include "Drive/Drive.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::System_Types;

Result_Type System_Class::Create_Registry()
{
  Drive_Types::File_Type Temporary_File = Drive.Open(Registry("System"), true);
  StaticJsonDocument<512> System_Registry;
  System_Registry["Registry"] = "System";
  System_Registry["Version"]["Major"] = Xila_Version_Major;
  System_Registry["Version"]["Minor"] = Xila_Version_Minor;
  System_Registry["Version"]["Revision"] = Xila_Version_Revision;

  if (serializeJson(System_Registry, Temporary_File) == 0)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }

  Temporary_File.Close();
  return Result_Type::Success;
}

/// @brief Load System registry.
///
/// @return Result_Type
Result_Type System_Class::Load_Registry()
{
  Log_Information("System", "Load system registry...");
  Drive_Types::File_Type Temporary_File = Drive.Open((Registry("System")));
  StaticJsonDocument<1024> System_Registry;
  if (deserializeJson(System_Registry, Temporary_File)) // error while deserialising
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  if (strcmp("System", System_Registry["Registry"] | "") != 0)
  {
    return Result_Type::Error;
  }

  {
    JsonObject Version = System_Registry["Version"];

    if (Version["Major"] != Xila_Version_Major || Version["Minor"] != Xila_Version_Minor || Version["Revision"] != Xila_Version_Revision)
    {
      return Result_Type::Error;
    }
  }

  this->Device_Name = System_Registry["Device Name"] | static_cast<const char*>(this->Device_Name);

  return Result_Type::Success;
}

///
/// @brief Save System registry.
///
/// @return Result_Type
Result_Type System_Class::Save_Registry()
{
  // - Open current registry
  Drive_Types::File_Type Temporary_File = Drive.Open(Registry("System"), true);
  StaticJsonDocument<512> System_Registry;

  System_Registry["Device name"] = Device_Name;

  {
    JsonObject Version = System_Registry.createNestedObject("Version");
    Version["Major"] = Xila_Version_Major;
    Version["Minor"] = Xila_Version_Minor;
    Version["Revision"] = Xila_Version_Revision;
  }

  {
    JsonObject Time = System_Registry.createNestedObject("Time");
    Time["UTC Offset"] = this->UTC_Offset;
    Time["Daylight Offset"] = this->Daylight_Offset;
    Time["NTP Server"] = static_cast<const char*>(this->NTP_Server);
  }

  // - Serialise
  if (serializeJson(System_Registry, Temporary_File) == 0)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  return Result_Type::Success;
}
