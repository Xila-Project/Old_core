/// @file Drive.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021

#include "Core/Drive/Drive.hpp"

#include "Core/System/System.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Drive_Types;

Drive_Type Xila_Namespace::Drive;

// Custom methods

Result_Type Drive_Class::Remove_Directory(const char* Path, bool Recursive)
{
    if (!Recursive)
        return Remove_Directory(Path);

    Drive_Types::File_Type Directory = Open(Path);

    if (!Directory || !Directory.Is_Directory())
        return Result_Type::Error;
    
    Drive_Types::File_Type Item;
    while (Item = Directory.Open_Next_File())
    {
        if (Item.Is_Directory())
            Remove_Directory(Item.Get_Path(), true);
        else
            Remove_File(Item.Get_Path());
        
        Item.Close();
    }

    Directory.Close();

    return Remove_Directory(Path);
}

Result_Type Drive_Class::Remove(const char *Path)
{
    Drive_Types::File_Type File = Open(Path);
    if (!File)
        return Result_Type::Error;
 
    if (File.Is_Directory())
        return Remove_Directory(Path, true);
    else
        return Remove_File(Path);
}