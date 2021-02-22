#include "Core/Core.hpp"

Xila_Event Xila_Class::WiFi_Connect()
{
  Verbose_Print_Line("WiFi connect");

  if (WiFi.status() == WL_CONNECTED)
  {
    return Success;
  }
  File Temporary_File = Drive->open(Network_Registry_Path);

  DynamicJsonDocument Network_Registry(512);

  if (deserializeJson(Network_Registry, Temporary_File) != DeserializationError::Ok)
  {
    
    return Error;
  }

  JsonObject WiFi_Registry = Network_Registry["WiFi"];

  char Name[33];
  char Password[81];

  strlcpy(Name, WiFi_Registry["Name"] | "\0", sizeof(Name));
  strlcpy(Password, WiFi_Registry["Password"] | "\0", sizeof(Password));
  
  Verbose_Print_Line(Name);
  Verbose_Print_Line(Password);

  WiFi.setAutoConnect(false);
  WiFi.begin(Name, Password);
  for (uint8_t i = 0; i <= 50; i++)
  {
    if (i == 50)
    {
      return Error;
    }
    else if (WiFi.status() == WL_CONNECTED)
    {
      break;
    }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::WiFi_Connect(char *Name, char *Password)
{
  WiFi.setAutoConnect(false);
  WiFi.begin(Name, Password);
  for (uint8_t i = 0; i <= 50; i++)
  {
    if (i == 50)
    {
      return Error;
    }
    else if (WiFi.status() == WL_CONNECTED)
    {
      break;
    }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
  File Temporary_File = Drive->open(Network_Registry_Path);
  if (!Temporary_File)
  {
    return Error;
  }
  DynamicJsonDocument Network_Registry(512);
  deserializeJson(Network_Registry, Temporary_File);
  JsonObject WiFi = Network_Registry["WiFi"];
  WiFi["Name"] = Name;
  WiFi["Password"] = Password;
  serializeJson(Network_Registry, Temporary_File);
  Temporary_File.close();
  return Success;
}


Xila_Event Xila_Class::Load_Network_Registry()
{
  // Currently network is handled by wifi connect ()
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

  strlcpy(Device_Name, System_Registry["Device Name"], sizeof(Device_Name));
  Temporary_File.close();

  return Success;
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
  return Success;
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
  return Success;
}

Xila_Event Xila_Class::Load_Time_Registry()
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

Xila_Event Xila_Class::Load_Keyboard_Registry()
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Regional_Registry(256);
  if (deserializeJson(Regional_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  JsonObject Keyboard_Registry = Regional_Registry["Keyboard"];
  Keyboard_Data_Pin = Keyboard_Registry["Data_Pin"];
  Keyboard_Interrupt_Pin = Keyboard_Registry["Interrupt_Pin"];
  Keyboard_Keymap = Keyboard_Registry["Keymap"];
  switch (Keyboard_Keymap)
  {
  case 'G':
    Keyboard.begin(Keyboard_Data_Pin, Keyboard_Interrupt_Pin, Keyboard.Keymap_German);
    break;
  case 'F':
    Keyboard.begin(Keyboard_Data_Pin, Keyboard_Interrupt_Pin, Keyboard.Keymap_French);
    break;
  case 'S':
    Keyboard.begin(Keyboard_Data_Pin, Keyboard_Interrupt_Pin, Keyboard.Keymap_Spanish);
    break;
  case 'I':
    Keyboard.begin(Keyboard_Data_Pin, Keyboard_Interrupt_Pin, Keyboard.Keymap_Italian);
    break;
  case 'u':
    Keyboard.begin(Keyboard_Data_Pin, Keyboard_Interrupt_Pin, Keyboard.Keymap_UK);
    break;
  default: //U or other
    Keyboard.begin(Keyboard_Data_Pin, Keyboard_Interrupt_Pin);
    break;
  }
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Set_System_Registry(const char *Device_Name)
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument System_Registry(256);
  if (deserializeJson(System_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  if (Device_Name != NULL)
  {
    System_Registry["Device Name"] = Device_Name;
    strlcpy(this->Device_Name, Device_Name, sizeof(this->Device_Name));
  }

  if (serializeJson(System_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Set_Sound_Registry(uint8_t Volume)
{
  File Temporary_File = Drive->open(Sound_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Sound_Registry(256);
  if (deserializeJson(Sound_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  Sound_Registry["Volume"] = Volume;
  if (serializeJson(Sound_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  return Success;
}

Xila_Event Xila_Class::Set_Time_Registry(const char *NTP_Server, int32_t GMT_Offset, int16_t Daylight_Offset)
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

Xila_Event Xila_Class::Set_Keyboard_Registry(uint8_t Data_Pin, uint8_t Interrupt_Pin, uint8_t Keymap)
{
  File Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  DynamicJsonDocument Regional_Registry(256);
  if (deserializeJson(Regional_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  JsonObject Keyboard_Registry = Regional_Registry["Keyboard"];
  if (Data_Pin != 0xFF)
  {
    Keyboard_Data_Pin = Data_Pin;
    Keyboard_Registry["Data Pin"] = Data_Pin;
  }
  if (Interrupt_Pin != 0xFF)
  {
    Keyboard_Interrupt_Pin = Interrupt_Pin;
    Keyboard_Registry["Interrupt Pin"] = Interrupt_Pin;
  }
  if (Keymap != 0xFF)
  {
    Keyboard_Registry["Keymap"] = Keymap;
    Keyboard_Keymap = Keymap;
  }

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
    Standby_Display_Time = Standby_Time;
  }
  if (serializeJson(Display_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  return Success;
}
