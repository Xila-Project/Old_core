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

namespace Xila_Namespace
{

    namespace Drive_Types
    {
        enum class Seek_Mode_Type
        {
            Set,
            Current,
            End
        };

        /// @brief Drive types.
        enum class Drive_Type_Type
        {
            None,  ///< None (nothing connected).
            MMC,   ///< MMC type.
            SD_SC, ///< SD type.
            SD_HC, ///< SD HC type.
            Unknow ///< Unknow type.
        };
    }

    typedef class File_Class : public Stream
    {
    public:
        // - Methods

        // - - Constructors / destructor
        File_Class();
        File_Class(fs::File File);
        ~File_Class();

        // - - Stream methods override
        size_t write(uint8_t) override;
        size_t write(const uint8_t *Buffer, size_t Size) override;
        int available() override;
        int read() override;
        int peek() override;
        void flush() override;

        // - - File methods

        Size_Type Write(uint8_t);
        Size_Type Write(const uint8_t *buf, Size_Type Size);

        int Available();
        int Read();
        int Peek();
        void Flush();
        bool Is_Valid() const;


        Size_Type Read(uint8_t *Buffer, Size_Type Size);
        Size_Type Read_Bytes(char *Buffer, Size_Type Length);

        bool Seek(uint32_t Position, Drive_Types::Seek_Mode_Type Mode);
        bool Seek(uint32_t Position);

        Size_Type Get_Position() const;
        Size_Type Get_Size() const;

        Result_Type Set_Buffer_Size(Size_Type Size);

        void Close();

        time_t Get_Modification_Time();
        const char *Get_Path() const;
        const char *Get_Name() const;

        // - - Directory methods

        bool Is_Directory();
        File_Class Open_Next_File(bool Write = false, bool Append = false);
        void Rewind_Directory();
        uint16_t Count_Items();

        // - - Operators

        operator bool() const;

    private:
        // - Attributes
        fs::File File;
    } File_Type;

    typedef class Drive_Class : public Module_Class
    {
    public:
        // - Methods
        // - - Drive informations
        Size_Type Get_Size();
        Drive_Types::Drive_Type_Type Get_Type();

        uint64_t Total_Bytes();
        uint64_t Used_Bytes();

        // - - File system management
        bool Exists(const char *Path);
        bool Exists(const String &Path);

        bool Make_Directory(const char *Path);
        bool Make_Directory(const String &Path);

        bool Remove_Directory(const char *Path);
        bool Remove_Directory(const String &Path);

        File_Type Open(const char *Path, bool Write = false, bool Append = false);
        File_Type Open(const String &Path, bool Write = false, bool Append = false);

        bool Remove(const char *Path);
        bool Remove(const String &Path);

        bool Rename(const char *Path_From, const char *Path_To);
        bool Rename(const String &Path_From, const String &Path_To);

        Result_Type Copy(File_Type &Origin_File, File_Type &Destination_File);
        Result_Type Copy(const char *Path_From, const char *Path_To);
        Result_Type Cut(File_Type &Origin_File, File_Type &Destination_File);
        Result_Type Cut(const char *Path_From, const char *Path_To);

        void End();

        Result_Type Start();

    } Drive_Type;

    extern Drive_Type Drive;
}

#endif