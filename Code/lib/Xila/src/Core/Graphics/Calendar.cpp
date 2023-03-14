///
/// @file Calendar.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Calendar.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Calendar_Class::Class = lv_calendar_class;

// - Methods

// - - Constructors / destructors

Calendar_Class::Calendar_Class() : Object_Class()
{
}

Calendar_Class::Calendar_Class(const Object_Class &Object_To_Copy) : Object_Class(Object_To_Copy)
{
}

// - - Manipulation

void Calendar_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Auto_Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_calendar_create(Parent_Object.Get_Pointer());
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Calendar_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&lv_calendar_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Calendar_Class::Set_Days_Names(const char **Day_Names)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_calendar_set_day_names(Get_Pointer(), Day_Names);
}

void Calendar_Class::Set_Highlighted_Dates(lv_calendar_date_t *Date, uint16_t Number)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_calendar_set_highlighted_dates(Get_Pointer(), Date, Number);
}

void Calendar_Class::Set_Showed_Date(uint32_t Year, uint32_t Month)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_calendar_set_showed_date(Get_Pointer(), Year, Month);
}

void Calendar_Class::Set_Today_Date(Date_Type Date)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_calendar_set_today_date(Get_Pointer(), Date.Get_Year(), Date.Get_Month(), Date.Get_Day());
}

// - - Getters

Button_Matrix_Class Calendar_Class::Get_Button_Matrix()
{
    lv_obj_t *Button_Matrix;

    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Button_Matrix = lv_calendar_get_btnmatrix(Get_Pointer());
    };

    return Button_Matrix_Type(Object_Type(Button_Matrix));
}

lv_calendar_date_t *Calendar_Class::Get_Highlighted_Dates()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_calendar_get_highlighted_dates(Get_Pointer());
}

uint16_t Calendar_Class::Get_Highlighted_Dates_Number()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_calendar_get_highlighted_dates_num(Get_Pointer());
}

bool Calendar_Class::Get_Pressed_Date(Date_Type& Date)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_calendar_date_t* Date_Pointer;
    if (lv_calendar_get_pressed_date(Get_Pointer(), Date_Pointer) == LV_RES_INV)
    {
        return false;
    }
    Date.Set(Date_Pointer->year, Date_Pointer->month, Date_Pointer->day);
    return true;
}

Date_Type Calendar_Class::Get_Showed_Date()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    const lv_calendar_date_t* Date = lv_calendar_get_showed_date(Get_Pointer());
    return Date_Type(Date->year, Date->month, Date->day);;
}

Date_Type Calendar_Class::Get_Today_Date()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    const lv_calendar_date_t* Date = lv_calendar_get_today_date(Get_Pointer());
    return Date_Type(Date->year, Date->month, Date->day);;
}
