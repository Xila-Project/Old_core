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
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

std::list<Parent_Window_Class*> Parent_Window_Class::List;

/// @brief Custom LVGL class for Parent window (almost identical to object class).
const Class_Type Parent_Window_Class::Class = Window_Class::Class;

// - Methods

// - - Constructors / destructors

Parent_Window_Class::Parent_Window_Class() : Window_Class()
{
}

Parent_Window_Class::Parent_Window_Class(Parent_Window_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy.Get_Pointer());
    Owner_Software = Object_To_Copy.Get_Owner_Software();
    Header = Object_To_Copy.Header;
    Body = Object_To_Copy.Body;
    Title_Label = Object_To_Copy.Title_Label;
    Close_Button = Object_To_Copy.Close_Button;
    Minimize_Button = Object_To_Copy.Minimize_Button;
}

Parent_Window_Class::Parent_Window_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy.Get_Pointer());
}

void Parent_Window_Class::Create(const Software_Type *Owner_Module)
{
    if (Owner_Module == NULL)
    {
        return;
    }
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(lv_scr_act());
        this->LVGL_Object_Pointer->class_p = &Parent_Window_Class::Class;
    }

    this->Owner_Software = Owner_Module;
    this->Set_Interface();

    Log_Verbose("Parent_Window", "Parent win LVGL pointer : %p", this->LVGL_Object_Pointer);

    List.push_back(this);
}

void Parent_Window_Class::Delete()
{
    if (!this->Is_Valid())
    {
        return;
    }
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_obj_del_async(Get_Pointer());
    List.remove(this);
}

Parent_Window_Class* Parent_Window_Class::Get_User_Parent_Window(const Accounts_Types::User_Type *User)
{
    uint8_t i = 0;
    Log_Verbose("Parent_Window", "Get_User_Parent_Window for user : %s", (const char*)User->Name);
    if (User != NULL)
    {
        for (auto &Parent_Window : List)
        {
            Log_Verbose("Parent_Window", "- i : %u", i++);
            Log_Verbose("Parent window", "- Owner_Software->Get_Owner_User() : %s", (const char*)Parent_Window->Owner_Software->Get_Owner_User()->Name);

            if (Parent_Window->Owner_Software->Get_Owner_User() == User)
            {
                Log_Verbose("Parent_Window", "- Found");
                return Parent_Window;
            }
        }
    }
    return NULL;
}
