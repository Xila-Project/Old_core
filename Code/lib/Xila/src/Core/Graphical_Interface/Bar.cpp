///
/// @file Bar.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Bar.hpp"


// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Bar_Class::Create(Object_Class& Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_bar_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Bar_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (LVGL_Object_Pointer == NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_bar_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Bar_Class::Set_Value(int32_t Value, bool Enable_Animation)
{
    if (Enable_Animation)
    {
        lv_bar_set_value(Get_Pointer(), Value, LV_ANIM_ON);
    }
    else
    {
        lv_bar_set_value(Get_Pointer(), Value, LV_ANIM_OFF);
    }
    
}

void Bar_Class::Set_Start_Value(int32_t Start_Value, bool Enable_Animation)
{
    if (Enable_Animation)
    {
        lv_bar_set_start_value(Get_Pointer(), Start_Value, LV_ANIM_ON);
    }
    else
    {
        lv_bar_set_start_value(Get_Pointer(), Start_Value, LV_ANIM_OFF);
    }
}

void Bar_Class::Set_Range(int32_t Minimum_Value, int32_t Maximum_Value)
{
    lv_bar_set_range(Get_Pointer(), Minimum_Value, Maximum_Value);
}

void Bar_Class::Set_Mode(Mode_Type Mode)
{
    lv_bar_set_mode(Get_Pointer(), Mode);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

int32_t Bar_Class::Get_Value()
{
    return lv_bar_get_value(Get_Pointer());
}

int32_t Bar_Class::Get_Start_Value()
{
    return lv_bar_get_start_value(Get_Pointer());
}

int32_t Bar_Class::Get_Minimum_Value()
{
    return lv_bar_get_min_value(Get_Pointer());
}

int32_t Bar_Class::Get_Maximum_Value()
{
    return lv_bar_get_max_value(Get_Pointer());
}

Bar_Class::Mode_Type Bar_Class::Get_Mode()
{
    return lv_bar_get_mode(Get_Pointer());
}