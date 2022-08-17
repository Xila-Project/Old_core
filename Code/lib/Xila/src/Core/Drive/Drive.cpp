///
/// @file Drive.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Drive/Drive.hpp"

///
 /// @brief Construct a new Drive_Class::Drive_Class object
 /// 
Drive_Class::Drive_Class()
{
}

// Custom methods

///
/// @brief Copy file from two openned file
///
/// @param Origin_File File to duplicate
/// @param Destination_File File to write
/// @return Result_Type::Success or Result_Type::Error
Module_Class::Result_Type Drive_Class::Copy(File_Type &Origin_File, File_Type &Destination_File)
{
    uint8_t Readed_Bytes;
    uint8_t Buffer[255];
    if (!Origin_File || !Destination_File)
    {
        return Error;
    }
    while ((Readed_Bytes = Origin_File.read(Buffer, sizeof(Buffer))) > 0)
    {
        Destination_File.write(Buffer, Readed_Bytes);
        Task_Class::Delay(2);
    }
    return Success;
}

///
/// @brief
///
/// @param Folder
/// @return uint16_t return the number of files inside a folder
uint16_t Drive_Class::Count_Items(File &Folder)
{
    if (!Folder || !Folder.isDirectory())
    {
        return 0;
    }
    uint32_t i = 0;
    Folder.rewindDirectory();
    File Temporary_File = Folder.openNextFile();
    while (Temporary_File)
    {
        Temporary_File.close();
        Temporary_File = Folder.openNextFile();
        i++;
    }
    return i;
}

///
/// @brief
///
/// @param File
/// @param File_Name
/// @param Size
/// @return Result_Type
Module_Class::Result_Type Drive_Class::Get_Name(File_Type const &File, char *File_Name, size_t Size)
{
    if (!File)
    {
        return Error;
    }
    if (File.name() == NULL)
    {
        return Error;
    }

    const char *Temporary_File_Name = File.name();
    memset(File_Name, '\0', Size);
    if (!File)
    {
        return Error;
    }
    for (uint8_t i = (strlen(Temporary_File_Name) - 1); i >= 0; i--)
    {
        if (Temporary_File_Name[i] == '/')
        {
            strlcpy(File_Name, Temporary_File_Name + i + 1, Size);
            break;
        }
    }
    return Success;
}