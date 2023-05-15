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

        virtual int Available() = 0;
        virtual int Read() = 0;
        virtual int Peek() = 0;
        virtual Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) = 0;
        virtual String_Type &Read_String(String_Type &String) = 0;

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

    } Stream_Type;
}

#endif