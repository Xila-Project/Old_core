/// @file Software_Handle.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#include "Core/Software/Software_Handle.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;

template<typename T, size_t N>
std::array<T, N> Init_Array(const T& value) {
  std::array<T, N> result;
  std::generate(result.begin(), result.end(), [&value]() { return value; });
  return result;
}

/// Fill array with nullptr
std::array<Software_Handle_Class*, 40> Software_Handle_Class::List = Init_Array<Software_Handle_Class*, 40>(NULL);
// Software handle

/// @brief Construct and define a new Software_Handle::Software_Handle object
///
/// @param Software_Name Software name
/// @param Icon_ID Software icon
/// @param Load_Function_Pointer Load function pointer
/// @param Startup_Function_Pointer Startup function pointer (NULL by default)
Software_Handle_Class::Software_Handle_Class(const char* Name)
    : Name(Name)
{
  for (auto& Software_Handle_Pointer : List)
  {
    if (Software_Handle_Pointer == NULL)
    {
      Software_Handle_Pointer = this;
      break;
    }
  }
}

Software_Handle_Class::~Software_Handle_Class()
{
  for (auto &Software_Handle_Pointer : List)
  {
    if (Software_Handle_Pointer == this)
    {
      Software_Handle_Pointer = nullptr;
    }
  }
}

///
/// @brief Compare a software handle with this object.
///
/// @param Software_Handle_To_Compare Software handle to compare
/// @return true if software handle are identical
/// @return false if software handle are different
bool Software_Handle_Class::Is_Equal(const Software_Handle_Class &Software_Handle) const
{
  if (Software_Handle.Name == this->Name)
  {
    return true;
  }
  return false;
}

String_Type& Software_Handle_Class::Get_Name(String_Type& Name) const
{
  Name = this->Name;
  return Name;
}

void Software_Handle_Class::Create_Instance(const Accounts_Types::User_Type* Owner_User) const
{
  // 
}

bool Software_Handle_Class::operator==(const Software_Handle_Class &Software_Handle_To_Compare) const
{
  return Is_Equal(Software_Handle_To_Compare);
}

bool Software_Handle_Class::operator!=(const Software_Handle_Class &Software_Handle_To_Compare) const
{
  return !Is_Equal(Software_Handle_To_Compare);
}