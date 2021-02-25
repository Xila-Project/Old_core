#include "Core/Software_Handle.hpp"

// Software handle

Software_Handle_Class::Software_Handle_Class()
    : Icon(0),
      Type(0),
      Load_Function_Pointer(NULL),
      Startup_Function_Pointer(NULL)
{
  memset(Name, '\0', sizeof(Name));
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

Software_Handle_Class::Software_Handle_Class(char const *Software_Name, uint8_t Icon_ID, Software_Class *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)())
    : Icon(Icon_ID),
      Type(0),
      Load_Function_Pointer(Load_Function_Pointer),
      Startup_Function_Pointer(Startup_Function_Pointer)
{
  memset(Name, '\0', sizeof(Name));
  strcpy(Name, Software_Name);
}

Software_Handle_Class::~Software_Handle_Class()
{
}

// Operators

bool operator==(Software_Handle_Class const& a, Software_Handle_Class const& b)
{
  return a.Is_Equal(b);
}