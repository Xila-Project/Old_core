///
/// @file Software.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Software/Software.hpp"

extern Software_Handle_Class Shell_Handle;

///
 /// @brief Start a software instance main task.
 /// 
 /// @param Instance_Pointer 
void Software_Class::Start_Main_Task(void *Instance_Pointer)
{
  (Software_Class *)Instance_Pointer->Main_Task_Function();
}

///
/// @brief Return openned software's state.
///
/// @param Software_Handle Software handle to check.
/// @return Software::State
State Software_Class::Get_State(Software_Handle const &Software_Handle)
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
void Software_Class::Check_Watchdog()
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
void Software_Class::Defrag()
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
void Software_Class::Feed_Watchdog(Software_Handle const &Software_Handle)
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
Result_Type Software_Class::Open(Software_Handle const &Software_Handle)
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
void Software_Class::Close(Software_Handle const &Software_Handle)
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
void Software_Class::Minimize(Software_Handle const &Software_Handle)
{
  if (Openned[0] != NULL)
  {
    if (*Openned[0]->Handle == Software_Handle)
    {
      Openned[0]->Send_Instruction(Xila.Minimize); // -- Inform software that its minimized
      Xila.Task.Delay(10);                         // -- purge time
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
Result_Type Software_Class::Maximize(Software_Handle const &Software_Handle)
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
Result_Type Software_Class::Force_Close(Xila_Class::Software_Handle const &Software_Handle)
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
void Xila_Class::Software_Class::Add_Handle(Xila_Class::Software_Handle &Software_Handle_To_Add)
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
void Software_Class::Shell_Maximize()
{
  Maximize(Shell_Handle);
}

///
/// @brief Construct a new Xila_Class::Software object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Software_Class::Software_Class(uint8_t Queue_Size)
      Current_Instruction(Xila.Idle),
      Last_Watchdog_Feed(millis()),
      Watchdog_Timeout(Default_Watchdog_Timeout)
{
  if (Queue_Size != 0)
  {
    if (Instruction_Queue.Create(Queue_Size) == Error)
    {
      delete this;
    }
    else
    {
      Send_Instruction(Open);
    }
  }
  vTaskDelay(pdMS_TO_TICKS(5)); // -- Wait fews ms (crash if not)
}

///
/// @brief Destroy the Xila_Class::Software object
///
Xila_Class::Software::~Software() // Destructor : close
{
  vQueueDelete(Instruction_Queue_Handle);
}

///
/// @brief Set watchdog timeout, by default it's set to 5000 ms.
///
/// @param Watchdog_Timeout Watchdog timeout in milliseconds.
void Xila_Class::Software::Set_Watchdog_Timeout(uint16_t Watchdog_Timeout)
{
  if (Watchdog_Timeout <= Maximum_Watchdog_Timeout)
  {
    this->Watchdog_Timeout = Watchdog_Timeout;
  }
}

///
/// @brief Return last instruction from the instructions queue.
///
/// @return Xila_Class::Instruction Software instruction.
Xila_Class::Instruction Xila_Class::Software::Get_Instruction()
{
  if (xQueueReceive(Instruction_Queue_Handle, &Current_Instruction, 0) != pdTRUE)
  {
    Current_Instruction = 0;
  }
  Last_Watchdog_Feed = millis();
  return Current_Instruction;
}

///
/// @brief Used to send instructions to software.
///
/// @param Instruction Instruction to send.
///
/// @details It's used by Xila and the software itself to fill the instructions queue.
void Xila_Class::Software::Send_Instruction(Xila_Class::Instruction Instruction)
{
  xQueueSendToBack(Instruction_Queue_Handle, (void *)&Instruction, portMAX_DELAY);
}

uint8_t Software_Class::Seek_Open_Software_Handle(Software_Handle const &Software_Handle)
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

// -- Shell shortcut -- //

void Software_Class::Shell_Set_Variable(Address Address, uint8_t Type, const void *Variable)
{
  Openned[1]->Set_Variable(Address, Type, Variable);
}

void Software_Class::Shell_Send_Instruction(Instruction Instruction)
{
  Openned[1]->Send_Instruction(Instruction);
}
