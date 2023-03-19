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
#include "Core/Log/Log.hpp"
#include "Core/Core.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Accounts_Types;

Accounts_Type Xila_Namespace::Accounts;

Result_Type Accounts_Class::Start()
{
  Log_Information("Account", "Start account module...");

  User_Type Xila_User("Xila", User_State_Type::Logged);
  User_List.push_back(Xila_User);

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
  StaticJsonDocument<256> Account_Registry;
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

/// @brief
///
/// @return  const String_Type& Logged username (empty if there's no logged user).
const User_Type *Accounts_Class::Get_Logged_User()
{
  Log_Verbose("Account", "Get logged user...");
  Log_Verbose("Account", "User list size : %u", User_List.size());

  for (auto &User_Pointer : User_List)
  {
    if (User_Pointer.Get_State() == User_State_Type::Logged)
    {
      return &User_Pointer;
    }
  }
  return NULL;
}

const Accounts_Types::User_Type *Accounts_Class::Get_User(uint8_t Index)
{
  if (Index >= User_List.size())
  {
    return NULL;
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

  uint8_t Hashed_Password[65];

  {
    // - Create a salted and peppered password.
    Static_String_Type<69> Salted_Password = Password;
    this->Salt_Password(Salted_Password, static_cast<char>(Mathematics.Random(0x000000FF)));
    // Hash the salted and peppered password.
    if (this->Hash_Password(Salted_Password, Hashed_Password) != Result_Type::Success)
    {
      return Result_Type::Error;
    }
    // Add null terminator in order to handle it as a regular character array.
    Hashed_Password[64] = '\0';
  }

  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry/User.xrf", User_Name);
  File_Type Temporary_File = Drive.Open(Temporary_Path, true);
  StaticJsonDocument<256> User_Registry;

  User_Registry["Registry"] = "User";
  User_Registry["Password"] = (char *)Hashed_Password;

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
    for (auto &User : User_List)
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

  uint8_t Hashed_Password[65];

  {
    // - Create a salted and peppered password.
    Static_String_Type<69> Salted_Password = New_Password;
    this->Salt_Password(Salted_Password, static_cast<char>(Mathematics.Random(0x000000FF)));
    // Hash the salted and peppered password.
    if (this->Hash_Password(Salted_Password, Hashed_Password) != Result_Type::Success)
    {
      return Result_Type::Error;
    }
    // Add null terminator in order to handle it as a regular character array.
    Hashed_Password[64] = '\0';
  }


  char Temporary_Char[48];
  snprintf(Temporary_Char, sizeof(Temporary_Char), (Users_Directory_Path "/%s/Registry/User.xrf"), Name);
  File_Type Temporary_File = Drive.Open(Temporary_Char, true);
  StaticJsonDocument<256> User_Registry;
  User_Registry["Registry"] = "User";

  User_Registry["Password"] = (char *)Hashed_Password;

  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  return Result_Type::Success;
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

  uint8_t Hashed_Password[65];
  Static_String_Type<69> Salted_Password; // Nice

  for (uint8_t i = 0; i < 0xFF; i++)
  {
    // Create a copy of password
    Salted_Password = Password_To_Check;
    // Salt password
    this->Salt_Password(Salted_Password, static_cast<char>(i));
    // Hash password
    this->Hash_Password(Salted_Password, Hashed_Password);
    // - Check if password is correct
    if (strcmp(User_Registry["Password"] | "", (const char *)Hashed_Password) == 0)
    {
      return Result_Type::Success;
    }
  }

  return Result_Type::Error;
}

///
/// @brief Login into user account.
///
/// @param Username_To_Check User account name.
/// @param Password_To_Check User account password.
/// @return Result_Type
Result_Type Accounts_Class::Login(const String_Type &Name, const String_Type &Password, bool Lock_Other_User)
{
  if (Name == "Xila")
  {
    return Result_Type::Error;
  }

  // Check credentials
  if (Check_Credentials(Name, Password) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  User_Type User_To_Log(Name, User_State_Type::Locked);

  User_List.push_back(User_To_Log);

  if (Lock_Other_User)
  {
    User_To_Log.Login();
  }

  return Result_Type::Success;
}

uint8_t Accounts_Class::Find_User(const String_Type &Name)
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

  return 0xFF;
}

uint8_t Accounts_Class::Get_User_Count()
{
  return User_List.size();
}

Result_Type Accounts_Type::Hash_Password(const String_Type &Password, uint8_t *Hash_Buffer)
{
  using namespace Xila_Namespace::Mathematics_Types;

  if (Hash_Buffer == NULL)
    return Result_Type::Error;

  Hash_Type Hash;
  if (Hash.Create(Message_Digest_Type::SHA_512) != Result_Type::Success)
    return Result_Type::Error;

  if (Hash.Add(Password) != Result_Type::Success)
    return Result_Type::Error;

  Hash.Delete(Hash_Buffer);

  // In order to make the password more secure, we hash it 10 times.
  for (uint8_t i = 0; i < 10; i++)
  {
    if (Hash.Create(Message_Digest_Type::SHA_512) != Result_Type::Success)
      return Result_Type::Error;

    if (Hash.Add(Hash_Buffer, Hash.Get_Size()) != Result_Type::Success)
      return Result_Type::Error;

    Hash.Delete(Hash_Buffer);
  }

  return Result_Type::Success;
}

void Accounts_Type::Salt_Password(String_Type &Password, char Pepper_Character)
{
  Password += Pepper_Character;
  Password += "Xila";
}