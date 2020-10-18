#include "Software.hpp"

//Software class

Software_Class *Software_Class::Instance_Pointer = NULL;

Software_Class::Software_Class(uint8_t Task_Queue_Size) //constructor
{
  Serial.println(F("Software constructor"));
  Task_Handle = NULL;
  xQueueCreate(Task_Queue_Size, sizeof(uint16_t));
}

Software_Class::~Software_Class() // Destructor : close
{
  Serial.println(F("Software destructor"));
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer == NULL;
  
  vQueueDelete(Command_Queue_Handle);
  vTaskDelete(Task_Handle);
}

uint16_t Software_Class::Get_Command()
{
  uint16_t Command_Buffer;
  xQueueReceive(Command_Queue_Handle, &Command_Buffer, portMAX_DELAY);
  return Command_Buffer;
}

void Software_Class::Execute(uint16_t const& Command_To_Execute)
{
  xQueueSendToBack(Command_Queue_Handle, (void *) &Command_To_Execute, portMAX_DELAY);
}

void Software_Class::Execute(char const &Task_Method_Char1, char const &Task_Method_Char2)
{
  Execute(((uint16_t)Task_Method_Char1 << 8) | (uint16_t)Task_Method_Char2);
}

void Software_Class::Close()
{
  vTaskResume(Task_Handle);
  Execute(Code::Close);
}

void Software_Class::Maximize()
{
  vTaskResume(Task_Handle);
  Execute(Code::Maximize);
}

void Software_Class::Minimize()
{
  Execute(Code::Minimize);
}

Software_Class* Software_Class::Load() // just an example
{
  if (Instance_Pointer == NULL)
  {
    Instance_Pointer = new Software_Class(6);
  }
  return Instance_Pointer;
}

// Software handle

Software_Handle_Class::Software_Handle_Class(char const *Software_Name, uint8_t Icon_ID, Software_Class* (*Load_Function_Pointer_To_Set)())
{
  strcpy(Name, Software_Name);
  Icon = Icon_ID;
  Load_Function_Pointer = Load_Function_Pointer_To_Set;
}

Software_Handle_Class::~Software_Handle_Class()
{
}