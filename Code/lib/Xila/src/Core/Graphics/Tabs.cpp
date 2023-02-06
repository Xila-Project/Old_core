///
/// @file Tabs.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Tabs.hpp"

using namespace Xila_Namespace;

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Tabs_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Set_Pointer(lv_tabview_create(Parent_Object.Get_Pointer(), static_cast<lv_dir_t>(Direction_Type::Top), 20));
    }

}

void Tabs_Class::Create(Object_Class Parent_Object, Direction_Type Direction, Coordinate_Type Size)
{
    if (Parent_Object)
    {
        Set_Pointer(lv_tabview_create(Parent_Object.Get_Pointer(), static_cast<lv_dir_t>(Direction), Size));
    }
}

Object_Class Tabs_Class::Add_Tab(const char *Name)
{
    Object_Class Object;
    Object.Set_Pointer(lv_tabview_add_tab(Get_Pointer(), Name));
    return Object;
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Tabs_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
     if (Get_Pointer() != NULL)
    {
        return false;
    }
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

Button_Class Tabs_Class::Get_Tab_Buttons()
{
    Button_Class Button;
    Button.Set_Pointer(lv_tabview_get_tab_btns(Get_Pointer()));
    return Button;
}