///
/// @file String.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 19-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Module/String.hpp"
#include "Core/Log/Log.hpp"
#include <cstring>

using namespace Xila_Namespace;

String_Class::String_Class() : Characters_Pointer(NULL), Size(0)
{
}

String_Class::String_Class(const String_Class &String) : String_Class()
{
    Set_Size(String.Get_Size());
    Copy(String);
}

String_Class::String_Class(const char *String) : String_Class()
{
    Set_Size(std::strlen(String) + 1);
    Copy(String);
}

String_Class::String_Class(const char *String, Size_Type Size) : String_Class()
{
    Set_Size(Size);
    Copy(String, Size);
}

String_Class::String_Class(String_Class &&String) : String_Class()
{
    Characters_Pointer = String.Characters_Pointer;
    Size = String.Size;
    String.Characters_Pointer = NULL;
    String.Size = 0;
}

String_Class::String_Class(char Character)
{
    Set_Size(2);
    Copy(Character);
}

String_Class::~String_Class()
{
    this->Set_Size(0);
}

Size_Type String_Class::Get_Length() const
{
    if (Is_Valid())
    {
        return std::strlen(Characters_Pointer);
    }
    else
    {
        return 0;
    }
}

Size_Type String_Class::Get_Size() const
{
    return Size;
}

Size_Type String_Class::Get_Capacity() const
{
    return Get_Size() - 1;
}

/// @brief
/// @param Position
/// @return
char String_Class::Get_Character(Size_Type Position) const
{
    if ((Position < Get_Size()) && Is_Valid())
    {
        return Characters_Pointer[Position];
    }
    else
    {
        return '\0';
    }
}

Result_Type String_Class::Set_Size(Size_Type Size)
{
    // If the String is valid.
    if (Is_Valid())
    {
        // If the String is set to be empty.
        if (Size == 0)
        {
            free(Characters_Pointer);
            this->Characters_Pointer = NULL;
        }
        // Change size
        else if (Size != Get_Size())
        {
            char *New_Buffer = (char *)realloc(Characters_Pointer, Size * sizeof(char));
            if (New_Buffer == NULL)
            {
                this->Size = 0;
                return Result_Type::Error;
            }
            else
            {
                this->Characters_Pointer = New_Buffer;
            }
        }
    }
    // If the String is not valid.
    else
    {

        if (Size == 0)
        {
            Characters_Pointer = NULL;
        }
        else
        {
            this->Characters_Pointer = (char *)malloc(Size * sizeof(char));
            if (this->Characters_Pointer == NULL)
            {
                this->Size = 0;
                return Result_Type::Error;
            }
            Clear();
        }
    }

    this->Size = Size;
    return Result_Type::Success;
}

Result_Type String_Class::Set_Capacity(Size_Type Capacity)
{
    if (Capacity == 0)
    {
        return Set_Size(0);
    }
    return Set_Size(Capacity + 1);
}

void String_Class::Set_Buffer(char *Buffer, Size_Type Size)
{
    if (Is_Valid())
    {
        Set_Size(0);
    }
    Characters_Pointer = Buffer;
    this->Size = Size;
}

void String_Class::Set_Character(char Character, Size_Type Position)
{
    if (Position < Size && Is_Valid())
    {
        Characters_Pointer[Position] = Character;
    }
}

void String_Class::Clear()
{
    if (Is_Valid())
    {
        memset(Characters_Pointer, '\0', Get_Size());
    }
}

Result_Type String_Class::Fit()
{
    if (Is_Valid())
    {
        return Set_Capacity(Get_Length());
    }
    return Result_Type::Error;
}

bool String_Class::Is_Empty() const
{
    if (Is_Valid())
    {
        return Characters_Pointer[0] == '\0';
    }
    else
    {
        return true;
    }
}

/// @brief Return if the string is valid (allocated).
/// @return true if the string is valid, false otherwise.
bool String_Class::Is_Valid() const
{
    return (Characters_Pointer != NULL) && (Size > 0);
}


Result_Type String_Class::Copy(const char *String, Size_Type Size, bool Change_Size)
{
    Log_Verbose("String", "String_Class::Copy(const char *String, Size_Type Size, bool Change_Size)");
    if (String == NULL || !Is_Valid())
    {
        
        return Result_Type::Error;
    }
    
    if (Size == 0)
    {
        
        Size = std::strlen(String) + 1;
    }
    
    if (Change_Size)
    {
        
        if (Set_Size(Size) != Result_Type::Success)
        {
            return Result_Type::Error;
        }
    }
    

    if (Get_Size() <= Size)
    {
        
        std::strncpy(Characters_Pointer, String, Get_Size());
    }
    else
    {  
        
        std::strncpy(Characters_Pointer, String, Size);
    }

    
    Characters_Pointer[Get_Size() - 1] = '\0';
    Log_Verbose("String", "String_Class::Copy(const char *String, Size_Type Size, bool Change_Size) - Success");
    return Result_Type::Success;
}

Result_Type String_Class::Copy(const String_Class &String, bool Change_Size)
{
    return Copy(String.Characters_Pointer, String.Size, Change_Size);
}

Result_Type String_Class::Copy(char Character, bool Change_Size)
{
    char String[2] = {Character, '\0'};
    return Copy(String, 2, Change_Size);
}

Result_Type String_Class::Copy_Format(const char *Format, ...)
{
    if (Format == NULL || !Is_Valid())
    {
        return Result_Type::Error;
    }

    va_list Arguments;
    va_start(Arguments, Format);
    vsnprintf(Characters_Pointer, Get_Size(), Format, Arguments);
    va_end(Arguments);
}

Result_Type String_Class::Concatenate(const char *String, Size_Type Size, bool Increase_Size)
{
    
    Log_Verbose("String", "Char pointer : %p", String);
    Log_Verbose("String", "Size : %d", Size);
    Log_Verbose("String", "Increase_Size : %d", Increase_Size);

    Log_Verbose("String", "String pointer : %p", Characters_Pointer);
    Log_Verbose("String", "Size : %d", Size);

    if (String == NULL || !Is_Valid())
    {
        return Result_Type::Error;
    }

    if (Size == 0)
    {
        Size = std::strlen(String);
    }

    Size += Get_Length() + 1;

    if (Increase_Size && (Get_Size() < Size))
    {
        if (Set_Size(Size) != Result_Type::Success)
        {
            return Result_Type::Error;
        }
    }

    std::strncat(Characters_Pointer, String, Get_Size());
    Characters_Pointer[Get_Size() - 1] = '\0';

    return Result_Type::Success;
}

Result_Type String_Class::Concatenate(const String_Class &String, bool Increase_Size)
{
    return Concatenate(String.Characters_Pointer, String.Size, Increase_Size);
}

Result_Type String_Class::Concatenate(char Character, bool Increase_Size)
{
    char Character_Array[2] = {Character, '\0'};
    return Concatenate(Character_Array, 2, Increase_Size);
}

Result_Type String_Class::Concatenate(Short_Natural_Type Byte, bool Increase_Size)
{
    return Concatenate((Static_String_Type<3 * sizeof(Short_Natural_Type)>)Byte, Increase_Size);
}

Result_Type String_Class::Concatenate(Integer_Type Integer, bool Increase_Size)
{
    return Concatenate((Static_String_Type<3 * sizeof(Natural_Type)>)Integer, Increase_Size);
}

Result_Type String_Class::Concatenate(Natural_Type Natural, bool Increase_Size)
{
    return Concatenate((Static_String_Type<3 * sizeof(Natural_Type)>)Natural, Increase_Size);
}

Result_Type String_Class::Concatenate(Long_Natural_Type Long_Natural, bool Increase_Size)
{
    return Concatenate((Static_String_Type<3 * sizeof(Long_Natural_Type)>)Long_Natural, Increase_Size);
}

Result_Type String_Class::Concatenate(Long_Integer_Type Long_Integer, bool Increase_Size)
{
    return Concatenate((Static_String_Type<3 * sizeof(Long_Integer_Type)>)Long_Integer, Increase_Size);
}

Result_Type String_Class::Concatenate(Real_Type Real, bool Increase_Size)
{
    return Concatenate((Static_String_Type<3 * sizeof(Real_Type)>)Real, Increase_Size);
}

Result_Type String_Class::Concatenate(Long_Real_Type Long_Real, bool Increase_Size)
{
    return Concatenate((Static_String_Type<3 * sizeof(Long_Real_Type)>)Long_Real, Increase_Size);
}

bool String_Class::Equals(const char *String) const
{
    if (String != NULL || Is_Valid())
    {
        if (Compare(String) == 0)
        {
            return true;
        }
    }
    return false;
}

bool String_Class::Equals(const String_Class &String) const
{
    if (String && Is_Valid())
    {
        if (Compare(String) == 0)
        {
            return true;
        }
    }
    return false;
}

int8_t String_Class::Compare(const char *String) const
{
    if (String == NULL || !Is_Valid())
    {
        return 0;
    }

    return std::strncmp(Characters_Pointer, String, Get_Size());
}

int8_t String_Class::Compare(const String_Class &String) const
{
    return Compare(String.Characters_Pointer);
}

Result_Type String_Class::Remove(Size_Type Position, Size_Type Size)
{
    if (Position >= Get_Size() || !Is_Valid())
    {
        return Result_Type::Error;
    }

    if (Size == 0)
    {
        return Result_Type::Invalid_Argument;
    }

    if (Position + Size > Get_Length())
    {
        Size = Get_Length() - Position;
    }

    memmove(Characters_Pointer + Position, Characters_Pointer + Position + Size, Get_Length() - Position - Size + 1);

    Characters_Pointer[Get_Size() - 1] = '\0';

    return Result_Type::Success;
}

Result_Type String_Class::Set_Character(Size_Type Position, char Character)
{
    if (Position >= Get_Size() || !Is_Valid())
    {
        return Result_Type::Error;
    }

    Characters_Pointer[Position] = Character;
    Characters_Pointer[Get_Size() - 1] = '\0';

    return Result_Type::Success;
}

Result_Type String_Class::To_Char_Array(char *Array, Size_Type Size, Size_Type Offset_Position) const
{
    if (Array == NULL || Size == 0 || !Is_Valid())
    {
        return Result_Type::Error;
    }

    strlcpy(Array, Characters_Pointer, Size);
    return Result_Type::Success;
}

Result_Type String_Class::To_Upper_Case()
{
    if (!Is_Valid())
    {
        return Result_Type::Error;
    }

    for (Size_Type i = 0; i < Get_Length(); i++)
    {
        Characters_Pointer[i] = toupper(Characters_Pointer[i]);
    }
    return Result_Type::Success;
}

Result_Type String_Class::To_Lower_Case()
{
    if (!Is_Valid())
    {
        return Result_Type::Error;
    }

    for (Size_Type i = 0; i < Get_Length(); i++)
    {
        Characters_Pointer[i] = tolower(Characters_Pointer[i]);
    }
    return Result_Type::Success;
}

String_Class::operator bool() const
{
    return Is_Valid();
}

String_Class::operator const char *() const
{
    return Characters_Pointer;
}

String_Class::operator char *()
{
    return Characters_Pointer;
}

String_Class::operator const Byte_Type *() const
{
    return (const uint8_t *)Characters_Pointer;
}

String_Class &String_Class::operator=(const char *String)
{
    Copy(String);
    return *this;
}

String_Class &String_Class::operator=(const String_Class &String)
{
    Copy(String);
    return *this;
}

String_Class &String_Class::operator+=(const char *String)
{
    Concatenate(String);
    return *this;
}

String_Class &String_Class::operator+=(const String_Class &String)
{
    Concatenate(String);
    return *this;
}

String_Class &String_Class::operator+=(char Character)
{
    Concatenate(Character);
    return *this;
}

String_Class &String_Class::operator+=(Integer_Type Integer)
{
    Concatenate(Integer);
    return *this;
}

String_Class &String_Class::operator+=(Long_Integer_Type Integer)
{
    Concatenate(Integer);
    return *this;
}

String_Class &String_Class::operator+=(Short_Natural_Type Byte)
{
    Concatenate(Byte);
    return *this;
}

String_Class &String_Class::operator+=(Natural_Type Natural)
{
    Concatenate(Natural);
    return *this;
}

String_Class &String_Class::operator+=(Real_Type Real)
{
    Concatenate(Real);
    return *this;
}

String_Class &String_Class::operator+=(Long_Real_Type Real)
{
    Concatenate(Real);
    return *this;
}

bool String_Class::operator==(const char *String) const
{

    return Equals(String);
}

bool String_Class::operator==(const String_Class &String) const
{
    return Equals(String);
}

bool String_Class::operator!=(const char *String) const
{
    return !Equals(String);
}

bool String_Class::operator!=(const String_Class &String) const
{
    return !Equals(String);
}

bool String_Class::operator<(const char *String) const
{
    return (Compare(String) < 0);
}

bool String_Class::operator<(const String_Class &String) const
{
    return (Compare(String) < 0);
}

bool String_Class::operator<=(const char *String) const
{
    return (Compare(String) <= 0);
}

bool String_Class::operator<=(const String_Class &String) const
{
    return (Compare(String) <= 0);
}

bool String_Class::operator>(const char *String) const
{
    return (Compare(String) > 0);
}

bool String_Class::operator>(const String_Class &String) const
{
    return (Compare(String) > 0);
}

bool String_Class::operator>=(const char *String) const
{
    return (Compare(String) >= 0);
}

bool String_Class::operator>=(const String_Class &String) const
{
    return (Compare(String) >= 0);
}

char String_Class::operator[](Size_Type Index) const
{
    return Get_Character(Index);
}

char &String_Class::operator[](Size_Type Index)
{
    if (Index >= Get_Size())
    {
        return Characters_Pointer[0];
    }
    return Characters_Pointer[Index];
}
