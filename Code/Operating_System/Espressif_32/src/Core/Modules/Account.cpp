///
/// @file Account.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Account management source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

Xila_Class::Account_Class::Account_Class()
{
  memset(Current_Username, '\0', sizeof(Current_Username));
}

Xila_Class::Event Xila_Class::Account_Class::Load_Registry()
{
  File Temporary_File = Xila.Drive.Open(Registry("Account"), FILE_WRITE);
  DynamicJsonDocument Account_Registry(256);
  if (deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  if (strcmp(Account_Registry["Registry"] | "", "Account") != 0)
  {
    return Error;
  }
  memcpy(Current_Username, '\0', sizeof(Current_Username));
  strlcpy(Current_Username, Account_Registry["Autologin"] | "", sizeof(Current_Username));
  if (Current_Username[0] != '\0')
  {
    State = Logged;
  }
  return Success;
}

/**
 * @brief 
 * 
 * @param Enable 
 * @return Xila_Class::Event 
 */
Xila_Class::Event Xila_Class::Account_Class::Set_Autologin(bool Enable)
{
  File Temporary_File = Xila.Drive.Open(Registry("Account"), FILE_WRITE);
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
    return Error;
  }
  Temporary_File.close();
  return Success;
}

/**
 * @brief Return current session state.
 * 
 * @return uint8_t return Xila_Class::Acount_Class::Session_State.
 */
uint8_t Xila_Class::Account_Class::Get_State()
{
  return State;
}

/**
 * @brief 
 * 
 * @return const char* Logged username (empty if there's no logged user).
 */
const char *Xila_Class::Account_Class::Get_Current_Username()
{
  return Current_Username;
}

/**
     * @brief A function that allow to add user.
     * 
     * @param Username Username of new user
     * @param Password 
     *
     * @return Xila_Class::Event::Success or Xila_Class::Event::Error
     */
Xila_Class::Event Xila_Class::Account_Class::Add(const char *Username, const char *Password)
{
  if (Xila.Drive.Exists(Users_Directory_Path "/" + String(Username)))
  {
    return Error;
  }
  char Temporary_Path[30];
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry", Username);
  Xila.Drive.Make_Directory(Temporary_Path);
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Desk", Username);
  Xila.Drive.Make_Directory(Temporary_Path);
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Images", Username);
  Xila.Drive.Make_Directory(Temporary_Path);
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Musics", Username);
  Xila.Drive.Make_Directory(Temporary_Path);
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Document", Username);
  Xila.Drive.Make_Directory(Temporary_Path);
  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry/User.xrf", Username);
  File Temporary_File = Xila.Drive.Open(Temporary_Path, FILE_WRITE);
  DynamicJsonDocument User_Registry(256);

  User_Registry["Registry"] = "User";
  User_Registry["Password"] = Password;
  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  return Success;
}

Xila_Class::Event Xila_Class::Account_Class::Delete(const char *Target_User)
{
  char Temporary_Path[20];
  snprintf(Temporary_Path, sizeof(Temporary_Path), (Users_Directory_Path "/%s"), Target_User);
  if (Xila.Drive.Remove_Directory(Temporary_Path))
  {
    return Success;
  }
  return Error;
}

Xila_Class::Event Xila_Class::Account_Class::Change_Username(const char *Target_User, const char *New_Username)
{
  char Temporary_Path[20];
  char Temporary_Target_Path[20];
  strcpy(Temporary_Path, Users_Directory_Path);
  strlcat(Temporary_Path, "/", sizeof(Temporary_Path));
  strcpy(Temporary_Target_Path, Temporary_Path);
  strlcat(Temporary_Target_Path, Target_User, sizeof(Temporary_Target_Path));
  strlcat(Temporary_Path, New_Username, sizeof(Temporary_Path));
  if (!Xila.Drive.Rename(Temporary_Target_Path, Temporary_Path))
  {
    return Error;
  }
  if (strcmp(Target_User, Current_Username) == 0)
  {
    strlcpy(Current_Username, New_Username, sizeof(Current_Username));
  }
  return Success;
}

Xila_Class::Event Xila_Class::Account_Class::Change_Password(const char *Target_User, const char *Password_To_Set)
{
  char Temporary_Char[48];
  snprintf(Temporary_Char, sizeof(Temporary_Char), (Users_Directory_Path "/%s/Registry/User.xrf"), Target_User);
  File Temporary_File = Xila.Drive.Open(Temporary_Char, FILE_WRITE);
  DynamicJsonDocument User_Registry(Default_Registry_Size);
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  User_Registry["Password"] = Password_To_Set;
  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  return Success;
}

/** */

Xila_Class::Event Xila_Class::Account_Class::Logout()
{
  if (State != Disconnected)
  {

    memset(Current_Username, '\0', sizeof(Current_Username));
    State = Xila.Account.Disconnected;
  }

  return Success;
}

Xila_Class::Event Xila_Class::Account_Class::Lock()
{
  if (State == Logged)
  {
    State = Locked;
  }
  return Success;
}

Xila_Class::Event Xila_Class::Account_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
{
  char Temporary_Path[48];
  snprintf(Temporary_Path, sizeof(Temporary_Path), (Users_Directory_Path "/%s/Registry/User.xrf"), Username_To_Check);
  File Temporary_File = Xila.Drive.Open(Temporary_Path);
  DynamicJsonDocument User_Registry(256);
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  Temporary_File.close();
  if (strcmp("User", User_Registry["Registry"] | "") != 0)
  {
    return Error;
  }
  if (strcmp(Password_To_Check, User_Registry["Password"] | "") != 0)
  {
    return Error;
  }
  return Success;
}

Xila_Class::Event Xila_Class::Account_Class::Login(const char *Username_To_Check, const char *Password_To_Check)
{
  if (Check_Credentials(Username_To_Check, Password_To_Check) != Success)
  {
    State = Disconnected;
    return Error;
  }
  strcpy(Current_Username, Username_To_Check);
  State = Logged;
  return Success;
}