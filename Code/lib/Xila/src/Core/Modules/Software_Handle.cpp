#include "Core/Modules/Software_Handle.hpp"

// Software handle

///
/// @brief Construct a new Software_Handle_Class::Software_Handle_Class object
///
Software_Handle_Class::Software_Handle_Class()
    : Icon(0),
      Load_Function_Pointer(NULL),
      Startup_Function_Pointer(NULL)
{
  memset(Name, '\0', sizeof(Name));
}

///
/// @brief Compare a software handle with this object.
///
/// @param Software_Handle_To_Compare Software handle to compare
/// @return true if software handle are identical
/// @return false if software handle are different
bool Software_Handle_Class::Is_Equal(Software_Handle_Class const &Software_Handle_To_Compare) const
{
  if (strcmp(Name, Software_Handle_To_Compare.Name) != 0)
  {
    return false;
  }
  if (Icon != Software_Handle_To_Compare.Icon)
  {
    return false;
  }
  return true;
}

///
/// @brief Construct a new Software_Handle_Class::Software_Handle_Class object
///
/// @param Software_Name Software name
/// @param Icon_ID Software icon
/// @param Load_Function_Pointer Load function pointer
/// @param Startup_Function_Pointer Startup function pointer (NULL by default)
Software_Handle_Class::Software_Handle_Class(char const *Software_Name, uint8_t Icon_ID, Software_Class *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)())
    : Icon(Icon_ID),
      Load_Function_Pointer(Load_Function_Pointer),
      Startup_Function_Pointer(Startup_Function_Pointer)
{
  memset(Name, '\0', sizeof(Name));
  strcpy(Name, Software_Name);
}

///
/// @brief Destroy the Software_Handle_Class::Software_Handle_Class object
///
Software_Handle_Class::~Software_Handle_Class()
{
}

///
/// @brief Compare two software handle.
///
/// @param a 1st software handle to compare.
/// @param b 2nd software handle to compare.
/// @return true if software handle are identical
/// @return false if software handle are different
bool operator==(Software_Handle_Class const &a, Software_Handle_Class const &b)
{
  return a.Is_Equal(b);
}