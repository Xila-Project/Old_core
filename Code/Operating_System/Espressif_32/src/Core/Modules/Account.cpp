/**
 * @file Account.cpp
 * @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 * @brief Contains all of the methods of account management module.
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Core/Core.hpp"

Xila_Class::Account_Class::Account_Class()
{
  memset(Current_Username, '\0', sizeof(Current_Username));
#if LOGIN == 0
  strlcpy(Current_Username, "ALIX", sizeof(Current_Username));
#endif
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
  strlcpy(Current_Username, Account_Registry["Autologin"] | Default_Autologin_Account, sizeof(Current_Username));
  Temporary_File.close();
  return Success;
}

Xila_Class::Event Xila_Class::Account_Class::Save_Registry()
{
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
  if (deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.close();
    return Error;
  }
  Account_Registry["Autologin"] = Current_Username;
  serializeJson(Account_Registry, Temporary_File);
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
  if (Xila.Drive.Exists(Users_Directory_Path + String(Username)))
  {
    return Error;
  }

  Xila.Drive.Make_Directory(Users_Directory_Path + String(Username) + "/Registry");
  Xila.Drive.Make_Directory(Users_Directory_Path + String(Username) + "/Desk");
  Xila.Drive.Make_Directory(Users_Directory_Path + String(Username) + "/Images");
  Xila.Drive.Make_Directory(Users_Directory_Path + String(Username) + "/Document");
  Xila.Drive.Make_Directory(Users_Directory_Path + String(Username) + "/Musics");
  File Temporary_File = Xila.Drive.Open(Users_Directory_Path + String(Username) + "/Registry/User.xrf", FILE_WRITE);
  DynamicJsonDocument User_Registry(256);
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return Error;
  }

  User_Registry["Registry"] = "User";
  User_Registry["Password"] = Password;
  serializeJson(User_Registry, Temporary_File);
  return Success;
}

Xila_Class::Event Xila_Class::Account_Class::Delete(const char *Target_User)
{
  char Temporary_Path[17];
  strcpy(Temporary_Path, Users_Directory_Path);
  strlcat(Temporary_Path, Target_User, sizeof(Temporary_Path));
  if (Xila.Drive.Remove_Directory(Temporary_Path))
  {
    return Success;
  }
  return Error;
}

Xila_Class::Event Xila_Class::Account_Class::Change_Username(const char *Target_User, const char *New_Username)
{
  if (!Xila.Drive.Rename(Users_Directory_Path + String(Target_User), Users_Directory_Path + String(New_Username)))
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
  File Temporary_File = Xila.Drive.Open(Users_Directory_Path + String(Target_User) + "/Registry/User.xrf");
  DynamicJsonDocument User_Registry(Default_Registry_Size);
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return Error;
  }
  User_Registry["Password"] = Password_To_Set;
  serializeJson(User_Registry, Temporary_File);
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
  if (Xila.Drive.Exists(Users_Directory_Path + String(Username_To_Check) + "/Registry/User.xrf"))
  {
    File Temporary_File = Xila.Drive.Open(Users_Directory_Path + String(Username_To_Check) + "/Registry/User.xrf");
    DynamicJsonDocument User_Registry(256);
    if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
    {
      return Error;
    }
    if (strcmp("User", User_Registry["Registry"]) != 0)
    {
      Verbose_Print_Line("> Corrupted registry");
      return Error;
    }

    if (strcmp(Password_To_Check, User_Registry["Password"]) != 0)
    {
      Verbose_Print_Line("> Wrong Credentials ...");

      return Error;
    }

    Verbose_Print_Line("> Good Credentials ...");
    return Success;
  }
  Verbose_Print_Line("> Failed to open user registry");
  return Error;
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