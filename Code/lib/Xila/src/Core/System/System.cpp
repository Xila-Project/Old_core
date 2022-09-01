///
/// @file System.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/System/System.hpp"

#include "Core/Core.hpp"

#include "soc/rtc_wdt.h"
#include "esp_task_wdt.h"
#include "Update.h"

using namespace Xila;

///
/// @brief Construct a new System_Class object
///
System_Class::System_Class()
{
  Task_Handle = NULL;
  strlcpy(Device_Name, Default_Device_Name, sizeof(Device_Name));
}

///
/// @brief Destroy the System_Class object
///
System_Class::~System_Class()
{
}

///
/// @brief Load System registry.
///
/// @return Result::Type
Module_Class::Result::Type System_Class::Load_Registry()
{
  File Temporary_File = Drive.Open((Registry("System")));
  DynamicJsonDocument System_Registry(512);
  if (deserializeJson(System_Registry, Temporary_File)) // error while deserialising
  {
    Temporary_File.close();
    return Result::Error;
  }
  Temporary_File.close();
  if (strcmp("System", System_Registry["Registry"] | "") != 0)
  {
    return Result::Error;
  }
  JsonObject Version = System_Registry["Version"];
  if (Version["Major"] != Xila_Version_Major || Version["Minor"] != Xila_Version_Minor || Version["Revision"] != Xila_Version_Revision)
  {
    Panic_Handler(Installation_Conflict);
  }
  strlcpy(System.Device_Name, System_Registry["Device Name"] | Default_Device_Name, sizeof(System.Device_Name));
  return Result::Success;
}

///
/// @brief Save System registry.
///
/// @return Result::Type
Module_Class::Result::Type System_Class::Save_Registry()
{
  File Temporary_File = Drive.Open((Registry("System")), FILE_WRITE);
  DynamicJsonDocument System_Registry(256);
  System_Registry["Registry"] = "System";
  System_Registry["Device Name"] = Device_Name;
  JsonObject Version = System_Registry.createNestedObject("Version");
  Version["Major"] = Xila_Version_Major;
  Version["Minor"] = Xila_Version_Minor;
  Version["Revision"] = Xila_Version_Revision;
  if (serializeJson(System_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result::Error;
  }
  Temporary_File.close();
  return Result::Success;
}

void System_Class::Task_Start_Function(void *Instance)
{
  Instance_Pointer
}

///
/// @brief System task.
///
void System_Class::Task_Function(void *)
{
  uint32_t Next_Refresh = 0;
  Power.Button_Counter = 0;
  while (1)
  {
    // -- Check power button interrupt
    Power.Check_Button();
    // -- Task to refresh every 10 seconds
    if (Time.Milliseconds() > Next_Refresh)
    {
      if (Dialog_Save_File)
        // -- Check if drive is not disconnected.
        if (!Drive.Exists(Xila_Directory_Path) || !Drive.Exists(Software_Directory_Path))
        {
          System.Panic_Handler(System.System_Drive_Failure);
        }
      // -- Check if running software is not frozen
      Software_Management.Check_Watchdog();
      // -- Check WiFi is connected
      if (WiFi.status() != WL_CONNECTED)
      {
        WiFi.Load_Registry();
      }
      // -- Check available (prevent memory overflow)
      if (Memory.Get_Free_Heap() < Low_Memory_Threshold)
      {
        System.Panic_Handler(Low_Memory);
      }
      // -- Syncronise time
      Time.Synchronize();
      // -- Check if software is currently maximized
      if (Software_Management.Openned[0] == NULL)
      {
        Task_Class::Delay(100);
        // -- If no software is currently maximized, maximize shell.
        if (Software_Management.Openned[0] == NULL)
        {
          Software_Management.Open(Shell_Handle);
          Software_Management.Shell_Send_Instruction(Desk);
          Software_Management.Shell_Maximize();
        }
      }
      // -- Clear the refresh timer.
      Next_Refresh = Time.Milliseconds() + 10000;
    }
    Task_Class::Delay(20);
  }
}

///
/// @brief Update Xila on the MCU.
///
/// @param Update_File Executable file.
/// @return Result::Type
Module_Class::Result::Type System_Class::Load_Executable(File Executable_File)
{
  if (!Executable_File || Executable_File.isDirectory())
  {
    return Result::Error;
  }
  if (Executable_File.size() == 0)
  {
    return Result::Error;
  }
  if (!Update.begin(Executable_File.size(), U_FLASH))
  {
    return Result::Error;
  }
  size_t Written = Update.writeStream(Executable_File);
  if (Written != Executable_File.size())
  {
    return Result::Error;
  }
  if (!Update.end())
  {
    return Result::Error;
  }
  if (!Update.isFinished())
  {
    return Result::Error;
  }

  return Result::Success;
}

///
/// @brief Handle fatal events that the system cannot recover from.
///
/// @param Panic_Code Panic code to handle.
void System_Class::Panic_Handler(Panic_Code Panic_Code)
{
  Log_Error("Panic handler triggered, error code : %X.", Panic_Code);
  Display.Set_Current_Page(F("Core_Panic"));
  char Temporary_String[32];
  snprintf(Temporary_String, sizeof(Temporary_String), "Error code : %X", Panic_Code);
  Display.Set_Text(F("ERRORCODE_TXT"), Temporary_String);
  vTaskSuspendAll();
  uint32_t Delay_Time = Time.Milliseconds();
  while ((Time.Milliseconds() - Delay_Time) < 5000)
  {
  }
  abort();
}

///
/// @brief Save system dump.
///
/// @return Result::Type
Module_Class::Result::Type System_Class::Save_Dump()
{

  DynamicJsonDocument Dump_Registry(Default_Registry_Size);

  JsonArray Software = Dump_Registry.createNestedArray("Software");

  Dump_Registry["Registry"] = "Dump";

  for (uint8_t i = 2; i <= 7; i++)
  {
    if (Software_Management.Openned[i] != NULL)
    {
      Software.add(Software_Management.Openned[i]->Handle->Name);
    }
  }

  Dump_Registry["User"] = Account.Get_Current_Username();

  File Dump_File = Drive.Open(Dump_Registry_Path, FILE_WRITE);
  if (serializeJson(Dump_Registry, Dump_File) == 0)
  {
    Dump_File.close();
    return Result::Error;
  }
  Dump_File.close();
  return Result::Success;
}

///
/// @brief Load system dump.
///
/// @return Result::Type
Module_Class::Result::Type System_Class::Load_Dump()
{
  if (Drive.Exists(Dump_Registry_Path))
  {
    File Dump_File = Drive.Open((Dump_Registry_Path));
    DynamicJsonDocument Dump_Registry(Default_Registry_Size);

    if (deserializeJson(Dump_Registry, Dump_File) != DeserializationError::Ok)
    {
      Dump_File.close();
      Drive.Remove(Dump_Registry_Path);
      return Result::Error;
    }
    Dump_File.close();
    Drive.Remove(Dump_Registry_Path);

    if (strcmp(Dump_Registry["Registry"] | "", "Dump") != 0)
    {
      return Result::Error;
    }

    char Temporary_Software_Name[Default_Software_Name_Length];

    JsonArray Software = Dump_Registry["Software"];

    for (uint8_t i = 0; i < 6; i++)
    {
      memset(Temporary_Software_Name, '\0', sizeof(Temporary_Software_Name));
      strlcpy(Temporary_Software_Name, Software[i] | "", sizeof(Temporary_Software_Name));
      for (uint8_t j = 0; j < Maximum_Software; j++)
      {
        if (Software_Management.Handle[j] != NULL)
        {
          if (strcmp(Software_Management.Handle[j]->Name, Temporary_Software_Name) == 0)
          {
            Software_Management.Open(*Software_Management.Handle[j]);
          }
        }
      }
    }

    strlcpy(Account.Current_Username, Dump_Registry["User"] | "", sizeof(Account.Current_Username));
    if (Account.Current_Username[0] != '\0')
    {
      Account.Set_State(Account.Locked);
    }

    return Result::Success;
  }
  else
  {
    return Result::Error;
  }
}

///
/// @brief Return device name.
///
/// @return const char* Device name.
const char *System_Class::Get_Device_Name()
{
  return System.Device_Name;
}

///
/// @brief Refresh top header.
///
void System_Class::Refresh_Header()
{
  if (Display.Get_State() == false) // if display sleep
  {
    return;
  }
  static char Temporary_Char_Array[6];

  // -- Update clock
  Temporary_Char_Array[0] = Time.Current_Time.tm_hour / 10;
  Temporary_Char_Array[0] += 48;
  Temporary_Char_Array[1] = Time.Current_Time.tm_hour % 10;
  Temporary_Char_Array[1] += 48;
  Temporary_Char_Array[2] = ':';
  Temporary_Char_Array[3] = Time.Current_Time.tm_min / 10;
  Temporary_Char_Array[3] += 48;
  Temporary_Char_Array[4] = Time.Current_Time.tm_min % 10;
  Temporary_Char_Array[4] += 48;
  Temporary_Char_Array[5] = '\0';

  Display.Set_Text(F("CLOCK_TXT"), Temporary_Char_Array);

  // Update connection
  Temporary_Char_Array[5] = WiFi.RSSI();

  if (WiFi.status() == WL_CONNECTED)
  {
    if (Temporary_Char_Array[5] <= -70)
    {
      Display.Set_Text(F("CONNECTION_BUT"), Display.WiFi_Low);
    }
    if (Temporary_Char_Array[0] <= -50 && Temporary_Char_Array[0] > -70)
    {
      Display.Set_Text(F("CONNECTION_BUT"), Display.WiFi_Medium);
    }
    else
    {
      Display.Set_Text(F("CONNECTION_BUT"), Display.WiFi_High);
    }
  }
  else
  {
    Display.Set_Text(F("CONNECTION_BUT"), ' ');
  }

  // -- Update charge level
  Temporary_Char_Array[5] = Power.Get_Charge_Level();

  if (Temporary_Char_Array[5] <= 5)
  {
    Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Empty);
    Display.Set_Font_Color(F("BATTERY_BUT"), Display.Red);
  }
  else if (Temporary_Char_Array[5] <= 10 && Temporary_Char_Array[5] > 5)
  {
    Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Empty);
    Display.Set_Font_Color(F("BATTERY_BUT"), Display.White);
  }
  else if (Temporary_Char_Array[5] <= 35 && Temporary_Char_Array[5] > 10)
  {
    Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Quarter);
  }
  else if (Temporary_Char_Array[5] <= 60 && Temporary_Char_Array[5] > 35)
  {
    Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Half);
  }
  else if (Temporary_Char_Array[5] <= 85 && Temporary_Char_Array[5] > 60)
  {
    Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Three_Quarters);
  }
  else // more than 85 %
  {
    Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Full);
  }

  // -- Update sound
  Temporary_Char_Array[5] = Sound.Get_Volume();

  if (Temporary_Char_Array[5] == 0)
  {
    Display.Set_Text(F("SOUND_BUT"), Display.Sound_Mute);
  }
  else if (Temporary_Char_Array[5] < 86)
  {
    Display.Set_Text(F("SOUND_BUT"), Display.Sound_Low);
  }
  else if (Temporary_Char_Array[5] < 172)
  {
    Display.Set_Text(F("SOUND_BUT"), Display.Sound_Medium);
  }
  else
  {
    Display.Set_Text(F("SOUND_BUT"), Display.Sound_High);
  }
}

///
/// @brief Start Xila up with the default software bundle.
///
void System_Class::Start()
{

  esp_sleep_enable_ext0_wakeup(Power_Button_Pin, LOW);

  Flash.Set_Boot_Partition(Xila_Loader_Partition); // Set loader as boot partition if Xila is doesn't boot anymore.

#if USB_Serial == 1
  Serial.begin(Default_USB_Serial_Speed);
#endif

  Log_Raw_Line("");
  Log_Raw_Line("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
  Log_Raw_Line("||               __________   __   __  _____   _                              ||");
  Log_Raw_Line("||              |      |   |  \\ \\ / / |_   _| | |          /\\                 ||");
  Log_Raw_Line("||              |______|   |   \\ V /    | |   | |         /  \\                ||");
  Log_Raw_Line("||              |   |__|___|    | |     | |   | |        / /\\ \\               ||");
  Log_Raw_Line("||              |   |      |   / . \\   _| |_  | |____   / ____ \\              ||");
  Log_Raw_Line("||              |___|______|  /_/ \\_\\ |_____| |______| /_/    \\_\\             ||");
  Log_Raw_Line("||                                                                            ||");
  Log_Raw_Line("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
  Log_Raw_Line("");
  Log_Raw_Line(" > Version : " Xila_Version_Major_String "." Xila_Version_Minor_String "." Xila_Version_Revision_String " - Alix ANNERAUD - MIT Licence - 2021");
  Log_Raw_Line("");
  Log_Information("Starting Xila ...");
  Log_Verbose("First start routine.");

  if (System.Task_Handle != NULL) // Already started
  {
    return;
  }

  // -- Check if the power button was press or the power supply plugged.
  esp_sleep_enable_ext0_wakeup(Power_Button_Pin, LOW);
  esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();
#if Start_On_Power == 0
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0)
  {
    Power.Deep_Sleep();
  }
#elif Start_On_Power == 1
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
  {
    Power.Deep_Sleep();
  }
#endif

  // -- Set power button interrupts
  GPIO.Set_Mode(Power_Button_Pin, INPUT);
  GPIO.Attach_Interrupt(digitalPinToInterrupt(Power_Button_Pin), Power.Button_Interrupt_Handler, GPIO.Change);

  // -- Increase esp32 hardware watchdog timeout

  if (esp_task_wdt_init(Maximum_Watchdog_Timeout / 1000, true) != ESP_OK)
  {
    Log_Error("Failed to set watchdog timeout. Trying to reboot.");
    ESP.restart();
  }

  // -- Initialize drive. -- //

#if Drive_Mode == 0
  GPIO.Set_Mode(14, INPUT_PULLUP);
  GPIO.Set_Mode(2, INPUT_PULLUP);
  GPIO.Set_Mode(4, INPUT_PULLUP);
  GPIO.Set_Mode(12, INPUT_PULLUP);
  GPIO.Set_Mode(13, INPUT_PULLUP);
#endif

  if (!Drive.Begin() || Drive.Type() == Drive.None)
  {
    Log_Error("Failed to initialize drive.");
    Display.Set_Text(F("EVENT_TXT"), F("Failed to initialize drive."));
  }
  while (!Drive.Begin() || Drive.Type() == Drive.None)
  {
    Log_Information("Attemping to initialize drive ...");
    Drive.End();
    Task_Class::Delay(200);
  }
  Display.Set_Text(F("EVENT_TXT"), F(""));

  // -- Initialize display. -- //

  Task.Create(Display.Task, "Display driver", Memory_Chunk(8), NULL, Task.Driver_Task, Display.Task_Handle);

  if (Display.Load_Registry() != Success)
  {
    Display.Save_Registry();
  }

  if (!Drive.Exists(Users_Directory_Path))
  {
    Log_Information("No existing \"/Users\" directory.");
    File Temporary_File = Drive.Open(Display_Executable_Path);
    if (Display.Update(Temporary_File) != Display.Update_Succeed)
    {
      Panic_Handler(Failed_To_Update_Display);
    }

    Task_Class::Delay(5000);
    Display.Begin(Display.Baud_Rate, Display.Receive_Pin, Display.Transmit_Pin);
  }

  GPIO.Set_Mode(Default_Display_Switching_Pin, GPIO.Output);
  GPIO.Digital_Write(Default_Display_Switching_Pin, GPIO.High);
  Task_Class::Delay(2000);
  // Display.Wake_Up();
  // Display.Set_Touch_Wake_Up(true);
  // Display.Set_Serial_Wake_Up(true);
  Display.Set_Brightness(Display.Brightness);
  // Display.Set_Standby_Touch_Timer(Display.Standby_Time);
  Display.Set_Current_Page(F("Core_Load"));

  Display.Set_Trigger(F("LOAD_TIM"), true);

  // -- Check system integrity -- //

  if (!Drive.Exists(Xila_Directory_Path) || !Drive.Exists(Software_Directory_Path))
  {
    System.Panic_Handler(System.Missing_System_Files);
  }

  // -- Load system registry -- //
  if (System.Load_Registry() != Success)
  {
    System.Panic_Handler(System.Damaged_System_Registry);
  }
  WiFi.setHostname(System.Device_Name); // Set hostname

  // -- Load sound registry --

  if (Sound.Load_Registry() != Success)
  {
    Sound.Save_Registry();
  }
  Sound.Begin();

  // -- Play startup sound

  Sound.Play(Sounds("Startup.wav"));

  // -- Load power registry :

  if (Power.Load_Registry() != Success)
  {
    Power.Save_Registry();
  }

  // -- Network registry :

  if (WiFi.Load_Registry() != Success)
  {
    WiFi.Save_Registry();
  }

  // -- Time registry
  if (Time.Load_Registry() != Success)
  {
    Time.Save_Registry();
  }

  // -- Load account registry

  if (Account.Load_Registry() != Success)
  {
    Account.Set_Autologin(false);
  }

  // -- Load Keyboard Registry
  if (Keyboard.Load_Registry() != Success)
  {
    Keyboard.Save_Registry(); // recreate a keyboard registry with default values
  }

#if Animations == 1
  Task_Class::Delay(3000);
#endif

  Display.Set_Value(F("STATE_VAR"), 2);

#if Animations == 1
  Task_Class::Delay(3000);
#endif

  Task_Class::Delay(500);

  System.Load_Dump();

  Task_Class::Delay(100);

  Execute_Startup_Function();

  Task.Create(System.Task, "Core Task", Memory_Chunk(4), NULL, Task.System_Task, &System.Task_Handle);

  Task.Delete(); // delete main task
}

///
/// @brief Execute software startup function.
///
void System_Class::Execute_Startup_Function()
{

  (*Shell_Handle.Startup_Function_Pointer)();

  for (uint8_t i = 0; i < Maximum_Software; i++)
  {

    if (Software_Management.Handle[i] != NULL)
    {
      if (Software_Management.Handle[i]->Startup_Function_Pointer != NULL)
      {
        (*Software_Management.Handle[i]->Startup_Function_Pointer)();
      }
    }
  }
}

///
/// @brief Shutdown
///
void System_Class::Shutdown()
{
  Flash.Set_Boot_Partition(Xila_Partition); // Set Xila as boot partition if xila is shutdown properly.

  Software_Management.Shell_Maximize();
  Software_Management.Shell_Send_Instruction(Shutdown);

  for (uint8_t i = 2; i < 8; i++)
  {
    if (Software_Management.Openned[i] != NULL)
    {
      Software_Management.Openned[i]->Send_Instruction(Shutdown);
      Task.Resume(Software_Management.Openned[i]->Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t j = 0; j <= 200; j++)
      {
        if (Software_Management.Openned[i] == NULL)
        {
          break;
        }
        if (j == 200 && Software_Management.Openned[i] != NULL)
        {
          Software_Management.Force_Close(*Software_Management.Openned[i]->Handle);
        }
        Task_Class::Delay(20);
      }
    }
  }

  Second_Sleep_Routine();
  Power.Deep_Sleep();
}

///
/// @brief Second sleep routine called in shutdown function.
///
void System_Class::Second_Sleep_Routine()
{
  Task.Delete(System.Task_Handle);

  Display.Save_Registry();
  Keyboard.Save_Registry();
  Power.Save_Registry();
  Sound.Save_Registry();
  WiFi.Save_Registry();
  Time.Save_Registry();
  System.Save_Registry();

  Sound.Play(Sounds("Shutdown.wav"));

  Task_Class::Delay(8000);

  Task.Delete(Sound.Task_Handle);

  // Disconnect wifi
  WiFi.disconnect();
}

///
/// @brief Hibernate
///
void System_Class::Hibernate()
{
  Flash.Set_Boot_Partition(Xila_Partition); // Set Xila as boot partition if xila is shutdown properly.

  System.Save_Dump();

  Software_Management.Shell_Maximize();
  Software_Management.Shell_Send_Instruction(Hibernate);

  for (uint8_t i = 2; i < 8; i++)
  {
    if (Software_Management.Openned[i] != NULL)
    {
      Software_Management.Openned[i]->Send_Instruction(Hibernate);
      Task.Resume(Software_Management.Openned[i]->Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t j = 0; j <= 200; j++)
      {
        if (Software_Management.Openned[i] == NULL)
        {

          break;
        }
        if (j == 200 && Software_Management.Openned[i] != NULL)
        {

          Software_Management.Force_Close(*Software_Management.Openned[i]->Handle);
        }
        Task_Class::Delay(20);
      }
    }
  }

  Second_Sleep_Routine();
  Power.Deep_Sleep();
}

///
/// @brief Restart
///
void System_Class::Restart()
{
  Flash.Set_Boot_Partition(Xila_Partition); // Set Xila as boot partition if xila is shutdown properly.

  Software_Management.Shell_Send_Instruction(Restart);
  Software_Management.Shell_Maximize();

  for (uint8_t i = 2; i < 8; i++)
  {
    if (Software_Management.Openned[i] != NULL)
    {
      Software_Management.Openned[i]->Send_Instruction(Restart);
      Task.Resume(Software_Management.Openned[i]->Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t j = 0; j <= 200; j++)
      {
        if (Software_Management.Openned[i] == NULL)
        {
          break;
        }
        if (j == 200 && Software_Management.Openned[i] != NULL)
        {
          Software_Management.Force_Close(*Software_Management.Openned[i]->Handle);
        }
        Task_Class::Delay(20);
      }
    }
  }

  Second_Sleep_Routine();
  ESP.restart();
}

///
/// @brief Return chip revision.
///
/// @return uint8_t Chip revision.
uint8_t System_Class::Get_Chip_Revision()
{
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  return chip_info.revision;
}

///
/// @brief Return chip model.
///
/// @return const char* Chip model.
const char *System_Class::Get_Chip_Model()
{
  uint32_t chip_ver = REG_GET_FIELD(EFUSE_BLK0_RDATA3_REG, EFUSE_RD_CHIP_VER_PKG);
  uint32_t pkg_ver = chip_ver & 0x7;
  switch (pkg_ver)
  {
  case EFUSE_RD_CHIP_VER_PKG_ESP32D0WDQ6:
    return "ESP32-D0WDQ6";
  case EFUSE_RD_CHIP_VER_PKG_ESP32D0WDQ5:
    return "ESP32-D0WDQ5";
  case EFUSE_RD_CHIP_VER_PKG_ESP32D2WDQ5:
    return "ESP32-D2WDQ5";
  case EFUSE_RD_CHIP_VER_PKG_ESP32PICOD2:
    return "ESP32-PICO-D2";
  case EFUSE_RD_CHIP_VER_PKG_ESP32PICOD4:
    return "ESP32-PICO-D4";
  default:
    return "Unknown";
  }
}

///
/// @brief Return number of chip cores.
///
/// @return uint32_t Chip cores.
uint32_t System_Class::Get_Chip_Cores()
{
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  return chip_info.cores;
}

uint32_t System_Class::Get_CPU_Frequency()
{
  return getCpuFrequencyMhz();
}

const char *System_Class::Get_SDK_Version()
{
  return esp_get_idf_version();
}

uint64_t System_Class::Get_eFuse_MAC()
{
  uint64_t _chipmacid = 0LL;
  esp_efuse_mac_get_default((uint8_t *)(&_chipmacid));
  return _chipmacid;
}