#include "Software.hpp"

//Software class

Software_Class *Software_Class::Instance_Pointer = NULL;

Software_Class::Software_Class(Software_Handle_Class *Task_Handle_To_Set, uint8_t Task_Queue_Size) //constructor
{
  Task_Handle = NULL;
  xQueueCreate(Task_Queue_Size, sizeof(uint16_t));
  Handle_Pointer = Task_Handle_To_Set;
}

Software_Class::~Software_Class() // Destructor : close
{
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Execute(0x0043); // Wait until last Close
  Instance_Pointer == NULL;
  vQueueDelete(Command_Queue_Handle);
  vTaskDelete(Task_Handle);
}

uint16_t& Software_Class::Get_Command()
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
  Execute(Command::Close);
}

void Software_Class::Maximize()
{
  vTaskResume(Task_Handle);
  Execute(Command::Maximize);
}

void Software_Class::Minimize()
{
  Execute(Command::Minimize);
}

// Software handle

Software_Handle_Class::Software_Handle_Class(char const *Software_Name, uint8_t &Icon_ID)
{
  Name = new char[sizeof(Software_Name)];
  strcpy(Name, Software_Name);
  Icon = Icon_ID;
  Load_Function_Pointer = &Default_Load_Function;
}

Software_Handle_Class::~Software_Handle_Class()
{
}

Software_Class *Software_Handle_Class::Default_Load_Function(Software_Handle_Class* Software_Handle_To_Set)
{
  /*if (GalaxOS.Drive.exists("/SOFTWARE/" + String(Name) + "/" + String(Name) + ".GEF")) //looking for executable
  {
    GalaxOS.Drive.Open_File(SD_MMC.open("/SOFTWARE/" + String(Name) + "/" + String(Name) + ".GEF"));
  }*/
  return NULL; //return null pointer because it's an external executable
}