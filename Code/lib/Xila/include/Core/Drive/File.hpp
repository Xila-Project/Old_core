/// @file File.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 27-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef File_Hpp_Included
#define File_Hpp_Included

#include "../Module/Module.hpp"

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

        typedef class File_Class : public Stream
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
            size_t readBytes(char *, size_t) override;

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
            bool Seek(uint32_t Position, Seek_Mode_Type Mode);

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

        protected:
            // - Attributes
            fs::File File;
        } File_Type;
    }
}

#endif // File_Hpp_Included
