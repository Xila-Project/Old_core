///
/// @file Account.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Account management source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Account/Accounts.hpp"

#include "Core/Core.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Accounts_Types;

Accounts_Type Accounts;

Result_Type Accounts_Class::Start()
{
  User_List.push_back(User_Type("Xila", User_State_Type::Logged));
  if (Load_Registry() != Result_Type::Success)
  {
    if (Create_Registry() != Result_Type::Success)
    {
      return Result_Type::Error;
    }
  }
  return Result_Type::Success;
}

Result_Type Accounts_Class::Stop()
{
  User_List.clear();
  if (this->Save_Registry() != Result_Type::Success)
  {
    return Result_Type::Error;
  }
  return Result_Type::Success;
}

Result_Type Accounts_Class::Create_Registry()
{
  StaticJsonDocument<256> Account_Registry;
  Account_Registry["Registry"] = "Account";
  // TODO : Change how to autologin.
  File_Type Temporary_File = Drive.Open(Registry("Account"), true);
  if (!Temporary_File || (serializeJson(Account_Registry, Temporary_File) == 0))
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  return Result_Type::Success;
}

/// @brief Load account registry.
///
/// @return Result_Type
Result_Type Accounts_Class::Load_Registry()
{
  File_Type Temporary_File = Drive.Open(Registry("Account"));
  StaticJsonDocument<256> Account_Registry;

  if (!Temporary_File || deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();

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

Result_Type Accounts_Class::Save_Registry()
{
  File_Type Temporary_File = Drive.Open(Registry("Account"));
  StaticJsonDocument<256> Account_Registry;

  if (!Temporary_File || deserializeJson(Account_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();

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
Result_Type Accounts_Class::Set_Autologin(bool Enable, const String_Type &Name, const String_Type &Password)
{
  File_Type Temporary_File = Drive.Open(Registry("Account"), true);
  DynamicJsonDocument Account_Registry(256);
  Account_Registry["Registry"] = "Account";
  if (Enable)
  {
    // Check user credentials
    if (Check_Credentials(Name, Password) != Result_Type::Success)
    {
      Temporary_File.Close();
      return Result_Type::Error;
    }

    Account_Registry["Autologin"] = Name;
  }
  else
  {
    if ((strcmp(Account_Registry["Autologin"] | "", Name) != 0) && (Check_Credentials(Name, Password) != Result_Type::Success))
    {
      Temporary_File.Close();
      return Result_Type::Error;
    }

    Account_Registry["Autologin"] = "";
  }
  if (serializeJson(Account_Registry, Temporary_File) == 0)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  return Result_Type::Success;
}

const String_Type &Accounts_Class::Get_Autologin_User_Name()
{
  // TODO :
}

/// @brief
///
/// @return  const String_Type& Logged username (empty if there's no logged user).
const User_Type *Accounts_Class::Get_Logged_User()
{
  for (auto &User_Pointer : User_List)
  {
    if (User_Pointer.Get_State() == User_State_Type::Logged)
    {
      return &User_Pointer;
    }
  }
  return nullptr;
}

const Accounts_Types::User_Type *Accounts_Class::Get_User(uint8_t Index)
{
  if (Index >= User_List.size())
  {
    return nullptr;
  }

  auto User_Iterator = User_List.begin();

  for (uint8_t i = 0; i < Index; i++)
  {
    User_Iterator++;
  }
  
  return &(*User_Iterator);
}

///
/// @brief Create a new user (create necessary folder structure and registries).
///
/// @param Username Username of the new user.
/// @param Password Password of the new user.
/// @return Result_Type
Result_Type Accounts_Class::Create(const String_Type &User_Name, const String_Type &Password)
{
  Static_String_Type<64> Temporary_String;
  Temporary_String = Users_Directory_Path;
  Temporary_String += "/";
  Temporary_String += User_Name;

  if (Drive.Exists(Temporary_String))
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
  File_Type Temporary_File = Drive.Open(Temporary_Path, true);
  StaticJsonDocument<256> User_Registry;

  User_Registry["Registry"] = "User";
  User_Registry["Password"] = Password;
  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  return Result_Type::Success;
}

/// @brief Delete a user account.
///
/// @param Target_User User to delete.
/// @return Result_Type
Result_Type Accounts_Class::Delete(const String_Type &User_Name, const String_Type &Password)
{
  if (Check_Credentials(User_Name, Password) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  User_Type User_To_Delete(User_Name);

  for (auto &User : User_List)
  {
    if (User == User_To_Delete)
    {
      return Result_Type::Error;
    }
  }

  Static_String_Type<64> Path;
  Path = Users_Directory_Path;
  Path += "/";
  Path += User_Name;

  if (!Drive.Remove_Directory(Path))
  {
    return Result_Type::Error;
  }

  return Result_Type::Success;
}

/// @brief Change user account name.
///
/// @param Target_User User to rename.
/// @param New_Username New account name.
/// @return Result_Type
Result_Type Accounts_Class::Change_Name(const String_Type &Current_Name, const String_Type &New_Name, const String_Type &Password)
{
  if (Check_Credentials(Current_Name, Password) == Result_Type::Error)
  {
    return Result_Type::Error;
  }

  {
    Static_String_Type<32> New_User_Folder_Path;
    New_User_Folder_Path = Users_Directory_Path;
    New_User_Folder_Path += "/";
    New_User_Folder_Path += New_Name;

    if (Drive.Exists(New_User_Folder_Path))
    {
      return Result_Type::Error;
    }

    Static_String_Class<32> Current_User_Folder_Path;
    Current_User_Folder_Path = Users_Directory_Path;
    Current_User_Folder_Path += "/";
    Current_User_Folder_Path += Current_Name;

    if (!Drive.Rename(Current_User_Folder_Path, New_User_Folder_Path))
    {
      return Result_Type::Error;
    }
  }

  {
    User_Type User_To_Rename(Current_Name);
    for (auto & User : User_List)
    {
      if (User == User_To_Rename)
      {
        User.Set_Name(New_Name);
        break;
      }
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
Result_Type Accounts_Class::Change_Password(const String_Type &Name, const String_Type &Current_Password, const String_Type &New_Password)
{
  using namespace Xila_Namespace::Mathematics_Types;

  if (Check_Credentials(Name, Current_Password) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  char Temporary_Char[48];
  snprintf(Temporary_Char, sizeof(Temporary_Char), (Users_Directory_Path "/%s/Registry/User.xrf"), Name);
  File_Type Temporary_File = Drive.Open(Temporary_Char, true);
  DynamicJsonDocument User_Registry(Default_Registry_Size);
  User_Registry["Registry"] = "User";

  Hash_Type Hash;
  Hash.Create(Message_Digest_Type::SHA_256);

  if (Hash.Add(Current_Password) != Result_Type::Success)
  {
    return Result_Type::Error;
  }
  
  Byte_Type Hash_Buffer[Hash.Get_Size()] = {0};
  Hash.Delete(Hash_Buffer);

  User_Registry["Password"] = (char*)Hash_Buffer;

  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  return Result_Type::Success;
}

/// @brief Lock openned user session.
///
/// @return Result_Type
Result_Type Accounts_Class::Lock(const String_Type &Name)
{
  // Iterate through the list of users by index.
  User_Type User(Name);

  Static_String_Type<16> User_Name;
  for (auto &User_Pointer : User_List)
  {
    User_Pointer->Get_Name(User_Name);
    if ((User_Name == Name) && (User_Pointer->Get_State() == User_State_Type::Logged))
    {
      User_Pointer->Set_State(User_State_Type::Locked);
      return Result_Type::Success;
    }
  }
  return Result_Type::Error;
}

/// @brief Check user credentials.
///
/// @param Username_To_Check User account name.
/// @param Password_To_Check User account password.
/// @return Result_Type
Result_Type Accounts_Class::Check_Credentials(const String_Type &Username_To_Check, const String_Type &Password_To_Check)
{
  using namespace Xila_Namespace::Mathematics_Types;
  Static_String_Type<48> Temporary_Path;
  Temporary_Path = Users_Directory_Path;
  Temporary_Path += "/";
  Temporary_Path += Username_To_Check;
  Temporary_Path += "/Registry/User.xrf";
  
  File_Type Temporary_File = Drive.Open(Temporary_Path);
  StaticJsonDocument<256> User_Registry;
  if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  
  if (strcmp("User", User_Registry["Registry"] | "") != 0)
  {
    return Result_Type::Error;
  }

  Hash_Type Hash;
  Hash.Create(Message_Digest_Type::SHA_256);
  
  if (Hash.Add(Password_To_Check) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  uint8_t Hash_Buffer[Hash.Get_Size()] = {0};
  Hash.Delete(Hash_Buffer);

  if (strcmp(User_Registry["Password"] | "", (char *)Hash_Buffer) != 0)
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
Result_Type Accounts_Class::Login(const String_Type &Name, const String_Type &Password, bool Lock_Other_User)
{
  // Check credentials
  if (Check_Credentials(Name, Password) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  User_Type User_To_Log(Name);

  for (auto &User : User_List)
  {
    if ((User.Get_State() == User_State_Type::Logged) && Lock_Other_User)
    {
      User.Set_State(User_State_Type::Locked);
    }

    if (User_To_Log == User)
    {
      User.Set_State(User_State_Type::Logged);
      return Result_Type::Success;
    }
  }

  if (Lock_Other_User)
  {
    User_To_Log.Set_State(User_State_Type::Logged);
  }
  else
  {
    User_To_Log.Set_State(User_State_Type::Locked);
  }
  User_List.push_back(User_To_Log);
  return Result_Type::Success;
}

uint8_t Accounts_Class::Find_User(const String_Type& Name)
{
  User_Type User(Name);
  
  uint8_t Index = 0;

  for (auto User_Iterator : User_List)
  {
    if (User_Iterator == User)
    {
      return Index;
    }
    Index++;
  }
}

uint8_t Accounts_Class::Get_User_Count()
{
  return User_List.size();
}