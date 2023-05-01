
/// @file SD_SPI.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 24-07-2022
///
/// @copyright Copyright (c) 2022

#ifdef Xila_Drive_Hardware_SD_SPI

#include "SD.h"

#include "Core/Drive/Drive.hpp"
#include "Core/Pin/Pin.hpp"
#include "Core/System/System.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Drive_Types;

#ifdef Xila_Board_Hardware_Wireless_Tag_WT32_SC01_Plus
SPIClass &SD_SPI = SPI;
#endif
#ifdef Xila_Board_Hardware_Wireless_Tag_WT32_SC01
SPIClass &SD_SPI = SPI;
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
    // Pin.Set_Mode(SD_SPI_Clock_Pin, Mode_Type::Input_Pull_Up);
    // Pin.Set_Mode(SD_SPI_Master_In, Mode_Type::Input_Pull_Up);
    // Pin.Set_Mode(SD_SPI_Master_Out, Mode_Type::Input_Pull_Up);
    // Pin.Set_Mode(SD_SPI_Select_Pin, Mode_Type::Input_Pull_Up);

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
uint64_t Drive_Class::Get_Size()
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

Result_Type Drive_Class::Make_Directory(const char *Path)
{
    if (SD.mkdir(Path))
        return Result_Type::Success;
    
    return Result_Type::Error;
}

Drive_Types::File_Type Drive_Class::Open(const char *Path, bool Write, bool Append)
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

Result_Type Drive_Class::Remove_File(const char *Path)
{
    if (SD.remove(Path))
        return Result_Type::Success;

    return Result_Type::Error;
}

Result_Type Drive_Class::Rename(const char *Path_From, const char *Path_To)
{
    if (SD.rename(Path_From, Path_To))
        return Result_Type::Success;

    return Result_Type::Error;
}

Result_Type Drive_Class::Remove_Directory(const char *Path)
{
    if (SD.rmdir(Path))
        return Result_Type::Success;

    return Result_Type::Error;
}

uint64_t Drive_Class::Get_Total_Size()
{
    return SD.totalBytes();
}

uint64_t Drive_Class::Get_Used_Size()
{
    return SD.usedBytes();
}

#endif