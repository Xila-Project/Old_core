///
/// @file Button_Matrix.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Button_Matrix.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Button_Matrix_Class::Class = lv_btnmatrix_class;

// - Methods

// - - Constructors / destructors

Button_Matrix_Class::Button_Matrix_Class() : Object_Class()
{
}

Button_Matrix_Class::Button_Matrix_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy.Get_Pointer());
}

// - - Manipulation

void Button_Matrix_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Auto_Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_btnmatrix_create(Parent_Object.Get_Pointer());
    }
}

void Button_Matrix_Class::Clear_Button_Control(uint16_t Button_Identifier, Control::Type Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_clear_btn_ctrl(Get_Pointer(), Button_Identifier, Control);
}

void Button_Matrix_Class::Clear_All_Buttons_Control(Control::Type Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_clear_btn_ctrl_all(Get_Pointer(), Control);
}

bool Button_Matrix_Class::Has_Button_Control(uint16_t Button_Identifier, Control::Type Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_btnmatrix_has_btn_ctrl(Get_Pointer(), Button_Identifier, Control);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Button_Matrix_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&lv_btnmatrix_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Button_Matrix_Class::Set_Button_Width(uint16_t Button_Identifier, uint8_t Width)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_set_btn_width(Get_Pointer(), Button_Identifier, Width);
}

void Button_Matrix_Class::Set_Map(const char **Map)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_set_map(Get_Pointer(), Map);
}

void Button_Matrix_Class::Set_Control_Map(Control::Type *Map)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_set_ctrl_map(Get_Pointer(), Map);
}

void Button_Matrix_Class::Set_Selected_Button(uint16_t Button_Identifier)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_set_selected_btn(Get_Pointer(), Button_Identifier);
}

void Button_Matrix_Class::Set_Button_Control(uint16_t Button_Identifier, Control::Type Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_set_btn_ctrl(Get_Pointer(), Button_Identifier, Control);
}

void Button_Matrix_Class::Set_Button_Control_All(Control::Type Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_set_btn_ctrl_all(Get_Pointer(), Control);
}

void Button_Matrix_Class::Set_One_Checked(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_btnmatrix_set_one_checked(Get_Pointer(), Enabled);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

const char **Button_Matrix_Class::Get_Map()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_btnmatrix_get_map(Get_Pointer());
}

uint16_t Button_Matrix_Class::Get_Selected_Button()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_btnmatrix_get_selected_btn(Get_Pointer());
}

const char *Button_Matrix_Class::Get_Button_Text(uint16_t Button_Identifier)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_btnmatrix_get_btn_text(Get_Pointer(), Button_Identifier);
}

bool Button_Matrix_Class::Get_One_Checked()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_btnmatrix_get_one_checked(Get_Pointer());
}

bool Button_Matrix_Class::Get_Popovers()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_btnmatrix_get_popovers(Get_Pointer());
}