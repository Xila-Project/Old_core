///
/// @file Software_Handle.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Software/Software_Handle.hpp"

// Software handle

///
/// @brief Construct a new Software_Handle::Software_Handle object
///
Software_Handle::Software_Handle()
    : Load_Function_Pointer(NULL),
      Startup_Function_Pointer(NULL)
{
  memset(Name, '\0', sizeof(Name));
}

///
/// @brief Construct and define a new Software_Handle::Software_Handle object
///
/// @param Software_Name Software name
/// @param Icon_ID Software icon
/// @param Load_Function_Pointer Load function pointer
/// @param Startup_Function_Pointer Startup function pointer (NULL by default)
Software_Handle::Software_Handle(char const *Software_Name, Software_Class *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)())
    : Load_Function_Pointer(Load_Function_Pointer),
      Startup_Function_Pointer(Startup_Function_Pointer)
{
  memset(Name, '\0', sizeof(Name));
  strlcpy(Name, Software_Name, sizeof(Name));
}

///
/// @brief Compare a software handle with this object.
///
/// @param Software_Handle_To_Compare Software handle to compare
/// @return true if software handle are identical
/// @return false if software handle are different
bool Software_Handle::Is_Equal(Software_Handle const &Software_Handle_To_Compare) const
{
  if ((strcmp(Name, Software_Handle_To_Compare.Name)) != 0 || (Software_Handle_To_Compare.Load_Function_Pointer != Load_Function_Pointer) || (Software_Handle_To_Compare.Startup_Function_Pointer != Startup_Function_Pointer))
  {
    return false;
  }
  return true;
}

///
/// @brief Destroy the Software_Handle::Software_Handle object
///
///
/// @brief Compare two software handle.
///
/// @param a 1st software handle to compare.
/// @param b 2nd software handle to compare.
/// @return true if software handle are identical
/// @return false if software handle are different
bool operator==(Software_Handle const &a, Software_Handle const &b)
{
  return a.Is_Equal(b);
}