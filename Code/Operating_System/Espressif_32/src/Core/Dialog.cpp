#include "Core/Core.hpp"

Xila_Event Xila_Class::Keyboard_Dialog(char *Char_Array_To_Get, size_t Char_Array_Size, bool Masked_Input)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  Verbose_Print_Line("Keyboard dialog");

  // -- Save context
  Caller_Software_Pointer = Open_Software_Pointer[0];
  Display.Send_Raw(F("PAGE=dp"));
  // -- Initalize variable
  Dialog_State = None;
  Dialog_Pointer = Char_Array_To_Get;
  Dialog_Long[0] = Char_Array_Size - 1;
  Dialog_Long[1] = Masked_Input;
  // --
  Open_Software_Pointer[0] = NULL;
  Software_Maximize(Shell_Handle);
  Open_Software_Pointer[1]->Send_Instruction(Virtual_Keyboard);
  // -- Tasks suspended here
  while (Xila.Dialog_State == Xila.None)
  {
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  // -- Retore software state
  Open_Software_Pointer[0] = Caller_Software_Pointer;
  Display.Set_Current_Page(F("PAGE"));
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Keypad_Dialog(float &Number_To_Get)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  // -- Save context
  Caller_Software_Pointer = Open_Software_Pointer[0];
  Display.Send_Raw(F("PAGE=dp"));
  //
  Dialog_State = None;
  Dialog_Pointer = &Number_To_Get;

  // --
  Open_Software_Pointer[0] = NULL;
  Software_Maximize(Shell_Handle);
  Open_Software_Pointer[1]->Send_Instruction(Virtual_Keypad);

  // -- Tasks suspended here
  while (Xila.Dialog_State == Xila.None)
  {
    vTaskDelay(pdMS_TO_TICKS(20));
  }

  Open_Software_Pointer[0] = Caller_Software_Pointer;
  Display.Set_Current_Page(F("PAGE"));
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Color_Picker_Dialog(uint16_t &Color)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  // -- Save context
  Caller_Software_Pointer = Open_Software_Pointer[0];
  Display.Send_Raw(F("PAGE=dp"));
  // --
  Dialog_State = None;
  Dialog_Pointer = &Color;
  // --
  Open_Software_Pointer[0] = NULL;
  Software_Maximize(Shell_Handle);
  Open_Software_Pointer[1]->Send_Instruction(Color_Picker);
  // -- Tasks suspended here
  while (Xila.Dialog_State == Xila.None)
  {
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  // -- Retore software state
  Open_Software_Pointer[0] = Caller_Software_Pointer;
  Display.Set_Current_Page(F("PAGE"));
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Event_Dialog(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();
  // -- Save context
  Caller_Software_Pointer = Open_Software_Pointer[0];
  Display.Send_Raw(F("PAGE=dp")); // save app page id
  // -- Initalize variable
  Dialog_State = None;
  // -- Open
  Open_Software_Pointer[0] = NULL;
  Display.Set_Current_Page(F("Shell_Event"));
  Software_Maximize(Shell_Handle);
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

  Display.Set_Text(F("MESSAGE_TXT"), Message);
  switch (Event_Type)
  {
  case Error:
    Display.Set_Text(F("ICON_TXT"), Cross);
    Display.Set_Font_Color(F("ICON_TXT"), Red);
    Display.Set_Text(F("HEADER_TXT"), F("Error"));
    break;
  case Warning:
    Display.Set_Text(F("ICON_TXT"), Exclamation_Mark);
    Display.Set_Font_Color(F("ICON_TXT"), Yellow);
    Display.Set_Text(F("HEADER_TXT"), F("Warning"));
    break;
  case Information:
    Display.Set_Text(F("ICON_TXT"), Exclamation_Mark);
    Display.Set_Font_Color(F("ICON_TXT"), Blue);
    Display.Set_Text(F("HEADER_TXT"), F("Information"));
    break;
  case Question:
    Display.Set_Text(F("ICON_TXT"), Question_Mark);
    Display.Set_Font_Color(F("ICON_TXT"), Green);
    Display.Set_Text(F("HEADER_TXT"), F("Question"));
  default:
    break;
  }
  Display.Refresh(F("CLOSE_BUT"));
  // -- Tasks is suspended here
  while (Xila.Dialog_State == Xila.None)
  {
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  // -- Restore software state
  Open_Software_Pointer[0] = Caller_Software_Pointer;
  Display.Set_Current_Page(F("PAGE"));
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Open_File_Dialog(File &File_To_Open)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  // -- Save context
  Caller_Software_Pointer = Open_Software_Pointer[0];
  Display.Send_Raw(F("PAGE=dp"));
  // -- 
  Dialog_Pointer = &File_To_Open;
  Dialog_State = None;
  Caller_Software_Pointer = Open_Software_Pointer[0];
   // --
  Open_Software_Pointer[0] = NULL;
  Software_Maximize(Shell_Handle);
  Open_Software_Pointer[1]->Send_Instruction(Open_File);
  // -- Tasks suspended here
  while (Xila.Dialog_State == Xila.None)
  {
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  if (Dialog_State == Button_1)
  {
    File_To_Open = *(File *)Dialog_Pointer;
  }
  // -- Retore software state
  Open_Software_Pointer[0] = Caller_Software_Pointer;
  Display.Set_Current_Page(F("PAGE"));
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Save_File_Dialog(File &File_To_Save)
{
   xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  // -- Save context
  Caller_Software_Pointer = Open_Software_Pointer[0];
  Display.Send_Raw(F("PAGE=dp"));
  // -- 
  Dialog_Pointer = &File_To_Save;
  Dialog_State = None;
  Caller_Software_Pointer = Open_Software_Pointer[0];
   // --
  Open_Software_Pointer[0] = NULL;
  Software_Maximize(Shell_Handle);
  Open_Software_Pointer[1]->Send_Instruction(Save_File);
  // -- Tasks suspended here
  while (Xila.Dialog_State == Xila.None)
  {
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  if (Dialog_State == Button_1)
  {
    File_To_Save = *(File *)Dialog_Pointer;
  }
  // -- Retore software state
  Open_Software_Pointer[0] = Caller_Software_Pointer;
  Display.Set_Current_Page(F("PAGE"));
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Open_Folder_Dialog(File &Folder_To_Open)
{
     xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Feed_Watchdog();

  // -- Save context
  Caller_Software_Pointer = Open_Software_Pointer[0];
  Display.Send_Raw(F("PAGE=dp"));
  // -- 
  Dialog_Pointer = &Folder_To_Open;
  Dialog_State = None;
  Caller_Software_Pointer = Open_Software_Pointer[0];
   // --
  Open_Software_Pointer[0] = NULL;
  Software_Maximize(Shell_Handle);
  Open_Software_Pointer[1]->Send_Instruction(Open_Folder);
  // -- Tasks suspended here
  while (Xila.Dialog_State == Xila.None)
  {
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  if (Dialog_State == Button_1)
  {
    Folder_To_Open = *(File *)Dialog_Pointer;
  }
  // -- Retore software state
  Open_Software_Pointer[0] = Caller_Software_Pointer;
  Display.Set_Current_Page(F("PAGE"));
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}