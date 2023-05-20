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

            /// @brief Default constructor.
            Hash_Class();

            /// @brief Default destructor.
            ~Hash_Class();

            // - - Manipulators

            /// @brief Create a new hash.
            /// @param Type Type of hash to create.
            /// @return Result_Type
            Result_Type Create(Message_Digest_Type Type);

            /// @brief Delete the hash.
            /// @param Result Result of the operation.
            void Delete(Byte_Type *Result = NULL);

            // - - Getters

            bool Is_Valid() const;

            /// @brief Get the type of the hash.
            /// @return Message_Digest_Type
            Message_Digest_Type Get_Type() const;

            /// @brief Get the size of the hash.
            /// @return Size_Type
            Size_Type Get_Size() const;

            // - - Operations

            /// @brief Add data to the hash.
            /// @param Data Data to add.
            /// @param Data_Size Size of the data.
            /// @return Result_Type
            Result_Type Add(const Byte_Type *Data, Size_Type Data_Size);
            
            /// @brief Add a string to the hash.
            /// @param String String to add.
            /// @return Result_Type
            Result_Type Add(const char*String);

        private:
            // - Attributes

            void *Data;

        } Hash_Type;

    }
}

#endif