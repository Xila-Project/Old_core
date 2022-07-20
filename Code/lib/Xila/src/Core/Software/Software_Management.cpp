///
/// @file Software.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

extern Xila_Class::Software_Handle Shell_Handle;

///
/// @brief Construct a new Software_Class object
///
Xila_Class::Software_Management_Class::Software_Management_Class()
{
  Watchdog_Timer = 0;
  Watchdog_State = 0;
}

///
/// @brief Return openned software's state.
///
/// @param Software_Handle Software handle to check.
/// @return Xila_Class::Software::State
Xila_Class::State Xila_Class::Software_Management_Class::Get_State(Xila_Class::Software_Handle const &Software_Handle)
{
  if (Openned[0] != NULL)
  {
    if (Openned[0]->Handle == &Software_Handle) // only compare handle pointer Address to be faster
    {
      return Maximized;
    }
  }
  return Minimized;
}

///
/// @brief Check watchdog timer of every openned software.
///
void Xila_Class::Software_Management_Class::Check_Watchdog()
{
  for (uint8_t i = 1; i < (sizeof(Openned) / sizeof(Openned[0])); i++)
  {
    if (Openned[i] != NULL)
    {
      if (Xila.Time.Milliseconds() - Openned[i]->Last_Watchdog_Feed > Openned[i]->Watchdog_Timeout || Openned[i]->Watchdog_Timeout > Maximum_Watchdog_Timeout)
      {
        Xila.Software_Management.Force_Close(*Openned[i]->Handle);
        Xila.Task.Delay(100);
        Xila.Software_Management.Open(Shell_Handle);
        Xila.Software_Management.Shell_Send_Instruction(Desk);
      }
    }
  }
}

///
/// @brief Defrag current openned software array.
///
void Xila_Class::Software_Management_Class::Defrag()
{
  for (uint8_t i = 2; i < sizeof(Openned) / sizeof(Openned[0]); i++)
  {
    if (Openned[i] == NULL)
    {
      for (uint8_t j = i + 1; j < sizeof(Openned) / sizeof(Openned[0]); j++)
      {
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

///
/// @brief Feed watchdog timer (reset).
///
/// @param Software_Handle Software's handle to feed watchdog.
void Xila_Class::Software_Management_Class::Feed_Watchdog(Xila_Class::Software_Handle const &Software_Handle)
{
  if (Watchdog_State != 0 && &Software_Handle == Xila.Software_Management.Openned[Watchdog_State]->Handle)
  {
    Xila.Software_Management.Watchdog_Timer = Xila.Time.Milliseconds();
  }
}

///
/// @brief Function that open software.
///
/// @param Software_Handle Software's handle to open.
/// @return Result_Type
Result_Type Xila_Class::Software_Management_Class::Open(Xila_Class::Software_Handle const &Software_Handle)
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

///
/// @brief Function that close software.
///
/// @param Software_Handle Software's handle to close (equal NULL by default, which close currrent maximized software).
void Xila_Class::Software_Management_Class::Close(Xila_Class::Software_Handle const &Software_Handle)
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

        Openned[i]->Send_Instruction(Xila.Close);
        Xila.Task.Delay(20);
        Openned[i] = NULL;

        Defrag();

        Shell_Send_Instruction(Desk);
        Shell_Maximize();

        return;
      }
    }
  }
}

///
/// @brief Function that minimize software (and maximize Shell).
///
/// @param Software_Handle Software's handle to minimize.
void Xila_Class::Software_Management_Class::Minimize(Xila_Class::Software_Handle const &Software_Handle)
{
  if (Openned[0] != NULL)
  {
    if (*Openned[0]->Handle == Software_Handle)
    {
      Openned[0]->Send_Instruction(Xila.Minimize); // -- Inform software that its minimized
      Xila.Task.Delay(10);                                    // -- purge time
      Openned[0] = NULL;
    }
    else
    {
      return;
    }
  }
  Shell_Send_Instruction(Desk);
  Shell_Maximize();
}

///
/// @brief Function that maximize software (and minimize current maximized software).
///
/// @param Software_Handle Software handle to maximize.
/// @return Result_Type
Result_Type Xila_Class::Software_Management_Class::Maximize(Xila_Class::Software_Handle const &Software_Handle)
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
            Openned[0]->Send_Instruction(Xila.Minimize); // -- Inform software that its minimized

            Xila.Task.Delay(10); // -- purge time
            Openned[0] = NULL;
          }
        }
        // -- Then maximize target software
        Openned[0] = Openned[i];
        Openned[0]->Send_Instruction(Xila.Maximize);
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
Result_Type Xila_Class::Software_Management_Class::Force_Close(Xila_Class::Software_Handle const &Software_Handle)
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

///
/// @brief Add handle to software list.
///
/// @param Software_Handle_To_Add
void Xila_Class::Software_Management_Class::Add_Handle(Xila_Class::Software_Handle &Software_Handle_To_Add)
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

///
/// @brief A shortcut that maximize Shell.
///
void Xila_Class::Software_Management_Class::Shell_Maximize()
{
  Maximize(Shell_Handle);
}
