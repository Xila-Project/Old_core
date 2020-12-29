#include "Software.hpp"

//Software class

Software_Class *Software_Class::Instance_Pointer = NULL;
Software_Handle_Class *Software_Class::Handle_Pointer = NULL;

Software_Class::Software_Class(uint8_t Task_Queue_Size)
{
  Command_Queue_Handle = xQueueCreate(Task_Queue_Size, sizeof(uint16_t));
  if (Command_Queue_Handle == NULL)
  {
    Serial.print(F("Error cannot create software Queue !"));
    delete this;
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

void Software_Class::Open_File(File &File_To_Open)
{
}

void Software_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
}

uint16_t Software_Class::Get_Command()
{
  uint16_t Command_Buffer = 0;
  xQueueReceive(Command_Queue_Handle, &Command_Buffer, 0);
  return Command_Buffer;
}

void Software_Class::Execute(uint16_t Command_To_Execute)
{
  xQueueSendToBack(Command_Queue_Handle, (void *)&Command_To_Execute, portMAX_DELAY);
}

void Software_Class::Execute(char Task_Method_Char1, char Task_Method_Char2)
{
  Execute(((uint16_t)Task_Method_Char1 << 8) | (uint16_t)Task_Method_Char2);
}

void Software_Class::Maximize()
{
  vTaskResume(Task_Handle);
}

void Software_Class::Minimize()
{
  vTaskSuspend(Task_Handle);
}

Software_Class *Software_Class::Load() // just an example
{
  if (Instance_Pointer == NULL)
  {
    Instance_Pointer = new Software_Class(6);
  }
  return Instance_Pointer;
}

// Software handle

Software_Handle_Class::Software_Handle_Class()
    : Icon(0),
      Type(0),
      Load_Function_Pointer(NULL),
      Startup_Function_Pointer(NULL),
      Background_Function_Pointer(NULL)
{
  memset(Name, '\0', sizeof(Name));
}

Software_Handle_Class::Software_Handle_Class(char const *Software_Name, uint8_t Icon_ID, Software_Class *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)(), void (*Background_Function_Pointer)(), void (*Shutdown_Function_Pointer)())
    : Icon(Icon_ID),
      Type(0),
      Load_Function_Pointer(Load_Function_Pointer),
      Startup_Function_Pointer(Startup_Function_Pointer),
      Background_Function_Pointer(Background_Function_Pointer)
{
  memset(Name, '\0', sizeof(Name));
  strcpy(Name, Software_Name);
}

Software_Handle_Class::~Software_Handle_Class()
{
}