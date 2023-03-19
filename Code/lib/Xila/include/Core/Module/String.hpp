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

        /// @brief Default constructor.
        String_Class();

        /// @brief Copy constructor.
        /// @param String String to copy.
        String_Class(const String_Class& String);

        /// @brief Constructor from character array.
        String_Class(const char* String);

        /// @brief Constructor from character array.
        /// @param String Character array to copy.
        /// @param Size Character array size.
        String_Class(const char* String, Size_Type Size);

        /// @brief Copy constructor from String.
        /// @param String 
        String_Class(const String& String);

        /// @brief Move constructor.
        /// @param String String to move.
        String_Class(String_Class&& String);

        /// @brief Constructor from character.
        explicit String_Class(char Character);

        /// @brief Constructor from integer.
        /// @param Integer Integer to convert.
        /// @param Base Integer base.
        explicit String_Class(Integer_Type Integer, Short_Integer_Type Base = 10);
        explicit String_Class(Long_Integer_Type Integer, Short_Integer_Type Base = 10);
        explicit String_Class(Short_Natural_Type Natural, Short_Integer_Type Base = 10);
        explicit String_Class(Natural_Type Natural, Short_Integer_Type Base = 10);
        explicit String_Class(Long_Natural_Type Natural, Short_Integer_Type Base = 10);
        explicit String_Class(Real_Type Real, Short_Integer_Type Decimals = 2);
        explicit String_Class(Long_Real_Type Real, Short_Integer_Type Decimals = 2);
        virtual ~String_Class();
        

        // - - Getters

        Size_Type Get_Length() const;
        Size_Type Get_Size() const;
        Size_Type Get_Capacity() const;
        char Get_Character(Size_Type Position) const;

        Size_Type Get_Position(char Character, Size_Type Offset_Position = 0) const;
        Size_Type Get_Position(const char* String, Size_Type Position = 0) const;
        Size_Type Get_Position(const String_Class& String, Size_Type Position = 0) const;
        

        // - - Setters

        /// @brief Set the allocated size of the string (length + 1).
        /// @param Size Size to set.
        /// @return Result of the operation.
        virtual Result_Type Set_Size(Size_Type Size);

        /// @brief Set the allocated capacity of the string (maximum length).
        /// @param Capacity Capacity to set.
        /// @return Result of the operation.
        Result_Type Set_Capacity(Size_Type Capacity);

        /// @brief Set the buffer of the string.
        /// @param Buffer Buffer to set.
        /// @param Size Buffer size.
        void Set_Buffer(char* Buffer, Size_Type Size);

        /// @brief Set a character at a specific position.
        /// @param Character Character to set.
        /// @param Position Position of the character.
        void Set_Character(char Character, Size_Type Position);

        // - - Managment

        /// @brief Clear the string (do not deallocate it).
        void Clear();

        /// @brief Fit the allocated size to string lenght + 1.
        /// @return Result of the operation.
        Result_Type Fit();

        /// @brief Check if the string is empty.
        /// @return true if the string is empty, false otherwise.
        bool Is_Empty() const;

        /// @brief Check if the string is valid (allocated).
        /// @return true if the string is valid, false otherwise.
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

        bool Equals(const char* String) const;
        bool Equals(const String_Class& String) const;
        int8_t Compare(const char* String) const;
        int8_t Compare(const String_Class& String) const;

        // - - Edition

        Result_Type Remove(Size_Type Position, Size_Type Size = 1);
        Result_Type Set_Character(Size_Type Position, char Character);

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
        char operator[](Size_Type Index) const;
        char& operator[](Size_Type Index);        

    protected:

        char* Characters_Pointer;
        Size_Type Size;

    } String_Type;


    /// @brief Template class derivated from String_Class to create a static string (stack allocated).
    /// @tparam Buffer_Size Size of the static buffer.
    template <Size_Type Length>
    class Static_String_Class : public String_Class
    {
    public:
        // - Methods

        Static_String_Class()
        {
            log_printf("Static_String_Class::Static_String_Class() - Length = %d \n", Length);
            Set_Buffer(this->Buffer, Length);
            Clear();
        }

        Static_String_Class(const char* String) : Static_String_Class()
        {
            Copy(String);
        }

        Static_String_Class(const char* String, Size_Type Size) : Static_String_Class()
        {
            Copy(String, Size);
        }

        Static_String_Class(const Static_String_Class& String) : Static_String_Class()
        {
            log_printf("Static_String_Class::Static_String_Class(const Static_String_Class& String) - String = %s \n", (const char*)String);

            Copy(String);
        }

        Static_String_Class(const String_Class& String) : Static_String_Class()
        {
            
           log_printf("Static_String_Class::Static_String_Class(const String_Class& String) - String = %s \n", (const char*)String);

            Copy(String);
        }

        Static_String_Class(String_Class&& String) : Static_String_Class()
        {
            log_printf("Static_String_Class::Static_String_Class(String_Class&& String) - String = %s \n", (const char*)String);
            
            Set_Buffer(this->Buffer, Length);
            String.Characters_Pointer = NULL;
            String.Size = 0;
        }

        Static_String_Class(const String& String) : Static_String_Class()
        {
            Copy(String);
        }

        explicit Static_String_Class(char Character) : Static_String_Class()
        {
            Copy(Character);
        }

        explicit Static_String_Class(Short_Natural_Type Byte, Short_Natural_Type Base = 10) : Static_String_Class()
        {
        }

        explicit Static_String_Class(Integer_Type Integer, Short_Integer_Type Base = 10) : Static_String_Class()
        {
        }

        explicit Static_String_Class(Natural_Type Natural, Short_Integer_Type Base = 10) : Static_String_Class()
        {
        }

        explicit Static_String_Class(Long_Integer_Type Real, Short_Integer_Type Base = 10) : Static_String_Class()
        {
        }

        explicit Static_String_Class(Long_Natural_Type Real, Short_Integer_Type Base = 10) : Static_String_Class()
        {
        }

        explicit Static_String_Class(Real_Type Real, Short_Integer_Type Base = 10) : Static_String_Class()
        {
        }

        explicit Static_String_Class(Long_Real_Type Real, Short_Integer_Type Base = 10) : Static_String_Class()
        {
        }

        ~Static_String_Class() override
        {
            Size = 0;
            Characters_Pointer = NULL;
            
            log_printf("Static_String_Class::~Static_String_Class() - Static string destroyed. \n");
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

        Static_String_Class& operator=(char Character)
        {
            Copy(Character);
            return *this;
        }

        Static_String_Class& operator+=(char Character)
        {
            Concatenate(Character);
            return *this;
        }

        Static_String_Class& operator+=(const char* String)
        {
            Concatenate(String);
            return *this;
        }

        Static_String_Class& operator+=(const String_Class& String)
        {
            Concatenate(String);
            return *this;
        }

        

        Result_Type Set_Size(Size_Type Size) override {
            
            ESP_LOGI("Static_String", "Static_String_Class::Set_Size()");
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