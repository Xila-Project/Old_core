///
/// @file Roller.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Roller.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Roller_Class::Create(Object_Class &Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_roller_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Roller_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (LVGL_Object_Pointer != NULL)
    {
        return false;
    }
    if (!Has_Class(&lv_roller_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Roller_Class::Set_Options(const char* Options, Mode_Type Mode)
{
    lv_roller_set_options(Get_Pointer(), Options, Mode);
}

void Roller_Class::Set_Selected(uint16_t Index, bool Animated)
{
    if (Animated)
    {
        lv_roller_set_selected(Get_Pointer(), Index, LV_ANIM_ON);
    }
    else
    {
        lv_roller_set_selected(Get_Pointer(), Index, LV_ANIM_OFF);
    }
}

void Roller_Class::Set_Visible_Row_Count(uint8_t Count)
{
    lv_roller_set_visible_row_count(Get_Pointer(), Count);
}



// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

uint16_t Roller_Class::Get_Option_Count()
{
    return lv_roller_get_option_cnt(Get_Pointer());
}

const char *Roller_Class::Get_Options()
{
    return lv_roller_get_options(Get_Pointer());
}

uint16_t Roller_Class::Get_Selected()
{
    return lv_roller_get_selected(Get_Pointer());
}

void Roller_Class::Get_Selected_String(char* Buffer, size_t Size)
{
    return lv_roller_get_selected_str(Get_Pointer(), Buffer, Size);
}