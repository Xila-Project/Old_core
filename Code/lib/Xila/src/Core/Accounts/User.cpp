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


/// @brief Return current session state.
///
/// @return uint8_t return Acount_Class::Session_State.
Accounts_Class::State_Type Accounts_Class::User_Class::Get_State() const
{
  return State;
}

const char* Accounts_Class::User_Class::Get_Name() const
{
  return Name;
}

const char* Accounts_Class::User_Class::Get_Home_Folder_Path() const
{
  // TODO :
  
}

void Accounts_Class::User_Class::Set_State(State_Type State)
{
  this->State = State;
}