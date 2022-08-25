///
/// @file Tabs.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Tabs.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Tabs_Class::Create(Object_Class &Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_tabview_create(Parent_Object.Get_Pointer()));
    }

}

void Tabs_Class::Add_Tab(const char *Name)
{
    lv_tabview_add_tab(Get_Pointer(), Name);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Tabs_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_tabview_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Tabs_Class::Set_Active_Tab(uint16_t Identifier, bool Animation)
{
    if (Animation)
    {
        lv_tabview_set_act(Get_Pointer(), Identifier, LV_ANIM_ON);
    }
    else
    {
        lv_tabview_set_act(Get_Pointer(), Identifier, LV_ANIM_OFF);
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

Object_Class Tabs_Class::Get_Content()
{
    Object_Class Object;
    Object.Set_Pointer(lv_tabview_get_content(Get_Pointer()));
    return Object;
}

uint16_t Tabs_Class::Get_Tab_Active()
{
    return lv_tabview_get_tab_act(Get_Pointer());
}

Object_Class Tabs_Class::Get_Tab_Buttons()
{
    Button_Class Button;
    Button.Set_Pointer(lv_tabview_get_tab_btns(Get_Pointer()));
    return Button;
}