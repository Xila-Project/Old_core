#include "Arduino.h"

#include "Core/Core.hpp"
#include "soc/rtc_wdt.h"


Xila_Class *Xila_Class::Instance_Pointer = NULL;

Xila_Class Xila;

Xila_Class::Xila_Class() : Tag(0),
                           Display(),
                           Sound(),
                           Battery(13, 47, 47),
                           Dialog_Semaphore(xSemaphoreCreateMutex()),
                           Background_Function_Counter(0)

{
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

// Used to initialise the core
/*
void Xila_Class::Start(Software_Handle_Class *Software_Handle_To_Start)
{
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);

  // Restore attribute
  System_State = 1;

  File Temporary_File = Drive->open(Software_Dump_Registry_Path);
  char Temporary_Char_Array[26];

  uint16_t File_Position = 0;

  uint8_t i = 2;
  while (Temporary_File.available() < (6 * sizeof(Temporary_Char_Array)))
  {
    Temporary_File.seek(File_Position);
    if (Temporary_File.peek() != '\0')
    {
      Temporary_File.readBytes(Temporary_Char_Array, sizeof(Temporary_Char_Array));
      Open_Software_Pointer[i] = new Software_Class(0);
      Open_Software_Pointer[i]->Handle_Pointer = new Software_Handle_Class(Temporary_Char_Array);
    }
    File_Position += sizeof(Temporary_Char_Array);
    i++;
  }

  File_Position = 6 * sizeof(Temporary_Char_Array);
  i = 0;
  Software_Handle_Class Temporary_Software_Handle;
  while (Temporary_File.available())
  {
    Temporary_File.seek(File_Position);
    Temporary_File.readBytes(Temporary_Char_Array, sizeof(Temporary_Char_Array));
    Temporary_Software_Handle.From_Char_Array(Temporary_Char_Array);
    if (Seek_Open_Software_Handle(Temporary_Software_Handle) != 0)
    {
      Software_Handle_Pointer[i] = Open_Software_Pointer[Seek_Open_Software_Handle(Temporary_Software_Handle)]->Handle_Pointer;
    }
    else
    {
      Add_Software_Handle(new Software_Handle_Class(Temporary_Char_Array));
    }
    File_Position += sizeof(Temporary_Char_Array);
    i++;
  }

  Temporary_File.close();

  strcpy(Current_Username, Dump_Registry["Current User"])

  {
    uint8_t Number_Software = Dump_Registry["Number Software"];
    for (uint8_t i = 0; i <= Number_Software; i++)
    {
      Software_Handle_Pointer[i] = new Software_Handle_Class();
      strcpy(Software_Handle_Pointer[i]->Name, Software_Name[i]);
      Software_Handle_Pointer[i]->Icon = Software_Icon[i];
      Software_Handle_Pointer[i]->Type = Software_Type[i];
    }
  }

  (*Shell_Handle.Startup_Function_Pointer)();
  vTaskDelay(pdMS_TO_TICKS(500));
  Open_Software(*Software_Handle_To_Start);

  xTaskCreatePinnedToCore(Xila_Class::Core_Task, "Core Task", 4 * 1024, NULL, SYSTEM_TASK_PRIORITY, &Core_Task_Handle, SYSTEM_CORE);
}*/

void Xila_Class::Start(Software_Handle_Class *Software_Handle_To_Start)
{
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();
  if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
  {
    esp_deep_sleep_start();
  }
  pinMode(POWER_BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(POWER_BUTTON_PIN), Power_Button_Handler, FALLING);

  #if WATCHDOG == 0
  rtc_wdt_protect_off();
  rtc_wdt_disable();
  #endif
  


  System_State = 0;

  Remaining_Spaces = 0;

  //Print_Line("Flash : 1,310,720 Bytes - EEPROM : 512 Bytes - RAM : " + char(ESP.getFreeHeap()) + "/ 327680 Bytes");
  Print_Line(F("Xila Embedded Edition - Alix ANNERAUD - Alpha - 0.1.0"));
  Print_Line(F("Starting Xila ..."), 0);

  // Setting interrput for power buttons

  // Initialize display
  pinMode(DISPLAY_SWITCH_PIN, OUTPUT);
  digitalWrite(DISPLAY_SWITCH_PIN, HIGH);

  Display.Set_Callback_Function_Numeric_Data(&Incomming_Numeric_Data_From_Display);
  Display.Set_Callback_Function_String_Data(&Incomming_String_Data_From_Display);
  Display.Set_Callback_Function_Event(&Incomming_Event_From_Display);
  Display.Begin();

  Display.Wake_Up();
  Display.Set_Current_Page(F("Core_Load")); // Play animation
  Display.Set_Trigger(F("LOAD_TIM"), true);

// Initialize drive
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

  uint8_t Installation_State = 0;
  Xila_Event Returned_Data;

  Returned_Data = Load_System_Registry();
  if (Returned_Data != Success)
  {
    if (Returned_Data == Error)
    {
      Display.Set_Text(F("EVENT_TXT"), "Damaged system registry.");
    }
    else if (Returned_Data == 2)
    {
      Display.Set_Text(F("EVENT_TXT"), "Incompatible installation.");
    }
    else if (Returned_Data == 3) // install
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
      Installation_State = true;
    }
  }

  // Play sound
  {
    File Temporary_File = Drive->open(Startup_Sound_Path);
    Sound.Play(Temporary_File);
    Temporary_File.close();
  }

  // WiFi :
  WiFi.setHostname(Device_Name); // Set hostname
  WiFi_Connect();

  // Set keyboard layout
  Load_Time_Registry();
  Load_Keyboard_Registry();

  // Load software (including Shell UI)
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

  Load_Software_Handle(&Calculator_Handle, F("/SOFTWARE/CALCULAT/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Clock_Handle, F("/SOFTWARE/CLOCK/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Internet_Browser_Handle, F("/SOFTWARE/INTERNET/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Music_Player_Handle, F("/SOFTWARE/MUSICPLA/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Oscilloscope_Handle, F("/SOFTWARE/OSCOPE/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Periodic_Handle, F("/SOFTWARE/PERIODIC/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Piano_Handle, F("/SOFTWARE/PIANO/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Pong_Handle, F("/SOFTWARE/PONG/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Paint_Handle, F("/SOFTWARE/PAINT/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Signal_Generator_Handle, F("/SOFTWARE/SIGNAL/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&Text_Editor_Handle, F("/SOFTWARE/TEXTEDIT/REGISTRY/SOFTWARE.GRF"));
  Load_Software_Handle(&TinyBasic_Handle, F("/SOFTWARE/TINYBASI/REGISTRY/SOFTWARE.GRF"));

  // Execute startup function of each software

  (*Shell_Handle.Startup_Function_Pointer)();

  if (Installation_State == true)
  {
    Open_Software_Pointer[1]->Execute(Installation_Wizard);
  }

  xTaskCreatePinnedToCore(Xila_Class::Core_Task, "Core Task", 4 * 1024, NULL, SYSTEM_TASK_PRIORITY, &Core_Task_Handle, SYSTEM_CORE);

  vTaskDelay(pdMS_TO_TICKS(3000));
  Display.Set_Value(F("STATE_VAR"), 2);
  vTaskDelay(pdMS_TO_TICKS(1200));
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

/**
 * Try to connect to a WiFi access point, if succed, save parameters to the Network Registry.
 * @param Name  Pointer to the WiFi access point name.
 * @param Password Char array pointer to the WiFi access point password.
 * @return Xila.Success if connected or Xila.Error if not.
*/
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
  Close_Software(Open_Software_Pointer[2]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[3]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[4]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[5]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[6]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[7]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[1]->Handle_Pointer);

  // Shutdown screen
  Display.Sleep();

  // Disconnect wifi
  WiFi.disconnect(true);

  {
    File Temporary_File = Drive->open(Sound_Registry_Path);
    DynamicJsonDocument Sound_Registry(DEFAULT_REGISTRY_SIZE);
    Sound_Registry["Registry"] = "Sound";
    Sound_Registry["Volume"] = Sound.Get_Volume();
    serializeJson(Sound_Registry, Temporary_File);
  }

  vTaskDelay(pdMS_TO_TICKS(5000));

  //Set deep sleep
  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
  esp_deep_sleep_start();
}

void Xila_Class::Restart()
{
  Close_Software(Open_Software_Pointer[2]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[3]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[4]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[5]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[6]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[7]->Handle_Pointer);
  Close_Software(Open_Software_Pointer[1]->Handle_Pointer);

  esp_restart();
}

Xila_Event Xila_Class::Create_Dump()
{
}

Xila_Event Xila_Class::Update()
{
  File Temporary_File = Drive->open(Display_Executable_Path);
  if (!Temporary_File)
  {
    return Error;
  }
  if (Load_Executable(Temporary_File, 'D') != Success)
  {
    return Error;
  }

  Temporary_File = Drive->open(Microcontroller_Executable_Path);
  if (!Temporary_File)
  {
    return Error;
  }
  if (Load_Executable(Temporary_File, 'M') != Success)
  {
    return Error;
  }

  Restart();
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
    if (Create_Dump() != Success)
    {
      return Error;
    }
    if (!Update.begin(Executable_File.size()))
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
    if (Open_Software_Pointer[0] != NULL)
    {
      vTaskResume(Open_Software_Pointer[0]->Task_Handle);
      Open_Software_Pointer[0]->Execute(Xila.Hiberrnate);
    }
    if (Open_Software_Pointer[2] != NULL)
    {
      vTaskResume(Open_Software_Pointer[2]->Task_Handle);
      Open_Software_Pointer[2]->Execute(Xila.Hiberrnate);
    }
    if (Open_Software_Pointer[3] != NULL)
    {
      vTaskResume(Open_Software_Pointer[3]->Task_Handle);
      Open_Software_Pointer[3]->Execute(Xila.Hiberrnate);
    }
    if (Open_Software_Pointer[4] != NULL)
    {
      vTaskResume(Open_Software_Pointer[4]->Task_Handle);
      Open_Software_Pointer[4]->Execute(Xila.Hiberrnate);
    }
    if (Open_Software_Pointer[5] != NULL)
    {
      vTaskResume(Open_Software_Pointer[5]->Task_Handle);
      Open_Software_Pointer[5]->Execute(Xila.Hiberrnate);
    }
    if (Open_Software_Pointer[6] != NULL)
    {
      vTaskResume(Open_Software_Pointer[6]->Task_Handle);
      Open_Software_Pointer[6]->Execute(Xila.Hiberrnate);
    }
    if (Open_Software_Pointer[7] != NULL)
    {
      vTaskResume(Open_Software_Pointer[7]->Task_Handle);
      Open_Software_Pointer[7]->Execute(Xila.Hiberrnate);
    }
    esp_restart();
  }
  else if (Type = 'D')
  {
    if (Display.Update(Executable_File) != Display.Update_Succeed)
    {
      return Error;
    }
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
  case Xila.Keyboard_Dialog:
    Maximize_Shell();
    Shell_Execute();
    Xila.Open_Software_Pointer[1]->Execute('O', 'K');
    break;
  case Xila.Numpad_Dialog:
    Maximize_Shell();
    Shell_Execute();
    Xila.Open_Software_Pointer[1]->Execute('O', 'k');
    break;
  case Xila.Event:
    Xila.Event_Reply = (Xila_Event)Received_Data[1];
    break;
  case Xila.Variable_String_Local:
    Temporary_String = String(Received_Data + 2);
    Xila.Open_Software_Pointer[0]->Set_Variable(&Temporary_String, Variable_String_Local, Received_Data[0]);
    break;
  case Xila.Variable_Char_Local:
    Xila.Open_Software_Pointer[0]->Set_Variable(Received_Data + 2, Variable_Char_Local, Received_Data[1], Size);
    Xila.Tag = '\0';
    break;
  case Xila.Variable_String_Global:
    Temporary_String = String(Received_Data + 2);
    Xila.Open_Software_Pointer[0]->Set_Variable(&Temporary_String, Variable_String_Local, Received_Data[0]);
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
  Current_Software_Watchdog = millis();
}

void Xila_Class::Delay(uint32_t Delay_In_Millisecond)
{
  Current_Software_Watchdog = millis();
  vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

void Xila_Class::Incomming_Event_From_Display(uint8_t &Event_Code)
{
}

void Xila_Class::Rollback()
{
  File Temporary_File = Drive->open(Display_Executable_Path);
  while (Display.Update(Temporary_File) != Display.Update_Succeed)
  {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  Temporary_File = Drive->open(Microcontroller_Executable_Path);
  while (Load_Executable(Temporary_File))
  {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
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

void Xila_Class::Execute_Shell(uint16_t const &Command)
{
  Open_Software_Pointer[1]->Execute(Command);
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
  for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
  {
    if (Software_Handle_Pointer[i]->Startup_Function_Pointer != NULL)
    {
      (*Software_Handle_Pointer[i]->Startup_Function_Pointer)();
    }
  }
}

void Xila_Class::Execute_Background_Jobs()
{
  if ((millis() - Last_Execution) > 250)
  {
    if (Software_Handle_Pointer[Background_Function_Counter] != NULL)
    {
      if (Software_Handle_Pointer[Background_Function_Counter]->Background_Function_Pointer != NULL)
      {
        (*Software_Handle_Pointer[Background_Function_Counter]->Background_Function_Pointer)();
      }
      Background_Function_Counter = millis();
    }
    else
    {
      Background_Function_Counter = 0;
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