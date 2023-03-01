///
 /// @file String.hpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 22-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

 
#ifndef String_Hpp_Included
#define String_Hpp_Included

#include "Arduino.h"
#include <vector>

#include "Base_Types.hpp"

namespace Xila_Namespace
{

    /// @brief Base class for String (dynamic string)
    typedef class String_Class
    {
    public:
        // - Methods

        // - - Constructors / Destructors

        String_Class();
        String_Class(const String_Class& String);
        String_Class(const char* String);
        String_Class(const char* String, Size_Type Size);
        String_Class(const String& String);
        explicit String_Class(char Character);
        explicit String_Class(Integer_Type Integer, Short_Integer_Type Base = 10);
        explicit String_Class(Long_Integer_Type Integer, Short_Integer_Type Base = 10);
        explicit String_Class(Short_Natural_Type Natural, Short_Integer_Type Base = 10);
        explicit String_Class(Natural_Type Natural, Short_Integer_Type Base = 10);
        explicit String_Class(Long_Natural_Type Natural, Short_Integer_Type Base = 10);
        explicit String_Class(Real_Type Real, Short_Integer_Type Decimals = 2);
        explicit String_Class(Long_Real_Type Real, Short_Integer_Type Decimals = 2);
        ~String_Class();
        

        // - - Getters

        Size_Type Get_Length() const;
        Size_Type Get_Size() const;
        Size_Type Get_Capacity() const;
        char Get_Character(Size_Type Position) const;

        Size_Type Get_Position(char Character, Size_Type Offset_Position = 0) const;
        Size_Type Get_Position(const char* String, Size_Type Position = 0) const;
        Size_Type Get_Position(const String_Class& String, Size_Type Position = 0) const;
        

        // - - Setters

        virtual Result_Type Set_Size(Size_Type Size);
        Result_Type Set_Capacity(Size_Type Capacity);
        void Set_Buffer(char* Buffer, Size_Type Size);
        void Set_Character(char Character, Size_Type Position);

        // - - Managment

        void Clear();
        Result_Type Fit();

        bool Is_Empty() const;
        bool Is_Valid() const;

        // - - Copy

        Result_Type Copy(const char* String, Size_Type Size = 0, bool Change_Size = false);
        Result_Type Copy(const String_Class& String, bool Change_Size = false);
        Result_Type Copy(const String& String, bool Change_Size = false);
        Result_Type Copy(char Character, bool Change_Size = false);
        Result_Type Copy(Integer_Type Integer, bool Change_Size = false);
        Result_Type Copy(Long_Integer_Type Natural, bool Change_Size = false);
        Result_Type Copy(Short_Natural_Type Byte, bool Change_Size = false);
        Result_Type Copy(Natural_Type Natural, bool Change_Size = false);
        Result_Type Copy(Long_Natural_Type Natural, bool Change_Size = false);
        Result_Type Copy(Real_Type Real, bool Change_Size = false);
        Result_Type Copy(Long_Real_Type Real, bool Change_Size = false);

        Result_Type Copy_Format(const char* Format, ...);

        // - - Concatenation

        Result_Type Concatenate(const char* String, Size_Type Size = 0, bool Increase_Size = false);
        Result_Type Concatenate(const String_Class& String, bool Increase_Size = false);
        Result_Type Concatenate(char Character, bool Increase_Size = false);
        Result_Type Concatenate(Short_Natural_Type Byte, bool Increase_Size = false);
        Result_Type Concatenate(Integer_Type Integer, bool Increase_Size = false);
        Result_Type Concatenate(Natural_Type Natural, bool Increase_Size = false);
        Result_Type Concatenate(Long_Integer_Type Natural, bool Increase_Size = false);
        Result_Type Concatenate(Long_Natural_Type Natural, bool Increase_Size = false);
        Result_Type Concatenate(Real_Type Real, bool Increase_Size = false);
        Result_Type Concatenate(Long_Real_Type Real, bool Increase_Size = false);

        // - - Comparison

        bool Equals(const char* String, Size_Type Size) const;
        bool Equals(const String_Class& String) const;
        int8_t Compare(const char* String, Size_Type Size) const;
        int8_t Compare(const String_Class& String) const;

        // - - Edition

        Result_Type Remove(Size_Type Position, Size_Type Size = 1);

        // - - Conversion

        Result_Type To_Char_Array(char* Array, Size_Type Size, Size_Type Offset_Position = 0) const;
        Result_Type To_Lower_Case();
        Result_Type To_Upper_Case();
        
        // - - Operators

        // - - - Conversion

        operator int64_t() const;
        operator uint64_t() const;
        operator double() const;
        operator bool() const;
        operator const char*() const;
        explicit operator char*();
        explicit operator const Byte_Type*() const;

        // - - - Assignment

        String_Class& operator=(const char* String);
        String_Class& operator=(const String_Class& String);
        String_Class& operator=(const String& String);
        String_Class& operator=(char Character);
        String_Class& operator=(int64_t Integer);
        String_Class& operator=(uint64_t Natural);
        String_Class& operator=(double Real);
        
        // - - - Concatenation

        String_Class& operator+=(const char* String);
        String_Class& operator+=(const String_Class& String);
        String_Class& operator+=(char Character);
        String_Class& operator+=(Integer_Type Integer);
        String_Class& operator+=(Long_Integer_Type Integer);
        String_Class& operator+=(Short_Natural_Type Byte);
        String_Class& operator+=(Natural_Type Natural);
        String_Class& operator+=(Long_Natural_Type Natural);
        String_Class& operator+=(Real_Type Real);
        String_Class& operator+=(Long_Real_Type Real);

    
        // - - - Comparison

        bool operator==(const char* String) const;
        bool operator==(const String_Class& String) const;
        bool operator!=(const char* String) const;
        bool operator!=(const String_Class& String) const;
        bool operator>(const char* String) const;
        bool operator>(const String_Class& String) const;
        bool operator<(const char* String) const;
        bool operator<(const String_Class& String) const;
        bool operator>=(const char* String) const;
        bool operator>=(const String_Class& String) const;
        bool operator<=(const char* String) const;
        bool operator<=(const String_Class& String) const;

        // - - - Access

        char operator[](const Size_Type Index) const;
        char& operator[](const Size_Type Index);        

    protected:

        char* Characters_Pointer;
        Size_Type Size;

    } String_Type;


    /// @brief Template class derivated from String_Class to create a static string.
    /// @tparam Buffer_Size Size of the static buffer.
    template <Size_Type Length>
    class Static_String_Class : public String_Class
    {
    public:
        // - Methods

        Static_String_Class() : String_Class()
        {
            Set_Buffer(Buffer, Length + 1);
            Clear();
        }

        Static_String_Class(const char* String) : String_Class(String)
        {
        }

        Static_String_Class(const char* String, Size_Type Size) : String_Class(String, Size)
        {
        }

        Static_String_Class(const String_Class& String) : String_Class(String)
        {
        }

        Static_String_Class(const String& String) : String_Class(String)
        {
        }

        explicit Static_String_Class(char Character) : String_Class(Character)
        {
        }

        explicit Static_String_Class(Short_Natural_Type Byte, Short_Natural_Type Base = 10) : String_Class(Byte, Base)
        {
        }

        explicit Static_String_Class(Integer_Type Integer, Short_Integer_Type Base = 10) : String_Class(Integer, Base)
        {
        }

        explicit Static_String_Class(Natural_Type Natural, Short_Integer_Type Base = 10) : String_Class(Natural, Base)
        {
        }

        explicit Static_String_Class(Long_Integer_Type Real, Short_Integer_Type Base = 10) : String_Class(Real, Base)
        {
        }

        explicit Static_String_Class(Long_Natural_Type Real, Short_Integer_Type Base = 10) : String_Class(Real, Base)
        {
        }

        explicit Static_String_Class(Real_Type Real, Short_Integer_Type Base = 10) : String_Class(Real, Base)
        {
        }

        explicit Static_String_Class(Long_Real_Type Real, Short_Integer_Type Base = 10) : String_Class(Real, Base)
        {
        }


        Static_String_Class& operator=(const String_Class& String)
        {
            Copy(String);
            return *this;
        }
        
        Static_String_Class& operator=(const char* String)
        {
            Copy(String);
            return *this;
        }

        Result_Type Set_Size(Size_Type Size) override {
            // Do nothing since we deal with a static buffer;
            return Result_Type::Error;
        };


    protected:
        char Buffer[Length + 1];
    };

    template <Size_Type Length>
    using Static_String_Type = Static_String_Class<Length>;

};

#endif