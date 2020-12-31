#include "Software.hpp"

//Software class

Software_Class *Software_Class::Instance_Pointer = NULL;
Software_Handle_Class *Software_Class::Handle_Pointer = NULL;

Software_Class::Software_Class(uint8_t Task_Queue_Size)
{
  if (Task_Queue_Size != 0)
  {
    Command_Queue_Handle = xQueueCreate(Task_Queue_Size, sizeof(uint16_t));
    if (Command_Queue_Handle == NULL)
    {
      Serial.print(F("Error cannot create software Queue !"));
      delete this;
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

Software_Handle_Class::Software_Handle_Class(const char* Char_Array)
: Load_Function_Pointer(NULL),
Startup_Function_Pointer(NULL),
Background_Function_Pointer(NULL)
{
  From_Char_Array(Char_Array);
}

bool Software_Handle_Class::Is_Equal(Software_Handle_Class const& Software_Handle_To_Compare) const
{
  if (strcmp(Name, Software_Handle_To_Compare.Name) != 0)
  {
    return false;
  }
  if (Icon != Software_Handle_To_Compare.Icon)
  {
    return false;
  }
  if (Type != Software_Handle_To_Compare.Type)
  {
    return false;
  }
  return true;
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

void Software_Handle_Class::From_Char_Array(const char* Char_Array)
{


}

void Software_Handle_Class::To_Char_Array(char* Char_Array)
{
strcpy(Char_Array, Name);
Char_Array[sizeof(Name)];
Char_Array[sizeof(Name) + 1];
}

void Software_Handle_Class::From_Char_Array(const char* Char_Array)
{
  strcpy(Name, Char_Array);
  Icon = Char_Array[sizeof(Name)];
  Type = Char_Array[sizeof(Name) + 1];
}

// Operators

bool operator==(Software_Handle_Class const& a, Software_Handle_Class const& b)
{
  return a.Is_Equal(b);
}