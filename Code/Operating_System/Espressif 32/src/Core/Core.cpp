#include "Arduino.h"

#include "Core/Core.hpp"
#include "soc/rtc_wdt.h"

Xila_Class *Xila_Class::Instance_Pointer = NULL;

Xila_Class Xila;

Xila_Class::Xila_Class() : Tag(0),
                           Display(),
                           Sound(),
                           Battery(13, 47, 47),
                           Keyboard(),
                           Dialog_Semaphore(xSemaphoreCreateMutex()),
                           Background_Function_Counter(0)

{

  Watchdog_Reminder = false;
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  System_State = 0;
  if (Instance_Pointer != NULL)
  {
    // something went wrong
    ESP.restart();
  }
  Instance_Pointer = this;

  //strcpy(WiFi_SSID, "Avrupa");
  //strcpy(WiFi_Password, "0749230994");

#if SD_MODE == 0
  Drive = &SD_MMC;
#else
  Drive = &SD;
#endif

  memset(Current_Username, '\0', sizeof(Current_Username));

  memset(Open_Software_Pointer, NULL, sizeof(Open_Software_Pointer));
  memset(Software_Handle_Pointer, NULL, sizeof(Software_Handle_Pointer));

  memset(Device_Name, '\0', sizeof(Device_Name));

  //Core_Instruction_Queue_Handle = xQueueCreate(10, sizeof(Core_Instruction));cal
}

Xila_Class::~Xila_Class() // destructor
{
  Instance_Pointer = NULL;
}

void Xila_Class::First_Start_Routine()
{
  // -- Check if the power button was press or the power supply plugged.
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
  {
    Shutdown();
  }

  // -- Check if the battery level is enough to start.
  if (Battery.Get_Charge_Level() <= 3)
  {
    Shutdown();
  }
  pinMode(POWER_BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(POWER_BUTTON_PIN), Power_Button_Handler, FALLING);

  // -- Disable FreeRTOS watchdog and replace it with Xila watchdog

#if WATCHDOG == 0
  rtc_wdt_protect_off();
  rtc_wdt_disable();
#endif

  // --

  //Print_Line("Flash : 1,310,720 Bytes - EEPROM : 512 Bytes - RAM : " + char(ESP.getFreeHeap()) + "/ 327680 Bytes");
  Print_Line(F("Xila Embedded Edition - Alix ANNERAUD - Alpha - 0.1.0"));
  Print_Line(F("Starting Xila ..."), 0);

  // -- Initialize display. -- //

  pinMode(DISPLAY_SWITCH_PIN, OUTPUT);
  digitalWrite(DISPLAY_SWITCH_PIN, HIGH);

  Display.Set_Callback_Function_Numeric_Data(&Incomming_Numeric_Data_From_Display);
  Display.Set_Callback_Function_String_Data(&Incomming_String_Data_From_Display);
  Display.Set_Callback_Function_Event(&Incomming_Event_From_Display);
  Display.Begin();

  Display.Wake_Up();
  Display.Set_Current_Page(F("Core_Load")); // Play animation
  Display.Set_Trigger(F("LOAD_TIM"), true);

  // -- Initialize drive. -- //

#if SD_MODE == 0
  pinMode(14, INPUT_PULLUP);
  //pinMode(15, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  Drive = &SD_MMC;
#else
  Drive = &SD;
#endif

  if (!Drive->begin() || Drive->cardType() == CARD_NONE)
  {
    Display.Set_Text(F("EVENT_TXT"), F("Failed to initialize drive."));
  }
  while (!Drive->begin() || Drive->cardType() == CARD_NONE)
  {
    vTaskDelay(pdMS_TO_TICKS(50));
  }
  Display.Set_Text(F("EVENT_TXT"), F(""));

  System_State = Default;
  Xila_Event Returned_Data;

  // -- Load system registry -- //

  Returned_Data = Load_System_Registry();

  if (Returned_Data != Success)
  {

    if (Returned_Data == Error)
    {
      Panic_Handler(Damaged_System_Registry);
    }
    else if (Returned_Data == 2)
    {
      Panic_Handler(Installation_Conflict);
    }
    else if (Returned_Data == 3) // new installation
    {
      File Temporary_File = Drive->open(Display_Executable_Path);
      if (Display.Update(Temporary_File) != Display.Update_Succeed)
      {
        Verbose_Print("Display update failed");
        ESP.restart();
      }

      Display.Set_Callback_Function_Numeric_Data(&Incomming_Numeric_Data_From_Display);
      Display.Set_Callback_Function_String_Data(&Incomming_String_Data_From_Display);
      Display.Set_Callback_Function_Event(&Incomming_Event_From_Display);
      Display.Begin();
      Display.Wake_Up();
      Display.Set_Current_Page(F("Core_Load")); // Play animation
      Display.Set_Trigger(F("LOAD_TIM"), true);

      System_State = New_Installation;
    }
  }

  WiFi.setHostname(Device_Name); // Set hostname

  // -- Load sound registry --

  Returned_Data = Load_Sound_Registry();

  if (Returned_Data != Success)
  {
  }

  // -- Play startup sound

  {
    File Temporary_File = Drive->open(Startup_Sound_Path);
    Sound.Play(Temporary_File);
    Temporary_File.close();
  }

  // -- Load display registry

  Returned_Data = Load_Display_Registry();

  if (Returned_Data != Success)
  {
  }

  // WiFi :

  WiFi_Connect();

  // -- Load Time Registry
  Returned_Data = Load_Time_Registry();

  if (Returned_Data != Success)
  {
  }

  // -- Load Keyboard Registry

  Returned_Data = Load_Keyboard_Registry();

  if (Returned_Data != Success)
  {
  }

  Returned_Data = Load_Dump();
}

void Xila_Class::Second_Start_Routine()
{
  Execute_Startup_Function();

  vTaskDelay(pdMS_TO_TICKS(500));

  if (System_State == New_Installation)
  {
    Open_Software_Pointer[1]->Execute(Installation_Wizard);
  }

  xTaskCreatePinnedToCore(Xila_Class::Core_Task, "Core Task", 4 * 1024, NULL, SYSTEM_TASK_PRIORITY, &Core_Task_Handle, SYSTEM_CORE);

  vTaskDelay(pdMS_TO_TICKS(3000));
  Display.Set_Value(F("STATE_VAR"), 2);
  vTaskDelay(pdMS_TO_TICKS(1200));
}

void Xila_Class::Start(Software_Handle_Class *Software_Package, uint8_t Size)
{
  First_Start_Routine();

  // Restore attribute

  for (uint8_t i = 0; i < Size; i++)
  {
    Add_Software_Handle(Software_Package[i]);
  }

  Second_Start_Routine();
}

void Xila_Class::Start()
{
  First_Start_Routine();

  // -- Load softwares -- //

  Verbose_Print_Line("> Load software ...");

  extern Software_Handle_Class Oscilloscope_Handle;
  extern Software_Handle_Class Paint_Handle;
  extern Software_Handle_Class Calculator_Handle;
  extern Software_Handle_Class TinyBasic_Handle;
  extern Software_Handle_Class Internet_Browser_Handle;
  extern Software_Handle_Class Music_Player_Handle;
  extern Software_Handle_Class Piano_Handle;
  extern Software_Handle_Class Pong_Handle;
  extern Software_Handle_Class Signal_Generator_Handle;
  extern Software_Handle_Class Text_Editor_Handle;
  extern Software_Handle_Class Periodic_Handle;
  extern Software_Handle_Class Clock_Handle;

  Add_Software_Handle(Calculator_Handle);
  Add_Software_Handle(Clock_Handle);
  Add_Software_Handle(Internet_Browser_Handle);
  Add_Software_Handle(Music_Player_Handle);
  Add_Software_Handle(Oscilloscope_Handle);
  Add_Software_Handle(Periodic_Handle);
  Add_Software_Handle(Piano_Handle);
  Add_Software_Handle(Pong_Handle);
  Add_Software_Handle(Paint_Handle);
  Add_Software_Handle(Signal_Generator_Handle);
  Add_Software_Handle(Text_Editor_Handle);
  Add_Software_Handle(TinyBasic_Handle);

  Second_Start_Routine();
}

Xila_Event Xila_Class::WiFi_Connect()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    return Success;
  }
  File Temporary_File = Drive->open(Network_Registry_Path);
  if (!Temporary_File)
  {
    return Error;
  }
  DynamicJsonDocument Network_Registry(512);
  deserializeJson(Network_Registry, Temporary_File);
  JsonObject WiFi_Registry = Network_Registry["WiFi"];
  char Name[33];
  char Password[81];
  strlcpy(Name, WiFi_Registry["Name"], sizeof(Name));
  strlcpy(Password, WiFi_Registry["Password"], sizeof(Password));
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

void Xila_Class::Check_Watchdog()
{
  if ((millis() - Last_Watchdog_Feed) > WATCHDOG_INITAL_TIME)
  {
    if (Watchdog_Reminder == false)
    {
      Open_Software_Pointer[0]->Execute(Watchdog);
      Watchdog_Reminder = true;
    }
    else
    {
      if ((millis() - Last_Watchdog_Feed) > WATCHDOG_MAXIMUM_TIME)
      {
        Force_Close_Software();
        Watchdog_Reminder = false;
        Last_Watchdog_Feed = millis();
      }
    }
  }
}

Xila_Event Xila_Class::Load_Dump()
{
  if (!Drive->exists(Software_Dump_Registry_Path))
  {
    File Temporary_File = Drive->open(Software_Dump_Registry_Path);
    DynamicJsonDocument Dump_Registry(256);
    if (deserializeJson(Dump_Registry, Temporary_File) != DeserializationError::Ok)
    {
      return Error;
    }
    strlcpy(Current_Username, Dump_Registry["Current User"], sizeof(Current_Username));
  }
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

void Xila_Class::Shutdown()
{
  Execute_Shell(Shutting_down);
  Maximize_Shell();

  Xila_Task_Handle Temporary_Task_Handle;
  for (uint8_t i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      Temporary_Task_Handle = Open_Software_Pointer[i]->Task_Handle;
      Open_Software_Pointer[i]->Execute(Close);
      vTaskResume(Temporary_Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t ii = 0; ii <= 200; ii++)
      {
        if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
        {
          break;
        }
        vTaskDelay(pdMS_TO_TICKS(20));
      }
      // -- Force closing the software, if not closed within 4000 ms
      if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
      {
        delete Open_Software_Pointer[i];
        vTaskDelete(Temporary_Task_Handle);
      }
      Open_Software_Pointer[i] = NULL;
    }
  }

  // Shutdown screen
  Display.Sleep();

  // Disconnect wifi
  WiFi.disconnect(true);

  Set_Sound_Registry(Sound.Get_Volume());

  vTaskDelay(pdMS_TO_TICKS(4000));

  //Set deep sleep
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_deep_sleep_start();
}

void Xila_Class::Restart()
{
  Maximize_Shell();
  Execute_Shell(Close);

  Xila_Task_Handle Temporary_Task_Handle;
  for (uint8_t i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      Temporary_Task_Handle = Open_Software_Pointer[i]->Task_Handle;
      Open_Software_Pointer[i]->Execute(Close);
      vTaskResume(Temporary_Task_Handle);
      // -- Waiting for the software to close
      for (uint8_t ii = 0; ii <= 200; ii++)
      {
        if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
        {
          break;
        }
        vTaskDelay(pdMS_TO_TICKS(20));
      }
      // -- Force closing the software, if not closed within 4000 ms
      if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
      {
        delete Open_Software_Pointer[i];
        vTaskDelete(Temporary_Task_Handle);
      }
      Open_Software_Pointer[i] = NULL;
    }
  }

  Set_Sound_Registry(Sound.Get_Volume());

  vTaskDelay(pdMS_TO_TICKS(4000));

  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_restart();
}

Xila_Event Xila_Class::Create_Dump()
{
}

Xila_Event Xila_Class::Load_Executable(File Executable_File, uint8_t Type)
{
  if (!Executable_File)
  {
    return Error;
  }
  if (Executable_File.isDirectory())
  {
    return Error;
  }
  if (Executable_File.size() == 0)
  {
    return Error;
  }
  if (Type = 'M')
  {
    if (!Update.begin(Executable_File.size(), U_FLASH))
    {
      return Error;
    }
    size_t Written = Update.writeStream(Executable_File);
    if (Written != Executable_File.size())
    {
      return Error;
    }
    if (!Update.end())
    {
      return Error;
    }
    if (!Update.isFinished())
    {
      return Error;
    }
  }
  else if (Type = 'D')
  {
    if (Display.Update(Executable_File) != Display.Update_Succeed)
    {
      return Error;
    }

    // -- Initialize display. -- //

    pinMode(DISPLAY_SWITCH_PIN, OUTPUT);
    digitalWrite(DISPLAY_SWITCH_PIN, HIGH);

    Display.Set_Callback_Function_Numeric_Data(&Incomming_Numeric_Data_From_Display);
    Display.Set_Callback_Function_String_Data(&Incomming_String_Data_From_Display);
    Display.Set_Callback_Function_Event(&Incomming_Event_From_Display);
    Display.Begin();

    Display.Wake_Up();
    Display.Set_Current_Page(F("Core_Load")); // Play animation
    Display.Set_Trigger(F("LOAD_TIM"), true);

    return Success;
  }
}

// Interrput function

void IRAM_ATTR Xila_Class::Power_Button_Handler()
{
  vTaskEnterCritical(&Xila.Power_Button_Mutex);
  Xila.Power_Button_Counter = 1;
  vTaskExitCritical(&Xila.Power_Button_Mutex);
}

void Xila_Class::Check_Power_Button()
{
  if (Power_Button_Counter == 1)
  {
    Maximize_Software(Shell_Handle);
  }
}

// Callback function for display

void Xila_Class::Incomming_String_Data_From_Display(const char *Received_Data, uint8_t Size)
{
  String Temporary_String;
  switch (Received_Data[0])
  {
  case Xila.Command:
  case Xila.Command_New:
    Xila.Open_Software_Pointer[0]->Execute(Received_Data[1], Received_Data[2]);
    break;
  case Xila.Variable_String_Local:
    Xila.Open_Software_Pointer[0]->Set_Variable(Received_Data + 2, Variable_String_Local, Received_Data[0]);
    Xila.Tag = '\0';
    break;
  case Xila.Variable_String_Global:
    Xila.Open_Software_Pointer[0]->Set_Variable(Received_Data + 2, Variable_String_Local, Received_Data[0]);
    Xila.Tag = '\0';
    break;
  case Xila.Variable_Long_Local:
    Xila.Tag = Received_Data[1];
    break;
  case Xila.Variable_Long_Global:
    Xila.Tag = Received_Data[1];
    break;
  default:
    //error handle
    break;
  }
}

void Xila_Class::Incomming_Numeric_Data_From_Display(uint32_t &Received_Data)
{
  if (Xila.Tag != '\0')
  {
    Xila.Open_Software_Pointer[0]->Set_Variable(&Received_Data, Xila.Variable_Long_Local, Xila.Tag);
    Xila.Tag = '\0';
  }
  else
  {
    Xila.Event_Dialog(F("Unexpected Numeric Data Return From Display"), Error);
  }
}

void Xila_Class::Feed_Watchdog()
{
  Last_Watchdog_Feed = millis();
}

void Xila_Class::Delay(uint32_t Delay_In_Millisecond)
{
  Last_Watchdog_Feed = millis();
  vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

void Xila_Class::Incomming_Event_From_Display(uint8_t &Event_Code)
{
}

// Serial communication with commputer

void Xila_Class::Horizontal_Separator()
{
  Serial.println(F("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
}

void Xila_Class::Print_Line(const __FlashStringHelper *Text_To_Print, uint8_t const &Alignement)
{
  Serial.print(F("||"));
  Serial.print(F(" "));
  Serial.print(Text_To_Print);
  Serial.println(F("||"));
}

Xila_Event Xila_Class::Copy_File(File &Origin_File, File &Destination_File)
{
  uint8_t Readed_Bytes;
  uint8_t Buffer[255];
  if (!Origin_File || !Destination_File)
  {
    return Error;
  }
  while ((Readed_Bytes = Origin_File.read(Buffer, sizeof(Buffer))) > 0)
  {
    Destination_File.write(Buffer, Readed_Bytes);
    vTaskDelay(pdMS_TO_TICKS(2));
  }
  return Success;
}

void Xila_Class::Print_Line(const char *Text_To_Print, uint8_t const &Alignement)
{
  Serial.print(F("||"));

  if (sizeof(Text_To_Print) > 64)
  {
    //unsupported now
    return;
  }
  Remaining_Spaces = 64 - sizeof(Text_To_Print);
  switch (Alignement)
  {
  case 0: //left
    Serial.print(F(" "));
    Serial.print(Text_To_Print);
    break;
  case 1: //centered
    Serial.print(F(" "));
    for (uint8_t i = 0; i < Remaining_Spaces / 2; i++)
    {
      Serial.println(F(" "));
    }
    Serial.print(Text_To_Print);
    Remaining_Spaces /= 2;
  default:

    break;
  }
  for (uint8_t i = 0; i < Remaining_Spaces; i++)
  {
    Serial.println(F(" "));
  }
  Serial.println(F("||"));
}

void Xila_Class::Print_Line()
{
  Serial.print(F("||                                                                            ||"));
}

const char *Xila_Class::Get_Device_Name()
{
  return Device_Name;
}

void Xila_Class::Refresh_Header()
{
  uint32_t Update_Time = millis();
  static char Clock[5];
  Clock[0] = Time.tm_hour / 10;
  Clock[0] += 48;
  Clock[1] = Time.tm_hour % 10;
  Clock[1] += 48;
  Clock[2] = ':';
  Clock[3] = Time.tm_min / 10;
  Clock[3] += 48;
  Clock[4] = Time.tm_min % 10;
  Clock[4] += 48;
  Clock[5] += '\0';
  Display.Set_Text(F("CLOCK_TXT"), Clock);

  Clock[0] = WiFi.RSSI();

  if (WiFi.status() == WL_CONNECTED)
  {
    if (Clock[0] <= -70)
    {
      Display.Set_Text(F("CONNEXION_BUT"), F(WiFi_Low));
    }
    if (Clock[0] <= -50 && Clock[0] > -70)
    {
      Display.Set_Text(F("CONNEXION_BUT"), F(WiFi_Medium));
    }
    else
    {
      Display.Set_Text(F("CONNEXION_BUT"), F(WiFi_High));
    }
  }
  else
  {
    Display.Set_Text(F("CONNEXION_BUT"), F(' '));
  }

  Clock[0] = Battery.Get_Charge_Level();
  if (Clock[0] <= 15)
  {
    if (Clock[0] <= 2)
    {
      Shutdown();
    }
    Display.Set_Text(F("BATTERY_BUT"), F(Battery_Empty));
  }
  else if (Clock[0] <= 30 && Clock[0] > 15)
  {
    Display.Set_Text(F("BATTERY_BUT"), F(Battery_Low));
  }
  else if (Clock[0] <= 70 && Clock[0] > 30)
  {
    Display.Set_Text(F("BATTERY_BUT"), F(Battery_Medium));
  }
  else // more than 70 %
  {
    Display.Set_Text(F("BATTERY_BUT"), F(Battery_High));
  }

  Clock[0] = Sound.Get_Volume();
  if (Clock[0] == 0)
  {
    Display.Set_Text(F("SOUND_BUT"), F(Sound_Mute));
  }
  else if (Clock[0] < 33)
  {
    Display.Set_Text(F("SOUND_BUT"), F(Sound_Low));
  }
  else if (Clock[0] < 66)
  {
    Display.Set_Text(F("SOUND_BUT"), F(Sound_Medium));
  }
  else
  {
    Display.Set_Text(F("SOUND_BUT"), F(Sound_High));
  }
  Update_Time = millis() - Update_Time;

  Verbose_Print("Update header time :");
  Verbose_Print_Line(Update_Time);
}

void Xila_Class::Execute_Startup_Function()
{
  (*Shell_Handle.Startup_Function_Pointer)();

  for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
  {
    if (Software_Handle_Pointer[i] != NULL)
    {
      if (Software_Handle_Pointer[i]->Startup_Function_Pointer != NULL)
      {
        (*Software_Handle_Pointer[i]->Startup_Function_Pointer)();
      }
    }
  }
}

void Xila_Class::Synchronise_Time()
{
  time(&Now);
  localtime_r(&Now, &Time);
}

tm Xila_Class::Get_Time()
{
  Synchronise_Time();
  return Time;
}

void Xila_Class::Panic_Handler(uint32_t Panic_Code)
{
  vTaskSuspendAll();
  Display.Set_Current_Page(F("Core_Panic"));
  Display.Set_Text(F("ERRORCODE_TXT"), String("Error code:") + String(Panic_Code));
  while (digitalRead(POWER_BUTTON_PIN) == HIGH)
  {
  }
  ESP.restart();
}

// Create System file at 1st boot

/*void Xila_Class::Create_System_Files()
  {
    // Display Registry
    DynamicJsonDocument Display_Registry(256);
    Display_Registry["Backlight"] = 75;
    Display_Registry["Baud Rate"] = 921600;
    File Temporary_File = Drive->open(Display_Registry_Path, FILE_WRITE);
    serializeJson(Display_Registry, Temporary_File);
    Display_Registry.clear();
    Temporary_File.close();

    // Network registry
    DynamicJsonDocument Network_Registry(256);
    Network_Registry["Host name"] = "ESP32";
    Network_Registry["Number WiFi AP"] = 0;
    Temporary_File = Drive->open(Network_Registry_Path, FILE_WRITE);
    serializeJson(Display_Registry, Temporary_File);
    Network_Registry.clear();
    Temporary_File.close();

    // Regional registry
    DynamicJsonDocument Regional_Registry(256);
    Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
    serializeJson(Regional_Registry, Temporary_File);
    Regional_Registry.clear();
    Temporary_File.close();

    // Software registry
    DynamicJsonDocument Software_Registry(256);
    Temporary_File = Drive->open(Software_Registry_Path, FILE_WRITE);
    Software_Registry.clear();
    Temporary_File.close();
  }*/