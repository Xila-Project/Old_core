#include "Core/Software.hpp"

//Software class

Software_Class::Software_Class(Software_Handle_Class& Software_Handle, uint8_t Queue_Size):
Handle_Pointer(&Software_Handle),
Instruction_Queue_Handle(NULL)
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
  vTaskDelay(pdMS_TO_TICKS(5));
}

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
  return Current_Instruction;
}

void Software_Class::Send_Instruction(uint16_t Instruction)
{
  xQueueSendToBack(Instruction_Queue_Handle, (void *)&Instruction, portMAX_DELAY);
  
}

void Software_Class::Send_Instruction(char Instruction_Char_1, char Instruction_Char_2)
{
  Send_Instruction(((uint16_t)Instruction_Char_1 << 8) | (uint16_t)Instruction_Char_1);
  Verbose_Print("Instrution :");
  Serial.print(Instruction_Char_2);
  Serial.println(Instruction_Char_2);
}

