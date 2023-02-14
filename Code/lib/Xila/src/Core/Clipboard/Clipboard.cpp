///
/// @file Clipboard.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila clipboard source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Clipboard/Clipboard.hpp"

using namespace Xila_Namespace;

Clipboard_Type Clipboard();

Clipboard_Class::Clipboard_Class()
{
  Clear();
}

/// @brief Clear data of the clipboard.
void Clipboard_Class::Clear()
{
  memset(Char_Array, '\0', sizeof(Char_Array));
}

///
/// @brief Push data into the clipboard.
///
/// @param Value_To_Copy Data to push.
/// @return Result_Type
void Clipboard_Class::Copy(uint64_t Value_To_Copy)
{
  Number = Value_To_Copy;
}

///
/// @brief Push data into the clipboard.
///
/// @param Char_Array_To_Copy Data to push.
/// @param Char_Array_Length Data size.
/// @return Result_Type
void Clipboard_Class::Copy(const char *Char_Array_To_Copy, Size_Type Char_Array_Length)
{
  strlcpy(Char_Array, Char_Array_To_Copy, sizeof(Char_Array));
}

///
/// @brief Push data into the clipboard.
///
/// @param String_To_Copy Data to push.
/// @return Result_Type
void Clipboard_Class::Copy(String String_To_Copy)
{
  strlcpy(Char_Array, String_To_Copy.c_str(), sizeof(Char_Array));
}

void Clipboard_Class::Copy(const void *Data, Size_Type Data_Size)
{
  if (Data_Size <= sizeof(Char_Array))
  {
    memcpy(Char_Array, Data, Data_Size);
  }
  else
  {
    memcpy(Char_Array, Data, sizeof(Char_Array));
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

///
/// @brief Pull data from the clipboard.
///
/// @param Char_Array_To_Paste Buffer reference to pull from.
/// @param Char_Array_Length Buffer size.
/// @return Result_Type
void Clipboard_Class::Paste(char *Destination_Char_Array, Size_Type Char_Array_Length) const
{
  strlcpy(Destination_Char_Array, Char_Array, Char_Array_Length);
}