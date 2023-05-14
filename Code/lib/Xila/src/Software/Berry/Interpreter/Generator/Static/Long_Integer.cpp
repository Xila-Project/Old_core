/// @file Long_Integer.cpp
/// @author Theo ARENDS (arendst)
/// @brief
/// @version 0.1.0
/// @date 13-05-2023
/// @note This is a slightly modified version of the implementation of 64 bits integers in the Tasmota project.

/********************************************************************
 * int64 - support 64 bits int on 32 bits architecture
 *
 *******************************************************************/

#include "Software/Berry/Berry.hpp"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
#include "be_mem.h"
}

static void Berry_Integer_Type_toa(int64_t num, uint8_t *str)
{
    uint64_t sum = num;
    if (num < 0)
    {
        sum = -num;
        str[0] = '-';
        str++;
    }
    int len = 0;
    do
    {
        str[len++] = '0' + sum % 10LL;
        sum /= 10LL;
    } while (sum);
    str[len] = '\0';
    /* strrev */
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        uint8_t a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}

void *Berry_Integer_Type_init(bvm *vm, int32_t val)
{
    int64_t *i64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    *i64 = (int64_t)val;
    // serial_debug("int64_init p=%p\n", i64);
    return i64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_init, "+_p", "@[i]")

void Berry_Integer_Type_deinit(bvm *vm, int64_t *i64)
{
    // serial_debug("int64_deinit p=%p\n", i64);
    be_free(vm, i64, sizeof(int64_t));
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_deinit, "", "@.")

const char *Berry_Integer_Type_To_String(bvm *Instance, int64_t *i64)
{
    uint8_t* Buffer = Berry_Class::Get_Instance(Instance)->Buffer;
    Berry_Integer_Type_toa(*i64, Buffer);
    return (char*)Buffer;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_To_String, "s", "@.")

int64_t *Berry_Integer_Type_From_String(bvm *vm, const char *s)
{
    int64_t *i64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    if (i64 == NULL)
    {
        be_raise(vm, "memory_error", "cannot allocate buffer");
    }
    if (s)
    {
        *i64 = atoll(s);
    }
    else
    {
        *i64 = 0;
    }
    return i64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_From_String, "Long_Integer_Type", "@s")

int32_t Berry_Integer_Type_To_Integer(int64_t *i64)
{
    return (int32_t)*i64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_To_Integer, "i", ".")

void Berry_Integer_Type_Set(int64_t *i64, int32_t high, int32_t low)
{
    *i64 = ((int64_t)high << 32) | ((int64_t)low & 0xFFFFFFFF);
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_Set, "", ".ii")

int64_t *Berry_Integer_Type_From_Integer(bvm *vm, uint32_t low)
{
    int64_t *r64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    *r64 = low;
    return r64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_From_Integer, "Long_Integer_Type", "@i")

int64_t *Berry_Integer_Type_add(bvm *vm, int64_t *i64, int64_t *j64)
{
    int64_t *r64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    *r64 = j64 ? *i64 + *j64 : *i64;
    return r64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_add, "Long_Integer_Type", "@(Long_Integer_Type)(Long_Integer_Type)")

int64_t *Berry_Integer_Type_sub(bvm *vm, int64_t *i64, int64_t *j64)
{
    int64_t *r64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    *r64 = j64 ? *i64 - *j64 : *i64;
    return r64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_sub, "Long_Integer_Type", "@(Long_Integer_Type)(Long_Integer_Type)")

int64_t *Berry_Integer_Type_neg(bvm *vm, int64_t *i64)
{
    int64_t *r64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    *r64 = -*i64;
    return r64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_neg, "Long_Integer_Type", "@.")

int64_t *Berry_Integer_Type_mul(bvm *vm, int64_t *i64, int64_t *j64)
{
    int64_t *r64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    *r64 = j64 ? *i64 * *j64 : 0;
    return r64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_mul, "Long_Integer_Type", "@(Long_Integer_Type)(Long_Integer_Type)")

int64_t *Berry_Integer_Type_mod(bvm *vm, int64_t *i64, int64_t *j64)
{
    int64_t *r64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    *r64 = j64 ? *i64 % *j64 : 0;
    return r64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_mod, "Long_Integer_Type", "@(Long_Integer_Type)(Long_Integer_Type)")

int64_t *Berry_Integer_Type_div(bvm *vm, int64_t *i64, int64_t *j64)
{
    int64_t *r64 = (int64_t *)be_malloc(vm, sizeof(int64_t));
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    if (j64 == NULL || *j64 == 0)
    {
        be_raise(vm, "divzero_error", "division by zero");
    }
    else
    {
        *r64 = *i64 / *j64;
    }
    return r64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_div, "Long_Integer_Type", "@.(Long_Integer_Type)")

bbool Berry_Integer_Type_equals(int64_t *i64, int64_t *j64)
{
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    int64_t j = 0;
    if (j64)
    {
        j = *j64;
    }
    return *i64 == j;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_equals, "b", ".(Long_Integer_Type)")

bbool Berry_Integer_Type_nequals(int64_t *i64, int64_t *j64)
{
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    int64_t j = 0;
    if (j64)
    {
        j = *j64;
    }
    return *i64 != j;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_nequals, "b", ".(Long_Integer_Type)")

bbool Berry_Integer_Type_gt(int64_t *i64, int64_t *j64)
{
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    int64_t j = 0;
    if (j64)
    {
        j = *j64;
    }
    return *i64 > j;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_gt, "b", ".(Long_Integer_Type)")

bbool Berry_Integer_Type_gte(int64_t *i64, int64_t *j64)
{
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    int64_t j = 0;
    if (j64)
    {
        j = *j64;
    }
    return *i64 >= j;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_gte, "b", ".(Long_Integer_Type)")

bbool Berry_Integer_Type_lt(int64_t *i64, int64_t *j64)
{
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    int64_t j = 0;
    if (j64)
    {
        j = *j64;
    }
    return *i64 < j;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_lt, "b", ".(Long_Integer_Type)")

bbool Berry_Integer_Type_lte(int64_t *i64, int64_t *j64)
{
    // it's possible that arg j64 is nullptr, since class type does allow NULLPTR to come through.
    int64_t j = 0;
    if (j64)
    {
        j = *j64;
    }
    return *i64 <= j;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_lte, "b", ".(Long_Integer_Type)")

void *Berry_Integer_Type_To_Bytes(int64_t *i64, size_t *len)
{
    if (len)
    {
        *len = sizeof(int64_t);
    }
    return i64;
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_To_Bytes, "&", ".")

void Berry_Integer_Type_From_Bytes(int64_t *i64, uint8_t *ptr, size_t len, int32_t idx)
{
    if (idx < 0)
    {
        idx = len + idx;
    } // support negative index, counting from the end
    if (idx < 0)
    {
        idx = 0;
    } // sanity check
    if (idx > len)
    {
        idx = len;
    }
    uint32_t usable_len = len - idx;
    if (usable_len > sizeof(int64_t))
    {
        usable_len = sizeof(int64_t);
    }
    *i64 = 0; // start with 0
    memmove(i64, ptr + idx, usable_len);
}
BE_FUNC_CTYPE_DECLARE(Berry_Integer_Type_From_Bytes, "", ".(bytes)~[i]")

extern "C"
{
    #include "../generate/be_fixed_be_class_Berry_Long_Integer_Type.h"
}

/* @const_object_info_begin
class be_class_Berry_Long_Integer_Type (scope:global, name:Long_Integer_Type) {
  _p, var
  init, ctype_func(Berry_Integer_Type_init)
  deinit, ctype_func(Berry_Integer_Type_deinit)
  Set, ctype_func(Berry_Integer_Type_Set)
  From_Integer, static_ctype_func(Berry_Integer_Type_From_Integer)

  To_String, ctype_func(Berry_Integer_Type_To_String)
  From_String, static_ctype_func(Berry_Integer_Type_From_String)
  To_Integer, ctype_func(Berry_Integer_Type_To_Integer)

  +, ctype_func(Berry_Integer_Type_add)
  -, ctype_func(Berry_Integer_Type_sub)
  *, ctype_func(Berry_Integer_Type_mul)
  /, ctype_func(Berry_Integer_Type_div)
  %, ctype_func(Berry_Integer_Type_mod)
  -*, ctype_func(Berry_Integer_Type_neg)
  ==, ctype_func(Berry_Integer_Type_equals)
  !=, ctype_func(Berry_Integer_Type_nequals)
  >, ctype_func(Berry_Integer_Type_gt)
  >=, ctype_func(Berry_Integer_Type_gte)
  <, ctype_func(Berry_Integer_Type_lt)
  <=, ctype_func(Berry_Integer_Type_lte)

  To_Bytes, ctype_func(Berry_Integer_Type_To_Bytes)
  From_Bytes, ctype_func(Berry_Integer_Type_From_Bytes)
}
@const_object_info_end */
