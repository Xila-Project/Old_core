///
/// @file Tabs.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Button_Matrix.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Methods

// - - Constructors / Destructors

Tabs_Class::Tabs_Class() : Object_Class()
{
}

Tabs_Class::Tabs_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy);
}

// - - Manipulation

void Tabs_Class::Create(Object_Class Parent_Object)
{
    this->Create(Parent_Object, Direction_Type::Top, 20);
}

void Tabs_Class::Create(Object_Class Parent_Object, Direction_Type Direction, Coordinate_Type Size)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_tabview_create(Parent_Object, static_cast<lv_dir_t>(Direction), Size);
    }
}

Object_Class Tabs_Class::Add_Tab(const char*Name)
{
    lv_obj_t* Tab_Pointer;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Tab_Pointer = lv_tabview_add_tab(Get_Pointer(), Name);
    }
    return Object_Class(Tab_Pointer);
}

void Tabs_Class::Rename_Tab(uint32_t Index, const char*New_name)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_tabview_rename_tab(Get_Pointer(), Index, New_name);
}

// - - Setters

bool Tabs_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&lv_tabview_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Tabs_Class::Set_Active_Tab(uint32_t Identifier, bool Animation)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    if (Animation)
    {
        lv_tabview_set_act(Get_Pointer(), Identifier, LV_ANIM_ON);
    }
    else
    {
        lv_tabview_set_act(Get_Pointer(), Identifier, LV_ANIM_OFF);
    }
}

// - - Getters

Object_Class Tabs_Class::Get_Content()
{
    lv_obj_t *Object_Type;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Object_Type = lv_tabview_get_content(Get_Pointer());
    }
    return Object_Class(Object_Type);
}

uint16_t Tabs_Class::Get_Tab_Active()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_tabview_get_tab_act(Get_Pointer());
}

Button_Matrix_Type Tabs_Class::Get_Tab_Buttons()
{
    lv_obj_t *Button_Pointer;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Button_Pointer = lv_tabview_get_tab_btns(Get_Pointer());
    }
    return Button_Matrix_Type(Object_Type(Button_Pointer));
}

