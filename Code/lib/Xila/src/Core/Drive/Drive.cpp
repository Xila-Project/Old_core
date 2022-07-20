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

///
 /// @brief Construct a new Xila_Class::Drive_Class::Drive_Class object
 /// 
Xila_Class::Drive_Class::Drive_Class()
{
}

#if Drive_Mode == 0

///
 /// @brief Initialize drive.
 /// 
 /// @param Slave_Select_Pin Slave select pin.
 /// @param spi SPI interface.
 /// @param Frequency Frequency of the SPI bus.
 /// @param Mount_Point Mount point path.
 /// @param Maximum_Files Maximum simultaneous openned files.
 /// @return true if the initialization succeed.
 /// @return false if the initialization succeed.
bool Xila_Class::Drive_Class::Begin(uint8_t Slave_Select_Pin, SPIClass &spi, uint32_t Frequency, const char *Mount_Point, uint8_t Maximum_Files)
{
    return SD_MMC.begin(Mount_Point, false, false);
}

///
 /// @brief Return the drive size.
 /// 
 /// @return uint64_t Drive size in bytes.
uint64_t Xila_Class::Drive_Class::Size()
{
    return SD_MMC.cardSize();
}

///
 /// @brief Return drive type.
 /// 
 /// @return Xila_Class::Drive_Class::Sd_Card_Type 
Xila_Class::Drive_Class::Sd_Card_Type Xila_Class::Drive_Class::Type()
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
void Xila_Class::Drive_Class::End()
{
    SD_MMC.end();
}

///
 /// @brief Check if a file / folder exists.
 /// 
 /// @param Path Item path.
 /// @return true if the item exist.
 /// @return false if the item doesn't exist.
bool Xila_Class::Drive_Class::Exists(const char *Path)
{
    return SD_MMC.exists(Path);
}

///
 /// @brief Check if a file / folder exists.
 /// 
 /// @param Path Item path.
 /// @return true if the item exists.
 /// @return false if the item doesn't exist.
bool Xila_Class::Drive_Class::Exists(const String &Path)
{
    return SD_MMC.exists(Path);
}

///
 /// @brief Make a new directory.
 /// 
 /// @param Path Path of new directory.
 /// @return true if the operation succeed.
 /// @return false of the operation failed.
bool Xila_Class::Drive_Class::Make_Directory(const char *Path)
{
    return SD_MMC.mkdir(Path);
}

///
 /// @brief Make a new directory.
 /// 
 /// @param Path Path of new directory.
 /// @return true if the operation succeed.
 /// @return false of the operation failed.
bool Xila_Class::Drive_Class::Make_Directory(const String &Path)
{
    return SD_MMC.mkdir(Path);
}

///
 /// @brief Open a file / folder.
 /// 
 /// @param Path Item path.
 /// @param Mode Open mode (read or write).
 /// @return File File instance.
File Xila_Class::Drive_Class::Open(const char *Path, const char *Mode)
{
    return SD_MMC.open(Path, Mode);
}

///
 /// @brief Open a file / folder.
 /// 
 /// @param Path Item path.
 /// @param Mode Open mode (read or write).
 /// @return File File instance.
File Xila_Class::Drive_Class::Open(const String &Path, const char *Mode)
{
    return SD_MMC.open(Path, Mode);
}

///
 /// @brief Remove a file 
 /// 
 /// @param Path 
 /// @return true 
 /// @return false 
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

#elif Drive_Mode == 1

///
/// @brief Initalize drive.
///
/// @param Slave_Select_Pin Slave select pin.
/// @param spi SPI interface.
/// @param Frequency Frequency of the spi bus.
/// @param Mount_Point Mount point path.
/// @param Maximum_Files Maximum simultaneous openned files.
/// @return true if the initialization succed.
/// @return false if the initalization failed.
bool Xila_Class::Drive_Class::Begin(uint8_t Slave_Select_Pin, SPIClass &spi, uint32_t Frequency, const char *Mount_Point, uint8_t Maximum_Files)
{
    return SD.begin(Slave_Select_Pin, spi, Frequency, Mount_Point, Maximum_Files);
}

///
/// @brief A method that return the drive size
///
/// @return uint64_t Drive size in bytes
uint64_t Xila_Class::Drive_Class::Size()
{
    return SD.cardSize();
}

///
/// @brief A method that return the drive type
///
/// @return Xila_Class::Drive_Class::Sd_Card_Type
Xila_Class::Drive_Class::Sd_Card_Type Xila_Class::Drive_Class::Type()
{
    switch (SD.cardType())
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
/// @brief A method that unmount the drive
///
void Xila_Class::Drive_Class::End()
{
    SD.end();
}

///
/// @brief A method that return if a file or a folder exist
///
/// @param Path Path to the file / folder
/// @return true if the item exist
/// @return false if the item doesn't exist
bool Xila_Class::Drive_Class::Exists(const char *Path)
{
    return SD.exists(Path);
}

///
/// @brief A method that return if a file or a folder exist
///
/// @param Path Path to the file / folder
/// @return true if the item exist
/// @return false if the item doesn't exist
bool Xila_Class::Drive_Class::Exists(const String &Path)
{
    return SD.exists(Path);
}

///
/// @brief A method that make directory
///
/// @param Path Path to directory
/// @return true if the operation succeed
/// @return false if the operation fail
bool Xila_Class::Drive_Class::Make_Directory(const char *Path)
{
    return SD.mkdir(Path);
}

///
/// @brief A method that make directory
///
/// @param Path Path to directory
/// @return true if the operation succeed
/// @return false if the operation fail
bool Xila_Class::Drive_Class::Make_Directory(const String &Path)
{
    return SD.mkdir(Path);
}

///
 /// @brief A method that open file.
 /// 
 /// @param Path Path of the file to open
 /// @param Mode Mode to open path
 /// @return The openned file instance
File Xila_Class::Drive_Class::Open(const char *Path, const char *Mode)
{
    return SD.open(Path, Mode);
}

///
 /// @brief A method that open file
 /// 
 /// @param Path Path of the file to open
 /// @param Mode Mode to open path (FILE_READ or FILE_WRITE)
 /// @return The openned file instance
File Xila_Class::Drive_Class::Open(const String &Path, const char *Mode)
{
    return SD.open(Path, Mode);
}

///
 /// @brief A method that remove file.
 /// 
 /// @param Path Path of the file to remove.
 /// @return true if the operation succeed.
 /// @return false if the operaton failed.
bool Xila_Class::Drive_Class::Remove(const char *Path)
{
    return SD.remove(Path);
}

///
 /// @brief A method that remove file.
 /// 
 /// @param Path Path of the file to remove.
 /// @return true if the operation succeed.
 /// @return false if the operaton failed.
bool Xila_Class::Drive_Class::Remove(const String &Path)
{
    return SD.remove(Path);
}

///
 /// @brief A method that rename file.
 /// 
 /// @param Path_From Origin path of the file.
 /// @param Path_To Destination path of the file.
 /// @return true if the operation succeed.
 /// @return false if the operation failed.
bool Xila_Class::Drive_Class::Rename(const char *Path_From, const char *Path_To)
{
    return SD.rename(Path_From, Path_To);
}

///
 /// @brief A method that rename file.
 /// 
 /// @param Path_From Origin path of the file.
 /// @param Path_To Destination path of the file.
 /// @return true if the operation succeed.
 /// @return false if the operation failed.
bool Xila_Class::Drive_Class::Rename(const String &Path_From, const String &Path_To)
{
    return SD.rename(Path_From, Path_To);
}

///
 /// @brief A method that delete directory.
 /// 
 /// @param Path Path of the directory.
 /// @return true if the operation succeeed.
 /// @return false if the operation failed.
bool Xila_Class::Drive_Class::Remove_Directory(const char *Path)
{
    return SD.rmdir(Path);
}


///
 /// @brief A method that delete directory.
 /// 
 /// @param Path Path of the directory.
 /// @return true if the operation succeeed.
 /// @return false if the operation failed.
bool Xila_Class::Drive_Class::Remove_Directory(const String &Path)
{
    return SD.rmdir(Path);
}

///
 /// @brief A method that return the drive total space.
 /// 
 /// @return uint64_t Total space in bytes.
uint64_t Xila_Class::Drive_Class::Total_Bytes()
{
    return SD.totalBytes();
}

///
 /// @brief A method that return the drive used space.
 /// 
 /// @return uint64_t Used space in bytes.
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
/// @return Result_Type::Success or Result_Type::Error
Result_Type Xila_Class::Drive_Class::Copy(File &Origin_File, File &Destination_File)
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
/// @return Result_Type
Result_Type Xila_Class::Drive_Class::Get_Name(File const &File, char *File_Name, size_t Size)
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