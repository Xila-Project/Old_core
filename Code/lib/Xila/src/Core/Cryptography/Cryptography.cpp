#include "Core/Cryptography/Cryptography.hpp"

using namespace Xila_Namespace;

Cryptography_Type Cryptography;

#include "mbedtls/md.h"

Result_Type Cryptography_Class::Get_Hash(const char* Message, Size_Type Message_Length, uint8_t* Result, Size_Type Result_Size, Hash_Type Type)
{
    mbedtls_md_context_t Context;
    mbedtls_md_type_t MBED_Type;

    switch (Type)
    {
    case Hash_Type::MD_None:
        MBED_Type = MBEDTLS_MD_NONE;
    case Hash_Type::MD_2:
        MBED_Type = MBEDTLS_MD_MD2;
        if (Result_Size < 16)
            return Result_Type::Error;
        break;
    case Hash_Type::MD_4:
        MBED_Type = MBEDTLS_MD_MD4;
        if (Result_Size < 16)
            return Result_Type::Error;
        break;
    case Hash_Type::MD_5:
        MBED_Type = MBEDTLS_MD_MD5;
        if (Result_Size < 16)
            return Result_Type::Error;
        break;
    case Hash_Type::SHA_1:
        MBED_Type = MBEDTLS_MD_SHA1;
        if (Result_Size < 20)
            return Result_Type::Error;
        break;
    case Hash_Type::SHA_224:
        MBED_Type = MBEDTLS_MD_SHA224;
        if (Result_Size < 28)
            return Result_Type::Error;
        break;
    case Hash_Type::SHA_256:
        MBED_Type = MBEDTLS_MD_SHA256;
        if (Result_Size < 32)
            return Result_Type::Error;
        break;
    case Hash_Type::SHA_384:
        MBED_Type = MBEDTLS_MD_SHA384;
        if (Result_Size < 48)
            return Result_Type::Error;
        break;
    case Hash_Type::SHA_512:
        MBED_Type = MBEDTLS_MD_SHA512;
        if (Result_Size < 64)
            return Result_Type::Error;
        break;  
    }

    mbedtls_md_init(&Context);
    mbedtls_md_setup(&Context, mbedtls_md_info_from_type(MBED_Type), 0);
    mbedtls_md_starts(&Context);
    mbedtls_md_update(&Context, (const unsigned char*)Message, Message_Length);
    mbedtls_md_finish(&Context, (unsigned char*)Result);
    mbedtls_md_free(&Context); 

    return Result_Type::Success;   
}