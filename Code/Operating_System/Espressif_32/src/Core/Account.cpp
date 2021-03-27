#include "Core/Core.hpp"

// Account management
Xila_Event Xila_Class::Add_User(const char *Username, const char *Password)
{
  if (Drive->exists(Users_Directory_Path + String(Username)))
  {
    return Error;
  }

  Drive->mkdir(Users_Directory_Path + String(Username) + "/Registry");
  Drive->mkdir(Users_Directory_Path + String(Username) + "/Desk");
  Drive->mkdir(Users_Directory_Path + String(Username) + "/Images");
  Drive->mkdir(Users_Directory_Path + String(Username) + "/Document");
  Drive->mkdir(Users_Directory_Path + String(Username) + "/Musics");
  File Temporary_File = Drive->open(Users_Directory_Path + String(Username) + "/Registry/User.xrf", FILE_WRITE);
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

Xila_Event Xila_Class::Delete_User(const char *Target_User)
{
  char Temporary_Path[17];
  strcpy(Temporary_Path, Users_Directory_Path);
  strlcat(Temporary_Path, Target_User, sizeof(Temporary_Path));
  if (Drive->rmdir(Temporary_Path))
  {
    return Success;
  }
  return Error;
}

Xila_Event Xila_Class::Change_Username(const char *Target_User, const char *New_Username)
{
  if (!Drive->rename(Users_Directory_Path + String(Target_User), Users_Directory_Path + String(New_Username)))
  {
    return Error;
  }
  if (strcmp(Target_User, Current_Username) == 0)
  {
    strlcpy(Current_Username, New_Username, sizeof(Current_Username));
  }
  return Success;
}

Xila_Event Xila_Class::Change_Password(const char *Target_User, const char *Password_To_Set)
{
  File Temporary_File = Drive->open(Users_Directory_Path + String(Target_User) + "/Registry/User.xrf");
  DynamicJsonDocument User_Registry(DEFAULT_REGISTRY_SIZE);
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return Error;
  }
  User_Registry["Password"] = Password_To_Set;
  serializeJson(User_Registry, Temporary_File);
  return Success;
}

Xila_Event Xila_Class::Logout()
{
  memset(Current_Username, '\0', sizeof(Current_Username));
  User_Session = Disconnected;
  return Success;
}

Xila_Event Xila_Class::Lock()
{
  if (User_Session == Logged)
  {
    User_Session = Locked;
  }
  return Success;
}

Xila_Event Xila_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
{
  if (Drive->exists(Users_Directory_Path + String(Username_To_Check) + "/Registry/User.xrf"))
  {
    File Temporary_File = Drive->open(Users_Directory_Path + String(Username_To_Check) + "/Registry/User.xrf");
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

Xila_Event Xila_Class::Login(const char *Username_To_Check, const char *Password_To_Check)
{
  if (Check_Credentials(Username_To_Check, Password_To_Check) != Success)
  {
    User_Session = Disconnected;
    return Error;
  }
  strcpy(Current_Username, Username_To_Check);
  User_Session = Logged;
  return Success;
}