///
/// @file Keyboard.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 11-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Keyboard.hpp"

using namespace Xila_Namespace;

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Keyboard_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_keyboard_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Keyboard_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
     if (Get_Pointer() == NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_keyboard_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Keyboard_Class::Set_Map(Mode_Type Mode, const char* Map[], const Button_Matrix_Class::Control::Type Control_Map[])
{
    lv_keyboard_set_map(Get_Pointer(), Mode, Map, Control_Map);
}

void Keyboard_Class::Set_Mode(Mode_Type Mode)
{
    lv_keyboard_set_mode(Get_Pointer(), Mode);
}

void Keyboard_Class::Set_Pop_Overs(bool Enabled)
{
    lv_keyboard_set_popovers(Get_Pointer(), Enabled);
}

void Keyboard_Class::Set_Text_Area(Text_Area_Class& Text_Area)
{
    lv_keyboard_set_textarea(Get_Pointer(), Text_Area.Get_Pointer());
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

const char* Keyboard_Class::Get_Button_Text(uint16_t Button_Identifier)
{
    return lv_keyboard_get_btn_text(Get_Pointer(), Button_Identifier);
}

const char** Keyboard_Class::Get_Map_Array()
{
    return lv_keyboard_get_map_array(Get_Pointer());
}

Keyboard_Class::Mode_Type Keyboard_Class::Get_Mode()
{
    return lv_keyboard_get_mode(Get_Pointer());
}

uint16_t Keyboard_Class::Get_Selected_Button()
{
    return lv_keyboard_get_selected_btn(Get_Pointer());
}

Text_Area_Class Keyboard_Class::Get_Text_Area()
{
    Text_Area_Class Text_Area;
    Text_Area.Set_Pointer(lv_keyboard_get_textarea(Get_Pointer()));
    return Text_Area;
}

