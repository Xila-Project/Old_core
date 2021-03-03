#include "Arduino.h"

#include "Core/Core.hpp"

Xila_Class *Xila_Class::Instance_Pointer = NULL;

Xila_Class Xila;

Xila_Class::Xila_Class() : Tag(0),
                           Display(),
                           Sound(),
                           Battery(36, 47, 47),
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

  memset(Device_Name, '\0', sizeof(Device_Name));

  //Core_Instruction_Queue_Handle = xQueueCreate(10, sizeof(Core_Instruction));cal
}

Xila_Class::~Xila_Class() // destructor
{
  Instance_Pointer = NULL;
  vSemaphoreDelete(Dialog_Semaphore);
}

void Xila_Class::Check_Watchdog()
{
  if ((millis() - Last_Watchdog_Feed) > WATCHDOG_INITAL_TIME)
  {
    if (Watchdog_Reminder == false)
    {
      Verbose_Print_Line("Watchdog warning sent");
      Open_Software_Pointer[0]->Execute(Watchdog);
      Watchdog_Reminder = true;
    }
    else
    {
      if ((millis() - Last_Watchdog_Feed) > WATCHDOG_MAXIMUM_TIME)
      {
        Verbose_Print_Line("Watchdog triggered, close software");
        Force_Close_Software();
        Watchdog_Reminder = false;
        Last_Watchdog_Feed = millis();
      }
    }
  }
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
  if (Type == 'M')
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
    
    return Success;
  }
  else if (Type == 'D')
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
  return Error;
}


// Callback function for display

void Xila_Class::Incomming_String_Data_From_Display(const char *Received_Data, uint8_t Size)
{
  String Temporary_String;
  while (Xila.Open_Software_Pointer[0] == NULL)
  {
    Verbose_Print_Line("NULL Open_Software_Pointer[0]");
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  switch (Received_Data[0])
  {
  case Xila.Command:
  case Xila.Command_New:
    Xila.Open_Software_Pointer[0]->Execute(Received_Data[1], Received_Data[2]);
    break;
  case Xila.Variable_String_Local:
    Xila.Open_Software_Pointer[0]->Set_Variable(Received_Data + 2, Variable_String_Local, Received_Data[1]);
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

void Xila_Class::Incomming_Numeric_Data_From_Display(uint32_t Received_Data)
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



void Xila_Class::Incomming_Event_From_Display(uint8_t Event_Code)
{
  switch (Event_Code)
  {
  case Nextion_Display_Class::Current_Page_Number:
    Xila.Refresh_Header();
    break;
  case Nextion_Display_Class::Serial_Buffer_Overflow:
    Verbose_Print_Line("Display buffer overflow");
    break;
  default:
    break;
  }
  //Xila.Open_Software_Pointer[0]->Execute((uint16_t)Event_Code);
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

  static char Temporary_Char_Array[6];

  // -- Update clock
  Temporary_Char_Array[0] = Time.tm_hour / 10;
  Temporary_Char_Array[0] += 48;
  Temporary_Char_Array[1] = Time.tm_hour % 10;
  Temporary_Char_Array[1] += 48;
  Temporary_Char_Array[2] = ':';
  Temporary_Char_Array[3] = Time.tm_min / 10;
  Temporary_Char_Array[3] += 48;
  Temporary_Char_Array[4] = Time.tm_min % 10;
  Temporary_Char_Array[4] += 48;
  Temporary_Char_Array[5] = '\0';

  Display.Set_Text(F("CLOCK_TXT"), Temporary_Char_Array);

  // Update connexion
  Temporary_Char_Array[5] = WiFi.RSSI();

  if (WiFi.status() == WL_CONNECTED)
  {
    if (Temporary_Char_Array[5] <= -70)
    {
      Display.Set_Text(F("CONNEXION_BUT"), WiFi_Low);
    }
    if (Temporary_Char_Array[0] <= -50 && Temporary_Char_Array[0] > -70)
    {
      Display.Set_Text(F("CONNEXION_BUT"), WiFi_Medium);
    }
    else
    {
      Display.Set_Text(F("CONNEXION_BUT"), WiFi_High);
    }
  }
  else
  {
    Display.Set_Text(F("CONNEXION_BUT"), ' ');

  }

  // -- Update charge level
  Temporary_Char_Array[5] = Battery.Get_Charge_Level();
  
  if (Temporary_Char_Array[5] <= 15)
  {
    #if BATTERY_CHECKING == 1
    if (Temporary_Char_Array[5] <= 2)
    {
      Shutdown();
    }
    #endif
    Display.Set_Text(F("BATTERY_BUT"), Battery_Empty);
    
  }
  else if (Temporary_Char_Array[5] <= 30 && Temporary_Char_Array[5] > 15)
  {
    Display.Set_Text(F("BATTERY_BUT"), Battery_Low);
  }
  else if (Temporary_Char_Array[5] <= 70 && Temporary_Char_Array[5] > 30)
  {
    Display.Set_Text(F("BATTERY_BUT"), Battery_Medium);
  }
  else // more than 70 %
  {
    Display.Set_Text(F("BATTERY_BUT"), Battery_High);
  }



  // -- Update sound
  Temporary_Char_Array[5] = Sound.Get_Volume();
  
  if (Temporary_Char_Array[5] == 0)
  {
    Display.Set_Text(F("SOUND_BUT"), Sound_Mute);
  }
  else if (Temporary_Char_Array[5] < 33)
  {
    Display.Set_Text(F("SOUND_BUT"), Sound_Low);
  }
  else if (Temporary_Char_Array[5] < 66)
  {
    Display.Set_Text(F("SOUND_BUT"), Sound_Medium);
  }
  else
  {
    Display.Set_Text(F("SOUND_BUT"), Sound_High);
  }

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

void Xila_Class::Check_System_Drive()
{
  if (Drive->cardType() == CARD_NONE)
  {
    Panic_Handler(System_Drive_Failure);
  }
}

void Xila_Class::Panic_Handler(uint32_t Panic_Code)
{
  vTaskSuspendAll();
  Display.Set_Current_Page(F("Core_Panic"));
  Display.Set_Text(F("ERRORCODE_TXT"), String("Error code: ") + String(Panic_Code));
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