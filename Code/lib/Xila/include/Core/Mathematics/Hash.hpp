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
    namespace Mathematics_Types
    {
        enum class Message_Digest_Type
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
            RIPEMD_160
        };

        typedef class Hash_Class
        {
        public:
            // - Methods
            Hash_Class();

            Result_Type Create(Message_Digest_Type Type);
            void Delete(Byte_Type *Result);

            // - - Getters

            Message_Digest_Type Get_Type() const;
            Size_Type Get_Size() const;

            // - - Operations

            Result_Type Add(const Byte_Type *Data, Size_Type Data_Size);
            Result_Type Add(const String_Type &String);

        private:
            void *Data;

        } Hash_Type;

    }
}

#endif