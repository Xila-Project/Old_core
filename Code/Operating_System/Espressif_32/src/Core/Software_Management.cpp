/**
 * @file Software_Management.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Core/Core.hpp"

Xila_Class::Software_Management_Class::Software_Management_Class()
{
  Watchdog_Timer = 0;
  Watchdog_State = 0;
}

void Xila_Class::Software_Management_Class::Check_Watchdog()
{

  if (Watchdog_State < 10)
  {
    if (Watchdog_State > 7)
    {
      Watchdog_State = 0;
      return;
    }

    if ((millis() - Last_Watchdog_Feed) > WATCHDOG_INITAL_TIME)
    {
      if (Watchdog_Reminder == false)
      {
        Verbose_Print("Watchdog warning sent :");
        Serial.println(Openned_Software[0]->Handle_Pointer->Name);
        Openned_Software[0]->Send_Instruction(Software_Class::Watchdog);
        Watchdog_Reminder = true;
      }
      else
      {
        if ((millis() - Last_Watchdog_Feed) > WATCHDOG_MAXIMUM_TIME)
        {
          Verbose_Print_Line("Watchdog triggered, close software");
          Xila.Software.Force_Close();
          Watchdog_Reminder = false;
          Last_Watchdog_Feed = millis();
        }
      }
    }
  }
  Watchdog_Timer = 0;
  Watchdog_State++;
}

void Xila_Class::Software_Management_Class::Feed_Watchdog(Software_Handle_Class const &Software_Handle)
{
  if (Watchdog_State != 0 && &Software_Handle == Xila.Software.Openned_Software[Watchdog_State]->Handle_Pointer)
  {
    Xila.Software.Watchdog_Timer = millis();
  }
}

uint8_t Xila_Class::Software_Management_Class::Seek_Open_Software_Handle(Software_Handle_Class const &Software_Handle)
{
  for (uint8_t i = 1; i <= 8; i++)
  {
    if (i < 8 && *Openned_Software[i]->Handle_Pointer == Software_Handle)
    {
      return i;
    }
    else if (i == 8)
    {
      return 0;
    }
  }
}

/**
     * @brief Function used to open a Software.
     * 
     * @param Software_Handle The software's handle to open 
     */
Xila_Event Xila_Class::Software_Management_Class::Open(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Open software ...");
  // -- if software handle is shell handle, reopen it or maximize it

  uint8_t i = 2;

  if (Software_Handle == Shell_Handle)
  {
    if (Openned_Software[1] != NULL)
    {
      Maximize(Shell_Handle);
      return Success;
    }
    else
    {
      Openned_Software[1] = (*Shell_Handle.Load_Function_Pointer)();
      Openned_Software[0] = Openned_Software[1];
      return Success;
    }
  }

  // -- checking if software is already openned
  for (i = 2; i < 8; i++)
  {
    if (Openned_Software[i] != NULL)
    {
      if (Software_Handle == *Openned_Software[i]->Handle_Pointer)
      {
        Maximize(*Openned_Software[i]->Handle_Pointer);
        Verbose_Print("Maximized software :");
        Serial.print(Openned_Software[0]->Handle_Pointer->Name);
        Serial.println(i);
        return Success;
      }
    }
  }

  // -- if the software isn't minimized, load it. -- //

  for (i = 2; i < 8; i++)
  {
    if (Openned_Software[i] == NULL)
    {
      if (Software_Handle.Load_Function_Pointer == NULL)
      {
        return Error;
      }

      Openned_Software[i] = (*Software_Handle.Load_Function_Pointer)(); // <- at this point Openned_Software[1] to be modified

      if (Openned_Software[i]->Instruction_Queue_Handle == NULL)
      {
        Verbose_Print_Line("Failed to create queue, close software");
        vTaskDelete(Openned_Software[i]->Task_Handle);
        delete Openned_Software[i];
        Openned_Software[i] = NULL;
        return Error;
      }

      Openned_Software[0] = Openned_Software[i];

      return Success;
    }
  }
  return Error;
}

/**
     * @brief Function used to close a Software.
     * 
     * @param Software_Handle The software's handle to close, equal NULL by default which close the currently running software.
     */
void Xila_Class::Software_Management_Class::Close(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Close software");
  for (uint8_t i = 2; i < 8; i++)
  {
    if (Openned_Software[i] != NULL)
    {
      // -- If software handle bind with given software handle
      if (*Openned_Software[i]->Handle_Pointer == Software_Handle)
      {

        // -- Don't forget to remove maximized pointer.
        if (*Openned_Software[0]->Handle_Pointer == Software_Handle)
        {
          Openned_Software[0] = NULL;
        }

        Openned_Software[i]->Send_Instruction(Software_Class::Close);

        Xila.Task.Resume(Openned_Software[i]->Task_Handle);
        Xila.Task.Delay(20);
        Openned_Software[i] = NULL;

        Openned_Software[1]->Send_Instruction(Software_Class::Desk);

        if (Maximize(Shell_Handle) != Success)
        {
          Verbose_Print_Line("Failed to maximize shell");
        }

        return;
      }
    }
  }
}

/**
     * @brief Function used to minimize the currently running software, and then maximize Shell.
     */
void Xila_Class::Software_Management_Class::Minimize(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Minimize software");

  if (Openned_Software[0] != NULL)
  {
    Verbose_Print("0:");
    Serial.println(Openned_Software[0]->Handle_Pointer->Name);
  }
  if (Openned_Software[1] != NULL)
  {
    Verbose_Print("1:");
    Serial.println(Openned_Software[1]->Handle_Pointer->Name);
  }
  if (Openned_Software[2] != NULL)
  {
    Verbose_Print("2:");
    Serial.println(Openned_Software[2]->Handle_Pointer->Name);
  }

  if (Openned_Software[0] != NULL)
  {
    if (*Openned_Software[0]->Handle_Pointer == Software_Handle)
    {
      Openned_Software[0]->Send_Instruction(Software_Class::Minimize); // -- Inform software that its minimized
      Xila.Task.Delay(10);                                                    // -- purge time
      Openned_Software[0] = NULL;
    }
    else
    {
      return;
    }
  }

  Execute_Shell(Software_Class::Desk);
  Maximize(Shell_Handle);
}

/**
     * @brief Function used to maxmize the software.
     * 
     * @param Software_Handle The software's handle to maxmize.
     */
Xila_Event Xila_Class::Software_Management_Class::Maximize(Software_Handle_Class const &Software_Handle)
{
  Verbose_Print_Line("Maximize software");

  if (Openned_Software[0] != NULL)
  {
    Verbose_Print("0:");
    Serial.println(Openned_Software[0]->Handle_Pointer->Name);
  }
  if (Openned_Software[1] != NULL)
  {
    Verbose_Print("1:");
    Serial.println(Openned_Software[1]->Handle_Pointer->Name);
  }
  if (Openned_Software[3] != NULL)
  {
    Verbose_Print("3:");
    Serial.println(Openned_Software[3]->Handle_Pointer->Name);
  }

  // -- Looking for the involved software
  for (uint8_t i = 1; i < 8; i++)
  {
    if (Openned_Software[i] != NULL)
    {
      if (Software_Handle == *Openned_Software[i]->Handle_Pointer)
      {
        // -- Check if the software was already open or if another software is currently openned.
        if (Openned_Software[0] != NULL)
        {
          // -- If software handle bind with currently openned software do nothing and return success
          if (*Openned_Software[0]->Handle_Pointer == Software_Handle)
          {
            return Success;
          }
          // -- If not, minimize the maximized software
          else
          {
            Openned_Software[0]->Send_Instruction(Software_Class::Minimize); // -

            Xila.Task.Delay(10);
            Openned_Software[0] = NULL;
          }
        }
        // -- Then maximize target software
        Openned_Software[0] = Openned_Software[i];
        Openned_Software[0]->Send_Instruction(Software_Class::Maximize);
        return Success;
      }
    }
  }
  return Error;
}

/**
     * @brief Function that close roughly the current running software.
     * @details Delete manualy the main software task, and then delete software instance. That could leave undeleted memory fragment (external tasks, external variables ...).
     */
void Xila_Class::Software_Management_Class::Force_Close()
{
  Verbose_Print_Line("Force close software");
  if (*Openned_Software[0]->Handle_Pointer == Shell_Handle)
  {
    vTaskDelete(Openned_Software[1]->Task_Handle);
    delete Openned_Software[1];
    if (Openned_Software[1] == Openned_Software[0])
    {
      Openned_Software[0] = NULL;
    }
    Openned_Software[1] = NULL;

    Open(Shell_Handle);
  }
  else
  {

    if (Openned_Software[0] != NULL)
    {
      vTaskDelete(Openned_Software[0]->Task_Handle);
      delete Openned_Software[0];
    }
    Maximize_Shell();
  }
}

void Xila_Class::Software_Management_Class::Add_Handle(Software_Handle_Class &Software_Handle_To_Add)
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

void Xila_Class::Software_Management_Class::Execute_Shell(Xila_Instruction const &Command)
{
  Openned_Software[1]->Send_Instruction(Command);
}

void Xila_Class::Software_Management_Class::Maximize_Shell()
{
  Maximize(Shell_Handle);
}