#include "Core/Core.hpp"

extern Software_Handle_Class Shell_Handle;

Xila_Class::Dialog_Class::Dialog_Class()
{
  Semaphore = xSemaphoreCreateMutex();
}



Xila_Class::Event Xila_Class::Dialog_Class::Keyboard(char *Char_Array_To_Get, size_t Char_Array_Size, bool Masked_Input)
{
  xSemaphoreTake(Semaphore, portMAX_DELAY);
  // -- Save context
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  Xila.Display.Send_Raw(F("PAGE=dp"));
  // -- Initialize attributes
  State = Xila.None;
  Pointer = Char_Array_To_Get;
  Long[0] = Char_Array_Size - 1;
  Long[1] = Masked_Input;
  // -- Maximzie shell
  Xila.Software.Openned[0] = NULL;
  Xila.Software.Maximize(Shell_Handle);
  Xila.Software.Openned[1]->Send_Instruction(Software_Class::Dialog_Keyboard);
  // -- Tasks suspended here
  while (State == Xila.None)
  {
    Xila.Dialog.Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds();
    Xila.Task.Delay(20);
  }
  // -- Retore software state
  Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
  Xila.Display.Set_Current_Page(F("PAGE"));
  // -- Clear attributes
  Pointer = NULL;
  Long[0] = 0;
  Long[1] = 0;
  Xila.Dialog.Caller_Software = NULL;
  // -- Wait 5 ms to switch page
  Xila.Task.Delay(20);
  // -- Give semaphore back and return dialog result
  xSemaphoreGive(Semaphore);
  return State;
}

Xila_Class::Event Xila_Class::Dialog_Class::Keypad(float &Number_To_Get)
{
  xSemaphoreTake(Semaphore, portMAX_DELAY);
  // -- Save context
  Xila.Display.Send_Raw(F("PAGE=dp"));
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  //
  State = None;
  Pointer = &Number_To_Get;

  // --
  Xila.Software.Openned[0] = NULL;
  Xila.Software.Maximize(Shell_Handle);
  Xila.Software.Openned[1]->Send_Instruction(Software_Class::Dialog_Keypad);

  // -- Tasks suspended here
  while (State == Xila.None)
  {
    Xila.Dialog.Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds();
    Xila.Task.Delay(20);
  }

  Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
  Xila.Display.Set_Current_Page(F("PAGE"));

  Xila.Task.Delay(20);
  //
  Pointer = NULL;
  Long[0] = 0;
  Long[1] = 0;
  Xila.Dialog.Caller_Software = NULL;
  //
  xSemaphoreGive(Semaphore);
  return State;
}

Xila_Class::Event Xila_Class::Dialog_Class::Color_Picker(uint16_t &Color)
{
  xSemaphoreTake(Semaphore, portMAX_DELAY);

  // -- Save context
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  Xila.Display.Send_Raw(F("PAGE=dp"));
  // --
  State = None;
  Pointer = &Color;
  // --
  Xila.Software.Openned[0] = NULL;
  Xila.Software.Maximize(Shell_Handle);
  Xila.Software.Openned[1]->Send_Instruction(Software_Class::Dialog_Color_Picker);
  // -- Tasks suspended here
  while (State == Xila.None)
  {
    Xila.Dialog.Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds();
    Xila.Task.Delay(20);
  }
  // -- Retore software state
  Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
  Xila.Display.Set_Current_Page(F("PAGE"));
  
  Xila.Task.Delay(20);
  //
  Pointer = NULL;
  Xila.Dialog.Caller_Software = NULL;
  //
  xSemaphoreGive(Semaphore);
  return State;
}

Xila_Class::Event Xila_Class::Dialog_Class::Event(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  xSemaphoreTake(Semaphore, portMAX_DELAY);

  // -- Save context
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  Xila.Display.Send_Raw(F("PAGE=dp")); // save app page id
  // -- Initalize variable
  State = None;
  Pointer = NULL;
  // -- Open
  Xila.Software.Openned[0] = NULL;
  Xila.Display.Set_Current_Page(F("Shell_Event"));
  Xila.Software.Maximize(Shell_Handle);
  // Currently handle by the core, but will be soon mooved to shell

  if (Button_Text_1 != NULL)
  {
    Xila.Display.Set_Text(F("BUTTON1_BUT"), Button_Text_1);
    if (Button_Text_2 != NULL)
    {
      Xila.Display.Set_Text(F("BUTTON2_BUT"), Button_Text_2);
    }
    else
    {
      Xila.Display.Set_Text(F("BUTTON2_BUT"), F(""));
    }
    if (Button_Text_3 != NULL)
    {
      Xila.Display.Set_Text(F("BUTTON3_BUT"), Button_Text_3);
    }
    else
    {
      Xila.Display.Set_Text(F("BUTTON3_BUT"), F(""));
    }
  }

  Xila.Display.Set_Text(F("MESSAGE_TXT"), Message);
  switch (Event_Type)
  {
  case Error:
    Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Cross);
    Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Red);
    Xila.Display.Set_Text(F("HEADER_TXT"), F("Error"));
    break;
  case Warning:
    Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
    Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Yellow);
    Xila.Display.Set_Text(F("HEADER_TXT"), F("Warning"));
    break;
  case Information:
    Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
    Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Blue);
    Xila.Display.Set_Text(F("HEADER_TXT"), F("Information"));
    break;
  case Question:
    Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Question_Mark);
    Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Green);
    Xila.Display.Set_Text(F("HEADER_TXT"), F("Question"));
  default:
    break;
  }
  Xila.Display.Refresh(F("CLOSE_BUT"));
  // -- Tasks is suspended here
  while (Xila.Dialog.State == Xila.None)
  {
    Xila.Dialog.Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds();
    Xila.Task.Delay(20);
  }
  // -- Restore software state
  Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
  Xila.Display.Set_Current_Page(F("PAGE"));
  //
  Pointer = NULL;
  Long[0] = 0;
  Long[1] = 0;
  Xila.Dialog.Caller_Software = NULL;
  //

  Xila.Task.Delay(60);

  xSemaphoreGive(Semaphore);
  return State;
}

Xila_Class::Event Xila_Class::Dialog_Class::Open_File(File &File_To_Open)
{
  xSemaphoreTake(Semaphore, portMAX_DELAY);
  // -- Save context
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  Xila.Display.Send_Raw(F("PAGE=dp"));
  // -- Initalize variable
  Pointer = &File_To_Open;
  State = None;
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  // --
  Xila.Software.Openned[0] = NULL;
  Xila.Software.Maximize(Shell_Handle);
  Xila.Software.Openned[1]->Send_Instruction(Software_Class::Dialog_Open_File);
  // -- Tasks suspended here
  while (State == Xila.None)
  {
    
    Xila.Dialog.Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds();
    Xila.Task.Delay(20);
  }
  if (State == Button_1)
  {
    File_To_Open = *(File *)Pointer;
  }
  // -- Retore software state
  Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
  Xila.Display.Set_Current_Page(F("PAGE"));
  
  Xila.Task.Delay(20);
  // --
  Pointer = NULL;
  Xila.Dialog.Caller_Software = NULL;
  //
  xSemaphoreGive(Semaphore);
  return State;
}

Xila_Class::Event Xila_Class::Dialog_Class::Save_File(File &File_To_Save)
{
  xSemaphoreTake(Semaphore, portMAX_DELAY);

  // -- Save context
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  Xila.Display.Send_Raw(F("PAGE=dp"));
  // -- Intiliaze attributes
  Pointer = &File_To_Save;
  State = None;
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  // --
  Xila.Software.Openned[0] = NULL;
  Xila.Software.Maximize(Shell_Handle);
  Xila.Software.Openned[1]->Send_Instruction(Software_Class::Dialog_Save_File);
  // -- Tasks suspended here
  while (State == Xila.None)
  {
    Xila.Dialog.Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds();
    Xila.Task.Delay(20);
  }
  if (State == Button_1)
  {
    File_To_Save = *(File *)Pointer;
  }
  // -- Retore software state
  Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
  Xila.Display.Set_Current_Page(F("PAGE"));
  
  Xila.Task.Delay(20);
  // -- Reset attributes
  Pointer = NULL;
  Xila.Dialog.Caller_Software = NULL;
  //

  xSemaphoreGive(Semaphore);
  return State;
}

Xila_Class::Event Xila_Class::Dialog_Class::Dialog_Open_Folder(File &Folder_To_Open)
{
  xSemaphoreTake(Semaphore, portMAX_DELAY);

  // -- Save context
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  Xila.Display.Send_Raw(F("PAGE=dp"));
  // --
  Pointer = &Folder_To_Open;
  State = None;
  Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
  // --
  Xila.Software.Openned[0] = NULL;
  Xila.Software.Maximize(Shell_Handle);
  Xila.Software.Openned[1]->Send_Instruction(Software_Class::Dialog_Open_Folder);
  // -- Tasks suspended here
  while (State == None)
  {
    Xila.Dialog.Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds();
    Xila.Task.Delay(20);
  }
  if (State == Button_1)
  {
    Folder_To_Open = *(File *)Pointer;
  }
  // -- Retore software state
  Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
  Xila.Display.Set_Current_Page(F("PAGE"));

  Xila.Task.Delay(20);
  //
  Pointer = NULL;
  Xila.Dialog.Caller_Software = NULL;
  xSemaphoreGive(Semaphore);
  return State;
}