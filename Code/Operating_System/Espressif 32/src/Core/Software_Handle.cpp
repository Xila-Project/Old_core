#include "Core/Software_Handle.hpp"

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