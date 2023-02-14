///
/// @file File.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Drive/Drive.hpp"

using namespace Xila_Namespace;
using namespace Drive_Types;


File_Class::File_Class()
{
}

File_Class::File_Class(fs::File File) : File(File)
{
}

File_Class::~File_Class()
{
}

size_t File_Class::write(uint8_t Data)
{
    return File.write(Data);
}

size_t File_Class::write(const uint8_t *Buffer, size_t Size)
{
    return File.write(Buffer, Size);
}

int File_Class::available()
{
    return File.available();
}

int File_Class::read()
{
    return File.read();
}

int File_Class::peek()
{
    return File.peek();
}

void File_Class::flush()
{
    File.flush();
}

Size_Type File_Class::Write(uint8_t Data)
{
    return File.write(Data);
}

Size_Type File_Class::Write(const uint8_t *Buffer, Size_Type Size)
{
    return File.write(Buffer, Size);
}

int File_Class::Available()
{
    return File.available();
}

int File_Class::Read()
{
    return File.read();
}

int File_Class::Peek()
{
    return File.peek();
}

void File_Class::Flush()
{
    File.flush();
}

Size_Type File_Class::Read(uint8_t *Buffer, Size_Type Size)
{
    return File.read(Buffer, Size);
}

Size_Type File_Class::Read_Bytes(char *Buffer, Size_Type Length)
{
    return File.readBytes(Buffer, Length);
}

bool File_Class::Seek(uint32_t Position, Seek_Mode_Type Mode)
{
    return File.seek(Position, (SeekMode)Mode);
}

bool File_Class::Seek(uint32_t Position)
{
    return File.seek(Position);
}

Size_Type File_Class::Get_Position() const
{
    return File.position();
}

Size_Type File_Class::Get_Size() const
{
    return File.size();
}

Result_Type File_Class::Set_Buffer_Size(Size_Type Size)
{
    if (File.setBufferSize(Size))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

void File_Class::Close()
{
    File.close();
}

time_t File_Class::Get_Modification_Time()
{
    return File.getLastWrite();
}

const char* File_Class::Get_Name() const
{
    return File.name();
}

const char* File_Class::Get_Path() const
{
    return File.path();
}

bool File_Class::Is_Valid() const
{
    return File;
}

File_Class::operator bool() const
{
    return Is_Valid();
}

bool File_Class::Is_Directory()
{
    return File.isDirectory();
}

File_Class File_Class::Open_Next_File(bool Write, bool Apprend)
{
    if (Write)
    {
        if (Apprend)
        {
            return File_Class(File.openNextFile(FILE_APPEND));
        }
        return File_Class(File.openNextFile(FILE_WRITE));
    }
    return File_Class(File.openNextFile(FILE_READ));
}

void File_Class::Rewind_Directory()
{
    File.rewindDirectory();
}

uint16_t File_Class::Count_Items()
{
    if (!Is_Valid() || !Is_Directory())
    {
        return 0;
    }
    
    Rewind_Directory();
    File_Type Temporary_File = Open_Next_File();
    for (uint16_t i = 0; i < 0xFFFF; i++)
    {
        if (!Temporary_File)
        {
            Temporary_File.Close();
            return i;
        }

        Temporary_File.Close();
        Temporary_File = Open_Next_File();
    }
}