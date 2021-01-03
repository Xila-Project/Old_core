#include "Core/Core.hpp"

Xila_Event Xila_Class::Load_Regionnal_Registry()
{
  Verbose_Print_Line("> Load regional registry ...");
  File Temporary_File = Drive->open(Regional_Registry_Path);
  if (!Temporary_File)
  {
    return Error
  }

  DynamicJsonDocument Regional_Registry(256);
  deserializeJson(Regional_Registry, Temporary_File);

  strcpy(NTP_Server, Regional_Registry["Time"]["NTP Server"]);

  int32_t GMT_Offset = Regional_Registry["Time"]["GMT Offset"];
  int16_t Daylight_Offset = Regional_Registry["Time"]["Daylight Offset"];

  Serial.println(NTP_Server);
  Serial.println(GMT_Offset);
  Serial.println(Daylight_Offset);

  configTime(GMT_Offset, Daylight_Offset, NTP_Server);
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Load_System_Registry()
{
  Verbose_Print_Line("> Load system registry");
  File Temporary_File = Drive->open(System_Registry_Path);
  if (!Temporary_File)
  {
    return Error;
  }
  DynamicJsonDocument System_Registry(512);
  if (deserializeJson(System_Registry, Temporary_File)) // error while deserialising
  {
    return Error;
  }

  JsonObject Version = System_Registry["Version"];

  if (Version["Major"] != VERSION_MAJOR || Version["Minor"] != VERSION_MINOR || Version["Revision"] != VERSION_REVISION)
  {
    return 2;
  }

  if (System_Registry["State"] != 0)
  {
    return 3;
  }

  strlcpy(Device_Name, System_Registry["Davice Name"], sizeof(Device_Name));

  Temporary_File.close();
}

Xila_Event Xila_Class::Load_Display_Registry()
{
  Verbose_Print_Line("> Load display registry ...");
  File Temporary_File = Drive->open(Display_Registry_Path);
  DynamicJsonDocument Display_Registry(256);
  if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return Error;
  }
  Display.Set_Brightness(Display_Registry["Brightness"]);
  Temporary_File.close();
  return Success
}

Xila_Event Xila_Class::Load_Sound_Registry()
{
  File Temporary_File = Drive->open(Sound_Registry_Path);
  DynamicJsonDocument Sound_Registry(256);
  if (deserializeJson(Sound_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return Error;
  }
  Sound.Set_Volume(Sound_Registry["Volume"]);
  Temporary_File.close();
  return Success
}

Xila_Event Xila_Class::Load_Regionnal_Registry()
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Regional_Registry(256);
  if (deserializeJson(Regional_Registry, Temporary_File) != DeserializationError::Ok)
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

Xila_Event Xila_Class::Set_Regionnal_Registry(const char *NTP_Server, int32_t GMT_Offset, int16_t Daylight_Offset)
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Regional_Registry(256);
  if (deserializeJson(Regional_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  JsonObject Time = Regional_Registry["Time"];
  if (GMT_Offset != 0xFFFFFFFF)
  {
    Time["GMT Offset"] = GMT_Offset;
  }
  if (Daylight_Offset != 0xFFFF)
  {
    Time["Daylight Offset"] = Daylight_Offset;
  }
  if (NTP_Server != NULL)
  {
    Time["NTP Server"] = NTP_Server;
    strlcpy(this->NTP_Server, NTP_Server, sizeof(this->NTP_Server));
  }
  configTime(GMT_Offset, Daylight_Offset, NTP_Server);
  if (serializeJson(Regional_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Load_Account_Registry()
{
  File Temporary_File = Drive->open(Account_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Account_Registry(256);
  if (deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  strlcpy(Current_Username, Account_Registry["Autologin"], sizeof(Current_Username));
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Set_Account_Registry(const char *Autologin_Account)
{
  if (Autologin_Account == NULL)
  {
    return Success;
  }
  File Temporary_File = Drive->open(Account_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Account_Registry(256);
  if (deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  Account_Registry["Autologin"] = Autologin_Account;
  serializeJson(Account_Registry, Temporary_File);
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Set_Display_Registry(uint8_t Brighness, uint16_t Standby_Time, uint8_t Receive_Pin, uint8_t Send_Pin)
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Display_Registry(256);
  if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  if (Brighness != 0xFF)
  {
    Display_Registry["Brightness"] = Brighness;
    Display.Set_Brightness(Brighness);
  }
  if (Receive_Pin != 0xFF)
  {
    Display_Registry["Receive Pin"] = Receive_Pin;
  }
  if (Send_Pin != 0xFF)
  {
    Display_Registry["Send Pin"] = Send_Pin;
  }
  if (Standby_Time != 0xFFFF)
  {
    Display_Registry["Standby Time"] = Standby_Time;
    Display_Standby_Time = Standby_Time;
  }
  if (serializeJson(Display_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  return Success;
}
