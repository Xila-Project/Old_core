#include "Core/Core.hpp"

Xila_Event Xila_Class::Color_Picker_Dialog(uint16_t& Color)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  Dialog_Reply = NULL;
  while (Dialog_Reply == NULL)
  {

  }
  
}

Xila_Event Xila_Class::Event_Dialog(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
    Dialog_Reply = new Xila_Event;
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
    Display.Set_Text(F("BUTTON1_BUT"), F("Okay"));
    Display.Set_Text(F("BUTTON2_BUT"), F("Yes"));
    Display.Set_Text(F("BUTTON3_BUT"), F("No"));
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
  while (Dialog_Reply == NULL)
  {
    vTaskDelay(pdMS_TO_TICKS(10));
  }
  Xila_Event Event_Reply_Copy = *(Xila_Event*)Dialog_Reply;
  delete Dialog_Reply;
  Dialog_Reply = NULL;
  xSemaphoreGive(Dialog_Semaphore);
  return Event_Reply_Copy;
}

Xila_Event Xila_Class::File_Dialog(File &File_To_Open)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
  File_Dialog_Reply = NULL;
  Software_Handle_Class* Temporary_Software_Handle = Open_Software_Pointer[0]->Handle_Pointer;
  Maximize_Shell();
  Execute_Shell(Open_File_Dialog);

  while (!Dialog_Reply)
  {
    vTaskDelay(pdMS_TO_TICKS(10));
  }

  Maximize_Software(*Temporary_Software_Handle);
  File_To_Open = *File_Dialog_Reply;
  File_Dialog_Reply->close();
  delete File_Dialog_Reply;
  xSemaphoreGive(Dialog_Semaphore);
  return Success;
}