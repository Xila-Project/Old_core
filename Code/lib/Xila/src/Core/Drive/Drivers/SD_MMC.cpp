///
/// @file SD_MMC.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 24-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifdef Xila_Drive_Hardware_SD_MMC

#include "Core/Drive/Drive.hpp"

#include "SD_MMC.h"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Drive_Types;

/// @brief Start drive module.
Result_Type Drive_Class::Start()
{
    if (!SD_MMC.begin() || Get_Type() == Drive_Type_Type::None)
    {
        End();
        return Result_Type::Error;
    }

    return Result_Type::Success;

}

///
/// @brief Return the drive size.
///
/// @return uint64_t Drive size in bytes.
Size_Type Drive_Class::Get_Size()
{
    return SD_MMC.cardSize();
}

///
/// @brief Return drive type.
///
/// @return Drive_Class::Sd_Card_Type
Drive_Class::SD_Card_Type Drive_Class::Type()
{
    switch (SD_MMC.cardType())
    {
    case sdcard_type_t::CARD_NONE:
        return None;
        break;
    case sdcard_type_t::CARD_MMC:
        return MMC;
        break;
    case sdcard_type_t::CARD_SD:
        return SD_SC;
        break;
    case sdcard_type_t::CARD_SDHC:
        return SD_HC;
        break;
    default:
        break;
    }
    return Unknow;
}

///
/// @brief Unmount drive.
///
void Drive_Class::End()
{
    SD_MMC.end();
}

///
/// @brief Check if a file / folder exists.
///
/// @param Path Item path.
/// @return true if the item exist.
/// @return false if the item doesn't exist.
bool Drive_Class::Exists(const char *Path)
{
    return SD_MMC.exists(Path);
}

///
/// @brief Check if a file / folder exists.
///
/// @param Path Item path.
/// @return true if the item exists.
/// @return false if the item doesn't exist.
bool Drive_Class::Exists(const String &Path)
{
    return SD_MMC.exists(Path);
}

///
/// @brief Make a new directory.
///
/// @param Path Path of new directory.
/// @return true if the operation succeed.
/// @return false of the operation failed.
bool Drive_Class::Make_Directory(const char *Path)
{
    return SD_MMC.mkdir(Path);
}

///
/// @brief Make a new directory.
///
/// @param Path Path of new directory.
/// @return true if the operation succeed.
/// @return false of the operation failed.
bool Drive_Class::Make_Directory(const String &Path)
{
    return SD_MMC.mkdir(Path);
}

///
/// @brief Open a file / folder.
///
/// @param Path Item path.
/// @param Mode Open mode (read or write).
/// @return File File instance.
File_Type Drive_Class::Open(const char *Path, bool Write, bool Append)
{
    if (Write)
    {
        if (Append)
        {
            return SD_MMC.open(Path, FILE_APPEND, true);
        }
        return SD_MMC.open(Path, FILE_WRITE, true);
    }
    return SD_MMC.open(Path, FILE_READ);
}

///
/// @brief Open a file / folder.
///
/// @param Path Item path.
/// @param Mode Open mode (read or write).
/// @return File File instance.
File_Type Drive_Class::Open(const String &Path, bool Write, bool Append)
{
   return Open(Path.c_str(), Write, Append);
}

///
/// @brief Remove a file
///
/// @param Path
/// @return true
/// @return false
bool Drive_Class::Remove(const char *Path)
{
    return SD_MMC.remove(Path);
}

bool Drive_Class::Remove(const String &Path)
{
    return SD_MMC.remove(Path);
}

bool Drive_Class::Rename(const char *Path_From, const char *Path_To)
{
    return SD_MMC.rename(Path_From, Path_To);
}

bool Drive_Class::Rename(const String &Path_From, const String &Path_To)
{
    return SD_MMC.rename(Path_From, Path_To);
}

bool Drive_Class::Remove_Directory(const char *Path)
{
    return SD_MMC.rmdir(Path);
}

bool Drive_Class::Remove_Directory(const String &Path)
{
    return SD_MMC.rmdir(Path);
}

uint64_t Drive_Class::Total_Bytes()
{
    return SD_MMC.totalBytes();
}

uint64_t Drive_Class::Used_Bytes()
{
    return SD_MMC.usedBytes();
}

#endif
