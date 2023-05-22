///
/// @file User.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 26-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Account/Accounts.hpp"
#include "Software/Softwares.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Accounts_Types;

/// @brief User class constructor.
/// @param Name User name.
/// @param State User state.
User_Class::User_Class(const char *Name, User_State_Type State) : Name(Name), State(State)
{
}

User_Class::User_Class(const User_Class &User) : Name(User.Name), State(User.State)
{
}

User_Class::User_Class(User_Class &&User) : User_Class(User.Name, User.State)
{
}

User_State_Type User_Class::Get_State() const
{
  return State;
}

String_Type &User_Class::Get_Name(String_Type &Name) const
{
  Name = this->Name;
  return Name;
}

String_Type &User_Class::Get_Home_Folder_Path(String_Type &Home_Folder_Path) const
{
  Home_Folder_Path = Users_Directory_Path;
  Home_Folder_Path += "/";
  Home_Folder_Path += this->Name;
  return Home_Folder_Path;
}

void User_Class::Set_Name(const char *Name)
{
  this->Name = Name;
}

bool User_Class::operator==(const User_Class &User) const
{
  return (Name == User.Name);
}

bool User_Class::operator!=(const User_Class &User) const
{
  return (Name != User.Name);
}

void User_Class::Lock()
{
  if (State == User_State_Type::Locked)
  {
    return;
  }

  this->State = User_State_Type::Locked;

  User_Class Xila_User("Xila");

  for (auto &User : Accounts.User_List)
  {
    if (User != Xila_User)
    {
      User.State = User_State_Type::Locked;
    }
    else
    {
      User.State = User_State_Type::Logged;
    }
  }
}

void User_Class::Login()
{
  if (State == User_State_Type::Logged)
    return;

  // - Lock all other users.
  for (auto &User : Accounts.User_List)
  {
    User.State = User_State_Type::Locked;
  }

  for (auto &User : Accounts.User_List)
  {
    if (User == *this)
    {
      User.State = User_State_Type::Logged;
      break;
    }
  }
}

void User_Class::Logout()
{
  this->Login();

  Softwares.Close_User_Softwares(this);
  Task_Type::Delay_Static(5000);
  Softwares.Kill_User_Softwares(this);

  this->Lock();

  Accounts.User_List.remove(*this);
}
