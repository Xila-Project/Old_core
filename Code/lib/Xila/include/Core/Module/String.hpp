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
        String_Class(const String_Class &String);

        /// @brief Constructor from character array.
        String_Class(const char *String);

        /// @brief Constructor from character array.
        /// @param String Character array to copy.
        /// @param Size Character array size.
        String_Class(const char *String, Size_Type Size);

        /// @brief Move constructor.
        /// @param String String to move.
        String_Class(String_Class &&String);

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

        /// @brief Get the string length (just the number of characters).
        /// @return String length.
        Size_Type Get_Length() const;

        /// @brief Get the string size (maximum length - 1 that the string can contain).
        /// @return String size.
        Size_Type Get_Size() const;

        /// @brief Get the string capacity (maximum length that the string can contain).
        /// @return String capacity.
        Size_Type Get_Capacity() const;

        /// @brief Get character at a specific position.
        /// @param Position Position of the character.
        /// @return Character at the position or '\0' if not in range.
        char Get_Character(Size_Type Position) const;

        /// @brief Get the position of the first occurence of a character in the string.
        /// @param Character Character to search.
        /// @param Offset_Position Position to start the search.
        /// @return Position of the character or -1 if not found.
        Size_Type Get_Position(char Character, Size_Type Offset_Position = 0) const;

        /// @brief Get the position of the first occurence of a string in the string.
        /// @param String String to search.
        /// @param Offset_Position Position to start the search.
        /// @return Position of the string or -1 if not found.
        Size_Type Get_Position(const char *String, Size_Type Position = 0) const;

        /// @brief Get the position of the first occurence of a string in the string.
        /// @param String String to search.
        /// @param Offset_Position Position to start the search.
        /// @return Position of the string or -1 if not found.
        Size_Type Get_Position(const String_Class &String, Size_Type Position = 0) const;

        // - - Setters

        /// @brief Set the allocated size of the string (length + 1).
        /// @param Size Size to set.
        /// @return Result of the operation.
        virtual Result_Type Set_Size(Size_Type Size);

        /// @brief Set the allocated capacity of the string (maximum length that the string can contain).
        /// @param Capacity Capacity to set.
        /// @return Result of the operation.
        Result_Type Set_Capacity(Size_Type Capacity);

        /// @brief Set the buffer of the string.
        /// @param Buffer Buffer to set.
        /// @param Size Buffer size.
        void Set_Buffer(char *Buffer, Size_Type Size);

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

        /// @brief  that copy a string into the current string.
        /// @param String The string to copy.
        /// @param Size The size of the string to copy. If 0, the size will be calculated according to the length of the text (must be null terminated).
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(const char *String, Size_Type Size = 0, bool Change_Size = false);

        /// @brief  that copy a string into the current string.
        /// @param String The string to copy.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(const String_Class &String, bool Change_Size = false);

        /// @brief  that copy a character into the current string.
        /// @param Character The character to copy.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(char Character, bool Change_Size = false);

        /// @brief  that copy an integer into the current string.
        /// @param Integer The integer to copy.
        /// @param Base Integer base.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(Integer_Type Integer, bool Change_Size = false);

        /// @brief Convert to string a long integer and copy into the current string.
        /// @param Integer The long integer to copy.
        /// @param Base Integer base.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(Long_Integer_Type Natural, bool Change_Size = false);

        /// @brief Convert to string a short natural and copy it into the current string.
        /// @param Natural The short natural to copy.
        /// @param Base Natural base.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        Result_Type Copy(Short_Natural_Type Byte, bool Change_Size = false);

        /// @brief Convert to string a natural and copy it into the current string.
        /// @param Natural The natural to copy.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(Natural_Type Natural, bool Change_Size = false);

        /// @brief Convert to string a long natural and copy it into the current string.
        /// @param Natural The long natural to copy.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(Long_Natural_Type Natural, bool Change_Size = false);

        /// @brief Convert to string a real and copy it into the current string.
        /// @param Real The real to copy.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(Real_Type Real, bool Change_Size = false);

        /// @brief Convert to string a long real and copy it into the current string.
        /// @param Real The long real to copy.
        /// @param Change_Size Does the string size must be changed to fit the new string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy(Long_Real_Type Real, bool Change_Size = false);

        /// @brief Copy a formated string into the current string.
        /// @param Format Format of the string.
        /// @param ... Arguments of the format.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type Copy_Format(const char *Format, ...);

        // - - Concatenation

        /// @brief Concatenate a string to the current string.
        /// @param String String to concatenate.
        /// @param Size Size of the string to concatenate. If 0, the size will be calculated according to the length of the text (must be null terminated)
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(const char *String, Size_Type Size = 0, bool Increase_Size = false);

        /// @brief Concatenate a string to the current string.
        /// @param String String to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(const String_Class &String, bool Increase_Size = false);

        /// @brief Concatenate a character to the current string.
        /// @param Character Character to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(char Character, bool Increase_Size = false);

        /// @brief Convert a byte to string and concatenate it into the current string.
        /// @param Byte Short natural to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(Short_Natural_Type Byte, bool Increase_Size = false);

        /// @brief Convert an integer to string and concatenate it into the current string.
        /// @param Integer Integer to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(Integer_Type Integer, bool Increase_Size = false);

        /// @brief Convert a natural to string and concatenate it into the current string.
        /// @param Natural Natural to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(Natural_Type Natural, bool Increase_Size = false);

        /// @brief Convert a long integer to string and concatenate it into the current string.
        /// @param Natural Long integer to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(Long_Integer_Type Natural, bool Increase_Size = false);

        /// @brief Convert a long natural to the current string and concatenate it into the current string.
        /// @param Natural Long natural to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(Long_Natural_Type Natural, bool Increase_Size = false);

        /// @brief Convert a real to string and concatenate it into the current string.
        /// @param Real Real to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        Result_Type Concatenate(Real_Type Real, bool Increase_Size = false);

        /// @brief Convert a long real to string and concatenate it into the current string.
        /// @param Real Long real to concatenate.
        /// @param Increase_Size Does the string size must be increased to fit the new string.
        /// @return Result_Type::Success if the string was concatenated, Result_Type::Error otherwise.
        Result_Type Concatenate(Long_Real_Type Real, bool Increase_Size = false);

        // - - Comparison

        /// @brief Compare the current string with another string.
        /// @param String String to compare.
        /// @return 0 if the strings are equals, -1 if the current string is lower than the string to compare, 1 if the current string is greater than the string to compare.
        int8_t Compare(const char *String) const;

        /// @brief Compare the current string with another string.
        /// @param String String to compare.
        /// @return 0 if the strings are equals, -1 if the current string is lower than the string to compare, 1 if the current string is greater than the string to compare.
        int8_t Compare(const String_Class &String) const;

        /// @brief Check if the current string is equal to another string.
        /// @param String String to compare.
        /// @return true if the strings are equals, false otherwise.
        bool Equals(const char *String) const;

        /// @brief Check if the current string is equal to another string.
        /// @param String String to compare.
        /// @return true if the strings are equals, false otherwise.
        bool Equals(const String_Class &String) const;

        // - - Edition

        /// @brief Remove characters at a given position from the string.
        /// @param Position Position of the character to remove.
        /// @param Size Number of characters to remove.
        /// @return Result_Type::Success if the character was removed, Result_Type::Error otherwise.
        Result_Type Remove(Size_Type Position, Size_Type Size = 1);

        /// @brief Set a character at a given position in the string.
        /// @param Position Position of the character to set.
        /// @param Character Character to set.
        /// @return Result_Type::Success if the character was set, Result_Type::Error otherwise.
        Result_Type Set_Character(Size_Type Position, char Character);

        // - - Conversion

        /// @brief Copy the current string to a character array.
        /// @param Array Array to copy the string to.
        /// @param Size Size of the array.
        /// @param Offset_Position Position in the array to start copying the string.
        /// @return Result_Type::Success if the string was copied, Result_Type::Error otherwise.
        Result_Type To_Char_Array(char *Array, Size_Type Size, Size_Type Offset_Position = 0) const;

        /// @brief Convert the string to a lower case string.
        /// @return Result_Type::Success if the string was converted, Result_Type::Error otherwise.
        Result_Type To_Lower_Case();

        /// @brief Convert the string to an upper case string.
        /// @return Result_Type::Success if the string was converted, Result_Type::Error otherwise.
        Result_Type To_Upper_Case();

        // - - Operators

        // - - - Casting

        /// @brief Convert and cast the string into a real.
        operator Real_Type() const;

        /// @brief Cast the string to a character array (return the buffer pointer).
        operator const char *() const;

        /// @brief Cast the string to a boolean (return if the string is valid).
        operator bool() const;

        /// @brief Convert and cast the string into a long real.
        explicit operator Long_Real_Type() const;

        /// @brief Convert and cast the string into long integer.
        explicit operator Long_Integer_Type() const;

        /// @brief Convert and cast the string into long natural.
        explicit operator Long_Natural_Type() const;

        /// @brief Convert and cast the string into an integer.
        explicit operator Integer_Type() const;

        /// @brief Convert and cast the string into a natural.
        explicit operator Natural_Type() const;

        /// @brief Cast the string to a character array (return the buffer pointer).
        explicit operator char *();

        /// @brief Cast the string to a byte array (return the buffer pointer).
        explicit operator const Byte_Type *() const;

        // - - - Assignment

        /// @brief Copy a character array into the current string (doesn't change the size of the string).
        /// @param String Character array to copy.
        String_Class &operator=(const char *String);

        /// @brief Copy a string into the current string (doesn't change the size of the string).
        /// @param String String to copy.
        String_Class &operator=(const String_Class &String);

        /// @brief Copy a character into the current string (doesn't change the size of the string).
        /// @param Character Character to copy.
        String_Class &operator=(char Character);

        /// @brief Convert an interger to string and copy it into the current string (doesn't change the size of the string).
        /// @param Integer Integer to copy.
        String_Class &operator=(Long_Integer_Type Integer);

        /// @brief Convert a natural to string and copy it into the current string (doesn't change the size of the string).
        /// @param Natural Natural to copy.
        String_Class &operator=(Long_Natural_Type Natural);

        /// @brief Convert a real to string and copy it into the current string (doesn't change the size of the string).
        /// @param Real Real to copy.
        String_Class &operator=(Long_Real_Type Real);

        // - - - Concatenation

        /// @brief Concatenate a character array to the current string.
        /// @param String Character array to concatenate.
        String_Class &operator+=(const char *String);

        /// @brief Concatenate a string to the current string.
        /// @param String String to concatenate.
        String_Class &operator+=(const String_Class &String);

        /// @brief Concatenate a character to the current string.
        /// @param Character Character to concatenate.
        String_Class &operator+=(char Character);

        /// @brief Convert an interger to string and concatenate it to the current string.
        /// @param Integer Integer to concatenate.
        String_Class &operator+=(Integer_Type Integer);

        /// @brief Convert a natural to string and concatenate it to the current string.
        /// @param Natural Natural to concatenate.
        String_Class &operator+=(Long_Integer_Type Integer);

        String_Class &operator+=(Short_Natural_Type Byte);
        String_Class &operator+=(Natural_Type Natural);
        String_Class &operator+=(Long_Natural_Type Natural);
        String_Class &operator+=(Real_Type Real);
        String_Class &operator+=(Long_Real_Type Real);

        // - - - Comparison

        /// @brief Check if the current string is equal to another string.
        /// @param String String to compare.
        /// @return true if the strings are equals, false otherwise.
        bool operator==(const char *String) const;

        /// @brief Check if the current string is equal to another string.
        /// @param String String to compare.
        /// @return true if the strings are equals, false otherwise.
        bool operator==(const String_Class &String) const;

        /// @brief Check if the current string is different from another string.
        /// @param String String to compare.
        /// @return true if the strings are different, false otherwise.
        bool operator!=(const char *String) const;

        /// @brief Check if the current string is different from another string.
        /// @param String String to compare.
        /// @return true if the strings are different, false otherwise.
        bool operator!=(const String_Class &String) const;

        /// @brief Check if the current string is greater than another string.
        /// @param String String to compare.
        /// @return true if the current string is greater than the other string, false otherwise.
        bool operator>(const char *String) const;

        /// @brief Check if the current string is greater than another string.
        /// @param String String to compare.
        /// @return true if the current string is greater than the other string, false otherwise.
        bool operator>(const String_Class &String) const;

        /// @brief Check if the current string is lower than another string.
        /// @param String String to compare.
        /// @return true if the current string is lower than the other string, false otherwise.
        bool operator<(const char *String) const;

        /// @brief Check if the current string is lower than another string.
        /// @param String String to compare.
        /// @return true if the current string is lower than the other string, false otherwise.
        bool operator<(const String_Class &String) const;

        /// @brief Check if the current string is greater or equal than another string.
        /// @param String String to compare.
        /// @return true if the current string is greater or equal than the other string, false otherwise.
        bool operator>=(const char *String) const;

        /// @brief Check if the current string is greater or equal than another string.
        /// @param String String to compare.
        /// @return true if the current string is greater or equal than the other string, false otherwise.
        bool operator>=(const String_Class &String) const;

        /// @brief Check if the current string is lower or equal than another string.
        /// @param String String to compare.
        /// @return true if the current string is lower or equal than the other string, false otherwise.
        bool operator<=(const char *String) const;

        /// @brief Check if the current string is lower or equal than another string.
        /// @param String String to compare.
        /// @return true if the current string is lower or equal than the other string, false otherwise.
        bool operator<=(const String_Class &String) const;

        // - - - Access

        /// @brief Get the character at a given position.
        /// @param Position Position of the character to get.
        /// @return Character at the given position or `\0` if the position is out of range.
        char operator[](Size_Type Index) const;

        /// @brief Get the character at a given position.
        /// @param Position Position of the character to get.
        /// @return Character at the given index or `\0` if the index is out of range.
        char &operator[](Size_Type Index);

    protected:
    // - Attributes

        /// @brief Pointer to the buffer.
        char *Characters_Pointer;

        /// @brief Size of the buffer.
        Size_Type Size;
    } String_Type;

    /// @brief Template, child of `String_Class`, that uses a static buffer (stack allocated) instead of a dynamic one (heap allocated).
    /// @tparam Length Capacity (Size + 1) of the static buffer.
    template <Size_Type Length>
    class Static_String_Class : public String_Class
    {
    public:
        // - Methods

        Static_String_Class()
        {
            // log_printf("Static_String_Class::Static_String_Class() - Length = %d \n", Length);
            Set_Buffer(this->Buffer, Length);
            Clear();
        }

        Static_String_Class(const char *String) : Static_String_Class()
        {
            Copy(String);
        }

        Static_String_Class(const char *String, Size_Type Size) : Static_String_Class()
        {
            // log_printf("Static_String_Class::Static_String_Class(const char* String, Size_Type Size) - String = %s \n", String);
            Copy(String, Size);
            // log_printf("Static_String_Class::Static_String_Class(const char* String, Size_Type Size) - String = %s \n", (const char *)*this);
        }

        Static_String_Class(const Static_String_Class &String) : Static_String_Class()
        {
            // log_printf("Static_String_Class::Static_String_Class(const Static_String_Class& String) - String = %s \n", (const char *)String);

            Copy(String);
        }

        Static_String_Class(const String_Class &String) : Static_String_Class()
        {

            // log_printf("Static_String_Class::Static_String_Class(const String_Class& String) - String = %s \n", (const char *)String);

            Copy(String);
        }

        Static_String_Class(String_Class &&String) : Static_String_Class()
        {
            // log_printf("Static_String_Class::Static_String_Class(String_Class&& String) - String = %s \n", (const char *)String);

            Set_Buffer(this->Buffer, Length);
            String.Characters_Pointer = NULL;
            String.Size = 0;
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

            // log_printf("Static_String_Class::~Static_String_Class() - Static string destroyed. \n");
        }

        Static_String_Class &operator=(const String_Class &String)
        {
            //  log_printf("Static_String_Class::operator=(const String_Class& String) - String = %s \n", (const char *)String);
            Copy(String);
            return *this;
        }

        Static_String_Class &operator=(const char *String)
        {
            Copy(String);
            return *this;
        }

        Static_String_Class &operator=(char Character)
        {
            Copy(Character);
            return *this;
        }

        Static_String_Class &operator+=(char Character)
        {
            Concatenate(Character);
            return *this;
        }

        Static_String_Class &operator+=(const char *String)
        {
            Concatenate(String);
            return *this;
        }

        Static_String_Class &operator+=(const String_Class &String)
        {
            Concatenate(String);
            return *this;
        }

        Result_Type Set_Size(Size_Type Size) override
        {
            // ESP_LOGI("Static_String", "Static_String_Class::Set_Size()");
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