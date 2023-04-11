///
/// @file Keyboard.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 11-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Keyboard.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Keyboard_Class::Class = lv_keyboard_class;

// - Methods

// - - Constructors / destructors

Keyboard_Class::Keyboard_Class() : Object_Class()
{
}

Keyboard_Class::Keyboard_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy.Get_Pointer());
}

// - - Manipulation

void Keyboard_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_keyboard_create(Parent_Object.Get_Pointer());
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Keyboard_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&lv_keyboard_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Keyboard_Class::Set_Map(Mode_Type Mode, const char *Map[], const Button_Matrix_Class::Control::Type Control_Map[])
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_keyboard_set_map(Get_Pointer(), Mode, Map, Control_Map);
}

void Keyboard_Class::Set_Mode(Mode_Type Mode)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_keyboard_set_mode(Get_Pointer(), Mode);
}

void Keyboard_Class::Set_Pop_Overs(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_keyboard_set_popovers(Get_Pointer(), Enabled);
}

void Keyboard_Class::Set_Text_Area(Text_Area_Class &Text_Area, bool Show)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_keyboard_set_textarea(Get_Pointer(), Text_Area.Get_Pointer());
    if (Show)
        this->Clear_Flag(Flag_Type::Hidden);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

const char *Keyboard_Class::Get_Button_Text(uint16_t Button_Identifier)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_keyboard_get_btn_text(Get_Pointer(), Button_Identifier);
}

const char **Keyboard_Class::Get_Map_Array()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_keyboard_get_map_array(Get_Pointer());
}

Keyboard_Class::Mode_Type Keyboard_Class::Get_Mode()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_keyboard_get_mode(Get_Pointer());
}

uint16_t Keyboard_Class::Get_Selected_Button()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_keyboard_get_selected_btn(Get_Pointer());
}

Text_Area_Class Keyboard_Class::Get_Text_Area()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return Text_Area_Class(Object_Type(lv_keyboard_get_textarea(Get_Pointer())));
}

void Keyboard_Class::Remove_Text_Area(bool Hide)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_keyboard_set_textarea(Get_Pointer(), NULL);
    if (Hide)
        this->Add_Flag(Flag_Type::Hidden);
}