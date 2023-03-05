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

using namespace Xila_Namespace;
using namespace Xila_Namespace::Drive_Types;

Drive_Type Xila_Namespace::Drive;

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
Result_Type Drive_Class::Copy(File_Type &Origin_File, File_Type &Destination_File)
{
    uint8_t Readed_Bytes;
    uint8_t Buffer[255];
    if (!Origin_File || !Destination_File)
    {
        return Result_Type::Error;
    }
    while ((Readed_Bytes = Origin_File.Read(Buffer, sizeof(Buffer))) > 0)
    {
        Destination_File.write(Buffer, Readed_Bytes);
    }
    return Result_Type::Success;
}

Result_Type Drive_Class::Copy(const char *Origin_Path, const char *Destination_Path)
{
    File_Type Origin_File = Open(Origin_Path);
    File_Type Destination_File = Open(Destination_Path, true);
    return Copy(Origin_File, Destination_File);
}