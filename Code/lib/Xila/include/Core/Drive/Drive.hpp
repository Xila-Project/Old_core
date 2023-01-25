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

#include "../Module/Module.hpp"

// TODO : create own FS management.
#include "FS.h"

/*


class File_Class : public Module_Class
{
public:

    File_Class();
    ~File_Class();

    typedef enum Seek_Mode_Enumeration
    {
        Set,
        Current,
        End
    } Seek_Mode_Type;

    Size_Type Write(uint8_t);
    Size_Type Write(const uint8_t *buf, Size_Type Size);
    int Available();
    int Read();
    int Peek();
    void Flush();

    Size_Type Read(uint8_t* Buffer, Size_Type Size);
    Size_Type Read_Bytes(char *Buffer, Size_Type Length)
    {
        return Read((uint8_t*)Buffer, Length);
    }

    bool Seek(uint32_t Position, Seek_Mode_Type Mode);
    bool Seek(uint32_t Position)
    {
        return Seek(Position, Seek_Mode_Enumeration::Set);
    }
    Size_Type Position();
    Size_Type Size();
    void Close();

    operator bool();

    Time_Type Get_Last_Write();
    const char* Path();
    const char* Name();

    bool Is_Directory(void);
    File_Class Open_Next_File(const char* mode = FILE_READ);
    void Rewind_Directory(void);

private:

    void* Data_Pointer;
};*/

//==============================================================================//
///
/// @brief Drive class
///

namespace Xila_Namespace
{
    typedef File File_Type;
    
    class Drive_Class : public Module_Class
    {
    public:
        // - Types and enumerations


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
        } SD_Card_Type;

        // - Methods

        // - - Constructor
        Drive_Class();

        // - - Drive informations
        uint64_t Size();
        SD_Card_Type Type();
        uint64_t Total_Bytes();
        uint64_t Used_Bytes();

        // - - File system management
        bool Exists(const char *Path);
        bool Exists(const String &Path);

        bool Make_Directory(const char *Path);
        bool Make_Directory(const String &Path);

        bool Remove_Directory(const char *Path);
        bool Remove_Directory(const String &Path);

        File_Type Open(const char *Path, const char *Mode = "r");
        File_Type Open(const String &Path, const char *Mode = "r");

        bool Remove(const char *Path);
        bool Remove(const String &Path);

        bool Rename(const char *Path_From, const char *Path_To);
        bool Rename(const String &Path_From, const String &Path_To);

        Result_Type Copy(File_Type &Origin_File, File_Type &Destination_File);
        Result_Type Get_Name(File_Type const &File, char *File_Name_Buffer, Size_Type Size);
        uint16_t Count_Items(File_Type &Folder);

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

        void End();

        bool Begin(const char *Mount_Point = "/");
    } Drive;
}

#endif