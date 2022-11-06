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

using namespace Xila;

///
/// @brief Construct a new Xila_Namespace::Account_Class::Account_Class object
///
Account_Class::Account_Class()
{
  memset(Current_Username, '\0', sizeof(Current_Username));
}

///
/// @brief Load account registry.
///
/// @return Result::Type
Module_Class::Result::Type Xila_Namespace::Account_Class::Load_Registry()
{
  using namespace Xila;
  File_Type Temporary_File = Drive.Open(Registry("Account"));
  DynamicJsonDocument Account_Registry(256);

  if (deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {

    Temporary_File.close();
    return Result::Error;
  }
  Temporary_File.close();
  if (strcmp(Account_Registry["Registry"] | "", "Account") != 0)
  {

    return Result::Error;
  }
  memset(Current_Username, '\0', sizeof(Current_Username));
  strlcpy(Current_Username, Account_Registry["Autologin"] | "", sizeof(Current_Username));
  if (Current_Username[0] != '\0')
  {
    State = Logged;
  }

  return Result::Success;
}

///
/// @brief A method that set autologin and save account registry.
///
/// @param Enable true to enable and false to disable autologin.
/// @return Result::Type
Module_Class::Result::Type Xila_Namespace::Account_Class::Set_Autologin(bool Enable)
{
  File_Type Temporary_File = Drive.Open(Registry("Account"), FILE_WRITE);
  DynamicJsonDocument Account_Registry(256);
  Account_Registry["Registry"] = "Account";
  if (Enable)
  {
    Account_Registry["Autologin"] = Current_Username;
  }
  else
  {
    Account_Registry["Autologin"] = "";
  }
  if (serializeJson(Account_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result::Error;
  }
  Temporary_File.close();
  return Result::Success;
}

///
/// @brief Return current session state.
///
/// @return uint8_t return Acount_Class::Session_State.
///
Account_Class::Session_State Xila_Namespace::Account_Class::Get_State()
{
  return State;
}

void Xila_Namespace::Account_Class::Set_State(Session_State State)
{
  this->State = State;
}

/**
 * @brief 
 * 
 * @return const char* Logged username (empty if there's no logged user).
 */
const char *Account_Class::Get_Current_Username()
{
  return Current_Username;
}

void Xila_Namespace::Account_Class::Set_Current_Username(const char *Username)
{
  strlcpy(Current_Username, Username, sizeof(Current_Username));
}

///
 /// @brief Add a new user (create necessary folder structure and registries).
 /// 
 /// @param Username Username of the new user.
 /// @param Password Password of the new user.
 /// @return Result::Type 
Module_Class::Result::Type Xila_Namespace::Account_Class::Add(const char *Username, const char *Password)
{
  if (Drive.Exists(Users_Directory_Path "/" + String(Username)))
  {
    return Result::Error;
  }
  char Temporary_Path[30];
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s", Username);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry", Username);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Desk", Username);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Images", Username);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Musics", Username);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result::Error;
  }

  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Document", Username);
  if (Drive.Make_Directory(Temporary_Path) == false)
  {
    return Result::Error;
  }
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry/User.xrf", Username);
  File_Type Temporary_File = Drive.Open(Temporary_Path, FILE_WRITE);
  DynamicJsonDocument User_Registry(256);

  User_Registry["Registry"] = "User";
  User_Registry["Password"] = Password;
  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result::Error;
  }
  Temporary_File.close();
  return Result::Success;
}

///
/// @brief Delete a user account.
///
/// @param Target_User User to delete.
/// @return Result::Type
Module_Class::Result::Type Xila_Namespace::Account_Class::Delete(const char *Target_User)
{
  char Temporary_Path[20];
  snprintf(Temporary_Path, sizeof(Temporary_Path), (Users_Directory_Path "/%s"), Target_User);
  if (Drive.Remove_Directory(Temporary_Path))
  {
    return Result::Success;
  }
  return Result::Error;
}

///
/// @brief Change user account name.
///
/// @param Target_User User to rename.
/// @param New_Username New account name.
/// @return Result::Type
Module_Class::Result::Type Xila_Namespace::Account_Class::Change_Username(const char *Target_User, const char *New_Username)
{
  char Temporary_Path[20];
  char Temporary_Target_Path[20];
  strlcpy(Temporary_Path, Users_Directory_Path, sizeof(Temporary_Path));
  strlcat(Temporary_Path, "/", sizeof(Temporary_Path));
  strlcpy(Temporary_Target_Path, Temporary_Path, sizeof(Temporary_Path));
  strlcat(Temporary_Target_Path, Target_User, sizeof(Temporary_Target_Path));
  strlcat(Temporary_Path, New_Username, sizeof(Temporary_Path));
  if (!Drive.Rename(Temporary_Target_Path, Temporary_Path))
  {
    return Result::Error;
  }
  if (strcmp(Target_User, Current_Username) == 0)
  {
    strlcpy(Current_Username, New_Username, sizeof(Current_Username));
  }
  return Result::Success;
}

///
/// @brief Change user password.
///
/// @param Target_User User to change password.
/// @param Password_To_Set New password.
/// @return Result::Type
Module_Class::Result::Type Xila_Namespace::Account_Class::Change_Password(const char *Target_User, const char *Password_To_Set)
{
  char Temporary_Char[48];
  snprintf(Temporary_Char, sizeof(Temporary_Char), (Users_Directory_Path "/%s/Registry/User.xrf"), Target_User);
  File_Type Temporary_File = Drive.Open(Temporary_Char, FILE_WRITE);
  DynamicJsonDocument User_Registry(Default_Registry_Size);
  User_Registry["Registry"] = "User";
  User_Registry["Password"] = Password_To_Set;
  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Result::Error;
  }
  Temporary_File.close();
  return Result::Success;
}

///
/// @brief Logout from the openned user session.
///
/// @return Result::Type
Module_Class::Result::Type Xila_Namespace::Account_Class::Logout()
{
  if (Get_State() != Disconnected)
  {

    memset(Current_Username, '\0', sizeof(Current_Username));
    Set_State(Disconnected);
  }

  return Result::Success;
}

///
/// @brief Lock openned user session.
///
/// @return Result::Type
Module_Class::Result::Type Xila_Namespace::Account_Class::Lock()
{
  if (State == Logged)
  {
    State = Locked;
  }
  return Result::Success;
}

///
 /// @brief Check user credentials.
 /// 
 /// @param Username_To_Check User account name.
 /// @param Password_To_Check User account password.
 /// @return Result::Type 
Module_Class::Result::Type Xila_Namespace::Account_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
{
  char Temporary_Path[48];
  snprintf(Temporary_Path, sizeof(Temporary_Path), (Users_Directory_Path "/%s/Registry/User.xrf"), Username_To_Check);
  File_Type Temporary_File = Drive.Open(Temporary_Path);
  DynamicJsonDocument User_Registry(256);
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Result::Error;
  }
  Temporary_File.close();
  if (strcmp("User", User_Registry["Registry"] | "") != 0)
  {
    return Result::Error;
  }
  if (strcmp(Password_To_Check, User_Registry["Password"] | "") != 0)
  {
    return Result::Error;
  }
  return Result::Success;
}

///
 /// @brief Login into user account.
 /// 
 /// @param Username_To_Check User account name.
 /// @param Password_To_Check User account password.
 /// @return Result::Type 
Module_Class::Result::Type Xila_Namespace::Account_Class::Login(const char *Username_To_Check, const char *Password_To_Check)
{
  using namespace Xila;
  if (Check_Credentials(Username_To_Check, Password_To_Check) != Result::Success)
  {
    State = Disconnected;
    return Result::Error;
  }
  // -- If another user was already connected, close all of it's software.
  if (State == Locked && (strcmp(Account.Current_Username, Username_To_Check) != 0))
  {
    // Iterate through software list and close all of them.
    for (auto & Software : Software_Type::List)
    {
      if (Software != NULL)
      {
        Software->Close();
      }
    }
  }
  //
  strlcpy(Current_Username, Username_To_Check, sizeof(Current_Username));
  State = Logged;
  return Result::Success;
}