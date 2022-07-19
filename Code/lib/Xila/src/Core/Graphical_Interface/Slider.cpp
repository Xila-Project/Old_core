///
 /// @file Slider.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 12-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #include "Core/Graphical_Interface/Slider.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Slider_Class::Create(Object_Class &Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_slider_create(Parent_Object.Get_Pointer()));
    }
}

bool Slider_Class::Is_Dragged()
{
    return lv_slider_is_dragged(Get_Pointer());
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Slider_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
    if (!lv_obj_has_class(LVGL_Object_Pointer, , &lv_slider_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}


void Slider_Class::Set_Value(int32_t Value, bool Animation)
{
    if (Animation)
    {
        lv_slider_set_value(Get_Pointer(), Value, LV_ANIM_ON);
    }
    else
    {
        lv_slider_set_value(Get_Pointer(), Value, LV_ANIM_OFF);
    }
}

void Slider_Class::Set_Left_Value(int32_t Value, bool Animation)
{
    if (Animation)
    {
        lv_slider_set_left_value(Get_Pointer(), Value, LV_ANIM_ON);
    }
    else
    {
        lv_slider_set_left_value(Get_Pointer(), Value, LV_ANIM_OFF);
    }
}

void Slider_Class::Set_Range(int32_t Minimum_Value, int32_t Maximum_Value)
{
    lv_slider_set_range(Get_Pointer(), Minimum_Value, Maximum_Value);
}

void Slider_Class::Set_Mode(Mode_Type Mode)
{
    lv_slider_set_mode(Get_Pointer(), Mode);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

int32_t Slider_Class::Get_Value()
{
    return lv_slider_get_value(Get_Pointer());
}

int32_t Slider_Class::Get_Left_Value()
{
    return lv_slider_get_left_value(Get_Pointer());
}

int32_t Slider_Class::Get_Minimum_Value()
{
    return lv_slider_get_min_value(Get_Pointer());
}

int32_t Slider_Class::Get_Maximum_Value()
{
    return lv_slider_get_max_value(Get_Pointer());
}

Slider_Class::Mode_Type Slider_Class::Get_Mode()
{
    return lv_slider_get_mode(Get_Pointer());
}
