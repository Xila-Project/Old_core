#include "Core/Core.hpp"

Xila_Event Xila_Class::Copy(uint64_t const &Value_To_Copy)
{
  Clipboard_File = Drive->open(Clipboard_Path, FILE_WRITE);
  if (!Clipboard_File)
  {
    return Error;
  }
  if (!Clipboard_File.seek(0))
  {
    return Error;
  }
  Split_Number[0] = (uint8_t)Value_To_Copy;
  Split_Number[1] = (uint8_t)Value_To_Copy << 8;
  Split_Number[2] = (uint8_t)Value_To_Copy << 16;
  Split_Number[3] = (uint8_t)Value_To_Copy << 24;
  Split_Number[4] = (uint8_t)Value_To_Copy << 32;
  Split_Number[5] = (uint8_t)Value_To_Copy << 40;
  Split_Number[6] = (uint8_t)Value_To_Copy << 48;
  Split_Number[7] = (uint8_t)Value_To_Copy << 56;
  Clipboard_File.write(Split_Number, sizeof(Value_To_Copy));
  return Success;
}

Xila_Event Xila_Class::Copy(const char *Char_Array_To_Copy, size_t Char_Array_Lenght)
{
  Drive->remove(Clipboard_Path);
  Clipboard_File = Drive->open(Clipboard_Path, FILE_WRITE);
  if (!Clipboard_File)
  {
    return Error;
  }
  if (!Clipboard_File.seek(0))
  {
    return Error;
  }
  if (Char_Array_Lenght == 0)
  {
    Clipboard_File.write((uint8_t *)Char_Array_To_Copy, strlen(Char_Array_To_Copy));
  }
  else
  {
    Clipboard_File.write((uint8_t *)Char_Array_To_Copy, Char_Array_Lenght);
  }
  Clipboard_File.close();
  return Success;
}

Xila_Event Xila_Class::Copy(String const &String_To_Copy)
{
  Drive->remove(Clipboard_Path);
  Clipboard_File = Drive->open(Clipboard_Path, FILE_WRITE);
  if (!Clipboard_File)
  {
    return Error;
  }
  if (!Clipboard_File.seek(0))
  {
    return Error;
  }
  Clipboard_File.print(String_To_Copy);
  Clipboard_File.close();
  return Success;
}

Xila_Event Xila_Class::Paste(uint64_t &Value_To_Paste)
{
  Clipboard_File = Drive->open(Clipboard_Path, FILE_WRITE);
  if (!Clipboard_File)
  {
    return Error;
  }
  if (!Clipboard_File.seek(0))
  {
    return Error;
  }
  Clipboard_File.readBytes((char *)Split_Number, sizeof(Split_Number));
  Value_To_Paste = (uint64_t)Split_Number << 56 | (uint64_t)Split_Number << 48 | (uint64_t)Split_Number << 40 | (uint64_t)Split_Number << 32 | (uint64_t)Split_Number << 24 | (uint64_t)Split_Number << 16 | (uint64_t)Split_Number << 8 | (uint64_t)Split_Number;
  Clipboard_File.close();
  return Success;
}

Xila_Event Xila_Class::Paste(char *Char_Array_To_Paste, size_t Char_Array_Lenght)
{
  Clipboard_File = Drive->open(Clipboard_Path, FILE_WRITE);
  if (!Clipboard_File)
  {
    return Error;
  }
  if (!Clipboard_File.seek(0))
  {
    return Error;
  }
  if (Char_Array_Lenght == 0)
  {
    Clipboard_File.readBytes(Char_Array_To_Paste, Clipboard_File.available());
  }
  else
  {
    Clipboard_File.readBytes(Char_Array_To_Paste, Char_Array_Lenght);
  }
  Clipboard_File.close();
  return Success;
}

Xila_Event Xila_Class::Paste(String &String_To_Paste)
{
  Clipboard_File = Drive->open(Clipboard_Path, FILE_WRITE);
  if (!Clipboard_File)
  {
    return Error;
  }
  if (!Clipboard_File.seek(0))
  {
    return Error;
  }
  String_To_Paste = Clipboard_File.readString();
  Clipboard_File.close();
  return Success;
}
