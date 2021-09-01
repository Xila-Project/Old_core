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

extern Xila_Class::Software_Handle Shell_Handle;

///
/// @brief Construct a new System_Class object
///
Xila_Class::System_Class::System_Class()
{
  Task_Handle = NULL;
  strlcpy(Device_Name, Default_Device_Name, sizeof(Device_Name));
}

///
/// @brief Destroy the System_Class object
///
Xila_Class::System_Class::~System_Class()
{
}

///
/// @brief Load System registry.
///
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::System_Class::Load_Registry()
{
  File Temporary_File = Xila.Drive.Open((Registry("System")));
  DynamicJsonDocument System_Registry(512);
  if (deserializeJson(System_Registry, Temporary_File)) // error while deserialising
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  if (strcmp("System", System_Registry["Registry"] | "") != 0)
  {
    return Error;
  }
  JsonObject Version = System_Registry["Version"];
  if (Version["Major"] != Xila_Version_Major || Version["Minor"] != Xila_Version_Minor || Version["Revision"] != Xila_Version_Revision)
  {
    Panic_Handler(Installation_Conflict);
  }
  strlcpy(Xila.System.Device_Name, System_Registry["Device Name"] | Default_Device_Name, sizeof(Xila.System.Device_Name));
  return Success;
}

///
/// @brief Save System registry.
///
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::System_Class::Save_Registry()
{
  File Temporary_File = Xila.Drive.Open((Registry("System")), FILE_WRITE);
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
    return Error;
  }
  Temporary_File.close();
  return Success;
}

///
/// @brief System task.
///
void Xila_Class::System_Class::Task(void *)
{
  uint32_t Next_Refresh = 0;
  Xila.Power.Button_Counter = 0;
  while (1)
  {
    // -- Check power button interrupt
    Xila.Power.Check_Button();
    // -- Execute data from display.
    Xila.Display.Loop();
    // -- Task to refresh every 10 seconds
    if (Xila.Time.Milliseconds() > Next_Refresh)
    {
      // -- Check if drive is not disconnected.
      if (!Xila.Drive.Exists(Xila_Directory_Path) || !Xila.Drive.Exists(Software_Directory_Path))
      {
        Xila.System.Panic_Handler(Xila.System.System_Drive_Failure);
      }
      // -- Check if running software is not frozen
      Xila.Software_Management.Check_Watchdog();
      // -- Check WiFi is connected
      if (Xila.WiFi.status() != WL_CONNECTED)
      {
        Xila.WiFi.Load_Registry();
      }
      // -- Check available (prevent memory overflow)
      if (Xila.Memory.Get_Free_Heap() < Low_Memory_Threshold)
      {
        Xila.System.Panic_Handler(Low_Memory);
      }
      // -- Synchronise time
      Xila.Time.Synchronize();
      // -- Check if software is currently maximized
      if (Xila.Software_Management.Openned[0] == NULL)
      {
        Xila.Task.Delay(100);
        // -- If no software is currently maximized, maximize shell.
        if (Xila.Software_Management.Openned[0] == NULL)
        {
          Xila.Software_Management.Open(Shell_Handle);
          Xila.Software_Management.Shell_Send_Instruction(Xila.Desk);
          Xila.Software_Management.Shell_Maximize();
        }
      }
      // -- Clear the refresh timer.
      Next_Refresh = Xila.Time.Milliseconds() + 10000;
    }
    Xila.Task.Delay(20);
  }
}

///
/// @brief Update Xila on the MCU.
///
/// @param Update_File Executable file.
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::System_Class::Load_Executable(File Executable_File)
{
  if (!Executable_File || Executable_File.isDirectory())
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

///
/// @brief Handle fatal events that the system cannot recover from.
///
/// @param Panic_Code Panic code to handle.
void Xila_Class::System_Class::Panic_Handler(Panic_Code Panic_Code)
{
  Xila.Display.Set_Current_Page(F("Core_Panic"));
  char Temporary_String[32];
  snprintf(Temporary_String, sizeof(Temporary_String), "Error code : %X", Panic_Code);
  Xila.Display.Set_Text(F("ERRORCODE_TXT"), Temporary_String);
  vTaskSuspendAll();
  uint32_t Delay_Time = Xila.Time.Milliseconds();
  while ((Xila.Time.Milliseconds() - Delay_Time) < 5000)
  {
  }
  abort();
}

///
/// @brief Save system dump.
///
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::System_Class::Save_Dump()
{

  DynamicJsonDocument Dump_Registry(Default_Registry_Size);

  JsonArray Software = Dump_Registry.createNestedArray("Software");

  Dump_Registry["Registry"] = "Dump";

  for (uint8_t i = 2; i <= 7; i++)
  {
    if (Xila.Software_Management.Openned[i] != NULL)
    {
      Software.add(Xila.Software_Management.Openned[i]->Handle->Name);
    }
  }

  Dump_Registry["User"] = Xila.Account.Get_Current_Username();

  File Dump_File = Xila.Drive.Open(Dump_Registry_Path, FILE_WRITE);
  if (serializeJson(Dump_Registry, Dump_File) == 0)
  {
    Dump_File.close();
    return Error;
  }
  Dump_File.close();
  return Success;
}

///
/// @brief Load system dump.
///
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::System_Class::Load_Dump()
{
  if (Xila.Drive.Exists(Dump_Registry_Path))
  {
    File Dump_File = Xila.Drive.Open((Dump_Registry_Path));
    DynamicJsonDocument Dump_Registry(Default_Registry_Size);

    if (deserializeJson(Dump_Registry, Dump_File) != DeserializationError::Ok)
    {
      Dump_File.close();
      Xila.Drive.Remove(Dump_Registry_Path);
      return Error;
    }
    Dump_File.close();
    Xila.Drive.Remove(Dump_Registry_Path);

    if (strcmp(Dump_Registry["Registry"] | "", "Dump") != 0)
    {
      return Error;
    }

    char Temporary_Software_Name[Default_Software_Name_Length];

    JsonArray Software = Dump_Registry["Software"];

    for (uint8_t i = 0; i < 6; i++)
    {
      memset(Temporary_Software_Name, '\0', sizeof(Temporary_Software_Name));
      strlcpy(Temporary_Software_Name, Software[i] | "", sizeof(Temporary_Software_Name));
      for (uint8_t j = 0; j < Maximum_Software; j++)
      {
        if (Xila.Software_Management.Handle[j] != NULL)
        {
          if (strcmp(Xila.Software_Management.Handle[j]->Name, Temporary_Software_Name) == 0)
          {
            Xila.Software_Management.Open(*Xila.Software_Management.Handle[j]);
          }
        }
      }
    }

    strlcpy(Xila.Account.Current_Username, Dump_Registry["User"] | "", sizeof(Xila.Account.Current_Username));
    if (Xila.Account.Current_Username[0] != '\0')
    {
      Xila.Account.Set_State(Xila.Account.Locked);
    }

    return Success;
  }
  else
  {
    return Error;
  }
}

///
/// @brief Return device name.
///
/// @return const char* Device name.
const char *Xila_Class::System_Class::Get_Device_Name()
{
  return Xila.System.Device_Name;
}

///
/// @brief Refresh top header.
///
void Xila_Class::System_Class::Refresh_Header()
{
  if (Xila.Display.Get_State() == false) // if display sleep
  {
    return;
  }
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

  if (Temporary_Char_Array[5] <= 5)
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Empty);
    Xila.Display.Set_Font_Color(F("BATTERY_BUT"), Xila.Display.Red);
  }
  else if (Temporary_Char_Array[5] <= 10 && Temporary_Char_Array[5] > 5)
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Empty);
    Xila.Display.Set_Font_Color(F("BATTERY_BUT"), Xila.Display.White);
  }
  else if (Temporary_Char_Array[5] <= 35 && Temporary_Char_Array[5] > 10)
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Quarter);
  }
  else if (Temporary_Char_Array[5] <= 60 && Temporary_Char_Array[5] > 35)
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Half);
  }
  else if (Temporary_Char_Array[5] <= 85 && Temporary_Char_Array[5] > 60)
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Three_Quarters);
  }
  else // more than 85 %
  {
    Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Full);
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

///
/// @brief First start routine, first function executed when Xila.Start() is called.
///
inline void Xila_Class::System_Class::First_Start_Routine()
{
#if USB_Serial == 1
  Serial.begin(Default_USB_Serial_Speed);
#endif
  if (Xila.System.Task_Handle != NULL) // Already started
  {
    return;
  }

  // -- Check if the power button was press or the power supply plugged.
  esp_sleep_enable_ext0_wakeup(Power_Button_Pin, LOW);
  esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();
#if Start_On_Power == 0
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0)
  {
    Xila.Power.Deep_Sleep();
  }
#elif Start_On_Power == 1
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
  {
    Xila.Power.Deep_Sleep();
  }
#endif

  // -- Set power button interrupts
  Xila.GPIO.Set_Mode(Power_Button_Pin, INPUT);
  Xila.GPIO.Attach_Interrupt(digitalPinToInterrupt(Power_Button_Pin), Xila.Power.Button_Interrupt_Handler, Xila.GPIO.Change);

  // -- Increase esp32 hardware watchdog timeout

  if (esp_task_wdt_init(Maximum_Watchdog_Timeout / 1000, true) != ESP_OK)
  {
    ESP.restart();
  }

  // -- Initialize drive. -- //

#if Drive_Mode == 0
  Xila.GPIO.Set_Mode(14, INPUT_PULLUP);
  Xila.GPIO.Set_Mode(2, INPUT_PULLUP);
  Xila.GPIO.Set_Mode(4, INPUT_PULLUP);
  Xila.GPIO.Set_Mode(12, INPUT_PULLUP);
  Xila.GPIO.Set_Mode(13, INPUT_PULLUP);
#endif

  if (!Xila.Drive.Begin() || Xila.Drive.Type() == Xila.Drive.None)
  {
    Xila.Display.Set_Text(F("EVENT_TXT"), F("Failed to initialize drive."));
  }
  while (!Xila.Drive.Begin() || Xila.Drive.Type() == Xila.Drive.None)
  {
    Xila.Drive.End();
    Xila.Task.Delay(200);
  }
  Xila.Display.Set_Text(F("EVENT_TXT"), F(""));

  // -- Initialize display. -- //

  Xila.Display.Set_Callback_Function_Numeric_Data(Xila.Display.Incoming_Numeric_Data_From_Display);
  Xila.Display.Set_Callback_Function_String_Data(Xila.Display.Incoming_String_Data_From_Display);
  Xila.Display.Set_Callback_Function_Event(Xila.Display.Incoming_Event_From_Display);

  if (Xila.Display.Load_Registry() != Success)
  {
    Xila.Display.Save_Registry();
  }

  Xila.Display.Begin(Xila.Display.Baud_Rate, Xila.Display.Receive_Pin, Xila.Display.Transmit_Pin);

  if (!Xila.Drive.Exists(Users_Directory_Path))
  {
    File Temporary_File = Xila.Drive.Open(Display_Executable_Path);
    if (Xila.Display.Update(Temporary_File) != Xila.Display.Update_Succeed)
    {
      Panic_Handler(Failed_To_Update_Display);
    }

    Xila.Task.Delay(5000);
    Xila.Display.Begin(Xila.Display.Baud_Rate, Xila.Display.Receive_Pin, Xila.Display.Transmit_Pin);
  }

  Xila.GPIO.Set_Mode(Default_Display_Switching_Pin, Xila.GPIO.Output);
  Xila.GPIO.Digital_Write(Default_Display_Switching_Pin, Xila.GPIO.High);
  Xila.Task.Delay(2000);
  Xila.Display.Wake_Up();
  Xila.Display.Set_Touch_Wake_Up(true);
  Xila.Display.Set_Serial_Wake_Up(true);
  Xila.Display.Set_Brightness(Xila.Display.Brightness);
  Xila.Display.Set_Standby_Touch_Timer(Xila.Display.Standby_Time);
  Xila.Display.Set_Current_Page(F("Core_Load")); // Play animation
  Xila.Display.Set_Trigger(F("LOAD_TIM"), true);

  // -- Check system integrity -- //

  if (!Xila.Drive.Exists(Xila_Directory_Path) || !Xila.Drive.Exists(Software_Directory_Path))
  {
    Xila.System.Panic_Handler(Xila.System.Missing_System_Files);
  }

  // -- Load system registry -- //
  if (Xila.System.Load_Registry() != Success)
  {
    Xila.System.Panic_Handler(Xila.System.Damaged_System_Registry);
  }
  Xila.WiFi.setHostname(Xila.System.Device_Name); // Set hostname

  // -- Load sound registry --

  if (Xila.Sound.Load_Registry() != Success)
  {
    Xila.Sound.Save_Registry();
  }
  Xila.Sound.Begin();

  // -- Play startup sound

  Xila.Sound.Play(Sounds("Startup.wav"));

  // -- Load power registry :

  if (Xila.Power.Load_Registry() != Success)
  {
    Xila.Power.Save_Registry();
  }

  // -- Network registry :

  if (Xila.WiFi.Load_Registry() != Success)
  {
    Xila.WiFi.Save_Registry();
  }

  // -- Time registry
  if (Xila.Time.Load_Registry() != Success)
  {
    Xila.Time.Save_Registry();
  }

  // -- Load account registry

  if (Xila.Account.Load_Registry() != Success)
  {
    Xila.Account.Set_Autologin(false);
  }

  // -- Load Keyboard Registry
  if (Xila.Keyboard.Load_Registry() != Success)
  {
    Xila.Keyboard.Save_Registry(); // recreate a keyboard registry with default values
  }
}

///
/// @brief Second start routine, called secondly in Xila.Start().
///
void Xila_Class::System_Class::Second_Start_Routine()
{

#if Animations == 1
  Xila.Task.Delay(3000);
#endif

  Xila.Display.Set_Value(F("STATE_VAR"), 2);

#if Animations == 1
  Xila.Task.Delay(3000);
#endif

  Xila.Task.Delay(500);

  Xila.System.Load_Dump();

  Xila.Task.Delay(100);

  Execute_Startup_Function();

  Xila.Task.Create(Xila.System.Task, "Core Task", Memory_Chunk(4), NULL, Xila.Task.System_Task, &Xila.System.Task_Handle);

  Xila.Task.Delete(); // delete main task
}

///
/// @brief Start Xila up with a custom software bundle.
///
/// @param Software_Package Custom software bundle.
/// @param Size Size of the software bundle.
void Xila_Class::System_Class::Start(Xila_Class::Software_Handle **Software_Package, uint8_t Size)
{

  First_Start_Routine();

  // Restore attribute

  for (uint8_t i = 0; i < Size; i++)
  {
    Xila.Software_Management.Add_Handle(*Software_Package[i]);
  }

  Second_Start_Routine();
}

///
/// @brief Start Xila up with the default software bundle.
///
void Xila_Class::System_Class::Start()
{

  First_Start_Routine();

  extern Xila_Class::Software_Handle Calculator_Handle;
  extern Xila_Class::Software_Handle Clock_Handle;
  extern Xila_Class::Software_Handle Internet_Browser_Handle;
  extern Xila_Class::Software_Handle Music_Player_Handle;
  extern Xila_Class::Software_Handle Oscilloscope_Handle;
  extern Xila_Class::Software_Handle Paint_Handle;
  extern Xila_Class::Software_Handle Periodic_Handle;
  extern Xila_Class::Software_Handle Piano_Handle;
  extern Xila_Class::Software_Handle Pong_Handle;
  extern Xila_Class::Software_Handle Simon_Handle;
  extern Xila_Class::Software_Handle Text_Editor_Handle;
  extern Xila_Class::Software_Handle Tiny_Basic_Handle;

  Xila.Software_Management.Add_Handle(Calculator_Handle);
  Xila.Software_Management.Add_Handle(Clock_Handle);
  Xila.Software_Management.Add_Handle(Internet_Browser_Handle);
  Xila.Software_Management.Add_Handle(Music_Player_Handle);
  Xila.Software_Management.Add_Handle(Oscilloscope_Handle);
  Xila.Software_Management.Add_Handle(Paint_Handle);
  Xila.Software_Management.Add_Handle(Periodic_Handle);
  Xila.Software_Management.Add_Handle(Piano_Handle);
  Xila.Software_Management.Add_Handle(Pong_Handle);
  Xila.Software_Management.Add_Handle(Simon_Handle);
  Xila.Software_Management.Add_Handle(Text_Editor_Handle);
  Xila.Software_Management.Add_Handle(Tiny_Basic_Handle);

  Second_Start_Routine();
}

///
/// @brief Execute software startup function.
///
void Xila_Class::System_Class::Execute_Startup_Function()
{

  (*Shell_Handle.Startup_Function_Pointer)();

  for (uint8_t i = 0; i < Maximum_Software; i++)
  {

    if (Xila.Software_Management.Handle[i] != NULL)
    {
      if (Xila.Software_Management.Handle[i]->Startup_Function_Pointer != NULL)
      {
        (*Xila.Software_Management.Handle[i]->Startup_Function_Pointer)();
      }
    }
  }
}

///
/// @brief Shutdown Xila.
///
void Xila_Class::System_Class::Shutdown()
{
  Xila.Software_Management.Shell_Maximize();
  Xila.Software_Management.Shell_Send_Instruction(Xila.Shutdown);

  for (uint8_t i = 2; i < 8; i++)
  {
    if (Xila.Software_Management.Openned[i] != NULL)
    {
      Xila.Software_Management.Openned[i]->Send_Instruction(Xila.Shutdown);
      Xila.Task.Resume(Xila.Software_Management.Openned[i]->Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t j = 0; j <= 200; j++)
      {
        if (Xila.Software_Management.Openned[i] == NULL)
        {
          break;
        }
        if (j == 200 && Xila.Software_Management.Openned[i] != NULL)
        {
          Xila.Software_Management.Force_Close(*Xila.Software_Management.Openned[i]->Handle);
        }
        Xila.Task.Delay(20);
      }
    }
  }

  Second_Sleep_Routine();
  Xila.Power.Deep_Sleep();
}

///
/// @brief Second sleep routine called in shutdown function.
///
void Xila_Class::System_Class::Second_Sleep_Routine()
{
  Xila.Task.Delete(Xila.System.Task_Handle);

  Xila.Display.Save_Registry();
  Xila.Keyboard.Save_Registry();
  Xila.Power.Save_Registry();
  Xila.Sound.Save_Registry();
  Xila.WiFi.Save_Registry();
  Xila.Time.Save_Registry();
  Xila.System.Save_Registry();

  Xila.Sound.Play(Sounds("Shutdown.wav"));

  Xila.Task.Delay(8000);

  Xila.Task.Delete(Xila.Sound.Task_Handle);

  // Disconnect wifi
  Xila.WiFi.disconnect();
}

///
/// @brief Hibernate Xila.
///
void Xila_Class::System_Class::Hibernate()
{

  Xila.System.Save_Dump();

  Xila.Software_Management.Shell_Maximize();
  Xila.Software_Management.Shell_Send_Instruction(Xila.Hibernate);

  for (uint8_t i = 2; i < 8; i++)
  {
    if (Xila.Software_Management.Openned[i] != NULL)
    {
      Xila.Software_Management.Openned[i]->Send_Instruction(Xila.Hibernate);
      Xila.Task.Resume(Xila.Software_Management.Openned[i]->Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t j = 0; j <= 200; j++)
      {
        if (Xila.Software_Management.Openned[i] == NULL)
        {

          break;
        }
        if (j == 200 && Xila.Software_Management.Openned[i] != NULL)
        {

          Xila.Software_Management.Force_Close(*Xila.Software_Management.Openned[i]->Handle);
        }
        Xila.Task.Delay(20);
      }
    }
  }

  Second_Sleep_Routine();
  Xila.Power.Deep_Sleep();
}

///
/// @brief Restart Xila.
///
void Xila_Class::System_Class::Restart()
{
  Xila.Software_Management.Shell_Send_Instruction(Xila.Restart);
  Xila.Software_Management.Shell_Maximize();

  for (uint8_t i = 2; i < 8; i++)
  {
    if (Xila.Software_Management.Openned[i] != NULL)
    {
      Xila.Software_Management.Openned[i]->Send_Instruction(Xila.Restart);
      Xila.Task.Resume(Xila.Software_Management.Openned[i]->Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t j = 0; j <= 200; j++)
      {
        if (Xila.Software_Management.Openned[i] == NULL)
        {
          break;
        }
        if (j == 200 && Xila.Software_Management.Openned[i] != NULL)
        {
          Xila.Software_Management.Force_Close(*Xila.Software_Management.Openned[i]->Handle);
        }
        Xila.Task.Delay(20);
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
uint8_t Xila_Class::System_Class::Get_Chip_Revision()
{
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  return chip_info.revision;
}

///
 /// @brief Return chip model.
 /// 
 /// @return const char* Chip model.
const char *Xila_Class::System_Class::Get_Chip_Model()
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
uint32_t Xila_Class::System_Class::Get_Chip_Cores()
{
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  return chip_info.cores;
}
