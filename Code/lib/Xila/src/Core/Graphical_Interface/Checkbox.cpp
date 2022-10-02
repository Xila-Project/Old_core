///
/// @file Checkbox.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Checkbox.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Checkbox_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_checkbox_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Checkbox_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
     if (Get_Pointer() == NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_checkbox_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Checkbox_Class::Set_Text(const char *Text)
{
    lv_checkbox_set_text(Get_Pointer(), Text);
}

void Checkbox_Class::Set_Text_Static(const char *Text)
{
    lv_checkbox_set_text_static(Get_Pointer(), Text);
}



// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

const char *Checkbox_Class::Get_Text()
{
    return lv_checkbox_get_text(Get_Pointer());
}