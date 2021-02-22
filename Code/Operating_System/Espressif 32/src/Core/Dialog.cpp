#include "Core/Core.hpp"

Xila_Event Xila_Class::Keyboard_Dialog(char *Char_Array_To_Get, size_t Char_Array_Size, bool Masked_Input)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);

  Verbose_Print_Line("Keyboard dialog");

  Feed_Watchdog();

  Display.Send_Raw(F("PAGE=dp"));

  Dialog_State = None;
  Dialog_Pointer = Char_Array_To_Get;
  Dialog_Long[0] = Char_Array_Size - 1;
  Dialog_Long[1] = Masked_Input;
  Caller_Software_Handle_Pointer = Open_Software_Pointer[0]->Handle_Pointer;

  Execute_Shell(Virtual_Keyboard);

  if (Maximize_Software(Shell_Handle) != Success)
  {
    Verbose_Print_Line("Failed to maximize shell");
  }

  vTaskSuspend(NULL);

  // -- Tasks suspended here

  Display.Set_Current_Page(F("PAGE"));

  Maximize_Software(*Caller_Software_Handle_Pointer);

  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Keypad_Dialog(float &Number_To_Get)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  Display.Send_Raw(F("PAGE=dp"));

  Dialog_State = None;
  Dialog_Pointer = &Number_To_Get;

  Caller_Software_Handle_Pointer = Open_Software_Pointer[0]->Handle_Pointer;

  Execute_Shell(Virtual_Keypad);
  Maximize_Shell();

  // -- Tasks suspended here

  Display.Set_Current_Page(F("PAGE"));

  Maximize_Software(*Caller_Software_Handle_Pointer);

  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Color_Picker_Dialog(uint16_t &Color)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  Display.Send_Raw(F("PAGE=dp"));

  Dialog_State = None;
  Dialog_Pointer = &Color;

  Caller_Software_Handle_Pointer = Open_Software_Pointer[0]->Handle_Pointer;

  Execute_Shell(Color_Picker);
  Maximize_Shell();

  // -- Tasks suspended here

  return Dialog_State;
}

Xila_Event Xila_Class::Event_Dialog(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  Display.Send_Raw(F("PAGE=dp")); // save app page id
  Display.Set_Current_Page(F("Shell_Event"));

  Dialog_State = None;

  // Currently handle by the core, but will be soon mooved to shell

  if (Button_Text_1 != NULL)
  {
    Display.Set_Text(F("BUTTON1_BUT"), Button_Text_1);
    if (Button_Text_2 != NULL)
    {
      Display.Set_Text(F("BUTTON2_BUT"), Button_Text_2);
    }
    else
    {
      Display.Set_Text(F("BUTTON2_BUT"), F(""));
    }
    if (Button_Text_3 != NULL)
    {
      Display.Set_Text(F("BUTTON3_BUT"), Button_Text_3);
    }
    else
    {
      Display.Set_Text(F("BUTTON3_BUT"), F(""));
    }
  }
  else
  {
    Display.Set_Text(F("BUTTON1_BUT"), F("Yes"));
    Display.Set_Text(F("BUTTON2_BUT"), F("No"));
    Display.Set_Text(F("BUTTON3_BUT"), F("Cancel"));
  }
  Display.Set_Text(F("MESSAGE_TXT"), Message);
  switch (Event_Type)
  {
  case Error:
    Display.Set_Text(F("ICON_TXT"), F(Cross));
    Display.Set_Font_Color(F("ICON_TXT"), Red);
    Display.Set_Text(F("TITLE_TXT"), F("Error"));
    break;
  case Warning:
    Display.Set_Text(F("EVENT_PIC"), F(Exclamation_Mark));
    Display.Set_Font_Color(F("ICON_TXT"), Yellow);
    Display.Set_Text(F("TITLE_TXT"), F("Warning"));
    break;
  case Information:
    Display.Set_Text(F("EVENT_PIC"), F(Exclamation_Mark));
    Display.Set_Font_Color(F("ICON_TXT"), Blue);
    Display.Set_Text(F("TITLE_TXT"), F("Information"));
    break;
  case Question:
    Display.Set_Text(F("EVENT_PIC"), F(Question_Mark));
    Display.Set_Font_Color(F("ICON_TXT"), Green);
    Display.Set_Text(F("TITLE_TXT"), F("Question"));
  default:
    break;
  }
  Display.Refresh(F("CLOSE_PIC"));

  Execute_Shell(Event);
  Maximize_Shell();

  // -- Tasks is suspended here

  Display.Set_Current_Page(F("PAGE")); //go back to app page

  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Open_File_Dialog(File &File_To_Open)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();
  Dialog_Pointer = NULL;
  Dialog_State = None;
  Caller_Software_Handle_Pointer = Open_Software_Pointer[0]->Handle_Pointer;

  Display.Send_Raw(F("PAGE=dp"));

  Execute_Shell(Open_File);
  Maximize_Shell();

  // -- Task Suspended here

  Display.Set_Current_Page(F("PAGE")); //go back to app page

  if (Dialog_State == Button_1)
  {
    File_To_Open = *(File *)Dialog_Pointer;
  }

  Maximize_Software(*Caller_Software_Handle_Pointer);

  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Save_File_Dialog(File &File_To_Save)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();
  Dialog_Pointer = NULL;
  Dialog_State = None;
  Caller_Software_Handle_Pointer = Open_Software_Pointer[0]->Handle_Pointer;

  Display.Send_Raw(F("PAGE=dp"));

  Execute_Shell(Save_File);
  Maximize_Shell();

  // -- Task is suspended here, because the shell is running

  Display.Set_Current_Page(F("PAGE")); //go back to app page

  if (Dialog_State == Xila.Button_1)
  {
    File_To_Save = *(File *)Dialog_Pointer;
  }

  Maximize_Software(*Caller_Software_Handle_Pointer);

  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Open_Folder_Dialog(File &Folder_To_Open)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();
  Dialog_Pointer = NULL;
  Dialog_State = None;
  Software_Handle_Class *Temporary_Software_Handle = Open_Software_Pointer[0]->Handle_Pointer;

  Display.Send_Raw(F("PAGE=dp"));

  Execute_Shell(Open_Folder);
  Maximize_Shell();

  // -- Tasks is suspended here

  Display.Set_Current_Page(F("PAGE"));

  if (Dialog_State == Xila.Button_1)
  {
    Folder_To_Open = *(File *)Dialog_Pointer;
  }

  Maximize_Software(*Temporary_Software_Handle);

  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}