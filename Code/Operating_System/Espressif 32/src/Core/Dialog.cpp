#include "Core/Core.hpp"

Xila_Event Xila_Class::Keyboard_Dialog(char* Char_Array_To_Get, size_t Char_Array_Size, bool Masked_Input)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Maximize_Shell();
  Dialog_Pointer = Char_Array_To_Get;
  Dialog_Long = Char_Array_Size;
  Dialog_Byte = Masked_Input;
  Dialog_State = None;
  Execute_Shell(Instruction::Keyboard_Dialog);
  while (Dialog_State == None)
  {
    vTaskDelay(pdMS_TO_TICKS(30));
  }

  Dialog_Pointer = NULL;
  Dialog_Long = 0;
  xSemaphoreGive(Dialog_Semaphore);
  if (Dialog_State == Success)
  {
    Dialog_State = None;
    return Success;
  }
  else
  {
    Dialog_State = None;
    return Error;
  }
}

Xila_Event Xila_Class::Keypad_Dialog(float& Number_To_Get)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Maximize_Shell();
  Dialog_Long = Number_To_Get;
  Dialog_State = None;
  Execute_Shell(Instruction::Keypad_Dialog);
  while (Dialog_State == None)
  {
    vTaskDelay(pdMS_TO_TICKS(30));
  }
  memcpy(&Number_To_Get, &Dialog_Long, sizeof(uint32_t));
  xSemaphoreGive(Dialog_Semaphore);
  if (Dialog_State == Success)
  {
    Dialog_State = None;
    return Success;
  }
  else
  {
    Dialog_State = None;
    return Error;
  }
}

/*
Xila_Event Xila_Class::Color_Picker_Dialog(uint16_t& Color)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Dialog_Reply = NULL;
  while (Dialog_Reply == NULL)
  {

  }
  
}*/

Xila_Event Xila_Class::Event_Dialog(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Maximize_Shell();
  Dialog_State = None;
  Execute_Shell(Instruction::Event_Dialog);
  // Currently handle by the core, but will be soon mooved to shell
  Display.Send_Raw(F("PAGE=dp")); // save app page id
  Display.Set_Current_Page(F("Shell_Event"));
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

  while (Dialog_State == None)
  {
    vTaskDelay(pdMS_TO_TICKS(30));
  }
  Display.Set_Current_Page(F("PAGE")); //go back to app page
  xSemaphoreGive(Dialog_Semaphore);
  return Dialog_State;
}

Xila_Event Xila_Class::Open_File_Dialog(File &File_To_Open)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  File_Dialog_Reply = NULL;
  Software_Handle_Class *Temporary_Software_Handle = Open_Software_Pointer[0]->Handle_Pointer;
  Maximize_Shell();
  Execute_Shell(Instruction::Open_File_Dialog);

  while (Dialog_State = None)
  {
    vTaskDelay(pdMS_TO_TICKS(30));
  }

  Maximize_Software(*Temporary_Software_Handle);
  File_To_Open = *File_Dialog_Reply;
  File_Dialog_Reply->close();
  delete File_Dialog_Reply;
  xSemaphoreGive(Dialog_Semaphore);
  return Success;
}