#include "Core/Software.hpp"

//Software class

Software_Class *Software_Class::Instance_Pointer = NULL;

Software_Handle_Class* Software_Class::Handle_Pointer = NULL;

Software_Class::Software_Class(Software_Handle_Class& Software_Handle, uint8_t Queue_Size)
{
  Handle_Pointer = &Software_Handle;
  if (Queue_Size != 0)
  {
    Command_Queue_Handle = xQueueCreate(Queue_Size, sizeof(uint16_t));
    if (Command_Queue_Handle == NULL)
    {
      Serial.print(F("Error cannot create software Queue !"));
      delete this;
    }
    else
    {
      Send_Instruction('O');
    }
  }
}

Software_Class::~Software_Class() // Destructor : close
{
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer = NULL;
  vQueueDelete(Command_Queue_Handle);
}

void Software_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
}

uint16_t Software_Class::Get_Instruction()
{
  uint16_t Command_Buffer = 0;
  xQueueReceive(Command_Queue_Handle, &Command_Buffer, 0);
  return Command_Buffer;
}

void Software_Class::Send_Instruction(uint16_t Instruction)
{
  xQueueSendToBack(Command_Queue_Handle, (void *)&Instruction, portMAX_DELAY);
}

void Software_Class::Send_Instruction(char Task_Method_Char1, char Task_Method_Char2)
{
  Send_Instruction(((uint16_t)Task_Method_Char1 << 8) | (uint16_t)Task_Method_Char2);
}

