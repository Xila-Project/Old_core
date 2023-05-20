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
        // - Methods

        // - Virtual

        virtual int Available() = 0;
        virtual int Read() = 0;
        virtual int Peek() = 0;
        virtual Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) = 0;
        virtual String_Type &Read_String(String_Type &String) = 0;

        virtual int Available_For_Write() {return 0;};
        virtual Size_Type Write(uint8_t Byte) = 0;
        virtual Size_Type Write_String(const char *String) = 0;
        virtual Size_Type Write_Bytes(const uint8_t *Buffer, Size_Type Size) = 0;
        virtual void Flush() = 0;
       
        // - - Operations

        Size_Type Print(const char *String) { return print(String); }
        Size_Type Print_Line(const char *String) { return println(String); }
        Size_Type Print_Format(const char* Format, ...) { va_list Arguments; va_start(Arguments, Format); Size_Type Result = printf(Format, Arguments); va_end(Arguments); return Result; }

        void Clear_Write_Error() { clearWriteError(); }

        // - - Parsing

        Long_Integer_Type Parse_Integer() { return parseInt(); }
        Real_Type Parse_Real() { return parseFloat(); }

        // - - Find

        Result_Type Find(Byte_Type *Target)
        {
            if (find(Target) == true)
            {
                return Result_Type::Success;
            }
            return Result_Type::Error;
        }
        Result_Type Find(const char *Target)
        {
            if (find(Target) == true)
            {
                return Result_Type::Success;
            }
            return Result_Type::Error;
        }
        Result_Type Find_Until(const char *Target, const char *Terminator)
        {
            if (findUntil(Target, Terminator) == true)
            {
                return Result_Type::Success;
            }
            return Result_Type::Error;
        }
        Result_Type Find_Until(const Byte_Type *Target, const char *Terminator)
        {
            return Find_Until((char *)Target, Terminator);
        }

        Result_Type Find_Until(const char *Target, Size_Type Target_Length, const char *Terminator, Size_Type Terminator_Length)
        {
            if (findUntil(Target, Target_Length, Terminator, Terminator_Length) == true)
            {
                return Result_Type::Success;
            }
            return Result_Type::Error;
        }
        Result_Type Find_Until(const Byte_Type *Target, Size_Type Target_Length, const char *Terminator, Size_Type Terminator_Length)
        {
            return Find_Until((char *)Target, Target_Length, Terminator, Terminator_Length);
        }

        Size_Type Read_Bytes_Until(char Terminator, Byte_Type *Buffer, Size_Type Length)
        {
            return readBytesUntil(Terminator, Buffer, Length);
        }

        String_Type &Read_String_Until(char Terminator, String_Type &String)
        {
            return Read_String_Until(Terminator, String);
        }

        // - - Setters

        void Set_Timeout(unsigned long Timeout) { setTimeout(Timeout); }

        // - - Getters

        unsigned long Get_Timeout() { return getTimeout(); }
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