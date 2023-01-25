///
/// @file Account.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Account management source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Account/Account.hpp"

#include "Core/Core.hpp"

using namespace Xila_Namespace;

Account_Type Account();

///
/// @brief Construct a new Account_Class::Account_Class object
///
Account_Class::Account_Class()
{
}

///
/// @brief Load account registry.
///
/// @return Result_Type
Result_Type Account_Class::Load_Registry()
{
  File_Type Temporary_File = Drive.Open(Registry("Account"));
  DynamicJsonDocument Account_Registry(256);

  if (deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {

    Temporary_File.close();
    return Result_Type::Error;
  }
  Temporary_File.close();
  if (strcmp(Account_Registry["Registry"] | "", "Account") != 0)
  {

    return Result_Type::Error;
  }
  // TODO : Change how to autologin.
  /*
  memset(Current_Username, '\0', sizeof(Current_Username));
  strlcpy(Current_Username, Account_Registry["Autologin"] | "", sizeof(Current_Username));
  if (Current_Username[0] != '\0')
  {
    State = Logged;
  }
  */

  return Result_Type::Success;
}

/// @brief A method that set autologin and save account registry.
///
/// @param Enable true to enable and false to disable autologin.
/// @return Result_Type
Result_Type Account_Class::Set_Autologin(bool Enable, const char* Name, const char* Password)
{
  File_Type Temporary_File = Drive.Open(Registry("Account"), FILE_WRITE);
  DynamicJsonDocument Account_Registry(256);
  Account_Registry["Registry"] = "Account";
  if (Enable)
  {
    // Check user credentials
    if (Check_Credentials(Name, Password) != Result_Type::Success)
    {
      Temporary_File.close();
      return Result_Type::Error;
    }

    Account_Registry["Autologin"] = Name;
  }
  else
  {
    if ((strcmp(Account_Registry["Autologin"] | "", Name) != 0) && (Check_Credentials(Name, Password) != Result_Type::Success))
    {
      Temporary_File.close();
      return Result_Type::Error;
    }

    Account_Registry["Autologin"] = "";
  }
  if (serializeJson(Account_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result_Type::Error;
  }
  Temporary_File.close();
  return Result_Type::Success;
}

const char* Get_Autologin_User_Name()
{
  // TODO : 
}

/// @brief Return current session state.
///
/// @return uint8_t return Acount_Class::Session_State.
Account_Class::State_Type Account_Class::User_Class::Get_State() const
{
  return State;
}

const char* Account_Class::User_Class::Get_Name() const
{
  return Name;
}

void Account_Class::User_Class::Set_State(State_Type State)
{
  this->State = State;
}


/// @brief 
///
/// @return const char* Logged username (empty if there's no logged user).
const Account_Class::User_Type* Account_Class::Get_Logged_User()
{
  for (auto &User : User_Class::List) 
  {
    if (User.Get_State() == State_Type::Logged)
    {
      return &User;
    }
  }
}

const Account_Class::User_Type* Account_Class::Get_User(uint8_t Index)
{
  if (Index < User_Class::List.size())
  {
    return &User_Class::List[Index];
  }
  return nullptr;
}

///
 /// @brief Create a new user (create necessary folder structure and registries).
 /// 
 /// @param Username Username of the new user.
 /// @param Password Password of the new user.
 /// @return Result_Type 
Result_Type Account_Class::Create(const char *User_Name, const char *Password)
{
  if (Drive.Exists(Users_Directory_Path "/" + String(User_Name)))
  {
    return Result_Type::Error;
  }
  char Temporary_Path[30];
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s", User_Name);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result_Type::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry", User_Name);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result_Type::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Desk", User_Name);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result_Type::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Images", User_Name);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result_Type::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Musics", User_Name);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result_Type::Error;
  }

  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Document", User_Name);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result_Type::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry/User.xrf", User_Name);
  File_Type Temporary_File = Drive.Open(Temporary_Path, FILE_WRITE);
  DynamicJsonDocument User_Registry(256);

  User_Registry["Registry"] = "User";
  User_Registry["Password"] = Password;
  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result_Type::Error;
  }
  Temporary_File.close();
  return Result_Type::Success;
}

///
/// @brief Delete a user account.
///
/// @param Target_User User to delete.
/// @return Result_Type
Result_Type Account_Class::Delete(const char *User_Name, const char* Password)
{
  char Temporary_Path[20];
  snprintf(Temporary_Path, sizeof(Temporary_Path), (Users_Directory_Path "/%s"), User_Name);
  if (Drive.Remove_Directory(Temporary_Path))
  {
    return Result_Type::Success;
  }
  return Result_Type::Error;
}

///
/// @brief Change user account name.
///
/// @param Target_User User to rename.
/// @param New_Username New account name.
/// @return Result_Type
Result_Type Account_Class::Change_Name(const char *Current_Name, const char *New_Name, const char* Password)
{
  if (strlen(New_Name) > sizeof(User_Type::Name))
  {
    return Result_Type::Error;
  }

  if (Check_Credentials(Current_Name, Password) == Result_Type::Error)
  {
    return Result_Type::Error;
  }

  char Temporary_Path[20];
  char Temporary_Target_Path[25];
  strlcpy(Temporary_Path, Users_Directory_Path, sizeof(Temporary_Path));
  strlcat(Temporary_Path, "/", sizeof(Temporary_Path));
  strlcpy(Temporary_Target_Path, Temporary_Path, sizeof(Temporary_Path));
  strlcat(Temporary_Path, Current_Name, sizeof(Temporary_Path));

  if (!Drive.Rename(Temporary_Target_Path, Temporary_Path))
  {
    return Result_Type::Error;
  }

  for (auto &User : User_Class::List)
  {
    if (strcmp(User.Get_Name(), Current_Name) == 0)
    {
      User.Set_Name(New_Name);
      break;
    }
  }

  return Result_Type::Success;
}

///
/// @brief Change user password.
///
/// @param Target_User User to change password.
/// @param Password_To_Set New password.
/// @return Result_Type
Result_Type Account_Class::Change_Password(const char *Name, const char *Current_Password, const char* New_Password)
{
  if (Check_Credentials(Name, Current_Password) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  char Temporary_Char[48];
  snprintf(Temporary_Char, sizeof(Temporary_Char), (Users_Directory_Path "/%s/Registry/User.xrf"), Name);
  File_Type Temporary_File = Drive.Open(Temporary_Char, FILE_WRITE);
  DynamicJsonDocument User_Registry(Default_Registry_Size);
  User_Registry["Registry"] = "User";
  User_Registry["Password"] = New_Password;

  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result_Type::Error;
  }
  Temporary_File.close();
  return Result_Type::Success;
}

///
/// @brief Logout from the openned user session.
///
/// @return Result_Type
Result_Type Account_Class::Logout(const char* Name)
{
  // Iterate through the list of users by index.
  for (auto User = User_Class::List.begin(); User != User_Class::List.end(); User++)
  {
    if ((strcmp(User->Get_Name(), Name) == 0) && (User->Get_State() == State_Type::Logged))
    {
      User->Set_State(State_Type::Logged);
      // TODO : Send a message to user software.
      // Remove user from the list.
      User_Class::List.erase(User);
      break;
    }
    // If the user is not found
    else if (User == User_Class::List.end())
    {
      return Result_Type::Error;
    }
  }

  return Result_Type::Success;
}

///
/// @brief Lock openned user session.
///
/// @return Result_Type
Result_Type Account_Class::Lock(const char* Name)
{
  // Iterate through the list of users by index.
  for (uint8_t i = 0; i < User_Class::List.size(); i++)
  {
    // If the user is found
    if ((strcmp(User_Class::List[i].Get_Name(), Name) == 0) && (User_Class::List[i].Get_State() == State_Type::Logged))
    {
      User_Class::List[i].Set_State(State_Type::Locked);
      // TODO : Send a message to user software.
      break;
    }
    else
    {
      // If the user is not found
      if (i == User_Class::List.size())
      {
        return Result_Type::Error;
      }
    }
  }
  
  return Result_Type::Success;
}

///
 /// @brief Check user credentials.
 /// 
 /// @param Username_To_Check User account name.
 /// @param Password_To_Check User account password.
 /// @return Result_Type 
Result_Type Account_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
{
  char Temporary_Path[48];
  snprintf(Temporary_Path, sizeof(Temporary_Path), (Users_Directory_Path "/%s/Registry/User.xrf"), Username_To_Check);
  File_Type Temporary_File = Drive.Open(Temporary_Path);
  DynamicJsonDocument User_Registry(256);
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Result_Type::Error;
  }
  Temporary_File.close();
  if (strcmp("User", User_Registry["Registry"] | "") != 0)
  {
    return Result_Type::Error;
  }
  if (strcmp(Password_To_Check, User_Registry["Password"] | "") != 0)
  {
    return Result_Type::Error;
  }
  return Result_Type::Success;
}

///
 /// @brief Login into user account.
 /// 
 /// @param Username_To_Check User account name.
 /// @param Password_To_Check User account password.
 /// @return Result_Type 
Result_Type Account_Class::Login(const char *Name, const char *Password, bool Lock_Other_User = true)
{
  // Check credentials
  if (Check_Credentials(Name, Password) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  for (auto &User : User_Class::List)
    {
      if ((User.Get_State() == State_Type::Logged) && Lock_Other_User)
      {
        User.Set_State(State_Type::Locked);
      }
      if (strcmp(User.Get_Name(), Name) == 0)
      {
        return Result_Type::Error;
      }
    }


  User_Type User(Name, State_Type::Locked);
  if (Lock_Other_User)
  {
    User.Set_State(State_Type::Logged);
  }
  
  User_Class::List.push_back(User);

  return Result_Type::Success;
}

Account_Class::User_Class::User_Class(const char* Name, State_Type State = State_Type::Locked) : State(State)
{
  strlcpy(this->Name, Name, sizeof(Name));
}