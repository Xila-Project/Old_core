///
/// @file List.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 14-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/List.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void List_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Set_Pointer(lv_list_create(Parent_Object.Get_Pointer()));
    }
}

Button_Class List_Class::Add_Button(const char* Icon, const char* Text)
{
    Button_Class Button;
    Button.Set_Pointer(lv_list_add_btn(Get_Pointer(), Icon, Text));
    return Button;
}

Label_Class List_Class::Add_Text(const char* Text)
{
    Label_Class Label;
    Label.Set_Pointer(lv_list_add_text(Get_Pointer(), Text));
    return Label;
}


// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool List_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
     if (Get_Pointer() != NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_list_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

const char* List_Class::Get_Button_Text(Button_Class& Button)
{ Graphics.Take_Semaphore_Auto();
    return lv_list_get_btn_text(Get_Pointer(), Button.Get_Pointer());
}