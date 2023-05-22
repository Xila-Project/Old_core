/// @file Software_Handle.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#include "Software/Software_Handle.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Softwares_Types;

std::list<Software_Handle_Class*> Software_Handle_Class::List;

Software_Handle_Class::Software_Handle_Class(const char* Name)
    : Name(Name)
{
}

Software_Handle_Class::~Software_Handle_Class()
{
}

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