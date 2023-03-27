///
/// @file System.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

// - Constants

#ifndef Xila_Default_Device_Name
    #define Xila_Default_Device_Name "Xila"
#endif
#ifndef Low_Memory_Threshold
    #define Low_Memory_Threshold 2000
#endif

#include "Core/Core.hpp"
#include "esp_task_wdt.h"
#include "Update.h"

using namespace Xila_Namespace;
using namespace Xila_Namespace::System_Types;

System_Type Xila_Namespace::System;

/// @brief Construct a new System_Class::System_Class object
System_Class::System_Class() : Task(this)
{
}

/// @brief Destroy the System_Class object
System_Class::~System_Class()
{
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
  
  this->Load();

  while (1)
  {

    Log_Verbose("System", "System task is running...");

    // -- Check if drive is not disconnected.
    if (!Drive.Exists(Xila_Directory_Path) || !Drive.Exists(Software_Directory_Path))
    {
      System.Panic_Handler(Panic_Type::Drive_Failure);
    }

    Log_Verbose("System", "System task is running 2...");

    // -- Check if running software is not frozen.
    Task_Class::Check_Watchdogs();

    Log_Verbose("System", "System task is running 3...");

    // -- Check WiFi is connected
    // if (WiFi.Get_Status() != WiFi_Type::Status_Type::Connected)
    //{
    //  WiFi.Load_Registry();
    //}
    // - Check available memory (prevent stack / heap collision)

  

    if (Memory.Get_Free_Heap() < Low_Memory_Threshold)
    {
      System.Panic_Handler(Panic_Type::Low_Memory);
    }

    Task.Delay_Until(10000);
  }
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
  Log_Error("System", "Something went wrong...\r\nXila has encountered an unrecoverable error and must restart.\r\nPlease wait for the system to restart itself or press the power button for a few seconds.\r\nError : %X.", Panic_Code);

  Object_Type Background;
  Background.Create(Graphics.Get_Screen());
  Background.Set_Size(Percentage(100), Percentage(100));
  Background.Set_Style_Background_Color(Color_Type::Black, 0);
  Background.Set_Style_Pad_All(0, 0);
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
    Graphics_Types::Label_Type Title;
    Title.Create(Background);
    Title.Set_Text("Something went wrong ...");
    Title.Set_Style_Text_Color(Color_Type::White, 0);
  }
  {
    Graphics_Types::Label_Type Text;
    Text.Create(Background);
    Text.Set_Text("Xila has encountered an unrecoverable error and must restart.\nPlease wait for the system to restart itself or press the power button for a few seconds.");
    Text.Set_Width(Percentage(80));
    Text.Set_Style_Text_Color(Color_Type::White, 0);
    Text.Set_Long_Mode(Graphics_Types::Long_Type::Wrap);
  }

  Graphics_Types::Label_Type Error_Text;
  Error_Text.Create(Background);
  Error_Text.Set_Text_Format("Error : 0x%X.", Panic_Code);
  Error_Text.Set_Width(Percentage(80));
  Error_Text.Set_Long_Mode(Graphics_Types::Long_Type::Wrap);
  Error_Text.Set_Style_Text_Color(Color_Type::White, 0);

  Background.Move_Foreground();

  Log_Verbose("System", "Panic handler started.");

  Task_Type::Delay_Static(50); // Small delay to let the system refresh the screen.

  Task_Type::Suspend_All();
  uint32_t Timer = System.Get_Up_Time_Milliseconds() + 5000;

  while (Timer > System.Get_Up_Time_Milliseconds())
  {
  }

  abort();
}

/// @brief Function that start Xila.
void System_Class::Start()
{ 
  Task_Class::Delay_Static(5000);

  Log_Information("System", "Starting Xila ...");

  // Enable the power button.
  esp_sleep_enable_ext0_wakeup(static_cast<gpio_num_t>(Power_Button_Pin), LOW);

  if (Task.Get_State() != Task_Class::State_Type::Invalid) // Already started
  {
    Log_Warning("System", "Xila seems to be already started.");
    return;
  }

  // -- Check if the power button was press or the power supply plugged.;
  esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();

  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
  {
    Log_Information("System", "Wakeup cause : %X. Go into deep sleep", Wakeup_Cause);
    Task_Class::Delay_Static(10000);
    Power.Deep_Sleep();
  }

  if (Task.Create(Task_Start_Function, "System task", 8 * 1024, this, Task_Type::Priority_Type::System) != Result_Type::Success)
  {
    Log_Error("System", "Failed to create system task.");
    return;
  }
}

void System_Class::Load()
{

  // -- Increase esp32 hardware watchdog timeout

  if (esp_task_wdt_init(Maximum_Watchdog_Timeout / 1000, true) != ESP_OK)
  {
    Log_Error("System", "Failed to set watchdog timeout. Trying to reboot.");
    Power.Restart();
  }


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
  Log_Raw_Line("> Version : %u.%u.%u build on %s at %s.", Xila_Version_Major, Xila_Version_Minor,Xila_Version_Revision,__DATE__, __TIME__);
  Log_Information("System", "Alix ANNERAUD - MIT Licence");

  Log_Information("System", "Starting Xila ...");

  // - Drive
  while (Drive.Start() != Result_Type::Success)
  {
    Task.Delay(100);
  }

  // - Display
  if (Display.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Display);
  }

  // - Power
  if (Power.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Power);
  }

  // - Graphics
  if (Graphics.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Graphics);
  }

  Log_Information("System", "Start load animation ...");

  //Task.Delay(1000);

  Graphics_Types::Animation_Type* Animation = new Graphics_Types::Animation_Type();
  Object_Type Logo;
  this->Start_Load_Animation(&Logo, Animation);

  Task.Delay(2000);

  Log_Information("System", "Load animation done.");

  // - Check system folders.

  Log_Information("System", "Checking system folders ...");

  if (!Drive.Exists(Users_Directory_Path))
  {
    Drive.Make_Directory(Users_Directory_Path);
  }

  if (!Drive.Exists(Software_Directory_Path))
  {
    Drive.Make_Directory(Software_Directory_Path);
  }

  if (!Drive.Exists(Users_Directory_Path) || !Drive.Exists(Xila_Directory_Path) || !Drive.Exists(Software_Directory_Path))
  {
    System.Panic_Handler(Panic_Type::Missing_System_Files);
  }

  // - Load system registry
  this->Device_Name = Xila_Default_Device_Name;

  if (System.Load_Registry() != Result_Type::Success)
  {
     if (System.Create_Registry() != Result_Type::Success)
     {
       System.Panic_Handler(Panic_Type::Damaged_System_Registry);
     }
  }

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
  WiFi.Set_Host_Name(this->Device_Name); // Set hostname


  // - Account
  if (Accounts.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Accounts);
  }

  if (Softwares.Start() != Result_Type::Success)
  {
    Panic_Handler(Panic_Type::Failed_To_Start_Softwares);
  }

  // - Enable animation

#if Release_Type != Debug
  Task.Delay_Static(3000);
#endif

  Task.Delay(500);

  Task.Delay(100);

  this->Stop_Load_Animation(&Logo, Animation);
}

///
/// @brief Shutdown
///
void System_Class::Shutdown()
{
  Graphics_Types::Animation_Type* Animation = new Graphics_Types::Animation_Type;
  Object_Type Logo;
  this->Start_Load_Animation(Logo, Animation);

  //Sound.Play(Sounds("Shutdown.wav"));

  Task.Delete();
  Softwares.Stop();
  Display.Stop();
  Power.Stop();
  Sound.Stop();
  WiFi.Stop();
  System.Stop();

  this->Stop_Load_Animation(&Logo, Animation);

  Power.Deep_Sleep();
}

///
/// @brief Restart
///
void System_Class::Restart()
{
  Graphics_Types::Animation_Type* Animation = new Graphics_Types::Animation_Type;
  Object_Type Logo;
  this->Start_Load_Animation(Logo, Animation);

  //Sound.Play(Sounds("Shutdown.wav"));

  Task.Delete();

  Softwares.Stop();
  Display.Stop();
  Power.Stop();
  Sound.Stop();
  WiFi.Stop();
  System.Stop();

  this->Stop_Load_Animation(&Logo, Animation);

  Power.Restart();
}

