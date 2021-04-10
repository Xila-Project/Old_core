#include "Core/Core.hpp"



Xila_Class::Time_Class::Time_Class()
    : GMT_Offset(0),
      Daylight_Offset(0)
{
  strcpy(NTP_Server, "pool.ntp.org");
}

Xila_Class::Event Xila_Class::Time_Class::Save_Registry()
{
  File Temporary_File = Xila.Drive.Open(Registry("Time"), FILE_WRITE);
  DynamicJsonDocument Time_Registry(512);
  Time_Registry["GMT Offset"] = GMT_Offset;
  Time_Registry["Daylight Offset"] = Daylight_Offset;
  Time_Registry["NTP Server"] = NTP_Server;
  configTime(GMT_Offset, Daylight_Offset, NTP_Server);
  if (serializeJson(Time_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  return Success;
}

Xila_Class::Event Xila_Class::Time_Class::Load_Registry()
{
  File Temporary_File = Xila.Drive.Open(Registry("Time"));
  DynamicJsonDocument Time_Registry(512);
  if (deserializeJson(Time_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  GMT_Offset = Time_Registry["GMT Offset"];
  Daylight_Offset = Time_Registry["Daylight Offset"];
  strlcpy(NTP_Server, Time_Registry["NTP Server"], sizeof(NTP_Server));

  configTime(GMT_Offset, Daylight_Offset, NTP_Server);
  Temporary_File.close();
  return Success;
}

void Xila_Class::Time_Class::Synchronise()
{
  time(&Now);
  localtime_r(&Now, &Current_Time);
}

Xila_Time Xila_Class::Time_Class::Get_Time()
{
  Synchronise();
  return Current_Time;
}