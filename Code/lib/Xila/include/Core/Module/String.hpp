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

        explicit String_Class(char Character);
        explicit String_Class(int64_t Integer);
        explicit String_Class(uint64_t Natural);
        explicit String_Class(double Real);

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

        Result_Type Copy(const char* String, Size_Type Size = 0, bool Change_Size = false);
        Result_Type Copy(const String_Class& String, bool Change_Size = false);
        Result_Type Copy(const String& String, bool Change_Size = false);

        Result_Type Copy_Format(const char* Format, ...);

        Result_Type Concatenate(const char* String, Size_Type Size, bool Increase_Size = false);
        Result_Type Concatenate(const String_Class& String, bool Increase_Size = false);
        Result_Type Concatenate(char Character, bool Increase_Size = false);
        Result_Type Concatenate(int64_t Integer, bool Increase_Size = false);
        Result_Type Concatenate(uint64_t Natural, bool Increase_Size = false);
        Result_Type Concatenate(double Real, bool Increase_Size = false);

        bool Equals(const char* String, Size_Type Size) const;
        bool Equals(const String_Class& String) const;
        
        int8_t Compare(const char* String, Size_Type Size) const;
        int8_t Compare(const String_Class& String) const;

        Result_Type Remove(Size_Type Position, Size_Type Size = 1);

        // - - Conversion

        Result_Type To_Char_Array(char* Array, Size_Type Size, Size_Type Offset_Position = 0) const;
        Result_Type To_Lower_Case();
        Result_Type To_Upper_Case();

        
        // - - Operators

        operator int64_t() const;
        operator uint64_t() const;
        operator double() const;
        operator bool() const;
        operator const char*() const;
        explicit operator char*();

        String_Class& operator=(const char* String);
        String_Class& operator=(const String_Class& String);
        String_Class& operator=(const String& String);
        String_Class& operator=(char Character);
        String_Class& operator=(int64_t Integer);
        String_Class& operator=(uint64_t Natural);
        String_Class& operator=(double Real);
        

        String_Class& operator+=(const char* String);
        String_Class& operator+=(const String_Class& String);
        String_Class& operator+=(char Character);
        String_Class& operator+=(int64_t Integer);
        String_Class& operator+=(uint64_t Natural);
        String_Class& operator+=(double Real);

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