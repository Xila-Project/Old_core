///
/// @file Roller.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Roller.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type& Roller_Class::Class = lv_roller_class;

// - Methods

// - - Constructors / destructors

Roller_Class::Roller_Class() : Object_Class()
{
}

Roller_Class::Roller_Class(const Object_Class& Object_To_Copy) : Object_Class(Object_To_Copy)
{
}

// - - Manipulation

void Roller_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_roller_create(Parent_Object.Get_Pointer());
    }
}

// - - Setters

bool Roller_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class( &lv_roller_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Roller_Class::Set_Options(const char *Options, Mode_Type Mode)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_roller_set_options(Get_Pointer(), Options, static_cast<lv_roller_mode_t>(Mode));
}

void Roller_Class::Set_Selected(uint16_t Index, bool Animated)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
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
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_roller_set_visible_row_count(Get_Pointer(), Count);
}

// - - Getters

uint16_t Roller_Class::Get_Option_Count()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_roller_get_option_cnt(Get_Pointer());
}

const char *Roller_Class::Get_Options()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_roller_get_options(Get_Pointer());
}

uint16_t Roller_Class::Get_Selected()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_roller_get_selected(Get_Pointer());
}

void Roller_Class::Get_Selected_String(String_Type &String)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_roller_get_selected_str(Get_Pointer(), static_cast<char *>(String), String.Get_Size());
}