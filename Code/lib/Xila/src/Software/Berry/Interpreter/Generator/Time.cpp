#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}

using namespace Xila_Namespace;

void* Berry_Time_Type_Initialize(int Hour = 0, int Minute = 0, int Second = 0, int Milliseconds = 0)
{
    return new Time_Type(Hour, Minute, Second, Milliseconds);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Initialize, "+_p", "[iiii");

void Berry_Time_Type_Deinitialize(Time_Type* Time)
{
    delete Time;
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Deinitialize, "", ".");

int Berry_Time_Type_Get_Hour(Time_Type* Time)
{
    return Time->Get_Hour();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Hour, "i", ".");

int Berry_Time_Type_Get_Minute(Time_Type* Time)
{
    return Time->Get_Minute();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Minute, "i", ".");

int Berry_Time_Type_Get_Second(Time_Type* Time)
{
    return Time->Get_Second();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Second, "i", ".");

int Berry_Time_Type_Get_Milliseconds(Time_Type* Time)
{
    return Time->Get_Milliseconds();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Milliseconds, "i", ".");

void Berry_Time_Type_Set_Hour(Time_Type* Time, int Hour)
{
    Time->Set_Hour(Hour);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Hour, "", ".i");

void Berry_Time_Type_Set_Minute(Time_Type* Time, int Minute)
{
    Time->Set_Minute(Minute);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Minute, "", ".i");

void Berry_Time_Type_Set_Second(Time_Type* Time, int Second)
{
    Time->Set_Second(Second);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Second, "", ".i");

void Berry_Time_Type_Set_Milliseconds(Time_Type* Time, int Milliseconds)
{
    Time->Set_Milliseconds(Milliseconds);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Milliseconds, "", ".i");

void Berry_Time_Type_Set(Time_Type* Time, int Hour, int Minute, int Second, int Milliseconds)
{
    Time->Set(Hour, Minute, Second, Milliseconds);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set, "", ".iiii");

/*
@const_object_info_begin
class be_class_Berry_Time_Type(scope:global, name:Time_Type)
{
    _p, var
    init, ctype_func(Berry_Date_Type_Initialize)
    deinit, ctype_func(Berry_Date_Type_Deinitialize)
    Get_Hour, ctype_func(Berry_Date_Type_Get_Hour)
    Get_Minute, ctype_func(Berry_Date_Type_Get_Minute)
    Get_Second, ctype_func(Berry_Date_Type_Get_Second)
    Get_Milliseconds, ctype_func(Berry_Date_Type_Get_Milliseconds)
    Set_Hour, ctype_func(Berry_Date_Type_Set_Hour)
    Set_Minute, ctype_func(Berry_Date_Type_Set_Minute)
    Set_Second, ctype_func(Berry_Date_Type_Set_Second)
    Set_Milliseconds, ctype_func(Berry_Date_Type_Set_Milliseconds)
    Set, ctype_func(Berry_Date_Type_Set)    
}
@const_object_info_end
*/

extern "C"
{
    #include "../generate/be_fixed_be_class_Berry_Date_Type.h"
}