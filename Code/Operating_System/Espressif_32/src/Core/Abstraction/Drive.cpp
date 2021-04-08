///
/// @file Drive.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

#include "Core/Core.hpp"

#include "SD.h"
#include "SD_MMC.h"

Xila_Class::Drive_Class::Drive_Class()
{
}

#if SD_MODE == 0

bool Xila_Class::Drive_Class::Begin(uint8_t Slave_Select_Pin, SPIClass &spi, uint32_t Frequency, const char *Mount_Point, uint8_t Maximum_Files)
{
    return SD_MMC.begin(Mount_Point, false, false);
}

uint64_t Xila_Class::Drive_Class::Card_Size()
{
    return SD_MMC.cardSize();
}

Xila_Class::Drive_Class::Sd_Card_Type Xila_Class::Drive_Class::Card_Type()
{
    switch (SD_MMC.cardType())
    {
    case sdcard_type_t::CARD_NONE:
        return CARD_NONE;
        break;
    case sdcard_type_t::CARD_MMC:
        return CARD_MMC;
        break;
    case sdcard_type_t::CARD_SD:
        return CARD_SD;
        break;
    case sdcard_type_t::CARD_SDHC:
        return CARD_SDHC;
        break;
    case sdcard_type_t::CARD_UNKNOWN:
        return CARD_UNKNOWN;
        break;
    }
    return CARD_UNKNOWN;
}

void Xila_Class::Drive_Class::End()
{
    SD_MMC.end();
}

bool Xila_Class::Drive_Class::Exists(const char *Path)
{
    return SD_MMC.exists(Path);
}

bool Xila_Class::Drive_Class::Exists(const String &Path)
{
    return SD_MMC.exists(Path);
}

bool Xila_Class::Drive_Class::Make_Directory(const char *Path)
{
    return SD_MMC.mkdir(Path);
}

bool Xila_Class::Drive_Class::Make_Directory(const String &Path)
{
    return SD_MMC.mkdir(Path);
}

File Xila_Class::Drive_Class::Open(const char *Path, const char *Mode)
{
    return SD_MMC.open(Path, Mode);
}

File Xila_Class::Drive_Class::Open(const String &Path, const char *Mode)
{
    return SD_MMC.open(Path, Mode);
}

bool Xila_Class::Drive_Class::Remove(const char *Path)
{
    return SD_MMC.remove(Path);
}

bool Xila_Class::Drive_Class::Remove(const String &Path)
{
    return SD_MMC.remove(Path);
}

bool Xila_Class::Drive_Class::Rename(const char *Path_From, const char *Path_To)
{
    return SD_MMC.rename(Path_From, Path_To);
}

bool Xila_Class::Drive_Class::Rename(const String &Path_From, const String &Path_To)
{
    return SD_MMC.rename(Path_From, Path_To);
}

bool Xila_Class::Drive_Class::Remove_Directory(const char *Path)
{
    return SD_MMC.rmdir(Path);
}

bool Xila_Class::Drive_Class::Remove_Directory(const String &Path)
{
    return SD_MMC.rmdir(Path);
}

uint64_t Xila_Class::Drive_Class::Total_Bytes()
{
    return SD_MMC.totalBytes();
}

uint64_t Xila_Class::Drive_Class::Used_Bytes()
{
    return SD_MMC.usedBytes();
}

//==============================================================================//
//                              SD SPI                                          //
//==============================================================================//

#elif SD_MODE == 1

bool Xila_Class::Drive_Class::Begin(uint8_t Slave_Select_Pin, SPIClass &spi, uint32_t Frequency, const char *Mount_Point, uint8_t Maximum_Files)
{
    return SD.begin(Slave_Select_Pin, spi, Frequency, Mount_Point, Maximum_Files);
}

uint64_t Xila_Class::Drive_Class::Size()
{
    return SD.cardSize();
}

Xila_Class::Drive_Class::Sd_Card_Type Xila_Class::Drive_Class::Type()
{
    switch (SD.cardType())
    {
    case sdcard_type_t::CARD_NONE:
        return None;
        break;
    case sdcard_type_t::CARD_MMC:
        return SD_MMC;
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

void Xila_Class::Drive_Class::End()
{
    SD.end();
}

bool Xila_Class::Drive_Class::Exists(const char *Path)
{
    return SD.exists(Path);
}

bool Xila_Class::Drive_Class::Exists(const String &Path)
{
    return SD.exists(Path);
}

bool Xila_Class::Drive_Class::Make_Directory(const char *Path)
{
    return SD.mkdir(Path);
}

bool Xila_Class::Drive_Class::Make_Directory(const String &Path)
{
    return SD.mkdir(Path);
}

File Xila_Class::Drive_Class::Open(const char *Path, const char *Mode)
{
    return SD.open(Path, Mode);
}

File Xila_Class::Drive_Class::Open(const String &Path, const char *Mode)
{
    return SD.open(Path, Mode);
}

bool Xila_Class::Drive_Class::Remove(const char *Path)
{
    return SD.remove(Path);
}

bool Xila_Class::Drive_Class::Remove(const String &Path)
{
    return SD.remove(Path);
}

bool Xila_Class::Drive_Class::Rename(const char *Path_From, const char *Path_To)
{
    return SD.rename(Path_From, Path_To);
}

bool Xila_Class::Drive_Class::Rename(const String &Path_From, const String &Path_To)
{
    return SD.rename(Path_From, Path_To);
}

bool Xila_Class::Drive_Class::Remove_Directory(const char *Path)
{
    return SD.rmdir(Path);
}

bool Xila_Class::Drive_Class::Remove_Directory(const String &Path)
{
    return SD.rmdir(Path);
}

uint64_t Xila_Class::Drive_Class::Total_Bytes()
{
    return SD.totalBytes();
}

uint64_t Xila_Class::Drive_Class::Used_Bytes()
{
    return SD.usedBytes();
}

#endif

// Custom methods

///
/// @brief Copy file from two openned file
///
/// @param Origin_File File to duplicate
/// @param Destination_File File to write
/// @return Xila_Class::Event::Success or Xila_Class::Event::Error
Xila_Class::Event Xila_Class::Drive_Class::Copy(File &Origin_File, File &Destination_File)
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
        Xila.Task.Delay(2);
    }
    return Success;
}

///
/// @brief
///
/// @param Folder
/// @return uint16_t return the number of files inside a folder
uint16_t Xila_Class::Drive_Class::Count_Items(File &Folder)
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
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Drive_Class::Get_Name(File const &File, char *File_Name, size_t Size)
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