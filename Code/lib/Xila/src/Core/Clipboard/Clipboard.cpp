/// @file Clipboard.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila clipboard source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021

#include "Core/Clipboard/Clipboard.hpp"

using namespace Xila_Namespace;

Clipboard_Type Clipboard();

Clipboard_Class::Clipboard_Class()
{
}

Result_Type Clipboard_Class::Start()
{
  Clear();
  return Result_Type::Success;
}

Result_Type Clipboard_Class::Stop()
{
  Clear();
  return Result_Type::Success;
}

/// @brief Clear data of the clipboard.
void Clipboard_Class::Clear()
{

  memset(Data, 0, sizeof(Data));
}

/// @brief Push data into the clipboard.
///
/// @param Value_To_Copy Data to push.
/// @return Result_Type
void Clipboard_Class::Copy(QWord_Type Value_To_Copy)
{
  Number = Value_To_Copy;
}

void Clipboard_Class::Copy(const char *String_To_Copy)
{
  this->String = String_To_Copy;
}

void Clipboard_Class::Copy(const void *Data, Size_Type Data_Size)
{
  if (Data_Size <= sizeof(Data))
  {
    memcpy(this->Data, Data, Data_Size);
  }
  else
  {
    memcpy(this->Data, Data, sizeof(Data));
  }
}

///
/// @brief Pull data from the clipboard.
///
/// @param[out] Value_To_Paste Buffer reference to pull from.
/// @return Result_Type
uint64_t Clipboard_Class::Paste() const
{
  return Number;
}

/// @brief Pull data from the clipboard.
///
/// @param Char_Array_To_Paste Buffer reference to pull from.
/// @param Char_Array_Length Buffer size.
/// @return Result_Type
void Clipboard_Class::Paste(char *Destination_Char_Array, Size_Type Char_Array_Length) const
{
  strlcpy(Destination_Char_Array, String, Char_Array_Length);
}

String_Type& Clipboard_Class::Paste(String_Type &Destination_String) const
{
  Destination_String.Copy(String);
  return Destination_String;
}