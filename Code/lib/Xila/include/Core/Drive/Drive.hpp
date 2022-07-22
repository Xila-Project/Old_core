///
/// @file Drive.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 22-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Drive_Hpp_Included
#define Drive_Hpp_Included

#include "../Module.hpp"

//==============================================================================//
///
/// @brief Drive class
///
class Drive_Class : public Module_Class
{
public:
    ///
    /// @brief Drive type.
    ///
    typedef enum
    {
        None,  ///< None (nothing connected).
        MMC,   ///< MMC type.
        SD_SC, ///< SD type.
        SD_HC, ///< SD HC type.
        Unknow ///< Unknow type.
    } Sd_Card_Type;

    uint64_t Size();
    Sd_Card_Type Type();

    bool Exists(const char *Path);
    bool Exists(const String &Path);

    bool Make_Directory(const char *Path);
    bool Make_Directory(const String &Path);

    bool Remove_Directory(const char *Path);
    bool Remove_Directory(const String &Path);

    File Open(const char *Path, const char *Mode = "r");
    File Open(const String &Path, const char *Mode = "r");

    bool Remove(const char *Path);
    bool Remove(const String &Path);

    bool Rename(const char *Path_From, const char *Path_To);
    bool Rename(const String &Path_From, const String &Path_To);

    uint64_t Total_Bytes();
    uint64_t Used_Bytes();

    // Custom

    Result_Type Copy(File &Origin_File, File &Destination_File);
    Result_Type Get_Name(File const &File, char *File_Name_Buffer, size_t Size);
    uint16_t Count_Items(File &Folder);

    // -- Constructor
    Drive_Class();

    // -- Friendship
    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

protected:
    void End();

    bool Begin(uint8_t Slave_Select_Pin = SS, SPIClass &spi = SPI, uint32_t Frequency = 4000000, const char *Mount_Point = "/sd", uint8_t Maximum_Files = 5);

};

#endif