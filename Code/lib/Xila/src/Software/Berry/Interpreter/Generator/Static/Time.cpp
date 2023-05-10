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

int Berry_Time_Type_Get_Hours(Time_Type* Time)
{
    return Time->Get_Hours();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Hours, "i", ".");

int Berry_Time_Type_Get_Minutes(Time_Type* Time)
{
    return Time->Get_Minutes();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Minutes, "i", ".");

int Berry_Time_Type_Get_Seconds(Time_Type* Time)
{
    return Time->Get_Seconds();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Seconds, "i", ".");

int Berry_Time_Type_Get_Milliseconds(Time_Type* Time)
{
    return Time->Get_Milliseconds();
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Get_Milliseconds, "i", ".");

void Berry_Time_Type_Set_Hours(Time_Type* Time, int Hour)
{
    Time->Set_Hours(Hour);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Hours, "", ".i");

void Berry_Time_Type_Set_Minutes(Time_Type* Time, int Minute)
{
    Time->Set_Minutes(Minute);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Minutes, "", ".i");

void Berry_Time_Type_Set_Seconds(Time_Type* Time, int Second)
{
    Time->Set_Seconds(Second);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Seconds, "", ".i");

void Berry_Time_Type_Set_Milliseconds(Time_Type* Time, int Milliseconds)
{
    Time->Set_Milliseconds(Milliseconds);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Milliseconds, "", ".i");

void Berry_Time_Type_Set_Value(Time_Type* Time, int Hour, int Minute, int Second, int Milliseconds)
{
    Time->Set(Hour, Minute, Second, Milliseconds);
}
BE_FUNC_CTYPE_DECLARE(Berry_Time_Type_Set_Value, "", ".iiii");

/*@const_object_info_begin
class be_class_Berry_Time_Type(scope:global, name:Time_Type)
{
    _p, var
    init, ctype_func(Berry_Time_Type_Initialize)
    deinit, ctype_func(Berry_Time_Type_Deinitialize)
    Get_Hours, ctype_func(Berry_Time_Type_Get_Hours)
    Get_Minutes, ctype_func(Berry_Time_Type_Get_Minutes)
    Get_Seconds, ctype_func(Berry_Time_Type_Get_Seconds)
    Get_Milliseconds, ctype_func(Berry_Time_Type_Get_Milliseconds)
    Set_Hours, ctype_func(Berry_Time_Type_Set_Hours)
    Set_Minutes, ctype_func(Berry_Time_Type_Set_Minutes)
    Set_Seconds, ctype_func(Berry_Time_Type_Set_Seconds)
    Set_Milliseconds, ctype_func(Berry_Time_Type_Set_Milliseconds)
}
@const_object_info_end
*/

extern "C"
{
    #include "../generate/be_fixed_be_class_Berry_Time_Type.h"
}