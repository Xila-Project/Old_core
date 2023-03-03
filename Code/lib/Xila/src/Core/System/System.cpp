///
/// @file System.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

#include "soc/rtc_wdt.h"
#include "esp_task_wdt.h"
#include "Update.h"

using namespace Xila_Namespace;
using namespace Xila_Namespace::System_Types;

System_Type System();

/// @brief Construct a new System_Class::System_Class object
System_Class::System_Class() : Task(this)
{
  Device_Name = Default_Device_Name;
}

/// @brief Destroy the System_Class object
System_Class::~System_Class()
{
}

Result_Type System_Class::Create_Registry()
{
  File_Type Temporary_File = Drive.Open(Registry("System"), true);
  StaticJsonDocument<512> System_Registry;
  System_Registry["Registry"] = "System";
  System_Registry["Version"]["Major"] = Xila_Version_Major;
  System_Registry["Version"]["Minor"] = Xila_Version_Minor;
  System_Registry["Version"]["Revision"] = Xila_Version_Revision;
  System_Registry["Device Name"] = Default_Device_Name;

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
  File_Type Temporary_File = Drive.Open((Registry("System")));
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

  this->Device_Name = System_Registry["Device Name"] | Default_Device_Name;

  return Result_Type::Success;
}

///
/// @brief Save System registry.
///
/// @return Result_Type
Result_Type System_Class::Save_Registry()
{
  // - Open current registry
  File_Type Temporary_File = Drive.Open(Registry("System"), true);
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
    Time["NTP Server"] = this->NTP_Server;
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

/// @brief
/// @param Instance_Pointer
void System_Class::Task_Start_Function(void *Instance_Pointer)
{
  static_cast<System_Class *>(Instance_Pointer)->Task_Function();
}

/// @brief System task.
void System_Class::Task_Function()
{
  uint32_t Next_Refresh = 0;
  
  Load();

  while (1)
  {
    // -- Check power button interrupt
    Power.Check_Button();

    // -- Check if drive is not disconnected.
    if (!Drive.Exists(Xila_Directory_Path) || !Drive.Exists(Software_Directory_Path))
    {
      System.Panic_Handler(Panic_Type::Drive_Failure);
    }

    // -- Check if running software is not frozen.
    Task_Class::Check_Watchdogs();

    // -- Check WiFi is connected
    // if (WiFi.Get_Status() != WiFi_Type::Status_Type::Connected)
    //{
    //  WiFi.Load_Registry();
    //}
    // -- Check available (prevent memory overflow)
    if (Memory.Get_Free_Heap() < Low_Memory_Threshold)
    {
      System.Panic_Handler(Panic_Type::Low_Memory);
    }

    Task.Delay_Until(10000);
  }
}

Time_Type System_Class::Get_Time()
{
  struct tm Time_Info;
  if (!getLocalTime(&Time_Info))
  {
    return Time_Type();
  }
  return Time_Type(Time_Info.tm_hour, Time_Info.tm_min, Time_Info.tm_sec, 0);
}

Date_Type System_Class::Get_Date()
{
  struct tm Time_Info;
  if (!getLocalTime(&Time_Info))
  {
    return Date_Type();
  }
  return Date_Type(Time_Info.tm_year + 1900, Time_Info.tm_mon + 1, Time_Info.tm_mday);
}

Time_Type System_Class::Get_Up_Time()
{
  uint32_t Up_Time = millis();
  return Time_Type(Up_Time / 3600000, (Up_Time % 3600000) / 60000, (Up_Time % 60000) / 1000, (Up_Time % 1000) * 1000);
}

uint64_t System_Class::Get_Up_Time_Microseconds()
{
  return micros();
}

uint32_t System_Class::Get_Up_Time_Milliseconds()
{
  return millis();
}

uint32_t System_Class::Get_Cycles_Count()
{
  return cpu_hal_get_cycle_count();
}

uint32_t System_Class::Get_UTC_Offset()
{
  return UTC_Offset;
}

uint16_t System_Class::Get_Daylight_Offset()
{
  return Daylight_Offset;
}

void System_Class::Get_NTP_Server(String_Type &NTP_Server)
{
  NTP_Server = this->NTP_Server;
}

void System_Class::Set_Time_Zone(uint32_t UTC_Offset, uint16_t Daylight_Offset)
{
  this->UTC_Offset = UTC_Offset;
  this->Daylight_Offset = Daylight_Offset;
  configTime(this->UTC_Offset, this->Daylight_Offset, this->NTP_Server);
}

void System_Class::Set_NTP_Server(const String_Type &NTP_Server)
{
  this->NTP_Server = NTP_Server;
  configTime(this->UTC_Offset, this->Daylight_Offset, this->NTP_Server);
}

/// @brief Update Xila on the MCU.
///
/// @param Update_File Executable file.
/// @return Result_Type
Result_Type System_Class::Upgrade(File_Type Executable_File)
{
  if (!Executable_File || Executable_File.Is_Directory())
  {
    return Result_Type::Error;
  }
  if (Executable_File.Get_Size() == 0)
  {
    return Result_Type::Error;
  }
  // TODO : Deleguate to bootloader
  /*
  if (!Update.begin(Executable_File.Get_Size(), U_FLASH))
  {
    return Result_Type::Error;
  }
  size_t Written = Update.writeStream(Executable_File);
  if (Written != Executable_File.Get_Size())
  {
    return Result_Type::Error;
  }
  if (!Update.end())
  {
    return Result_Type::Error;
  }
  if (!Update.isFinished())
  {
    return Result_Type::Error;
  }*/

  return Result_Type::Success;
}

///
/// @brief Handle fatal events that the system cannot recover from.
///
/// @param Panic_Code Panic code to handle.
void System_Class::Panic_Handler(Panic_Type Panic_Code)
{
  Log_Error("Something went wrong ...");
  Log_Error("Xila has encountered an unrecoverable error and must restart.\nPlease wait for the system to restart itself or press the power button for a few seconds.");
  Log_Error("Error : %X.", Panic_Code);

  Object_Type Background;
  Background.Create(Graphics.Get_Screen());
  Background.Set_Size(Percentage(100), Percentage(100));
  Background.Set_Style_Background_Color(Color_Type::Black, 0);
  Background.Set_Flex_Flow(Flex_Flow_Type::Column);
  Background.Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);

  {
    Object_Type Logo;
    Logo.Create(Background);
    Logo.Set_Size(4 * 16, 4 * 16);
    Logo.Set_Style_Pad_All(0, 0);
    Logo.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);

    {
      Object_Type Red;
      Red.Create(Logo);
      Red.Set_Size(4 * 5, 4 * 10);
      Red.Set_Alignment(Alignment_Type::Top_Left);
      Red.Set_Style_Pad_All(0, 0);
      Red.Set_Style_Background_Color(Color_Type::White, 0);
    }

    {
      Object_Type Green;
      Green.Create(Logo);
      Green.Set_Size(4 * 5, 4 * 10);
      Green.Set_Alignment(Alignment_Type::Bottom_Right);
      Green.Set_Style_Pad_All(0, 0);
      Green.Set_Style_Background_Color(Color_Type::White, 0);
    }

    {
      Object_Type Blue;
      Blue.Create(Logo);
      Blue.Set_Size(4 * 10, 4 * 5);
      Blue.Set_Alignment(Alignment_Type::Bottom_Left);
      Blue.Set_Style_Pad_All(0, 0);
      Blue.Set_Style_Background_Color(Color_Type::White, 0);
    }

    {
      Object_Type Yellow;
      Yellow.Create(Logo);
      Yellow.Set_Size(4 * 10, 4 * 5);
      Yellow.Set_Alignment(Alignment_Type::Top_Right);
      Yellow.Set_Style_Pad_All(0, 0);
      Yellow.Set_Style_Background_Color(Color_Type::White, 0);
    }
  }

  {
    Label_Type Title;
    Title.Create(Background);
    Title.Set_Text("Something went wrong ...");
    Title.Set_Style_Text_Color(Color_Type::White, 0);
  }
  {
    Label_Type Text;
    Text.Create(Background);
    Text.Set_Text("Xila has encountered an unrecoverable error and must restart.\nPlease wait for the system to restart itself or press the power button for a few seconds.");
    Text.Set_Width(Percentage(80));
    Text.Set_Style_Text_Color(Color_Type::White, 0);
    Text.Set_Long_Mode(Label_Type::Long_Mode_Type::Wrap);
  }

  Label_Type Error_Text;
  Error_Text.Create(Background);
  Error_Text.Set_Text_Format("Error : %X.", Panic_Code);
  Error_Text.Set_Width(Percentage(80));
  Error_Text.Set_Long_Mode(Label_Type::Long_Mode_Type::Wrap);
  Error_Text.Set_Style_Text_Color(Color_Type::White, 0);

  Task_Type::Suspend_All();
  uint32_t Timer = System.Get_Up_Time_Milliseconds() + 5000;

  while (Timer > System.Get_Up_Time_Milliseconds())
  {
  }

  abort();
}

/// @brief Save system dump.
///
/// @return Result_Type
Result_Type System_Class::Save_Dump()
{
  /*
  DynamicJsonDocument Dump_Registry(Default_Registry_Size);

  Dump_Registry["Registry"] = "Dump";

  {
    JsonArray Users = Dump_Registry.createNestedArray("Users");

    for (uint8_t i = 0; i < Accounts.Get_User_Count(); i++)
    {
      Users.add(Accounts.Get_User(i)->Get_Name());
    }
  }

  {
    JsonArray Openned_Software = Dump_Registry.createNestedArray("Software");

    // Iterate through opened software list
    for (auto &Software_Pointer : Softwares.Get_List())
    {
      Openned_Software.add(Software_Pointer->Get_Handle_Pointer()->Get_Name());
    }
  }

  File_Type Dump_File = Drive.Open(Dump_Registry_Path, true);
  if (serializeJson(Dump_Registry, Dump_File) == 0)
  {
    Dump_File.Close();
    return Result_Type::Error;
  }
  Dump_File.Close();
  return Result_Type::Success;
  */
}

///
/// @brief Load system dump.
///
/// @return Result_Type
Result_Type System_Class::Load_Dump()
{
  /*
  if (Drive.Exists(Dump_Registry_Path))
  {
    File_Type Dump_File = Drive.Open((Dump_Registry_Path));
    DynamicJsonDocument Dump_Registry(Default_Registry_Size);

    if (deserializeJson(Dump_Registry, Dump_File) != DeserializationError::Ok)
    {
      Dump_File.Close();
      Drive.Remove(Dump_Registry_Path);
      return Result_Type::Error;
    }
    Dump_File.Close();
    Drive.Remove(Dump_Registry_Path);

    if (strcmp(Dump_Registry["Registry"] | "", "Dump") != 0)
    {
      return Result_Type::Error;
    }

    char Temporary_Software_Name[sizeof(Software_Handle_Type::Name)];

    JsonArray Software = Dump_Registry["Software"];

    for (uint8_t i = 0; i < 6; i++)
    {
      memset(Temporary_Software_Name, '\0', sizeof(Temporary_Software_Name));
      strlcpy(Temporary_Software_Name, Software[i] | "", sizeof(Temporary_Software_Name));
      for (auto & Software_Handle : Softwares.Get_Handle_List())
      {
        if (strcmp(Software_Handle->Get_Name(), Temporary_Software_Name) == 0)
        {
          Software_Handle->Create_Instance();
        }
      }
    }

    strlcpy(Account.Get_Logged_User()., Dump_Registry["User"] | "", sizeof(Account.Current_Username));
    if (Account.Current_Username[0] != '\0')
    {
      Account.Set_State(Account.Locked);
    }

    return Result_Type::Success;
  }
  else
  {
    return Result_Type::Error;
  }
  */
  return Result_Type::Success;
}

///
/// @brief Return device name.
///
/// @return const char* Device name.
void System_Class::Get_Device_Name(String_Class &Device_Name)
{
  Device_Name = this->Device_Name;
}

void System_Class::Set_Device_Name(const String_Class &Device_Name)
{
  this->Device_Name = Device_Name;
}

/// @brief Function that start Xila.
void System_Class::Start()
{
  // Enable the power button.
  esp_sleep_enable_ext0_wakeup(static_cast<gpio_num_t>(Power_Button_Pin), LOW);

  if (Task.Get_State() != Task_Class::State_Type::Invalid) // Already started
  {
    return;
  }

  // -- Check if the power button was press or the power supply plugged.;
  esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();
#if Xila_System_Wakeup_Undefined == 0
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0)
  {
    Power.Deep_Sleep();
  }
#elif Xila_System_Wakeup_Undefined == 1
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
  {
    Power.Deep_Sleep();
  }
#endif

  Task.Create(Task_Start_Function, "System task", 4 * 1024, this, Task_Type::Priority_Type::System);
}

void System_Class::Load()
{

  // -- Increase esp32 hardware watchdog timeout

  if (esp_task_wdt_init(Maximum_Watchdog_Timeout / 1000, true) != ESP_OK)
  {
    Log_Error("Failed to set watchdog timeout. Trying to reboot.");
    ESP.restart();
  }

  // - Serial

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
  Log_Raw_Line(" > Version :" Stringizing(Xila_Version_Major) " . " Stringizing(Xila_Version_Minor) " . " Stringizing(Xila_Version_Revision) " - Alix ANNERAUD - MIT Licence - 2023");
  Log_Raw_Line("");
  Log_Information("Starting Xila ...");
  Log_Verbose("First start routine.");

  // - Power

  while (Power.Start() != Result_Type::Success)
  {
    Log_Error("Failed to initialize power ...");
    Task.Delay(200);
  }

  // - Drive

  while (Drive.Start() != Result_Type::Success)
  {
    Log_Error("Failed to initialize drive ...");
    Task.Delay(200);
  }

  // - Display

  if (Display.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Display);
  }

  // - Graphics

  if (Graphics.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Graphics);
  }

  Object_Type Logo = this->Start_Load_Animation();

  Task.Delay(100);

  // - Check system folders.

  if (!Drive.Exists(Users_Directory_Path) || !Drive.Exists(Xila_Directory_Path) || !Drive.Exists(Software_Directory_Path))
  {
    System.Panic_Handler(Panic_Type::Missing_System_Files);
  }

  // - Load system registry
  if (System.Load_Registry() != Result_Type::Success)
  {
    System.Panic_Handler(Panic_Type::Damaged_System_Registry);
  }

  WiFi.Set_Host_Name(System.Device_Name); // Set hostname

  // - Sound

  if (Sound.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Sound);
  }

  // Sound.Play(Sounds("Startup.wav"));

  // - Power

  if (Power.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Power);
  }

  // - WiFi

  if (WiFi.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_WiFi);
  }


  // - Account
  if (Accounts.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Accounts);
  }

  // - Keyboard
  Keyboard.Start();

  // - Enable animation

#if Release_Type != Debug
  Task.Delay_Static(3000);
#endif

  Task.Delay(500);

  Task.Delay(100);

  this->Stop_Load_Animation(&Logo);
}

Object_Type System_Class::Start_Load_Animation()
{
  Object_Type Background;
  Background.Create(Graphics.Get_Screen());
  Background.Set_Size(Percentage(100), Percentage(100));
  Background.Set_Style_Background_Color(Color_Type::Black, 0);

  Object_Type Logo;
  Logo.Create(Background);
  Logo.Set_Size(256, 256);
  Logo.Set_Alignment(Alignment_Type::Center);
  Logo.Set_Style_Pad_All(0, 0);
  Logo.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
  Logo.Set_Style_Shadow_Color(Color_Type::White, 0);

  Object_Type Red;
  Red.Create(Logo);
  Red.Set_Size(40, 84);
  Red.Set_Alignment(Alignment_Type::Top_Left, 64, 64);
  Red.Set_Style_Background_Color(Color_Type::White, 0);
  Red.Set_Style_Shadow_Color(Color_Type::White, 0);
  Red.Set_Style_Opacity(Opacity_Type::Transparent, 0);

  Object_Type Blue;
  Blue.Create(Logo);
  Blue.Set_Size(84, 40);
  Blue.Set_Alignment(Alignment_Type::Top_Right, 64, -64);
  Blue.Set_Style_Background_Color(Color_Type::White, 0);
  Blue.Set_Style_Shadow_Color(Color_Type::White, 0);
  Blue.Set_Style_Opacity(Opacity_Type::Transparent, 0);

  Object_Type Green;
  Green.Create(Logo);
  Green.Set_Size(40, 84);
  Green.Set_Alignment(Alignment_Type::Bottom_Left, -64, -64);
  Green.Set_Style_Background_Color(Color_Type::White, 0);
  Green.Set_Style_Shadow_Color(Color_Type::White, 0);
  Green.Set_Style_Opacity(Opacity_Type::Transparent, 0);

  Object_Type Yellow;
  Yellow.Create(Logo);
  Yellow.Set_Size(84, 40);
  Yellow.Set_Alignment(Alignment_Type::Bottom_Right, -64, 64);
  Yellow.Set_Style_Background_Color(Color_Type::White, 0);
  Yellow.Set_Style_Shadow_Color(Color_Type::White, 0);
  Yellow.Set_Style_Opacity(Opacity_Type::Transparent, 0);

  Label_Type Text;
  Text.Create(Background);
  Text.Set_Alignment(Alignment_Type::Center, 0, 256);

  Graphics_Types::Animation_Type Animation;
  Animation.Create();
  Animation.Set_Variable(&Logo);
  Animation.Set_Values(64, 255);
  Animation.Set_Time(1000);
  Animation.Set_Playback_Delay(0);
  Animation.Set_Playback_Time(1000);
  Animation.Set_Repeat_Delay(0);
  Animation.Set_Repeat_Count(LV_ANIM_REPEAT_INFINITE); // TODO : Define a constant for this
  Animation.Set_Path_Callback(Graphics_Types::Animation_Type::Path_Ease_In_Out);
  Animation.Set_Execution_Callback(this->Animation_Callback);

  // TODO : Change how anim is created / deleted
  Animation.Delete();

  return Logo;
}

void System_Class::Stop_Load_Animation(Object_Type *Logo)
{
  Graphics_Types::Animation_Type::Delete(Logo, Animation_Callback);
}

void System_Class::Animation_Callback(void *Object, int32_t Value)
{
  // TODO : Optimize this : use animation timeline
  static uint8_t Animated_Part = 2;

  if ((Value) == 255 || (Value == 64))
  {
    if (Animated_Part == 4)
    {
      if (Value == 64)
      {
        Animated_Part = 1;
      }
      Animated_Part = 0;
    }
  }
  else
  {
    Animated_Part++;
  }

  Object_Type Logo;
  Logo.Set_Pointer(static_cast<lv_obj_t *>(Object));
  if ((Animated_Part % 2) == 0)
  {
    {
      Object_Type Part = Logo.Get_Child(Animated_Part - 1);
      Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
      Part.Set_Style_Opacity(255 + 64 - static_cast<uint8_t>(Value), 0);
    }

    {
      Object_Type Part = Logo.Get_Child(Animated_Part - 2);
      Part.Set_Style_Shadow_Width(Value, 0);
      Part.Set_Style_Opacity(static_cast<uint8_t>(Value), 0);
    }
  }
  else
  {
    {
      Object_Type Part = Logo.Get_Child(Animated_Part - 1);
      Part.Set_Style_Shadow_Width(Value, 0);
      Part.Set_Style_Opacity(static_cast<uint8_t>(Value), 0);
    }

    if (Animated_Part == 1)
    {
      Object_Type Part = Logo.Get_Child(Animated_Part - 2);
      Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
      Part.Set_Style_Opacity(255 + 64 - static_cast<uint8_t>(Value), 0);
    }
    else
    {
      Object_Type Part = Logo.Get_Child(Animated_Part - 2);
      Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
      Part.Set_Style_Opacity(255 + 64 - static_cast<uint8_t>(Value), 0);
    }
  }
}

///
/// @brief Shutdown
///
void System_Class::Shutdown()
{
#if Build_Type != Debug
  Flash.Set_Boot_Partition(Xila_Partition); // Set Xila as boot partition if xila is shutdown properly.
#endif

  Object_Type Logo = this->Start_Load_Animation();

  Sound.Play(Sounds("Shutdown.wav"));

  Task.Delete();

  Softwares.Stop();
  Display.Stop();
  Keyboard.Stop();
  Power.Stop();
  Sound.Stop();
  WiFi.Stop();
  Time.Stop();
  System.Stop();

  this->Stop_Load_Animation(&Logo);

  Power.Deep_Sleep();
}

///
/// @brief Restart
///
void System_Class::Restart()
{
#if Build_Type != Debug
  Flash.Set_Boot_Partition(Xila_Partition); // Set Xila as boot partition if xila is shutdown properly.
#endif

  Object_Type Logo = this->Start_Load_Animation();

  Sound.Play(Sounds("Shutdown.wav"));

  Task.Delete();

  Softwares.Stop();
  Display.Stop();
  Keyboard.Stop();
  Power.Stop();
  Sound.Stop();
  WiFi.Stop();
  System.Stop();

  this->Stop_Load_Animation(&Logo);

  Power.Deep_Sleep();
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

void System_Class::Logo_Annimation_Callback(void *Object, int32_t Value)
{
  static uint8_t Animated_Part = 2;

  if ((Value == 255) || (Value == 64))
  {
    if ((Animated_Part == 4))
    {
      if (Value == 64)
      {
        Animated_Part = 1;
      }
    }
    else
    {
      Animated_Part++;
    }
  }

  Object_Type Next_Part = static_cast<*Object_Type>(Object)->Get_Child(Animated_Part - 1);

  if ((Animated_Part % 2) == 0)
  {
    Next_Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
    Next_Part.Set_Style_Opacity(255 + 64 - (uint8_t)Value, 0);

    Object_Type Previous_Part = static_cast<*Object_Type>(Object)->Get_Child(Animated_Part - 2);

    Previous_Part.Set_Style_Shadow_Width(Value, 0);
    Previous_Part.Set_Style_Opacity(Value, 0);
  }
  else
  {
    Next_Part.Set_Style_Shadow_Width(Value, 0);
    Next_Part.Set_Style_Opacity(Value, 0);

    if (Animated_Part == 1)
    {
      Object_Type Previous_Part = static_cast<*Object_Type>(Object)->Get_Child(3);

      Previous_Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
      Previous_Part.Set_Style_Opacity(255 + 64 - (uint8_t)Value, 0);
    }
    else
    {
      Object_Type Previous_Part = static_cast<*Object_Type>(Object)->Get_Child(Animated_Part - 2);

      Previous_Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
      Previous_Part.Set_Style_Opacity(255 + 64 - (uint8_t)Value, 0);
    }
  }
}