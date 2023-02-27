///
 /// @file User.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 26-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

 #include "Core/Account/Account.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Accounts_Types;

/// @brief User class constructor.
/// @param Name User name.
/// @param State User state.
User_Class::User_Class(const String_Type& Name, User_State_Type State) : Name(Name), State(State)
{
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

void User_Class::Set_State(User_State_Type State)
{
  this->State = State;
}

void User_Class::Set_Name(const String_Type& Name)
{
  this->Name = Name;
}
