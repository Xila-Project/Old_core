#include "Core/Software.hpp"

//Software class

///
/// @brief Construct a new Software_Class object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Software_Class::Software_Class(Software_Handle_Class &Software_Handle, uint8_t Queue_Size)
    : Handle(&Software_Handle),
      Current_Instruction(Idle),
      Instruction_Queue_Handle(NULL),
      Last_Watchdog_Feed(millis())
{
  if (Queue_Size != 0)
  {
    Instruction_Queue_Handle = xQueueCreate(Queue_Size, sizeof(uint16_t));
    if (Instruction_Queue_Handle == NULL)
    {
      Serial.print(F("Error cannot create software Queue !"));
    }
    else
    {
      Send_Instruction('O');
    }
  }
  vTaskDelay(pdMS_TO_TICKS(5)); // -- Wait fews ms (crash if not)
}

///
/// @brief Destroy the Software_Class object
///
Software_Class::~Software_Class() // Destructor : close
{
  Verbose_Print_Line("destructor software");
  vQueueDelete(Instruction_Queue_Handle);
}

void Software_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
}

uint16_t Software_Class::Get_Instruction()
{
  if (xQueueReceive(Instruction_Queue_Handle, &Current_Instruction, 0) != pdTRUE)
  {
    Current_Instruction = 0;
  }
  Last_Watchdog_Feed = millis();
  return Current_Instruction;
}

///
/// @brief
///
/// @param Instruction Instruction to send
void Software_Class::Send_Instruction(Xila_Instruction Instruction)
{
  xQueueSendToBack(Instruction_Queue_Handle, (void *)&Instruction, portMAX_DELAY);
}