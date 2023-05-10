#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}

using namespace Xila_Namespace;

void* Berry_Date_Type_Initialize(int Day = 0, int Month = 0, int Year = 0)
{
    return new Date_Type(Day, Month, Year);
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Initialize, "+_p", "[iii");

void Berry_Date_Type_Deinitialize(Date_Type* Date)
{
    delete Date;
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Deinitialize, "", ".");

int Berry_Date_Type_Get_Day(Date_Type* Date)
{
    return Date->Get_Day();
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Get_Day, "i", ".");

int Berry_Date_Type_Get_Month(Date_Type* Date)
{
    return Date->Get_Month();
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Get_Month, "i", ".");

int Berry_Date_Type_Get_Year(Date_Type* Date)
{
    return Date->Get_Year();
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Get_Year, "i", ".");

void Berry_Date_Type_Set_Day(Date_Type* Date, int Day)
{
    Date->Set_Day(Day);
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Set_Day, "", "..");

void Berry_Date_Type_Set_Month(Date_Type* Date, int Month)
{
    Date->Set_Month(Month);
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Set_Month, "", "..");

void Berry_Date_Type_Set_Year(Date_Type* Date, int Year)
{
    Date->Set_Year(Year);
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Set_Year, "", "..");

void Berry_Date_Type_Set(Date_Type* Date, int Day, int Month, int Year)
{
    Date->Set(Day, Month, Year);
}
BE_FUNC_CTYPE_DECLARE(Berry_Date_Type_Set, "", "...");


/*
@const_object_info_begin
class be_class_Berry_Date_Type(scope:global, name:Date_Type)
{
    _p, var
    init, ctype_func(Berry_Date_Type_Initialize)
    deinit, ctype_func(Berry_Date_Type_Deinitialize)
    Get_Day, ctype_func(Berry_Date_Type_Get_Day)
    Get_Month, ctype_func(Berry_Date_Type_Get_Month)
    Get_Year, ctype_func(Berry_Date_Type_Get_Year)
    Set_Day, ctype_func(Berry_Date_Type_Set_Day)
    Set_Month, ctype_func(Berry_Date_Type_Set_Month)
    Set_Year, ctype_func(Berry_Date_Type_Set_Year)
    Set, ctype_func(Berry_Date_Type_Set)
}
@const_object_info_end
*/

#include "../generate/be_fixed_be_class_Berry_Date_Type.h"