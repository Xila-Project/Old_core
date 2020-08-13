#include "Software.hpp"

//Software class

Software_Class *Software_Class::Instance_Pointer = NULL;

Software_Class::Software_Class(Software_Handle_Class *Task_Handle_To_Set, uint8_t &Task_Queue_Size) //constructor
{
  Task_Handle = NULL;
  Handle_Pointer = Task_Handle_To_Set;

  Task_Method_Array = new uint16_t[Task_Queue_Size];
  memset(Task_Method_Array, NULL, sizeof(Task_Method_Array));

  Write_Position = 0;
  Read_Position = 0;
}

Software_Class::~Software_Class() // Destructor : close
{
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Execute(0x0043); // Wait until last Close
  Instance_Pointer == NULL;

  delete Task_Method_Array;
}

uint16_t Software_Class::Get_Command()
{
  if (Read_Position == Write_Position)
  {
    return 0; //idle state
  }
  return Task_Method_Array[Read_Position++];
}

void Software_Class::Execute(uint16_t const &Method_To_Execute)
{
  while (Write_Position == Read_Position - 1) // wait if write is too close from the read
  {
    vTaskDelay(pdMS_TO_TICKS(10));
  }
  Task_Method_Array[Write_Position++] = Method_To_Execute;
}

void Software_Class::Execute(char const &Task_Method_Char1, char const &Task_Method_Char2)
{
  Execute(((uint16_t)Task_Method_Char1 << 8) | (uint16_t)Task_Method_Char2);
}

void Software_Class::Maximize()
{
  vTaskResume(Task_Handle);
  Execute(0x004D)
}

void Software_Class::Minimize()
{
  Execute(0x006D);
}

// Software handle

Software_Handle_Class::Software_Handle_Class(char const *Software_Name, uint8_t &Icon_ID)
{
  Name = new char[sizeof(Software_Name)];
  strcpy(Name, Software_Name);
  Icon = Icon_ID;
  Load_Function_Pointer = Default_Load_Function;
}

Software_Handle_Class::~Software_Handle_Class()
{
}

Software_Class *Software_Handle_Class::Default_Load_Function()
{
  if (SD_MMC.exists("/SOFTWARE/" + String(Name) + "/" + String(Name) + ".GEF")) //looking for executable
  {
    GalaxOS.Open_File(SD_MMC.open("/SOFTWARE/" + String(Name) + "/" + String(Name) + ".GEF"));
  }
  return NULL; //return null pointer because it's an external executable
}