///
/// @file Software.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

///
/// @brief Construct a new Xila_Class::Software object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Xila_Class::Software::Software(Xila_Class::Software_Handle &Software_Handle, uint8_t Queue_Size)
    : Handle(&Software_Handle),
      Current_Instruction(Xila.Idle),
      Instruction_Queue_Handle(NULL),
      Last_Watchdog_Feed(millis()),
      Watchdog_Timeout(Default_Watchdog_Timeout)
{
  if (Queue_Size != 0)
  {
    Instruction_Queue_Handle = xQueueCreate(Queue_Size, sizeof(uint16_t));
    if (Instruction_Queue_Handle == NULL)
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

void Xila_Class::Software::Set_Variable(Xila_Class::Adress Adress, uint8_t Type, const void *Variable)
{
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
