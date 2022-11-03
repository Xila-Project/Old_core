///
/// @file Button.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Button.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Button_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_btn_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Button_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
     if (Get_Pointer() == NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_btn_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}