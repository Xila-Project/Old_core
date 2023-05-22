/// @file Account.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Account management source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021

#include "Account/Accounts.hpp"
#include "Core.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Accounts_Types;

Accounts_Type Xila_Namespace::Accounts;

Result_Type Accounts_Class::Start()
{
  Log_Information("Account", "Start account module...");

  User_Type Xila_User("Xila", User_State_Type::Logged);
  User_List.push_back(Xila_User);

  {
    Static_String_Type<32> Account_Name;
    for (auto User : User_List)
    {
      User.Get_Name(Account_Name);
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
  Drive_Types::File_Type Temporary_File = Drive.Open(Registry("Account"), true);
  if (!Temporary_File || (serializeJson(Account_Registry, Temporary_File) == 0))
  {
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();
  return Result_Type::Success;
}

Result_Type Accounts_Class::Load_Registry()
{
  Drive_Types::File_Type Temporary_File = Drive.Open(Registry("Account"));
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
  Drive_Types::File_Type Temporary_File = Drive.Open(Registry("Account"));
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

Result_Type Accounts_Class::Set_Autologin(bool Enable, const char *Name, const char *Password)
{
  Drive_Types::File_Type Temporary_File = Drive.Open(Registry("Account"), true);
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

const User_Type *Accounts_Class::Get_Logged_User()
{
  for (auto &User : User_List)
  {
    if (User.Get_State() == User_State_Type::Logged)
    {
      return &User;
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

Result_Type Accounts_Class::Create(const char *User_Name, const char *Password)
{
  Static_String_Type<64> Temporary_String;
  Temporary_String = Users_Directory_Path;
  Temporary_String += "/";
  Temporary_String += User_Name;

  Log_Verbose("Accounts", "Creating user %s with password %s", (const char *)User_Name, (const char *)Password);

  Log_Verbose("Accounts", "Temporary string is %s", (const char *)Temporary_String);

  if (Drive.Exists(Temporary_String))
  {
    Log_Verbose("Accounts", "User %s already exists", (const char *)User_Name);
    return Result_Type::Error;
  }

  //
  //  char Temporary_Path[30];
  //  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s", User_Name);
  if (Drive.Make_Directory(Temporary_String) != Result_Type::Success)
  {
    Log_Verbose("Accounts", "Failed to create user %s", (const char *)User_Name);
    return Result_Type::Error;
  }

  Temporary_String += "/Registry";

  //  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Registry", User_Name);
  if (Drive.Make_Directory(Temporary_String) != Result_Type::Success)
  {
    Log_Verbose("Accounts", "Failed to create user dir !");
    return Result_Type::Error;
  }

  Temporary_String.Remove(Temporary_String.Get_Length() - sizeof("/Registry") + 1, sizeof("/Registry") - 1);

  Log_Verbose("Accounts", "Temporary string is %s", (const char *)Temporary_String);

  Temporary_String += "/Desk";
  if (Drive.Make_Directory(Temporary_String) != Result_Type::Success)
  {
    return Result_Type::Error;
  }
  Temporary_String.Remove(Temporary_String.Get_Length() - sizeof("/Desk") + 1, sizeof("/Desk") - 1);

  //  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Images", User_Name);
  //  if (Drive.Make_Directory(Temporary_Path) == false)
  //  {
  //    return Result_Type::Error;
  //  }
  //  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Musics", User_Name);
  //  if (Drive.Make_Directory(Temporary_Path) == false)
  //  {
  //    return Result_Type::Error;
  //  }
  //
  //  snprintf(Temporary_Path, sizeof(Temporary_Path), Users_Directory_Path "/%s/Document", User_Name);
  //  if (Drive.Make_Directory(Temporary_Path) == false)
  //  {
  //    return Result_Type::Error;
  //  }

  uint8_t Hashed_Password[64];

  {
    // - Create a salted and peppered password.
    Static_String_Type<69> Salted_Password = Password;

    Log_Verbose("Accounts", "Password : %s", (const char *)Salted_Password);

    // char Salt = static_cast<char>(Mathematics.Random(0x000000FF));
    // Log_Verbose("Accounts", "Salt : %X", Salt);

    this->Salt_Password(Salted_Password, static_cast<char>(Mathematics.Random(' ', '~')));

    Log_Verbose("Accounts", "Salted password : %s", (const char *)Salted_Password);

    // Hash the salted and peppered password.
    if (this->Hash_Password(Salted_Password, Hashed_Password) != Result_Type::Success)
    {
      return Result_Type::Error;
    }

    Log_Verbose("Accounts", "Hashed password : ");

    for (uint8_t i = 0; i < 64; i++)
    {
      log_printf("%02X ", Hashed_Password[i]);
    }
    log_printf("\n");
  }

  Temporary_String += "/Registry/User.xrf";

  Drive_Types::File_Type Temporary_File = Drive.Open(Temporary_String, true);
  StaticJsonDocument<512> User_Registry;

  User_Registry["Registry"] = "User";

  char Hashed_Password_Characters[129] = "";

  // - Convert byte array to char array of hex values.

  const char *Hexadecimal_Characters = "0123456789ABCDEF";
  for (uint8_t i = 0; i < sizeof(Hashed_Password); i++)
  {
    Hashed_Password_Characters[i * 2] = Hexadecimal_Characters[Hashed_Password[i] >> 4];
    Hashed_Password_Characters[(i * 2) + 1] = Hexadecimal_Characters[Hashed_Password[i] & 0x0F];
  }

  Hashed_Password_Characters[sizeof(Hashed_Password_Characters) - 1] = '\0';

  Log_Verbose("Accounts", "Hashed password : %s", Hashed_Password_Characters);

  User_Registry["Password"] = (const char *)Hashed_Password_Characters;

  //  JsonArray Password_Array = User_Registry.createNestedArray("Password");

  //  for (uint8_t i = 0; i < 64; i++)
  //  {
  //    Password_Array.add(Hashed_Password[i]);
  //  }

  if (serializeJson(User_Registry, Temporary_File) == 0)
  {
    Log_Verbose("Accounts", "Failed to serialize user registry");
    Temporary_File.Close();
    return Result_Type::Error;
  }
  Temporary_File.Close();

  Log_Verbose("Accounts", "User %s created", (const char *)User_Name);
  return Result_Type::Success;
}

Result_Type Accounts_Class::Delete(const char *User_Name, const char *Password)
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

  if (Drive.Remove_Directory(Path) != Result_Type::Success)
  {
    return Result_Type::Error;
  }

  return Result_Type::Success;
}

Result_Type Accounts_Class::Change_Name(const char *Current_Name, const char *New_Name, const char *Password)
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

    if (Drive.Rename(Current_User_Folder_Path, New_User_Folder_Path) != Result_Type::Success)
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

Result_Type Accounts_Class::Change_Password(const char *Name, const char *Current_Password, const char *New_Password)
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
  Drive_Types::File_Type Temporary_File = Drive.Open(Temporary_Char, true);
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

Result_Type Accounts_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
{
  using namespace Xila_Namespace::Mathematics_Types;

  Byte_Type Expected_Hash[64];
  {
    Static_String_Type<48> Temporary_Path;

    Temporary_Path = Users_Directory_Path;
    Temporary_Path += "/";
    Temporary_Path += Username_To_Check;
    Temporary_Path += "/Registry/User.xrf";

    Drive_Types::File_Type Temporary_File = Drive.Open(Temporary_Path);
    StaticJsonDocument<512> User_Registry;

    if (!Temporary_File)
      return Result_Type::Error;

    if (deserializeJson(User_Registry, Temporary_File) != DeserializationError::Ok)
    {
      Log_Verbose("Accounts", "deserializeJson failed");
      Temporary_File.Close();
      return Result_Type::Error;
    }
    Temporary_File.Close();

    if (strcmp("User", User_Registry["Registry"] | "") != 0)
    {
      Log_Verbose("Accounts", "Registry is not a user registry");
      return Result_Type::Error;
    }

    const char *Password_Hash_Characters = User_Registry["Password"];

    if (Password_Hash_Characters == NULL)
    {
      Log_Verbose("Accounts", "Password_Hash_Characters is null");
      return Result_Type::Error;
    }

    // - Convert hexadecimal characters to bytes.
    for (uint8_t i = 0; i < sizeof(Expected_Hash); i++)
    {
      char Hexadecimal_Byte_Characters[3] = {Password_Hash_Characters[i * 2], Password_Hash_Characters[i * 2 + 1], '\0'};
      Expected_Hash[i] = strtol(Hexadecimal_Byte_Characters, NULL, 16);
    }
  }

  Static_String_Type<69> Salted_Password; // Nice

  Byte_Type Test_Hash[64];

  for (Byte_Type Salt = ' '; Salt < '~'; Salt++)
  {
    // Create a copy of password
    Salted_Password = Password_To_Check;
    // Salt password
    this->Salt_Password(Salted_Password, static_cast<char>(Salt));
    // Hash password
    this->Hash_Password(Salted_Password, Test_Hash);

    Log_Verbose("Accounts", "%c : Test hash : ", Salt);

    for (uint8_t i = 0; i < 64; i++)
    {
      log_printf("%02X ", Test_Hash[i]);
    }
    log_printf("\n");

    // - Compare expected hash with test hash.
    if (memcmp(Expected_Hash, Test_Hash, sizeof(Expected_Hash)) == 0)
    {
      Log_Verbose("Accounts", "Password is correct");
      return Result_Type::Success;
    }
  }

  return Result_Type::Error;
}

Result_Type Accounts_Class::Login(const char *Name, const char *Password, bool Lock_Other_User)
{
  // - Check if user is already logged.
  for (auto &User_Iterator : User_List)
  {
    if (User_Iterator.Name == Name)
      return Result_Type::Error;
  }

  if (Name == "Xila" || (Check_Credentials(Name, Password) != Result_Type::Success))
    return Result_Type::Error;

  User_Type User_To_Log(Name, User_State_Type::Locked);

  User_List.push_back(User_To_Log);

  if (Lock_Other_User)
  {
    User_To_Log.Login();
  }

  return Result_Type::Success;
}

uint8_t Accounts_Class::Find_User(const char *Name)
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

Result_Type Accounts_Type::Hash_Password(const char *Password, uint8_t *Hash_Buffer)
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

  // In order to make the password more secure, we hash it 3 times.
  for (uint8_t i = 0; i < 3; i++)
  {
    //    Log_Verbose("Accounts", "Hash_Buffer : ");
    //    for (uint8_t i = 0; i < 64; i++)
    //    {
    //      log_printf("%02X ", Hash_Buffer[i]);
    //    }
    //    log_printf("\n");

    if (Hash.Create(Message_Digest_Type::SHA_512) != Result_Type::Success)
    {
      Hash.Delete();
      return Result_Type::Error;
    }

    //    Log_Verbose("Accounts", "Hash size : %u", Hash.Get_Size());

    if (Hash.Add(Password) != Result_Type::Success)
    {
      Hash.Delete();
      return Result_Type::Error;
    }

    if (Hash.Add(Hash_Buffer, Hash.Get_Size()) != Result_Type::Success)
    {
      Hash.Delete();
      return Result_Type::Error;
    }

    Hash.Delete(Hash_Buffer);
  }

  return Result_Type::Success;
}

String_Type &Accounts_Type::Salt_Password(String_Type &Password, char Pepper_Character)
{
  Password += Pepper_Character;
  Password += "Xila";
  return Password;
}