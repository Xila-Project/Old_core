///
/// @file Calendar.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Calendar.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Calendar_Class::Create(Object_Class &Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_calendar_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Calendar_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_calendar_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Calendar_Class::Set_Days_Names(const char** Day_Names)
{
    lv_calendar_set_day_names(Get_Pointer(), Day_Names);
}

void Calendar_Class::Set_Highlighted_Dates(Date_Type* Date, uint16_t Number)
{
    lv_calendar_set_highlighted_dates(Get_Pointer(), Date, Number);
}

void Calendar_Class::Set_Showed_Date(uint32_t Year, uint32_t Month)
{
    lv_calendar_set_showed_date(Get_Pointer(), Year, Month);
}

void Calendar_Class::Set_Today_Date(uint32_t Year, uint32_t Month, uint32_t Day)
{
    lv_calendar_set_today_date(Get_Pointer(), Year, Month, Day);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

Button_Matrix_Class Calendar_Class::Get_Button_Matrix()
{
    Button_Matrix_Class Button_Matrix;
    Button_Matrix.Set_Pointer(lv_calendar_get_btnmatrix(Get_Pointer()));
    return Button_Matrix;
}

Calendar_Class::Date_Type* Calendar_Class::Get_Highlighted_Dates()
{
    return lv_calendar_get_highlighted_dates(Get_Pointer());
}

uint16_t Calendar_Class::Get_Highlighted_Dates_Number()
{
    return lv_calendar_get_highlighted_dates_num(Get_Pointer());
}

bool Calendar_Class::Get_Pressed_Date(Date_Type* Date)
{
    if (lv_calendar_get_pressed_date(Get_Pointer(), Date) == LV_RES_INV)
    {
        return false;
    }
    return true;
}

const Calendar_Class::Date_Type* Calendar_Class::Get_Showed_Dates()
{
    return lv_calendar_get_showed_date(Get_Pointer());
}

const Calendar_Class::Date_Type* Calendar_Class::Get_Today_Date()
{
    return lv_calendar_get_today_date(Get_Pointer());
}
