///
/// @file Parent_Window.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 27-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Graphics/Window.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

/// @brief Custom LVGL class for Parent window (almost identical to object class).
const Class_Type Parent_Window_Class::Class = Window_Class::Class;

// - Methods

// - - Constructors / destructors

Parent_Window_Class::Parent_Window_Class() : Window_Class()
{
}

Parent_Window_Class::Parent_Window_Class(const Object_Class &Object_To_Copy) : Window_Class(Object_To_Copy)
{
}

void Parent_Window_Class::Create(const Software_Type *Owner_Module)
{
    if (Owner_Module == NULL)
    {
        return;
    }
    {
        Auto_Semaphore_Class Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(lv_scr_act());
        this->LVGL_Object_Pointer->class_p = &Parent_Window_Class::Class;
    }
    this->Owner_Software = Owner_Software;
    this->Set_Interface();
}

Parent_Window_Class Parent_Window_Class::Get_User_Parent_Window(const Accounts_Types::User_Type *User)
{
    for (uint8_t i = 0; i < Graphics.Get_Screen().Get_Child_Count(); i--)
    {
        Parent_Window_Type Parent_Window = Graphics.Get_Screen().Get_Child(i);
        if (Parent_Window.Is_Valid())
        {
            if (Parent_Window.Owner_Software->Get_Owner_User() == User)
            {
                return Parent_Window;
            }
        }
    }
    return Parent_Window_Class();
}
