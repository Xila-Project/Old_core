#include "Core/Core.hpp"

// -- Software management -- //

void Xila_Class::Feed_Watchdog()
{
  Last_Watchdog_Feed = millis();
}

void Xila_Class::Delay(uint32_t Delay_In_Millisecond)
{
  Last_Watchdog_Feed = millis();
  vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

uint8_t Xila_Class::Seek_Open_Software_Handle(Software_Handle_Class const &Software_Handle)
{
  for (uint8_t i = 1; i <= 8; i++)
  {
    if (i < 8 && *Open_Software_Pointer[i]->Handle_Pointer == Software_Handle)
    {
      return i;
    }
    else if (i == 8)
    {
      return 0;
    }
  }
}

Xila_Event Xila_Class::Software_Open(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Open software ...");
  // -- if software handle is shell handle, reopen it or maximize it

  uint8_t i = 2;
  
  if (Software_Handle == Shell_Handle)
  {
    if (Open_Software_Pointer[1] != NULL)
    {
      Maximize_Software(Shell_Handle);
      return Success;
    }
    else
    {
      Open_Software_Pointer[1] = (*Shell_Handle.Load_Function_Pointer)();
      Open_Software_Pointer[0] = Open_Software_Pointer[1];
      return Success;
    }
  }

  // -- checking if software is already openned
  for (i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      if (Software_Handle == *Open_Software_Pointer[i]->Handle_Pointer)
      {
        Maximize_Software(*Open_Software_Pointer[i]->Handle_Pointer);
        Verbose_Print("Maximized software :");
        Serial.print(Open_Software_Pointer[0]->Handle_Pointer->Name);
        Serial.println(i);
        return Success;
      }
    }
  }

  // -- if the software isn't minimized, load it. -- //

  for (i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] == NULL)
    {
            Serial.print(Open_Software_Pointer[1]->Handle_Pointer->Name);
      Open_Software_Pointer[i] = (*Software_Handle.Load_Function_Pointer)();
      Open_Software_Pointer[0] = Open_Software_Pointer[i];
      Serial.print(Open_Software_Pointer[1]->Handle_Pointer->Name);
      Verbose_Print("Openned software :");


      return Success;
    }
  }
  return Error;
}

void Xila_Class::Software_Close(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Close software");
  for (uint8_t i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      // -- If software handle bind with given software handle
      if (*Open_Software_Pointer[i]->Handle_Pointer == Software_Handle)
      {

        // -- Don't forget to remove maximized pointer.
        if (*Open_Software_Pointer[0]->Handle_Pointer == Software_Handle)
        {
          Open_Software_Pointer[0] = NULL;
        }

        Open_Software_Pointer[i]->Send_Instruction(Close);

        Task_Resume(Open_Software_Pointer[i]->Task_Handle);
        vTaskDelay(pdMS_TO_TICKS(20));
        Open_Software_Pointer[i] = NULL;

        if (Maximize_Software(Shell_Handle) != Success)
        {
          Verbose_Print_Line("Failed to maximize shell");
        }

        return;
      }
    }
  }
}

void Xila_Class::Software_Minimize(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Minimize software");

  if (Open_Software_Pointer[0] != NULL)
  {
    if (*Open_Software_Pointer[0]->Handle_Pointer == Software_Handle)
    {
      Open_Software_Pointer[0]->Send_Instruction(Minimize);
      vTaskDelay(pdMS_TO_TICKS(10));
      Open_Software_Pointer[0] = NULL;
    }
    else
    {
      return;
    }
  }

  Execute_Shell(Xila.Desk);
  Maximize_Software(Shell_Handle);
}

Xila_Event Xila_Class::Maximize_Software(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Maximize software");

  Serial.println((uint32_t)&Software_Handle, HEX);

  Serial.print(Open_Software_Pointer[1]->Handle_Pointer->Name);

  Serial.println((uint32_t)&Open_Software_Pointer[1]->Handle_Pointer, HEX);

  Serial.println((uint32_t)Open_Software_Pointer[0], HEX);
  Serial.println((uint32_t)Open_Software_Pointer[1], HEX);
  Serial.println((uint32_t)Open_Software_Pointer[2], HEX);
  Serial.println((uint32_t)Open_Software_Pointer[3], HEX);
  Serial.println((uint32_t)Open_Software_Pointer[4], HEX);
  Serial.println((uint32_t)Open_Software_Pointer[5], HEX);
  Serial.println((uint32_t)Open_Software_Pointer[6], HEX);
  Serial.println((uint32_t)Open_Software_Pointer[7], HEX);

  // -- Looking for the involved software
  for (uint8_t i = 1; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      if (Software_Handle == *Open_Software_Pointer[i]->Handle_Pointer)
      {
        // -- Check if the software was already open or if another software is currently openned.
        if (Open_Software_Pointer[0]->Handle_Pointer != NULL)
        {
          // -- If software handle bind with currently openned software do nothing and return success
          if (*Open_Software_Pointer[0]->Handle_Pointer == Software_Handle)
          {
            return Success;
          }
          // -- If not, minimize the maximized software
          else
          {
            Open_Software_Pointer[0]->Send_Instruction(Minimize);
            vTaskDelay(pdMS_TO_TICKS(20));
            Open_Software_Pointer[0] = NULL;
          }
        }
        // -- Then maximize target software
        Open_Software_Pointer[i]->Send_Instruction(Maximize);
        vTaskResume(Open_Software_Pointer[i]->Task_Handle);
        Open_Software_Pointer[0] = Open_Software_Pointer[i];
        return Success;
      }
    }
  }
  return Error;
}

void Xila_Class::Force_Software_Close()
{
  Verbose_Print_Line("Force close software");
  if (*Open_Software_Pointer[0]->Handle_Pointer == Shell_Handle)
  {
    vTaskDelete(Open_Software_Pointer[1]->Task_Handle);
    delete Open_Software_Pointer[1];
    if (Open_Software_Pointer[1] == Open_Software_Pointer[0])
    {
      Open_Software_Pointer[0] = NULL;
    }
    Open_Software_Pointer[1] = NULL;
    Software_Open(Shell_Handle);
  }
  else
  {

    if (Open_Software_Pointer[0] != NULL)
    {
      vTaskDelete(Open_Software_Pointer[0]->Task_Handle);
      delete Open_Software_Pointer[0];
    }
    Maximize_Shell();
  }
}

void Xila_Class::Add_Software_Handle(Software_Handle_Class &Software_Handle_To_Add)
{
  for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
  {
    if (Software_Handle_Pointer[i] == NULL)
    {
      Software_Handle_Pointer[i] = &Software_Handle_To_Add;
      return;
    }
  }
}

// -- Shell shortcut -- //

void Xila_Class::Execute_Shell(Xila_Command const &Command)
{
  Open_Software_Pointer[1]->Send_Instruction(Command);
}

void Xila_Class::Maximize_Shell()
{
  Maximize_Software(Shell_Handle);
}