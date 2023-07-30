/// @file Flash.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#ifdef Xila_Flash_Hardware_None

#include "Flash/Flash.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Flash_Types;

Flash_Type Xila_Namespace::Flash;

Size_Type Flash_Class::Get_Sketch_Size()
{
    return 0;
}

Result_Type Flash_Class::Read(uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    return Result_Type::Error;
}

Result_Type Flash_Class::Partition_Read(const Partition_Type *Partition, uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    return Result_Type::Error;
}

Result_Type Flash_Class::Erase_Sector(uint32_t Sector)
{
    return Result_Type::Error;
}

Result_Type Flash_Class::Write(uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    return Result_Type::Error;
}

Result_Type Flash_Class::Partition_Erase_Range(const Partition_Type *Partition, uint32_t Offset, Size_Type Size)
{
    return Result_Type::Error;
}

Result_Type Flash_Class::Partition_Write(const Partition_Type *Partition, uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    return Result_Type::Error;
}

Result_Type Flash_Class::Set_Boot_Partition(uint8_t Partition_Subtype)
{
    return Result_Type::Error;
}

Size_Type Flash_Class::Get_Sketch_Free_Space()
{
    return 0;
}

String_Type &Flash_Class::Get_Sketch_MD5(String_Type &String)
{
    return String;
}

Size_Type Flash_Class::Get_Size()
{
    return 0;
}

QWord_Type Flash_Class::Get_Speed()
{
    return 0;
}

Natural_Type Flash_Class::Get_Mode()
{
    return 0;
}

const Partition_Type *Flash_Class::Find(Natural_Type Type, Natural_Type Subtype, const char *Label, Natural_Type Index)
{
    return NULL;
}

#endif