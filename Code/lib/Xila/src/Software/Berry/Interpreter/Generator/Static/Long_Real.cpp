#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}

using namespace Xila_Namespace;

void* Berry_Long_Real_Type_Initialize(bvm* V, int Value = 0)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = (Long_Real_Type)Value;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Initialize, "+_p", "@[i");

void Berry_Long_Real_Type_Deinitialize(bvm* V, Long_Real_Type* Long_Real)
{
    be_free(V, Long_Real, sizeof(Long_Real_Type));
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Deinitialize, "", "@.");

const char* Berry_Long_Real_Type_To_String(bvm* V, Long_Real_Type* Long_Real)
{
    char* Buffer = (char*)Berry_Class::Get_Instance(V)->Buffer;
    dtostrf(*Long_Real, 0, 4, Buffer);
    return Buffer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_To_String, "s", "@.");

Long_Real_Type* Berry_Long_Real_Type_From_String(bvm* V, const char* String)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = atof(String);
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_From_String, "Long_Real_Type", "@s");

int Berry_Long_Real_Type_To_Integer(Long_Real_Type* Long_Real)
{
    return (int)*Long_Real;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_To_Integer, "i", ".");

Long_Real_Type* Berry_Long_Real_Type_From_Integer(bvm* V, int Integer)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = Integer;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_From_Integer, "Long_Real_Type", "@i");

Long_Real_Type* Berry_Long_Real_Type_Add(bvm* V, Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = Long_Real_2 ? *Long_Real_1 + *Long_Real_2 : *Long_Real_1;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Add, "Long_Real_Type", "@..");

Long_Real_Type* Berry_Long_Real_Type_Subtract(bvm* V, Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = Long_Real_2 ? *Long_Real_1 - *Long_Real_2 : *Long_Real_1;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Subtract, "Long_Real_Type", "@..");

Long_Real_Type* Berry_Long_Real_Type_Negate(bvm* V, Long_Real_Type* Long_Real)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = -*Long_Real;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Negate, "Long_Real_Type", "@.");

Long_Real_Type* Berry_Long_Real_Type_Multiply(bvm* V, Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = Long_Real_2 ? *Long_Real_1 * *Long_Real_2 : *Long_Real_1;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Multiply, "Long_Real_Type", "@..");

Long_Real_Type* Berry_Long_Real_Type_Modulo(bvm* V, Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    *Pointer = Long_Real_2 ? fmod(*Long_Real_1, *Long_Real_2) : 0;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Modulo, "Long_Real_Type", "@..");

Long_Real_Type* Berry_Long_Real_Type_Divide(bvm* V, Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    Long_Real_Type* Pointer = (Long_Real_Type*)be_malloc(V, sizeof(Long_Real_Type));
    if (*Long_Real_2 == 0)
    {
        be_raise(V, "ZeroDivisionError", "division by zero");
    }
    *Pointer = Long_Real_2 ? *Long_Real_1 / *Long_Real_2 : *Long_Real_1;
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Divide, "Long_Real_Type", "@..");

Boolean_Type Berry_Long_Real_Type_Equal(Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    return Long_Real_2 ? *Long_Real_1 == *Long_Real_2 : *Long_Real_1 == 0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Equal, "b", "..");

Boolean_Type Berry_Long_Real_Type_Not_Equal(Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    return Long_Real_2 ? *Long_Real_1 != *Long_Real_2 : *Long_Real_1 != 0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Not_Equal, "b", "..");

Boolean_Type Berry_Long_Real_Type_Greater(Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    return Long_Real_2 ? *Long_Real_1 > *Long_Real_2 : *Long_Real_1 > 0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Greater, "b", "..");

Boolean_Type Berry_Long_Real_Type_Greater_Equal(Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    return Long_Real_2 ? *Long_Real_1 >= *Long_Real_2 : *Long_Real_1 >= 0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Greater_Equal, "b", "..");

Boolean_Type Berry_Long_Real_Type_Less(Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    return Long_Real_2 ? *Long_Real_1 < *Long_Real_2 : *Long_Real_1 < 0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Less, "b", "..");

Boolean_Type Berry_Long_Real_Type_Less_Equal(Long_Real_Type* Long_Real_1, Long_Real_Type* Long_Real_2)
{
    return Long_Real_2 ? *Long_Real_1 <= *Long_Real_2 : *Long_Real_1 <= 0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_Less_Equal, "b", "..");

void* Berry_Long_Real_Type_To_Bytes(Long_Real_Type* Long_Real, size_t* Size)
{
    if (Size)
    {
        *Size = sizeof(Long_Real_Type);
    }
    return Long_Real;
}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_To_Bytes, "&", ".");

void Berry_Long_Real_Type_From_Bytes(Long_Real_Type* Long_Real, void* Bytes, size_t Size, int32_t Index)
{
    if (Index < 0)
        Index += Size - 1;
    if (Index < 0)
        Index = 0;
    if (Index >= Size)
        Index = Size - 1;
    
    size_t Usable_Length = Size - Index;
    if (Usable_Length > sizeof(Long_Real_Type))
        Usable_Length = sizeof(Long_Real_Type);
    *Long_Real = 0;
    memmove(Long_Real, (uint8_t*)Bytes + Index, Usable_Length);

}
BE_FUNC_CTYPE_DECLARE(Berry_Long_Real_Type_From_Bytes, "", ".(bytes)~[i");

extern "C"
{
    #include "../generate/be_fixed_be_class_Berry_Long_Real_Type.h"
}

/*
@const_object_info_begin
class be_class_Berry_Long_Real_Type(scope:global, name:Long_Real_Type)
{
    _p, var
    init, ctype_func(Berry_Long_Real_Type_Initialize)
    deinit, ctype_func(Berry_Long_Real_Type_Deinitialize)

    To_String, ctype_func(Berry_Long_Real_Type_To_String)
    From_String, ctype_func(Berry_Long_Real_Type_From_String)
    To_Integer, ctype_func(Berry_Long_Real_Type_To_Integer)
    From_Integer, ctype_func(Berry_Long_Real_Type_From_Integer)
    To_Bytes, ctype_func(Berry_Long_Real_Type_To_Bytes)
    From_Bytes, ctype_func(Berry_Long_Real_Type_From_Bytes)

    +, ctype_func(Berry_Long_Real_Type_Add)
    -, ctype_func(Berry_Long_Real_Type_Subtract)
    *, ctype_func(Berry_Long_Real_Type_Multiply)
    /, ctype_func(Berry_Long_Real_Type_Divide)
    %, ctype_func(Berry_Long_Real_Type_Modulo)
    -*, ctype_func(Berry_Long_Real_Type_Negate)
    ==, ctype_func(Berry_Long_Real_Type_Equal)
    !=, ctype_func(Berry_Long_Real_Type_Not_Equal)
    >, ctype_func(Berry_Long_Real_Type_Greater)
    >=, ctype_func(Berry_Long_Real_Type_Greater_Equal)
    <, ctype_func(Berry_Long_Real_Type_Less)
    <=, ctype_func(Berry_Long_Real_Type_Less_Equal)
}
@const_object_info_end
*/
