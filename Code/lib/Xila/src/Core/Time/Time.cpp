///
 /// @file Time.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 11-07-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#include "Core/Core.hpp"

using namespace Xila_Namespace;

Time_Type Time();

///
 /// @brief Construct a new Time_Class::Time_Class object
 /// 
Time_Class::Time_Class()
    : GMT_Offset(Default_GMT_Offset),
      Daylight_Offset(Default_Daylight_Offset)
{
  strlcpy(NTP_Server, Default_NTP_Server, sizeof(NTP_Server));
}

///
 /// @brief Return cycle count since the system startup.
 /// 
 /// @return uint32_t Cycle count.
uint32_t IRAM_ATTR Time_Class::Get_Cycle_Count()
{
  uint32_t ccount;
  __asm__ __volatile__("esync; rsr %0,ccount"
                       : "=a"(ccount));
  return ccount;
}

///
 /// @brief Save time registry.
 /// 
 /// @return Result_Type 
Module_Class::Result_Type Time_Class::Save_Registry()
{
  File Temporary_File = Drive.Open(Registry("Time"), FILE_WRITE);
  DynamicJsonDocument Time_Registry(512);
  Time_Registry["Registry"] = "Time";
  Time_Registry["GMT Offset"] = GMT_Offset;
  Time_Registry["Daylight Offset"] = Daylight_Offset;
  Time_Registry["NTP Server"] = NTP_Server;
  configTime(GMT_Offset, Daylight_Offset, NTP_Server);
  if (serializeJson(Time_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result_Type::Error;
  }
  Temporary_File.close();
  return Result_Type::Success;
}

///
 /// @brief Load time registry.
 /// 
 /// @return Result_Type 
Module_Class::Result_Type Time_Class::Load_Registry()
{
  File Temporary_File = Drive.Open(Registry("Time"));
  DynamicJsonDocument Time_Registry(512);
  if (deserializeJson(Time_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Result_Type::Error;
  }
  Temporary_File.close();
  if (strcmp("Time", Time_Registry["Registry"] | "") != 0)
  {
    return Result_Type::Error;
  }
  GMT_Offset = Time_Registry["GMT Offset"] | Default_GMT_Offset;
  Daylight_Offset = Time_Registry["Daylight Offset"] | Default_Daylight_Offset;
  strlcpy(NTP_Server, Time_Registry["NTP Server"] | Stringizing(Default_NTP_Server), sizeof(NTP_Server));
  configTime(GMT_Offset, Daylight_Offset, NTP_Server);
  return Result_Type::Success;
}

///
 /// @brief Synchronize time.
 /// 
void Time_Class::Synchronize()
{
  time(&Now);
  localtime_r(&Now, &Current_Time);
}

///
 /// @brief Return current time.
 /// 
 /// @return tm Time structure.
tm Time_Class::Get_Time()
{
  Synchronize();
  return Current_Time;
}

uint32_t Time_Class::Milliseconds() const
{
  return (uint32_t)(esp_timer_get_time() / 1000ULL);
}

int64_t Time_Class::Microseconds() const
{
  return esp_timer_get_time();
}