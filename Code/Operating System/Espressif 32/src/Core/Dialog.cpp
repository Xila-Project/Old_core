#include "Core/Core.hpp"


Xila_Event Xila_Class::Event_Dialog(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  xSemaphoreTake(Dialog_Semaphore, portMAX_DELAY);
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
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Error"));
    break;
  case Warning:
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Warning"));
    break;
  case Information:
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Information"));
    break;
  case Question:
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Question"));
  default:
    break;
  }
  Display.Show(F("CLOSE_PIC"));
  while (Event_Reply == 0)
  {
    vTaskDelay(pdMS_TO_TICKS(10));
  }
  Xila_Event Event_Reply_Copy = Event_Reply;
  Event_Reply = 0;
  xSemaphoreGive(Dialog_Semaphore);
  return Event_Reply_Copy;
}

Xila_Event Xila_Class::Open_File_Dialog(File &File_To_Open)
{
  Maximize_Shell();
  Execute_Shell(Open_File);

  while (!Shell_Return_Item)
  {
    vTaskDelay(pdMS_TO_TICKS(10));
  }

  return
}