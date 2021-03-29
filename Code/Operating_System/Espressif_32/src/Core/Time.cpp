#include "Core/Core.hpp"

Xila_Event Xila_Class::Time_Class::Save_Registry()
{
  File Temporary_File = Xila.Drive.open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Regional_Registry(512);
  JsonObject Time = Regional_Registry["Time"];
  Time["GMT Offset"] = GMT_Offset;
  Time["Daylight Offset"] = Daylight_Offset;
  Time["NTP Server"] = NTP_Server;
  configTime(GMT_Offset, Daylight_Offset, NTP_Server);
  if (serializeJson(Regional_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Xila.Error;
  }
  Temporary_File.close();
  return Xila.Success;
}

Xila_Event Xila_Class::Time_Class::Load_Registry()
{

  File Temporary_File = Xila.Drive.open(Regional_Registry_Path);
  DynamicJsonDocument Regional_Registry(512);
  if (deserializeJson(Regional_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  if (strcmp("Regional", Regional_Registry["Registry"]) != 0)
  {
    Temporary_File.close();
    return Error;
  }
  JsonObject Time = Regional_Registry["Time"];
  GMT_Offset = Time["GMT Offset"];
  Daylight_Offset = Time["Daylight Offset"];
  strlcpy(NTP_Server, Time["NTP Server"], sizeof(NTP_Server));
  
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