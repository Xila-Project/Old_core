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

#ifdef Arduino
#include "FS.h"
#endif

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

    class File_Class : public Stream
    {
    public:
        // - Methods

        // - - Constructors / destructor

        /// @brief Default constructor.
        File_Class();

        /// @brief Constructor from a `fs::File` object.
        /// @param File `fs::File` object.
        File_Class(fs::File File);

        // - - Stream methods override

        size_t write(uint8_t) override;
        size_t write(const uint8_t *Buffer, size_t Size) override;
        int available() override;
        int read() override;
        int peek() override;
        void flush() override;
        size_t readBytes(char*, size_t) override;

        // - - File methods

        /// @brief Write a byte to the file.
        /// @param Data Byte to write.
        /// @return Number of bytes written.
        Size_Type Write(uint8_t);

        /// @brief Write an array of bytes to the file.
        /// @param Buffer Array of bytes to write.
        /// @param Size Number of bytes to write.
        /// @return Number of bytes written.
        Size_Type Write(const uint8_t *Buffer, Size_Type Size);

        /// @brief Get the number of bytes available to read.
        /// @return Number of bytes available.
        int Available();

        /// @brief Read a byte from the file.
        /// @return Byte read.
        int Read();

        /// @brief Peek a byte from the file (without moving the cursor).
        /// @return Byte read.
        int Peek();

        /// @brief Flush the file.
        void Flush();

        /// @brief Check if the object is valid.
        bool Is_Valid() const;

        /// @brief Read a byte from the file.
        /// @param Buffer Byte array to store the byte.
        /// @param Size Number of bytes to read.
        /// @return Number of bytes read.
        Size_Type Read(uint8_t *Buffer, Size_Type Size);

        /// @brief Read a character from the file.
        /// @param Buffer Character array to store the byte.
        /// @param Length Number of character to read.
        /// @return Number of bytes read.
        Size_Type Read_Bytes(char *Buffer, Size_Type Length);

        /// @brief Move the cursor to a specific position.
        /// @param Position Position to move the cursor to.
        /// @param Mode Mode of the seek.
        /// @return `true` if the seek was successful, `false` otherwise.
        bool Seek(uint32_t Position, Drive_Types::Seek_Mode_Type Mode);

        /// @brief Move the cursor to a specific position.
        /// @param Position Position to move the cursor to.
        /// @return `true` if the seek was successful, `false` otherwise.
        bool Seek(uint32_t Position);

        /// @brief Get the current position of the cursor.
        /// @return Current position of the cursor.
        Size_Type Get_Position() const;

        /// @brief Get the size of the file.
        /// @return Size of the file.
        Size_Type Get_Size() const;

        /// @brief Set the cache buffer size.
        /// @param Size Size of the cache buffer.
        /// @return `true` if the buffer size was set, `false` otherwise.
        Result_Type Set_Buffer_Size(Size_Type Size);

        /// @brief Close the file.
        void Close();

        /// @brief Get the modification time of the file.
        /// @return Modification time of the file.
        time_t Get_Modification_Time();

        /// @brief Get the path of the file.
        /// @return Path of the file.
        const char *Get_Path() const;

        /// @brief Get the name of the file.
        /// @return Name of the file.
        const char *Get_Name() const;

        // - - Directory methods

        /// @brief Check if the file is a directory.
        /// @return `true` if the file is a directory, `false` otherwise.
        bool Is_Directory();

        /// @brief Open the next item in the directory.
        /// @param Write `true` to open the item in write mode, `false` otherwise.
        /// @param Append `true` to open the item in append mode, `false` otherwise.
        /// @return `File_Class` object of the next item.
        File_Class Open_Next_File(bool Write = false, bool Append = false);
        
        /// @brief Rewind the directory to the first item.
        /// @return `true` if the rewind was successful, `false` otherwise.
        void Rewind_Directory();

        /// @brief Get the number of items in the directory.
        /// @return Number of items in the directory.
        uint16_t Count_Items();

        // - - Operators

        /// @brief Return if the object is valid.
        operator bool() const;

    private:
        // - Attributes
        fs::File File;
    };

    typedef class Drive_Class : public Module_Class
    {
    public:
        // - Methods
        // - - Drive informations

        /// @brief Get the drive size.
        /// @return Drive size in bytes.
        uint64_t Get_Size();

        /// @brief Get the drive type.
        /// @return Drive type.
        Drive_Types::Drive_Type_Type Get_Type();

        /// @brief Get the current partition size.
        /// @return Partition size in bytes.
        uint64_t Get_Total_Size();

        /// @brief Get the current partition used size.
        /// @return Partition used size in bytes.
        uint64_t Get_Used_Size();

        // - - File system management

        /// @brief Check if a file exists.
        /// @param Path Path of the file.
        /// @return `true` if the file exists, `false` otherwise.
        bool Exists(const char *Path);

        /// @brief Create a directory.
        /// @param Path Path of the directory.
        /// @return `true` if the directory was created, `false` otherwise.
        Result_Type Make_Directory(const char *Path);

        /// @brief Remove a directory.
        /// @param Path Path of the directory.
        /// @return `true` if the directory was removed, `false` otherwise.
        Result_Type Remove_Directory(const char *Path);

        /// @brief Remove a directory.
        /// @param Path Path of the directory.
        /// @param Recursive `true` to remove the directory recursively, `false` otherwise.
        /// @return `true` if the directory was removed, `false` otherwise.
        Result_Type Remove_Directory(const char* Path, bool Recursive);

        /// @brief Remove an item.
        /// @param Path Path of the item.
        /// @return `true` if the item was removed, `false` otherwise.
        Result_Type Remove(const char *Path);

        /// @brief Open a file / folder.
        /// @param Path Path of the file / folder.
        /// @param Write Open the file in write mode.
        /// @param Append Open the file in append mode.
        /// @return `File_Class` object of the file / folder.
        File_Type Open(const char *Path, bool Write = false, bool Append = false);
      
        /// @brief Remove a file / folder.
        /// @param Path Path of the file / folder.
        /// @return `true` if the file / folder was removed, `false` otherwise.
        Result_Type Remove_File(const char *Path);

        /// @brief Rename a file / folder.
        /// @param Path_From Path of the file / folder to rename.
        /// @param Path_To New path of the file / folder.
        /// @return `true` if the file / folder was renamed, `false` otherwise.
        Result_Type Rename(const char *Path_From, const char *Path_To);

        /// @brief Copy a file / folder.
        /// @param Path_From Path of the file / folder to copy.
        /// @param Path_To Path of the destination file / folder.
        /// @return `true` if the file / folder was copied, `false` otherwise.
        Result_Type Copy(File_Type &Origin_File, File_Type &Destination_File);

        /// @brief Copy a file / folder.
        /// @param Path_From Path of the file / folder to copy.
        /// @param Path_To Path of the destination file / folder.
        /// @return `true` if the file / folder was copied, `false` otherwise.
        Result_Type Copy(const char *Path_From, const char *Path_To);

        Result_Type Cut(File_Type &Origin_File, File_Type &Destination_File);
        Result_Type Cut(const char *Path_From, const char *Path_To);

        
        void End();

        Result_Type Start();

    } Drive_Type;

    extern Drive_Type Drive;
}

#endif