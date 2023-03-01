#include "Core/Mathematics/Hash.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Mathematics_Types;

#include "mbedtls/md.h"

mbedtls_md_type_t Convert(Message_Digest_Type Type)
{
    switch (Type)
    {
    case Message_Digest_Type::MD_2:
        return MBEDTLS_MD_MD2;
    case Message_Digest_Type::MD_4:
        return MBEDTLS_MD_MD4;
    case Message_Digest_Type::MD_5:
        return MBEDTLS_MD_MD5;
    case Message_Digest_Type::SHA_1:
        return MBEDTLS_MD_SHA1;
    case Message_Digest_Type::SHA_224:
        return MBEDTLS_MD_SHA224;
    case Message_Digest_Type::SHA_256:
        return MBEDTLS_MD_SHA256;
    case Message_Digest_Type::SHA_384:
        return MBEDTLS_MD_SHA384;
    case Message_Digest_Type::SHA_512:
        return MBEDTLS_MD_SHA512;
    case Message_Digest_Type::RIPEMD_160:
        return MBEDTLS_MD_RIPEMD160;
    default:
        return MBEDTLS_MD_NONE;
    }
}

Message_Digest_Type Convert(mbedtls_md_type_t Type)
{
    switch (Type)
    {
    case MBEDTLS_MD_MD2:
        return Message_Digest_Type::MD_2;
    case MBEDTLS_MD_MD4:
        return Message_Digest_Type::MD_4;
    case MBEDTLS_MD_MD5:
        return Message_Digest_Type::MD_5;
    case MBEDTLS_MD_SHA1:
        return Message_Digest_Type::SHA_1;
    case MBEDTLS_MD_SHA224:
        return Message_Digest_Type::SHA_224;
    case MBEDTLS_MD_SHA256:
        return Message_Digest_Type::SHA_256;
    case MBEDTLS_MD_SHA384:
        return Message_Digest_Type::SHA_384;
    case MBEDTLS_MD_SHA512:
        return Message_Digest_Type::SHA_512;
    case MBEDTLS_MD_RIPEMD160:
        return Message_Digest_Type::RIPEMD_160;
    default:
        return Message_Digest_Type::MD_None;
    }
}


Hash_Class::Hash_Class() : Data(NULL)
{
}

Result_Type Hash_Class::Create(Message_Digest_Type Type)
{
    Data = new mbedtls_md_context_t;
    mbedtls_md_init(static_cast<mbedtls_md_context_t*>(Data));
    if (mbedtls_md_setup(static_cast<mbedtls_md_context_t*>(Data), mbedtls_md_info_from_type(Convert(Type)), 0) != 0)
    {
        return Result_Type::Error;
    }
    if (mbedtls_md_starts(static_cast<mbedtls_md_context_t*>(Data)) != 0)
    {
        return Result_Type::Error;
    }
    return Result_Type::Success;
}

void Hash_Class::Delete(Byte_Type *Result)
{
    mbedtls_md_finish(static_cast<mbedtls_md_context_t*>(Data), Result);
    mbedtls_md_free(static_cast<mbedtls_md_context_t*>(Data));
    delete static_cast<mbedtls_md_context_t*>(Data);
}

Message_Digest_Type Hash_Class::Get_Type() const
{
    return Convert(mbedtls_md_get_type(static_cast<mbedtls_md_context_t*>(Data)->md_info));
}

Size_Type Hash_Class::Get_Size() const
{
    return mbedtls_md_get_size(static_cast<mbedtls_md_context_t*>(Data)->md_info);
}

Result_Type Hash_Class::Add(const Byte_Type *Data, Size_Type Size)
{
    mbedtls_md_update(static_cast<mbedtls_md_context_t*>(this->Data), Data, Size);
}

Result_Type Hash_Class::Add(const String_Type &Data)
{
    this->Add((const Byte_Type*)Data, Data.Get_Length());
}