#include "Core/Core.hpp"

Xila_Class::System_Class::System_Class()
{
  State = Default;
  memset(Device_Name, '\0', sizeof(Device_Name));
}

Xila_Event Xila_Class::System_Class::Load_Registry()
{
  Verbose_Print_Line("> Load system registry");
  File Temporary_File = Xila.Drive.open(System_Registry_Path);

  DynamicJsonDocument System_Registry(512);
  if (deserializeJson(System_Registry, Temporary_File)) // error while deserialising
  {
    Temporary_File.close();
    return Error;
  }

  JsonObject Version = System_Registry["Version"];

  if (Version["Major"] != VERSION_MAJOR || Version["Minor"] != VERSION_MINOR || Version["Revision"] != VERSION_REVISION)
  {
    Panic_Handler(Installation_Conflict);
  }

  strlcpy(Xila.System.Device_Name, System_Registry["Device Name"], sizeof(Xila.System.Device_Name));

  Temporary_File.close();
  return Success;
}

inline uint32_t Xila_Class::System_Class::Get_Free_Heap()
{
  return ESP.getFreeHeap();
}

///
/// @brief
///
void Xila_Class::System_Class::Task(void *)
{
  uint32_t Last_Header_Refresh = 0;
  while (1)
  {

    Xila.Software.Check_Watchdog(); // check if current running software is not frozen
    Xila.Time.Synchronise(); // Time synchro
    
    if ((millis() - Last_Header_Refresh) > 10000) // Refresh header every ~10000 ms
    {
      if (Xila.System.Get_Free_Heap() < Low_Memory_Threshold)
      {
        Xila.System.Panic_Handler(Low_Memory);
      }

      Xila.System.Refresh_Header(); // Header refreshing
      Last_Header_Refresh = millis();

      if (Xila.Software.Openned_Software[0] == NULL)
      {
        Xila.Task.Delay(40);
        if (Xila.Software.Openned_Software[0] == NULL)
        {
          Xila.Software.Execute_Shell(Software_Class::Desk);
          Xila.Software.Maximize_Shell();
        }
      }
    }

    Xila.Power.Check_Button();
    Xila.Display.Loop();
    Xila.Task.Delay(10);
  }
}

///
/// @brief
///
/// @param Executable_File Executable file
/// @param Type Type ('M' for MCU or 'D' for Display)
/// @return Xila_Event
///
Xila_Event Xila_Class::System_Class::Load_Executable(File Executable_File, uint8_t Type)
{
  if (!Executable_File)
  {
    return Xila.Error;
  }
  if (Executable_File.isDirectory())
  {
    return Xila.Error;
  }
  if (Executable_File.size() == 0)
  {
    return Xila.Error;
  }
  if (Type == 'M')
  {
    if (!Update.begin(Executable_File.size(), U_FLASH))
    {
      return Xila.Error;
    }
    size_t Written = Update.writeStream(Executable_File);
    if (Written != Executable_File.size())
    {
      return Xila.Error;
    }
    if (!Update.end())
    {
      return Xila.Error;
    }
    if (!Update.isFinished())
    {
      return Xila.Error;
    }

    return Xila.Success;
  }
  else if (Type == 'D')
  {
    if (Xila.Display.Update(Executable_File) != Xila.Display.Update_Succeed)
    {
      return Xila.Error;
    }

    // -- Initialize display. -- //

    pinMode(DISPLAY_SWITCH_PIN, OUTPUT);
    digitalWrite(DISPLAY_SWITCH_PIN, HIGH);

    Xila.Display.Set_Callback_Function_Numeric_Data(&Xila.Display.Incomming_Numeric_Data_From_Display);
    Xila.Display.Set_Callback_Function_String_Data(&Xila.Display.Incomming_String_Data_From_Display);
    Xila.Display.Set_Callback_Function_Event(&Xila.Display.Incomming_Event_From_Display);
    Xila.Display.Begin();

    Xila.Display.Wake_Up();
    Xila.Display.Set_Current_Page(F("Core_Load")); // Play animation
    Xila.Display.Set_Trigger(F("LOAD_TIM"), true);

    return Xila.Success;
  }
  return Xila.Error;
}

/**
 * @enum Events
 * @brief All kinds of events returned by Core API.
 */
void Xila_Class::System_Class::Panic_Handler(Panic_Code Panic_Code)
{
  vTaskSuspendAll();
  Xila.Display.Set_Current_Page(F("Core_Panic"));
  char Temporary_String[23];
  sprintf(Temporary_String, "Error code %X", Panic_Code);

  Xila.Display.Set_Text(F("ERRORCODE_TXT"), Temporary_String);
  while (digitalRead(POWER_BUTTON_PIN) == HIGH)
  {
  }
  ESP.restart();
}

Xila_Event Xila_Class::System_Class::Save_Registry()
{
  File Temporary_File = Xila.Drive.open(System_Registry_Path, FILE_WRITE);
  DynamicJsonDocument System_Registry(256);
  System_Registry["Device Name"] = Device_Name;
  if (serializeJson(System_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }

  Temporary_File.close();
  return Success;
}

uint32_t inline Xila_Class::System_Class::Random()
{
  return esp_random();
}

uint32_t Xila_Class::System_Class::Random(uint32_t Upper_Bound)
{
  uint32_t x = esp_random();
  uint64_t m = uint64_t(x) * uint64_t(Upper_Bound);
  uint32_t l = uint32_t(m);
  if (l < Upper_Bound)
  {
    uint32_t t = -Upper_Bound;
    if (t >= Upper_Bound)
    {
      t -= Upper_Bound;
      if (t >= Upper_Bound)
        t %= Upper_Bound;
    }
    while (l < t)
    {
      x = esp_random();
      m = uint64_t(x) * uint64_t(Upper_Bound);
      l = uint32_t(m);
    }
  }
  return m >> 32;
}

uint32_t Xila_Class::System_Class::Random(uint32_t Lower_Bound, uint32_t Upper_Bound)
{
  if (Lower_Bound >= Upper_Bound)
  {
    return Lower_Bound;
  }
  long diff = Upper_Bound - Lower_Bound;
  return Random(diff) + Lower_Bound;
}

Xila_Event Xila_Class::System_Class::Create_Dump()
{
  Xila.Software.Minimize(*Xila.Software.Openned_Software[0]->Handle_Pointer);

  File Dump_File = Xila.Drive.open(Dump_Registry_Path, FILE_WRITE);

  if (!Dump_File)
  {
    return Error;
  }

  Dump_File.seek(0 * 24);

  Dump_File.write((uint8_t *)Xila.Software.Openned_Software[2]->Handle_Pointer->Name, sizeof(Xila.Software.Openned_Software[2]->Handle_Pointer->Name));
  Dump_File.seek(1 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned_Software[3]->Handle_Pointer->Name, sizeof(Xila.Software.Openned_Software[3]->Handle_Pointer->Name));
  Dump_File.seek(2 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned_Software[4]->Handle_Pointer->Name, sizeof(Xila.Software.Openned_Software[4]->Handle_Pointer->Name));
  Dump_File.seek(3 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned_Software[5]->Handle_Pointer->Name, sizeof(Xila.Software.Openned_Software[5]->Handle_Pointer->Name));
  Dump_File.seek(4 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned_Software[6]->Handle_Pointer->Name, sizeof(Xila.Software.Openned_Software[6]->Handle_Pointer->Name));
  Dump_File.seek(5 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned_Software[7]->Handle_Pointer->Name, sizeof(Xila.Software.Openned_Software[7]->Handle_Pointer->Name));
  Dump_File.seek(6 * 24);
  Dump_File.write((uint8_t *)Xila.Account.Current_Username, sizeof(Xila.Account.Current_Username));
  Dump_File.close();

  Xila_Task_Handle Temporary_Task_Handle;
  for (uint8_t i = 1; i < 8; i++)
  {
    if (Openned_Software[i] != NULL)
    {
      Temporary_Task_Handle = Openned_Software[i]->Task_Handle;
      Openned_Software[i]->Send_Instruction(Hibernating);
      Xila.Task.Resume(Temporary_Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t ii = 0; ii <= 200; ii++)
      {
        if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
        {
          break;
        }
        Xila.Task.Delay(20);
      }
    }
  }

  return Success;
}

Xila_Event Xila_Class::System_Class::Load_Dump()
{
  if (Xila.Drive.exists(Dump_Registry_Path))
  {
    File Dump_File = Xila.Drive.open(Dump_Registry_Path);
    char Temporary_Software_Name[24];
    for (uint8_t i = 0; i < 7; i++)
    {
      Dump_File.seek(i * 24);
      Dump_File.readBytes(Temporary_Software_Name, sizeof(Temporary_Software_Name));
      for (uint8_t ii = 0; ii < (sizeof(Xila.Software.Software_Handle_Pointer) / sizeof(Xila.Software.Software_Handle_Pointer[0])); ii++)
      {
        if (strcmp(Xila.Software.Software_Handle_Pointer[ii]->Name, Temporary_Software_Name) == 0)
        {
          Xila.Software.Open(*Xila.Software.Software_Handle_Pointer[ii]);
        }
      }
    }

    Dump_File.seek(6 * 24);
    Dump_File.readBytes(Xila.Account.Current_Username, sizeof(Xila.Account.Current_Username));
    return Success;
  }
  else
  {
    return Error;
  }
}

const char *Xila_Class::System_Class::Get_Device_Name()
{
  return Xila.System.Device_Name;
}

void Xila_Class::System_Class::Refresh_Header()
{

  static char Temporary_Char_Array[6];

  // -- Update clock
  Temporary_Char_Array[0] = Xila.Time.Current_Time.tm_hour / 10;
  Temporary_Char_Array[0] += 48;
  Temporary_Char_Array[1] = Xila.Time.Current_Time.tm_hour % 10;
  Temporary_Char_Array[1] += 48;
  Temporary_Char_Array[2] = ':';
  Temporary_Char_Array[3] = Xila.Time.Current_Time.tm_min / 10;
  Temporary_Char_Array[3] += 48;
  Temporary_Char_Array[4] = Xila.Time.Current_Time.tm_min % 10;
  Temporary_Char_Array[4] += 48;
  Temporary_Char_Array[5] = '\0';

  Xila.Display.Set_Text(F("CLOCK_TXT"), Temporary_Char_Array);

  // Update connexion
  Temporary_Char_Array[5] = Xila.WiFi.RSSI();

  if (Xila.WiFi.status() == WL_CONNECTED)
  {
    if (Temporary_Char_Array[5] <= -70)
    {
      Xila.Display.Set_Text(F("CONNEXION_BUT"), Xila.Display.WiFi_Low);
    }
    if (Temporary_Char_Array[0] <= -50 && Temporary_Char_Array[0] > -70)
    {
      Xila.Display.Set_Text(F("CONNEXION_BUT"), Xila.Display.WiFi_Medium);
    }
    else
    {
      Xila.Display.Set_Text(F("CONNEXION_BUT"), Xila.Display.WiFi_High);
    }
  }
  else
  {
    Xila.Display.Set_Text(F("CONNEXION_BUT"), ' ');
  }

  // -- Update charge level
  Temporary_Char_Array[5] = Xila.Power.Get_Charge_Level();

  if (Temporary_Char_Array[5] <= 15)
  {
#if BATTERY_CHECKING == 1
    if (Temporary_Char_Array[5] <= 2)
    {
      Shutdown();
    }
#endif
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Empty);
  }
  else if (Temporary_Char_Array[5] <= 30 && Temporary_Char_Array[5] > 15)
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Low);
  }
  else if (Temporary_Char_Array[5] <= 70 && Temporary_Char_Array[5] > 30)
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Medium);
  }
  else // more than 70 %
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_High);
  }

  // -- Update sound
  Temporary_Char_Array[5] = Xila.Sound.Get_Volume();

  if (Temporary_Char_Array[5] == 0)
  {
    Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_Mute);
  }
  else if (Temporary_Char_Array[5] < 86)
  {
    Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_Low);
  }
  else if (Temporary_Char_Array[5] < 172)
  {
    Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_Medium);
  }
  else
  {
    Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_High);
  }
}
