#include "Core/Core.hpp"

Xila_Event Xila_Class::Set_Regionnal_Registry(const char *NTP_Server, int32_t GMT_Offset, int16_t Dayligh_Offset)
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Regional_Registry(256);
  if (deserializeJson(Regional_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return Error;
  }
  JsonObject Time = Regional_Registry["Time"];
  if (GMT_Offset != 0xFFFFFFFF)
  {
    Time["GMT Offset"] = GMT_Offset;
  }
  if (Dayligh_Offset != 0xFFFF)
  {
    Time["Time"]["Daylight Offset"] = Dayligh_Offset;
  }
  if (NTP_Server != NULL)
  {
    Time["NTP Server"] = NTP_Server;
  }
  serializeJson(Regional_Registry, Temporary_File);
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Set_Account_Registry(const char *Autologin_Account)
{
  if (Autologin_Account == NULL)
  {
    return Xila.Success;
  }
  File Temporary_File = Drive->open(Account_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Account_Registry(256);
  if (deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return Error;
  }
  Account_Registry["Autologin"] = Autologin_Account;
  serializeJson(Account_Registry, Temporary_File);
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Set_Display_Registry(uint8_t Brighness, , uint8_t Receive_Pin, uint8_t Send_Pin)
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Display_Registry(256);
  if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
  {
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
  serializeJson(Display_Registry, Temporary_File);
  Temporary_File.close();
  return Success;
}
