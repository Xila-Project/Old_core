/// @file Stream.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Stream_Hpp_Included
#define Stream_Hpp_Included

#include "Arduino.h"
#include "Base_Types.hpp"
#include "String.hpp"

namespace Xila_Namespace
{
    typedef class Stream_Class : public Stream
    {
    public:
        // - Methods

        // - Virtual

        /// @brief Get the number of bytes available for reading.
        /// @return `int` Number of bytes available for reading.
        virtual int Available() = 0;

        /// @brief Read a byte from the stream.
        /// @return `int` Byte read.
        virtual int Read() = 0;

        /// @brief Read a byte from the stream without removing it from the buffer.
        /// @return `int` Byte read.
        virtual int Peek() = 0;

        /// @brief Read bytes from the stream.
        /// @param Buffer Buffer to write.
        /// @param Length Length of the buffer.
        /// @return `Size_Type` Number of bytes read.
        virtual Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) = 0;

        /// @brief Read a bytes from the stream.
        /// @param String String to write.
        /// @return `String_Type&` String read.
        virtual String_Type &Read_String(String_Type &String) = 0;

        /// @brief Get the number of bytes available for writing.
        /// @return `int` Number of bytes available for writing.
        virtual int Available_For_Write() {return 0;};

        /// @brief Write a byte to the stream.
        /// @param Byte Byte to write.
        /// @return `Size_Type` Number of bytes written.
        virtual Size_Type Write(uint8_t Byte) = 0;

        /// @brief Write a string to the stream.
        /// @param String String to write.
        /// @return `Size_Type` Number of bytes written.
        virtual Size_Type Write_String(const char *String) = 0;

        /// @brief Write bytes to the stream.
        /// @param Buffer Buffer to output.
        /// @param Size Size of the buffer.
        /// @return `Size_Type` Number of bytes written.
        virtual Size_Type Write_Bytes(const uint8_t *Buffer, Size_Type Size) = 0;
    
        /// @brief Flush the stream.
        virtual void Flush() = 0;
       
        // - - Operations

        /// @brief Print a string to the stream.
        /// @param String String to print.
        /// @return `Size_Type` Number of bytes written.
        Size_Type Print(const char *String) { return print(String); }

        /// @brief Print a string to the stream and add a new line.
        /// @param String String to print.
        /// @return `Size_Type` Number of bytes written.
        Size_Type Print_Line(const char *String) { return println(String); }

        /// @brief Print a format string to the stream.
        /// @param Format Format string.
        /// @param  Arguments Arguments.
        /// @return `Size_Type` Number of bytes written.
        Size_Type Print_Format(const char* Format, ...) { va_list Arguments; va_start(Arguments, Format); Size_Type Result = printf(Format, Arguments); va_end(Arguments); return Result; }

        /// @brief Clear write error.
        void Clear_Write_Error() { clearWriteError(); }

        // - - Parsing

        /// @brief Parse a string to an integer.
        /// @return `Long_Integer_Type` Integer parsed.
        Long_Integer_Type Parse_Integer() { return parseInt(); }

        /// @brief Parse a string to a real.
        /// @return `Real_Type` Real parsed.
        Real_Type Parse_Real() { return parseFloat(); }

        // - - Find

        /// @brief Find bytes in the stream.
        /// @param Target Bytes to find.
        /// @return `Result_Type` Result of the operation.
        Result_Type Find(Byte_Type *Target)
        {
            return (Result_Type)find(Target);
        }

        /// @brief Find a string in the stream.
        /// @param Target String to find.
        /// @return `Result_Type` Result of the operation.
        Result_Type Find(const char *Target)
        {
            return (Result_Type)find(Target);
        }

        /// @brief Find a string in the stream until a terminator is found.
        /// @param Target String to find.
        /// @param Terminator Terminator to find.
        /// @return `Result_Type` Result of the operation.
        Result_Type Find_Until(const char *Target, const char *Terminator)
        {
            if (findUntil(Target, Terminator) == true)
            {
                return Result_Type::Success;
            }
            return Result_Type::Error;
        }

        /// @brief Find a string in the stream until a terminator is found.
        /// @param Target String to find.
        /// @param Terminator Terminator to find.
        /// @return `Result_Type` Result of the operation.
        Result_Type Find_Until(const Byte_Type *Target, const char *Terminator)
        {
            return Find_Until((char *)Target, Terminator);
        }

        /// @brief Find a string in the stream until a terminator is found.
        /// @param Target String to find.
        /// @param Target_Length Length of the string to find.
        /// @param Terminator Terminator to find.
        /// @param Terminator_Length Length of the terminator to find.
        /// @return `Result_Type` Result of the operation.
        Result_Type Find_Until(const char *Target, Size_Type Target_Length, const char *Terminator, Size_Type Terminator_Length)
        {
            if (findUntil(Target, Target_Length, Terminator, Terminator_Length) == true)
            {
                return Result_Type::Success;
            }
            return Result_Type::Error;
        }

        /// @brief Find bytes in the stream until a terminator is found.
        /// @param Target  Bytes to find.
        /// @param Target_Length Size of the bytes to find.
        /// @param Terminator Terminator to find.
        /// @param Terminator_Length Size of the terminator to find.
        /// @return `Result_Type` Result of the operation.
        Result_Type Find_Until(const Byte_Type *Target, Size_Type Target_Length, const char *Terminator, Size_Type Terminator_Length)
        {
            return Find_Until((char *)Target, Target_Length, Terminator, Terminator_Length);
        }

        /// @brief Find a string in the stream until a terminator is found.
        /// @param Terminator Terminator to find.
        /// @param Buffer Buffer to output.
        /// @param Length Length of the buffer.
        /// @return `Size_Type` Number of bytes read.
        Size_Type Read_Bytes_Until(char Terminator, Byte_Type *Buffer, Size_Type Length)
        {
            return readBytesUntil(Terminator, Buffer, Length);
        }

        /// @brief Find a string in the stream until a terminator is found.
        /// @param Terminator Terminator to find.
        /// @param String String to output.
        /// @return `String_Type` String read.
        String_Type &Read_String_Until(char Terminator, String_Type &String)
        {
            return Read_String_Until(Terminator, String);
        }

        // - - Setters

        /// @brief Set the timeout.
        /// @param Timeout Timeout to set.
        void Set_Timeout(unsigned long Timeout) { setTimeout(Timeout); }

        // - - Getters

        /// @brief Get the timeout.
        /// @return `unsigned long` Timeout.
        unsigned long Get_Timeout() { return getTimeout(); }

        /// @brief Get the last write error.
        /// @return `int` Last write error.
        int Get_Write_Error() { return getWriteError(); }

        // - - Stream methods overrides (ensure the compatibility with Arduino Stream class)

        int available() override { return Available(); }
        int read() override { return Read(); }
        int peek() override { return Peek(); }
        size_t readBytes(char *Buffer, size_t Length) override { return Read_Bytes((Byte_Type *)Buffer, Length); }
        size_t readBytes(Byte_Type *Buffer, size_t Length) override { return Read_Bytes(Buffer, Length); }
        String readString() override
        {
            char Buffer[64];
            String S;
            S.reserve(Available());
            while (Available() > 0)
            {
                Read_Bytes((Byte_Type *)Buffer, sizeof(Buffer));
                S += Buffer;
            }
            return S;
        }

        // - - Print methods overrides (ensure the compatibility with Arduino Print class)
        size_t write(uint8_t Byte) override { return Write(Byte); }
        size_t write(const uint8_t *Buffer, size_t Size) override { return Write_Bytes(Buffer, Size); }
        int availableForWrite() override { return Available_For_Write(); }
        void flush() override { Flush(); }

    } Stream_Type;
}

#endif