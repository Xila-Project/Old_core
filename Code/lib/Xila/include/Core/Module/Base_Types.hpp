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

#include "Arduino.h"

#include "Core/Graphics/Types.hpp"

namespace Xila_Namespace
{
    typedef bool Boolean_Type;

    typedef uint8_t Byte_Type;
    typedef uint16_t Word_Type;
    typedef uint32_t DWord_Type;
    typedef uint64_t QWord_Type;
    
    typedef int16_t Short_Integer;
    typedef int32_t Integer;
    typedef int64_t Long_Integer;

    typedef uint16_t Short_Natural;
    typedef uint32_t Natural;
    typedef uint64_t Long_Natural;

    typedef float Real;
    typedef double Long_Real;

    typedef char Character;
    // typedef String String;

    typedef void Void;

    typedef uint32_t Tick_Type;

    /// @brief Size Type;
    typedef size_t Size_Type;

    /// @brief Result type.
    enum class Result_Type
    {
        Success,
        Invalid_Argument,
        Error,
        Wait,
        None
    };

    typedef class File_Class File_Type;

}

#endif