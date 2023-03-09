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

// - Attributes

const Class_Type& List_Class::Class = lv_list_class;

// - Methods

// - - Constructors / destructors

List_Class::List_Class(const Object_Class& Object_To_Copy) : Object_Class(Object_To_Copy)
{
}

// - - Manipulation

void List_Class::Create(Object_Class& Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_list_create(Parent_Object.Get_Pointer());
    }
}

Button_Class List_Class::Add_Button(const char* Icon, const char* Text)
{
    lv_obj_t* Button_Pointer;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Button_Pointer = lv_list_add_btn(Get_Pointer(), Icon, Text);
    }
    return Button_Type(Object_Type(Button_Pointer));
}

Label_Class List_Class::Add_Text(const char* Text)
{
    lv_obj_t* Label_Pointer;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Label_Pointer = lv_list_add_text(Get_Pointer(), Text);
    }
    return List_Class(Object_Type(Label_Pointer));
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
    if (!Has_Class( &lv_list_class))
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
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_list_get_btn_text(Get_Pointer(), Button.Get_Pointer());
}