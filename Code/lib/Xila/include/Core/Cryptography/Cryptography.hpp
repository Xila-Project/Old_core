///
/// @file Mathematics.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Cryptography_Hpp_Included
#define Cryptography_Hpp_Included

#include "Arduino.h"
#include "../Module/Module.hpp"

namespace Xila_Namespace
{
    typedef class Cryptography_Class : Module_Class
    {
    public:

        enum class Hash_Type
        {
            MD_None,
            MD_2,
            MD_4,
            MD_5,
            SHA_1,
            SHA_224,
            SHA_256,
            SHA_384,
            SHA_512,
            RIPEMD_160,
        };

        Result_Type Get_Hash(const char* Message, Size_Type Message_Length, uint8_t* Result, Size_Type Result_Size, Hash_Type Type);

    } Cryptography_Type;

    extern Cryptography_Class Cryptography;
}

#endif