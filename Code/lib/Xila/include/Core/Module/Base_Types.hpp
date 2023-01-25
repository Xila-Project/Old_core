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

namespace Xila_Namespace
{
    typedef bool Boolean_Type;
    typedef short Short_Integer;
    typedef int Integer;
    typedef long Long_Integer;
    typedef long long Long_Long_Integer;

    typedef short Unsigned_Short_Integer;
    typedef int Unsigned_Integer;
    typedef long Unsigned_Long_Integer;
    typedef long long Unsigned_Long_Long_Integer;

    typedef float Float;
    typedef double Precision_Float;
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
        Error,       ///< Error event.
        Warning,     ///< Warning event.
        Information, ///< Information event.
        Question,    ///< Question event.
        None
    };

}

#endif