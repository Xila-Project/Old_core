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

extern Software_Handle_Class Shell_Handle;

///
/// @brief Construct a new Software_Management_Class object
///
Xila_Class::Software_Management_Class::Software_Management_Class()
{
  Watchdog_Timer = 0;
  Watchdog_State = 0;
}

///
/// @brief
///
/// @param Software_Handle
/// @return Software_Class::State
Software_Class::State Xila_Class::Software_Management_Class::Get_State(Software_Handle_Class const &Software_Handle)
{
  if (Openned[0] != NULL)
  {
    if (Openned[0]->Handle == &Software_Handle) // only compare handle pointer adress to be faster
    {
      return Software_Class::Maximized;
    }
  }
  return Software_Class::Minimized;
}

void Xila_Class::Software_Management_Class::Check_Watchdog()
{
  for (uint8_t i = 1; i < (sizeof(Openned) / sizeof(Openned[0])); i++)
  {
    if (Openned[i] != NULL)
    {
      if (Xila.Time.Milliseconds() - Openned[i]->Last_Watchdog_Feed > Openned[i]->Watchdog_Timeout || Openned[i]->Watchdog_Timeout > Maximum_Watchdog_Timeout)
      {
        Xila.Software.Force_Close(*Openned[i]->Handle);
        Xila.Task.Delay(100);
        Xila.Software.Open(Shell_Handle);
        Xila.Software.Send_Instruction_Shell(Software_Class::Desk);
      }
    }
  }
}

void Xila_Class::Software_Management_Class::Defrag()
{
  for (uint8_t i = 2; i < sizeof(Openned) / sizeof(Openned[0]); i++)
  {
    //DUMP(i);
    if (Openned[i] == NULL)
    {
      for (uint8_t j = i + 1; j < sizeof(Openned) / sizeof(Openned[0]); j++)
      {
        //DUMP(j);
        if (Openned[j] != NULL)
        {
          Openned[i] = Openned[j];
          Openned[j] = NULL;
          break;
        }
        
        if (j >= 7)
        {
          return;
        }

      }
    }
  }
}

void Xila_Class::Software_Management_Class::Feed_Watchdog(Software_Handle_Class const &Software_Handle)
{
  if (Watchdog_State != 0 && &Software_Handle == Xila.Software.Openned[Watchdog_State]->Handle)
  {
    Xila.Software.Watchdog_Timer = Xila.Time.Milliseconds();
  }
}

uint8_t Xila_Class::Software_Management_Class::Seek_Open_Software_Handle(Software_Handle_Class const &Software_Handle)
{
  for (uint8_t i = 1; i <= 8; i++)
  {
    if (i < 8 && *Openned[i]->Handle == Software_Handle)
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
Xila_Class::Event Xila_Class::Software_Management_Class::Open(Software_Handle_Class const &Software_Handle)
{
  if (Software_Handle == Shell_Handle)
  {
    if (Openned[1] != NULL)
    {
      Maximize(Shell_Handle);
      return Success;
    }
    else
    {
      Openned[1] = (*Shell_Handle.Load_Function_Pointer)();
      Openned[0] = Openned[1];
      return Success;
    }
  }

  uint8_t i = 2;
  // -- checking if software is already openned
  for (i = 2; i < 8; i++)
  {
    if (Openned[i] != NULL)
    {
      if (Software_Handle == *Openned[i]->Handle)
      {
        Maximize(*Openned[i]->Handle);
        return Success;
      }
    }
  }

  // -- if the software isn't minimized, load it. -- //

  for (i = 2; i < 8; i++)
  {
    if (Openned[i] == NULL)
    {
      if (Software_Handle.Load_Function_Pointer == NULL)
      {
        return Error;
      }

      Openned[i] = (*Software_Handle.Load_Function_Pointer)(); // <- at this point Openned[1] to be modified

      if (Openned[i]->Instruction_Queue_Handle == NULL)
      {
        vTaskDelete(Openned[i]->Task_Handle);
        delete Openned[i];
        Openned[i] = NULL;
        return Error;
      }

      Openned[0] = Openned[i];

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
  for (uint8_t i = 2; i < sizeof(Openned) / sizeof(Openned[0]); i++)
  {
    if (Openned[i] != NULL)
    {
      // -- If software handle bind with given software handle
      if (*Openned[i]->Handle == Software_Handle)
      {

        // -- Don't forget to remove maximized pointer.
        if (*Openned[0]->Handle == Software_Handle)
        {
          Openned[0] = NULL;
        }

        Openned[i]->Send_Instruction(Software_Class::Close);
        Xila.Task.Delay(20);
        Openned[i] = NULL;

        Defrag();

        Send_Instruction_Shell(Software_Class::Desk);
        Maximize_Shell();

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
  if (Openned[0] != NULL)
  {
    if (*Openned[0]->Handle == Software_Handle)
    {
      Openned[0]->Send_Instruction(Software_Class::Minimize); // -- Inform software that its minimized
      Xila.Task.Delay(10);                                    // -- purge time
      Openned[0] = NULL;
    }
    else
    {
      return;
    }
  }

  Send_Instruction_Shell(Software_Class::Desk);
  Maximize(Shell_Handle);
}

/**
     * @brief Function used to maxmize the software.
     * 
     * @param Software_Handle The software's handle to maxmize.
     */
Xila_Class::Event Xila_Class::Software_Management_Class::Maximize(Software_Handle_Class const &Software_Handle)
{
  // -- Looking for the involved software
  for (uint8_t i = 1; i < 8; i++)
  {
    if (Openned[i] != NULL)
    {
      if (Software_Handle == *Openned[i]->Handle)
      {

        // -- Check if the software was already open or if another software is currently openned.
        if (Openned[0] != NULL)
        {
          // -- If software handle bind with currently openned software do nothing and return success
          if (*Openned[0]->Handle == Software_Handle)
          {
            return Success;
          }
          // -- If not, minimize the maximized software
          else
          {
            Openned[0]->Send_Instruction(Software_Class::Minimize); // -- Inform software that its minimized

            Xila.Task.Delay(10); // -- purge time
            Openned[0] = NULL;
          }
        }
        // -- Then maximize target software
        Openned[0] = Openned[i];
        Openned[0]->Send_Instruction(Software_Class::Maximize);
        return Success;
      }
    }
  }
  return Error;
}

///
/// @brief Function that close roughly the current running software.
///  @details Delete manualy the main software's task, and then delete software instance. That could leave undeleted memory fragment (external tasks, external variables, dynamic allocated variables etc.).
///
/// @param Software_Handle Software handle to close.
Xila_Class::Event Xila_Class::Software_Management_Class::Force_Close(Software_Handle_Class const &Software_Handle)
{
  for (uint8_t i = 1; i < 8; i++)
  {
    if (Openned[i] != NULL)
    {
      // -- If software handle bind with given software handle
      if (*Openned[i]->Handle == Software_Handle)
      {

        Xila.Task.Delete(Openned[i]->Task_Handle);
        Xila.Task.Delay(10);
        // -- Don't forget to remove maximized pointer.
        if (*Openned[0]->Handle == Software_Handle)
        {
          Openned[0] = NULL;
        }
        if (*Openned[1]->Handle == Software_Handle)
        {
          Openned[1] = NULL;
        }

        delete Openned[i];
        Openned[i] = NULL;
        return Success;
      }
    }
  }
  return Error;
}

void Xila_Class::Software_Management_Class::Add_Handle(Software_Handle_Class &Software_Handle_To_Add)
{
  for (uint8_t i = 0; i < Maximum_Software; i++)
  {
    if (Handle[i] == NULL)
    {
      Handle[i] = &Software_Handle_To_Add;
      return;
    }
  }
}

// -- Shell shortcut -- //

void Xila_Class::Software_Management_Class::Send_Instruction_Shell(Xila_Instruction const &Command)
{
  Openned[1]->Send_Instruction(Command);
}

void Xila_Class::Software_Management_Class::Maximize_Shell()
{
  Maximize(Shell_Handle);
}