///
 /// @file SD_SPI.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 24-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

#if Drive_Hardware == Hardware_Class::SD_SPI

#include "SD.h"

#include "Core/Drive/Drive.hpp"

SPIClass SD_SPI(VSPI);

/*
File_Class::File_Class()
{
    Data_Pointer = new File;
}

File_Class::~File_Class()
{
    delete Data_Pointer;
}

Size_Type File_Class::Write(uint8_t Byte)
{
    return (File*)Data_Pointer->write(Byte);
}*/


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
bool Drive_Class::Begin(const char *Mount_Point)
{
    SPI.begin(SD_SPI_Clock_Pin, SD_SPI_Master_In, SD_SPI_Master_Out, SD_SPI_Select_Pin);
    return SD.begin(SD_SPI_Select_Pin, SD_SPI, SD_SPI_Frequency, Mount_Point);
}

///
/// @brief A method that return the drive size
///
/// @return uint64_t Drive size in bytes
uint64_t Drive_Class::Size()
{
    return SD.cardSize();
}

///
/// @brief A method that return the drive type
///
/// @return Drive_Class::Sd_Card_Type
Drive_Class::SD_Card_Type Drive_Class::Type()
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
void Drive_Class::End()
{
    SD.end();
}

///
/// @brief A method that return if a file or a folder exist
///
/// @param Path Path to the file / folder
/// @return true if the item exist
/// @return false if the item doesn't exist
bool Drive_Class::Exists(const char *Path)
{
    return SD.exists(Path);
}

///
/// @brief A method that return if a file or a folder exist
///
/// @param Path Path to the file / folder
/// @return true if the item exist
/// @return false if the item doesn't exist
bool Drive_Class::Exists(const String &Path)
{
    return SD.exists(Path);
}

///
/// @brief A method that make directory
///
/// @param Path Path to directory
/// @return true if the operation succeed
/// @return false if the operation fail
bool Drive_Class::Make_Directory(const char *Path)
{
    return SD.mkdir(Path);
}

///
/// @brief A method that make directory
///
/// @param Path Path to directory
/// @return true if the operation succeed
/// @return false if the operation fail
bool Drive_Class::Make_Directory(const String &Path)
{
    return SD.mkdir(Path);
}

///
 /// @brief A method that open file.
 /// 
 /// @param Path Path of the file to open
 /// @param Mode Mode to open path
 /// @return The openned file instance
File Drive_Class::Open(const char *Path, const char *Mode)
{
    return SD.open(Path, Mode);
}

///
 /// @brief A method that open file
 /// 
 /// @param Path Path of the file to open
 /// @param Mode Mode to open path (FILE_READ or FILE_WRITE)
 /// @return The openned file instance
File Drive_Class::Open(const String &Path, const char *Mode)
{
    return SD.open(Path, Mode);
}

///
 /// @brief A method that remove file.
 /// 
 /// @param Path Path of the file to remove.
 /// @return true if the operation succeed.
 /// @return false if the operaton failed.
bool Drive_Class::Remove(const char *Path)
{
    return SD.remove(Path);
}

///
 /// @brief A method that remove file.
 /// 
 /// @param Path Path of the file to remove.
 /// @return true if the operation succeed.
 /// @return false if the operaton failed.
bool Drive_Class::Remove(const String &Path)
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
bool Drive_Class::Rename(const char *Path_From, const char *Path_To)
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
bool Drive_Class::Rename(const String &Path_From, const String &Path_To)
{
    return SD.rename(Path_From, Path_To);
}

///
 /// @brief A method that delete directory.
 /// 
 /// @param Path Path of the directory.
 /// @return true if the operation succeeed.
 /// @return false if the operation failed.
bool Drive_Class::Remove_Directory(const char *Path)
{
    return SD.rmdir(Path);
}


///
 /// @brief A method that delete directory.
 /// 
 /// @param Path Path of the directory.
 /// @return true if the operation succeeed.
 /// @return false if the operation failed.
bool Drive_Class::Remove_Directory(const String &Path)
{
    return SD.rmdir(Path);
}

///
 /// @brief A method that return the drive total space.
 /// 
 /// @return uint64_t Total space in bytes.
uint64_t Drive_Class::Total_Bytes()
{
    return SD.totalBytes();
}

///
 /// @brief A method that return the drive used space.
 /// 
 /// @return uint64_t Used space in bytes.
uint64_t Drive_Class::Used_Bytes()
{
    return SD.usedBytes();
}

#endif