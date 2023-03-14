///
/// @file SD_SPI.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 24-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifdef Xila_Drive_Hardware_SD_SPI

#include "SD.h"

#include "Core/Drive/Drive.hpp"
#include "Core/Pin/Pin.hpp"
#include "Core/System/System.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Drive_Types;

#ifdef Xila_Board_Hardware_Wireless_Tag_WT32_SC01_Plus
    SPIClass& SD_SPI = SPI;
#endif
#ifdef Xila_Board_Hardware_Wireless_Tag_WT32_SC01
    SPIClass& SD_SPI = SPI;
#endif 


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
Result_Type Drive_Class::Start()
{
    Log_Information("Drive", "Start drive module...");
    using namespace Xila_Namespace::Pin_Types;
    //Pin.Set_Mode(SD_SPI_Clock_Pin, Mode_Type::Input_Pull_Up);
    //Pin.Set_Mode(SD_SPI_Master_In, Mode_Type::Input_Pull_Up);
    //Pin.Set_Mode(SD_SPI_Master_Out, Mode_Type::Input_Pull_Up);
    //Pin.Set_Mode(SD_SPI_Select_Pin, Mode_Type::Input_Pull_Up);
    
    SPI.begin(SD_SPI_Clock_Pin, SD_SPI_Master_In, SD_SPI_Master_Out, SD_SPI_Clock_Pin);
    if (!SD.begin(SD_SPI_Select_Pin, SD_SPI, SD_SPI_Frequency) || Get_Type() == Drive_Type_Type::None)
    {
        End();
        return Result_Type::Error;
    }

    return Result_Type::Success;
}

///
/// @brief A method that return the drive size
///
/// @return uint64_t Drive size in bytes
Size_Type Drive_Class::Get_Size()
{
    return SD.cardSize();
}

///
/// @brief A method that return the drive type
///
/// @return Drive_Class::Sd_Card_Type
Drive_Type_Type Drive_Class::Get_Type()
{
    switch (SD.cardType())
    {
    case sdcard_type_t::CARD_MMC:
        return Drive_Type_Type::MMC;
    case sdcard_type_t::CARD_SD:
        return Drive_Type_Type::SD_SC;
    case sdcard_type_t::CARD_SDHC:
        return Drive_Type_Type::SD_HC;
    default:
        return Drive_Type_Type::None;
    }
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
File_Type Drive_Class::Open(const char *Path, bool Write, bool Append)
{
    if (Write)
    {
        if (Append)
        {
            return SD.open(Path, FILE_APPEND, true);
        }
        return SD.open(Path, FILE_WRITE, true);
    }
    return SD.open(Path, FILE_READ);
}

///
/// @brief A method that open file
///
/// @param Path Path of the file to open
/// @param Mode Mode to open path (FILE_READ or FILE_WRITE)
/// @return The openned file instance
File_Type Drive_Class::Open(const String &Path, bool Write, bool Append)
{
    return Open(Path.c_str(), Write, Append);
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