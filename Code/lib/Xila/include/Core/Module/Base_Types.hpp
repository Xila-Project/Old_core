///
 /// @file Base_Types.hpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 25-01-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#ifndef Base_Types_Hpp_Included
#define Base_Types_Hpp_Included

#include "../Header.hpp"

namespace Xila_Namespace
{
    /// @brief Boolean type.
    typedef bool Boolean_Type;

    // - Absolute types

    /// @brief Byte type (8 bits).
    typedef uint8_t Byte_Type;
    /// @brief Word type (16 bits).
    typedef uint16_t Word_Type;
    /// @brief DWord type (32 bits).
    typedef uint32_t DWord_Type;
    /// @brief QWord type (64 bits).
    typedef uint64_t QWord_Type;

    // - Integer types

    /// @brief Short integer type (half register size).
    typedef int16_t Short_Integer_Type;
    /// @brief Integer type (register size).
    typedef int32_t Integer_Type;
    /// @brief Long integer type (double register size).
    typedef int64_t Long_Integer_Type;

    // - Natural types

    /// @brief Short natural type (half register size).
    typedef uint16_t Short_Natural_Type;
    /// @brief Natural type (register size).
    typedef uint32_t Natural_Type;
    /// @brief Long natural type (double register size).
    typedef uint64_t Long_Natural_Type;

    // - Real types
    /// @brief Real type (register size).
    typedef float Real_Type;
    /// @brief Long real type (double register size).
    typedef double Long_Real_Type;

    // - Character types
    typedef char Character_Type;

    typedef void Void;

    typedef uint32_t Tick_Type;

    // - Special types

    /// @brief Size Type;
    typedef size_t Size_Type;

    /// @brief Result type.
    enum class Result_Type
    {
        Error,
        Success = true,
        Invalid_Argument,
        Wait,
        None
    };

    typedef class File_Class File_Type;

    extern void* Null;

}

#endif