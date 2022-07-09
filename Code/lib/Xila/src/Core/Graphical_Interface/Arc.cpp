///
/// @file Arc.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 06-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Arc.hpp"

void Arc_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_arc_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //


// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //
 
bool Arc_Class::Set_Pointer(LVGL_Object_Type *LVGL_Object_Pointer)
{
    if (LVGL_Object_Pointer == NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_arc_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Arc_Class::Set_Angles(uint16_t Start_Angle, uint16_t End_Angle)
{
    lv_arc_set_angles(Get_Pointer(), Start_Angle, End_Angle);
}

void Arc_Class::Set_Background_Angles(uint16_t Start_Angle, uint16_t End_Angle)
{
    lv_arc_set_bg_angles(Get_Pointer(), Start_Angle, End_Angle);
}

void Arc_Class::Set_Start_Angle(uint16_t Start_Angle)
{
    lv_arc_set_start_angle(Get_Pointer(), Start_Angle);
}

void Arc_Class::Set_End_Angle(uint16_t End_Angle)
{
    lv_arc_set_end_angle(Get_Pointer(), End_Angle);
}

void Arc_Class::Set_Background_Start_Angle(uint16_t Start_Angle)
{
    lv_arc_set_bg_start_angle(Get_Pointer(), Start_Angle);
}

void Arc_Class::Set_Background_End_Angle(uint16_t End_Angle)
{
    lv_arc_set_bg_end_angle(Get_Pointer(), End_Angle);
}

void Arc_Class::Set_Rotation(uint16_t Rotation)
{
    lv_arc_set_rotation(Get_Pointer(), Rotation);
}

void Arc_Class::Set_Mode(Arc_Class::Mode_Type Mode)
{
    lv_arc_set_mode(Get_Pointer(), Mode);
}

void Arc_Class::Set_Value(int16_t Value)
{
    lv_arc_set_value(Get_Pointer(), Value);
}

void Arc_Class::Set_Range(int16_t Minimum_Value, int16_t Maximum_Value)
{
    lv_arc_set_range(Get_Pointer(), Minimum_Value, Maximum_Value);
}

void Arc_Class::Set_Change_Rate(uint16_t Rate)
{
    lv_arc_set_change_rate(Get_Pointer(), Rate);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //



uint16_t Arc_Class::Get_Angle_Start()
{
    return lv_arc_get_angle_start(Get_Pointer());
}

uint16_t Arc_Class::Get_Angle_End()
{
    return lv_arc_get_angle_end(Get_Pointer());
}

uint16_t Arc_Class::Get_Background_Angle_Start()
{
    return lv_arc_get_bg_angle_start(Get_Pointer());
}

uint16_t Arc_Class::Get_Background_Angle_End()
{
    return lv_arc_get_bg_angle_end(Get_Pointer());
}

int16_t Arc_Class::Get_Value()
{
    return lv_arc_get_value(Get_Pointer());
}

int16_t Arc_Class::Get_Minimum_Value()
{
    return lv_arc_get_min_value(Get_Pointer());
}

int16_t Arc_Class::Get_Maximum_Value()
{
    return lv_arc_get_max_value(Get_Pointer());
}

Arc_Class::Mode_Type Arc_Class::Get_Mode()
{
    return lv_arc_get_mode(Get_Pointer());
}