#include "Core/Core.hpp"

#include "soc/rtc_wdt.h"

Xila_Class::System_Class::System_Class()
{
  State = Default;
  Task_Handle = NULL;
  strlcpy(Name, Default_Name, sizeof(Name));
}

Xila_Class::Event Xila_Class::System_Class::Load_Registry()
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

  strlcpy(Xila.System.Name, System_Registry["Device Name"], sizeof(Xila.System.Name));

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
    Xila.Time.Synchronise();        // Time synchro

    if ((millis() - Last_Header_Refresh) > 10000) // Refresh header every ~10000 ms
    {
      if (Xila.System.Get_Free_Heap() < Low_Memory_Threshold)
      {
        Xila.System.Panic_Handler(Low_Memory);
      }

      Xila.System.Refresh_Header(); // Header refreshing
      Last_Header_Refresh = millis();

      if (Xila.Software.Openned[0] == NULL)
      {
        Xila.Task.Delay(40);
        if (Xila.Software.Openned[0] == NULL)
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
/// @return Xila_Class::Event
///
Xila_Class::Event Xila_Class::System_Class::Load_Executable(File Executable_File, uint8_t Type)
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

Xila_Class::Event Xila_Class::System_Class::Save_Registry()
{
  File Temporary_File = Xila.Drive.open(System_Registry_Path, FILE_WRITE);
  DynamicJsonDocument System_Registry(256);
  System_Registry["Device Name"] = Name;
  if (serializeJson(System_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }

  Temporary_File.close();
  return Success;
}

Xila_Class::Event Xila_Class::System_Class::Create_Dump()
{
  Xila.Software.Minimize(*Xila.Software.Openned[0]->Handle);

  File Dump_File = Xila.Drive.open(Dump_Registry_Path, FILE_WRITE);

  if (!Dump_File)
  {
    return Error;
  }

  Dump_File.seek(0 * 24);

  Dump_File.write((uint8_t *)Xila.Software.Openned[2]->Handle->Name, sizeof(Xila.Software.Openned[2]->Handle->Name));
  Dump_File.seek(1 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned[3]->Handle->Name, sizeof(Xila.Software.Openned[3]->Handle->Name));
  Dump_File.seek(2 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned[4]->Handle->Name, sizeof(Xila.Software.Openned[4]->Handle->Name));
  Dump_File.seek(3 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned[5]->Handle->Name, sizeof(Xila.Software.Openned[5]->Handle->Name));
  Dump_File.seek(4 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned[6]->Handle->Name, sizeof(Xila.Software.Openned[6]->Handle->Name));
  Dump_File.seek(5 * 24);
  Dump_File.write((uint8_t *)Xila.Software.Openned[7]->Handle->Name, sizeof(Xila.Software.Openned[7]->Handle->Name));
  Dump_File.seek(6 * 24);
  Dump_File.write((uint8_t *)Xila.Account.Current_Username, sizeof(Xila.Account.Current_Username));
  Dump_File.close();

  Xila_Task_Handle Temporary_Task_Handle;
  for (uint8_t i = 1; i < 8; i++)
  {
    if (Xila.Software.Openned[i] != NULL)
    {
      Temporary_Task_Handle = Xila.Software.Openned[i]->Task_Handle;
      Xila.Software.Openned[i]->Send_Instruction(Software_Class::Hibernate);
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

Xila_Class::Event Xila_Class::System_Class::Load_Dump()
{
  if (Xila.Drive.exists(Dump_Registry_Path))
  {
    File Dump_File = Xila.Drive.open(Dump_Registry_Path);
    char Temporary_Software_Name[24];
    for (uint8_t i = 0; i < 7; i++)
    {
      Dump_File.seek(i * 24);
      Dump_File.readBytes(Temporary_Software_Name, sizeof(Temporary_Software_Name));
      for (uint8_t ii = 0; ii < (sizeof(Xila.Software.Handle) / sizeof(Xila.Software.Handle[0])); ii++)
      {
        if (strcmp(Xila.Software.Handle[ii]->Name, Temporary_Software_Name) == 0)
        {
          Xila.Software.Open(*Xila.Software.Handle[ii]);
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

const char *Xila_Class::System_Class::Get_Name()
{
  return Xila.System.Name;
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

///
/// @brief
///
inline void Xila_Class::System_Class::First_Start_Routine()
{
  // -- Check if the power button was press or the power supply plugged.
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
  {
    Deep_Sleep();
  }

  // -- Check if the battery level is enough to start.

#if BATTERY_CHECKING == 1
  if (Battery.Get_Charge_Level() <= 3)
  {
    Deep_Sleep();
  }
#endif

  pinMode(POWER_BUTTON_PIN, INPUT);
  // Temporary disable power button interrupt due to disturbance caused maybe by WiFi
  attachInterrupt(digitalPinToInterrupt(POWER_BUTTON_PIN), Xila.Power.Button_Handler, FALLING);

  // -- Disable FreeRTOS watchdog and replace it with Xila watchdog
#if WATCHDOG == 0
  rtc_wdt_protect_off();
  rtc_wdt_disable();
#endif

#if USB_SERIAL == 1
  Serial.begin(USB_SERIAL_SPEED);
#endif

  // -- Initialize display. -- //

  pinMode(DISPLAY_SWITCH_PIN, OUTPUT);
  digitalWrite(DISPLAY_SWITCH_PIN, HIGH);

  Xila.Display.Set_Callback_Function_Numeric_Data(Xila.Display.Incomming_Numeric_Data_From_Display);
  Xila.Display.Set_Callback_Function_String_Data(Xila.Display.Incomming_String_Data_From_Display);
  Xila.Display.Set_Callback_Function_Event(Xila.Display.Incomming_Event_From_Display);
  Xila.Display.Begin();

  Xila.Display.Wake_Up();
  Xila.Display.Set_Current_Page(F("Core_Load")); // Play animation
  Xila.Display.Set_Trigger(F("LOAD_TIM"), true);

  // -- Initialize drive. -- //

#if SD_MODE == 0
  pinMode(14, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
#endif

  if (!Xila.Drive.begin() || Xila.Drive.cardType() == CARD_NONE)
  {
    Xila.Display.Set_Text(F("EVENT_TXT"), F("Failed to initialize drive."));
  }
  while (!Xila.Drive.begin() || Xila.Drive.cardType() == CARD_NONE)
  {
    Xila.Task.Delay(50);
  }
  Xila.Display.Set_Text(F("EVENT_TXT"), F(""));

  Xila_Class::Event Returned_Data;

  // -- Check system integrity -- //

  if (!Xila.Drive.exists(Xila_Directory_Path) || !Xila.Drive.exists(Software_Directory_Path))
  {
    Xila.System.Panic_Handler(Xila.System.Missing_System_Files);
  }

  // -- Load system registry -- //

  Returned_Data = Xila.System.Load_Registry();

  if (Returned_Data != Success)
  {

    if (Returned_Data == Error)
    {
      Xila.System.Panic_Handler(Xila.System.Damaged_System_Registry);
    }
    else if (Returned_Data == 2)
    {
      Xila.System.Panic_Handler(Xila.System.Installation_Conflict);
    }
    else if (Returned_Data == 3) // new installation
    {
      File Temporary_File = Xila.Drive.open(Display_Executable_Path);
      if (Xila.Display.Update(Temporary_File) != Xila.Display.Update_Succeed)
      {
        Verbose_Print("Display update failed");
        ESP.restart();
      }

      Xila.Display.Set_Callback_Function_Numeric_Data(&Xila.Display.Incomming_Numeric_Data_From_Display);
      Xila.Display.Set_Callback_Function_String_Data(&Xila.Display.Incomming_String_Data_From_Display);
      Xila.Display.Set_Callback_Function_Event(&Xila.Display.Incomming_Event_From_Display);
      Xila.Display.Begin();
      Xila.Display.Wake_Up();
      Xila.Display.Set_Current_Page(F("Core_Load")); // Play animation
      Xila.Display.Set_Trigger(F("LOAD_TIM"), true);
    }
  }

  Xila.WiFi.setHostname(Xila.System.Name); // Set hostname

  // -- Load sound registry --

  Returned_Data = Xila.Sound.Load_Registry();

  if (Returned_Data != Success)
  {
    Verbose_Print_Line("Failed to load sound registry");
  }

  Xila.Task.Create(Xila.Sound.Task, "Sound task", Memory_Chunk(3), NULL, Xila.Task.Driver_Task, &Xila.Sound.Task_Handle);

  // -- Play startup sound
  Xila.Sound.Play((Startup_Sound_Path));
  // -- Load display registry

  Returned_Data = Xila.Display.Load_Registry();

  if (Returned_Data != Success)
  {
    Verbose_Print_Line("Failed to load display registry");
  }

  // WiFi :

  Returned_Data = Xila.WiFi.Load_Registry();

  if (Returned_Data != Success)
  {
    Verbose_Print_Line("Failed to connect to WiFi");
  }

  // -- Load Time Registry
  Returned_Data = Xila.Time.Load_Registry();

  if (Returned_Data != Success)
  {
    Verbose_Print_Line("Failed to load time registry");
  }

  // -- Load Keyboard Registry

  Returned_Data = Xila.Keyboard.Load_Registry();

  if (Returned_Data != Success)
  {
    Verbose_Print_Line("Failed to play keyboard registry");
  }

  Xila.Task.Create(Xila.System.Task, "Core Task", Memory_Chunk(3), NULL, Xila.Task.System_Task, &Xila.System.Task_Handle);
}

///
/// @brief
///
inline void Xila_Class::System_Class::Second_Start_Routine()
{
  Xila.System.Load_Dump();

#if ANIMATION == 1
  Xila.Task.Delay(3000);
#endif
  Xila.Display.Set_Value(F("STATE_VAR"), 2);

#if ANIMATION == 1
  Xila.Task.Delay(3000);
#endif

  Execute_Startup_Function();

  Xila.Task.Delay(500);

  if (!Xila.Drive.exists(Users_Directory_Path))
  {
    Xila.Software.Openned[1]->Send_Instruction(Software_Class::Dialog_Install);
  }
}

/**
    * @brief Function handle deep-sleep wakeup, initialize the core, start software etc.
    * @param Software_Package Software that Xila need to load. 
    * @details Function steps :
    * 1) Check if the wakeup reasing is linked to a power button press, or undefined (power reset) and if not, go to sleep.
    * 2) Create an interrupt for the power button.
    * 3) Initalize display.
    * 4) Initalize system drive.
    * 5) Load registries (display, sound, keyboard, network, time).
    * 6) Play sound and animation.
    * 7) Load software handles.
    * 8) Execute software startup function (Shell and other software).
    */
void Xila_Class::System_Class::Start(Software_Handle_Class *Software_Package, uint8_t Size)
{
  if (Xila.System.Task_Handle != NULL) // Already started
  {
    return;
  }

  First_Start_Routine();

  // Restore attribute

  for (uint8_t i = 0; i < Size; i++)
  {
    Xila.Software.Add_Handle(Software_Package[i]);
  }

  Second_Start_Routine();
}

/**
     * @brief Function that handle deep-sleep wakeup, initialize the, start software etc.
     * @details Function steps :
     * 1) Cheeck if the wa
     */
void Xila_Class::System_Class::Start()
{
  if (Xila.System.Task_Handle != NULL) // Already started
  {
    return;
  }

  First_Start_Routine();

  // -- Load softwares -- //

  Verbose_Print_Line("> Load software ...");

  extern Software_Handle_Class Calculator_Handle;
  extern Software_Handle_Class Clock_Handle;
  extern Software_Handle_Class Internet_Browser_Handle;
  extern Software_Handle_Class Music_Player_Handle;
  extern Software_Handle_Class Oscilloscope_Handle;
  extern Software_Handle_Class Paint_Handle;
  extern Software_Handle_Class Periodic_Handle;
  extern Software_Handle_Class Piano_Handle;
  extern Software_Handle_Class Image_Viewer_Handle;
  extern Software_Handle_Class Pong_Handle;
  extern Software_Handle_Class Simon_Handle;
  extern Software_Handle_Class Text_Editor_Handle;
  extern Software_Handle_Class Tiny_Basic_Handle;

  Xila.Software.Add_Handle(Calculator_Handle);
  Xila.Software.Add_Handle(Clock_Handle);
  Xila.Software.Add_Handle(Internet_Browser_Handle);
  Xila.Software.Add_Handle(Music_Player_Handle);
  Xila.Software.Add_Handle(Oscilloscope_Handle);
  Xila.Software.Add_Handle(Paint_Handle);
  Xila.Software.Add_Handle(Periodic_Handle);
  Xila.Software.Add_Handle(Piano_Handle);
  Xila.Software.Add_Handle(Image_Viewer_Handle);
  Xila.Software.Add_Handle(Pong_Handle);
  Xila.Software.Add_Handle(Simon_Handle);
  Xila.Software.Add_Handle(Text_Editor_Handle);
  Xila.Software.Add_Handle(Tiny_Basic_Handle);

  Second_Start_Routine();
}

///
/// @brief
///
inline void Xila_Class::System_Class::Execute_Startup_Function()
{
  (*Shell_Handle.Startup_Function_Pointer)();

  for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
  {
    if (Xila.Software.Handle[i] != NULL)
    {
      if (Xila.Software.Handle[i]->Startup_Function_Pointer != NULL)
      {
        (*Xila.Software.Handle[i]->Startup_Function_Pointer)();
      }
    }
  }
}

/**
     * @brief Function shutdown the system.
     * @details Function that execute, before making 
     * 
     */
void Xila_Class::System_Class::Shutdown()
{
  Verbose_Print_Line("Shutdown");
  Xila.Software.Execute_Shell(Software_Class::Shutdown);
  Xila.Software.Maximize_Shell();

  Xila_Task_Handle Temporary_Task_Handle;
  for (uint8_t i = 2; i < 8; i++)
  {
    if (Xila.Software.Openned[i] != NULL)
    {
      Temporary_Task_Handle = Xila.Software.Openned[i]->Task_Handle;
      Xila.Software.Openned[i]->Send_Instruction(Software_Class::Shutdown);
      vTaskResume(Temporary_Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t ii = 0; ii <= 200; ii++)
      {
        if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
        {
          break;
        }
        Xila.Task.Delay(20);
      }
      // -- Force closing the software, if not closed within 4000 ms
      if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
      {
        delete Xila.Software.Openned[i];
        vTaskDelete(Temporary_Task_Handle);
      }
      Xila.Software.Openned[i] = NULL;
    }
  }

  // Shutdown screen
  Xila.Display.Sleep();

  // Disconnect wifi
  Xila.WiFi.disconnect(true);

  Xila.Sound.Save_Registry();

  //
  Xila.Drive.end();

  Xila.Task.Delay(4000);

  //Set deep sleep
  Deep_Sleep();
}

void Xila_Class::System_Class::Hibernate()
{
  Xila.System.Create_Dump();
}

void Xila_Class::System_Class::Deep_Sleep()
{
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_deep_sleep_start();
}

void Xila_Class::System_Class::Restart()
{
  Xila.Software.Execute_Shell(Software_Class::Close);
  Xila.Software.Maximize_Shell();

  Xila_Task_Handle Temporary_Task_Handle;
  for (uint8_t i = 2; i < 8; i++)
  {
    if (Xila.Software.Openned[i] != NULL)
    {
      Temporary_Task_Handle = Xila.Software.Openned[i]->Task_Handle;
      Xila.Software.Openned[i]->Send_Instruction(Software_Class::Close);
      vTaskResume(Temporary_Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t ii = 0; ii <= 200; ii++)
      {
        if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
        {
          break;
        }
        Xila.Task.Delay(20);
      }
      // -- Force closing the software, if not closed within 4000 ms
      if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
      {
        delete Xila.Software.Openned[i];
        vTaskDelete(Temporary_Task_Handle);
      }
      Xila.Software.Openned[i] = NULL;
    }
  }

  Xila.Sound.Save_Registry();

  Xila.Drive.end();

  Xila.Task.Delay(4000);

  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_restart();
}
