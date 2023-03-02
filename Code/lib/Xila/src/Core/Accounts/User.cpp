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

bool User_Class::operator==(const User_Class& User) const
{
  return (Name == User.Name);
}


/// @brief Logout from the openned user session.
///
/// @return Result_Type
void User_Class::Logout()
{
  // Iterate through the list of users by index.
  User_Type User(Name);

  Static_String_Type<16> User_Name;

  for (auto User = User_List.begin(); User != User_List.end(); User++)
  {
    User->Get_Name(User_Name);
    if ((User_Name == Name) && User->Get_State() == User_State_Type::Logged)
    {
      // 
      User->Set_State(User_State_Type::Logged);

      // Close all user softwares.
      Softwares.Close_User_Softwares(this);
      Task_Type::Delay_Static(5000);
      Softwares.Kill_User_Softwares(this);
      // Remove user from the list.
      User_List.erase(User);
      break;
    }
  }
}
