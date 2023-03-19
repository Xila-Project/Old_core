///
 /// @file User.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 26-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

 #include "Core/Account/Accounts.hpp"
 #include "Core/Software/Softwares.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Accounts_Types;

/// @brief User class constructor.
/// @param Name User name.
/// @param State User state.
User_Class::User_Class(const String_Type& Name, User_State_Type State) : Name(Name), State(State)
{
  Log_Verbose("User", "Constructor");
}

User_Class::User_Class(const User_Class& User) : Name(User.Name), State(User.State)
{
  Log_Verbose("User", "Copy constructor");
}

User_Class::User_Class(User_Class&& User) : User_Class(User.Name, User.State)
{
  Log_Verbose("User", "Move constructor");
}

/// @brief Return current session state.
///
/// @return uint8_t return Acount_Class::Session_State.
User_State_Type User_Class::Get_State() const
{
  return State;
}

void User_Class::Get_Name(String_Type& Name) const
{
  Name = this->Name;
}

void User_Class::Get_Home_Folder_Path(String_Type& Home_Folder_Path) const
{
  Home_Folder_Path = Users_Directory_Path;
  Home_Folder_Path += "/";
  Home_Folder_Path += this->Name;
  
}

void User_Class::Set_Name(const String_Type& Name)
{
  this->Name = Name;
}

bool User_Class::operator==(const User_Class& User) const
{
  return (Name == User.Name);
}

bool User_Class::operator!=(const User_Class& User) const
{
  return (Name != User.Name);
}

/// @brief Lock the current session and (re)login system account.
void User_Class::Lock()
{
  if (State == User_State_Type::Locked)
  {
    return;
  }

  this->State = User_State_Type::Locked;

  User_Class Xila_User("Xila");

  for (auto& User : Accounts.User_List)
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

/// @brief Re-login the user and lock the previous one.
void User_Class::Login()
{
  if (State == User_State_Type::Logged)
  {
    return;
  }

  for (auto& User : Accounts.User_List)
  {
    User.State = User_State_Type::Locked;
  }

  this->State = User_State_Type::Logged;
}

/// @brief Logout from the openned user session and (re)login system account.
void User_Class::Logout()
{
  this->Login();

  Softwares.Close_User_Softwares(this);
  Task_Type::Delay_Static(5000);
  Softwares.Kill_User_Softwares(this);

  this->Lock();

  Accounts.User_List.remove(*this);
}
