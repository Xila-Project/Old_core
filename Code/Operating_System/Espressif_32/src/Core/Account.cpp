#include "Core/Core.hpp"

// Account management
Xila_Event Xila_Class::Add_User(const char* Username, const char* Password)
{
  if (Drive->exists("/USERS/" + String(Username)))
  {
    return Error;
  }

  Drive->mkdir("/USERS/" + String(Username) + "/REGISTRY");
  Drive->mkdir("/USERS/" + String(Username) + "/DESK");
  Drive->mkdir("/USERS/" + String(Username) + "/IMAGES");
  Drive->mkdir("/USERS/" + String(Username) + "/DOCUMENT");
  Drive->mkdir("/USERS/" + String(Username) + "/MUSICS");
  File Temporary_File = Drive->open("/USERS/" + String(Username) + "/REGISTRY/USER.XRF", FILE_WRITE);
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

  if (Drive->remove("/USERS/" + String(Target_User)))
  {
    return Success;
  }
  return Error;
}

Xila_Event Xila_Class::Change_Username(const char *Target_User, const char *New_Username)
{
  if (!Drive->rename("/USERS/" + String(Target_User), "/USERS/" + String(New_Username)))
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
  File Temporary_File = Drive->open("/USERS/" + String(Target_User) + "/REGISTRY/USER.XRF");
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
  return Success;
}

Xila_Event Xila_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
{
  if (Drive->exists("/USERS/" + String(Username_To_Check) + "/REGISTRY/USER.XRF"))
  {
    File Temporary_File = Drive->open("/USERS/" + String(Username_To_Check) + "/REGISTRY/USER.XRF");
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
    return Error;
  }
  strcpy(Current_Username, Username_To_Check);
  return Success;
}