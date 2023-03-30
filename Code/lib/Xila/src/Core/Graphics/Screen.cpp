/// @file Screen.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 30-03-2023
///
/// @copyright Copyright (c) 2023

#include "Core/Graphics/Screen.hpp"
#include "Core/Graphics/Graphics.hpp"
#include "Core/Software/Software.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

std::list<Screen_Class *> Screen_Class::List;

const Class_Type Screen_Class::Class = {
    .base_class = &lv_obj_class,
    .constructor_cb = lv_obj_class.constructor_cb,
    .destructor_cb = lv_obj_class.destructor_cb,
    .event_cb = lv_obj_class.event_cb,
    .width_def = lv_obj_class.width_def,
    .height_def = lv_obj_class.height_def,
    .editable = lv_obj_class.editable,
    .group_def = lv_obj_class.group_def,
    .instance_size = sizeof(lv_obj_t),
};

// - Methods

// - - Constructors / destructors

Screen_Class::Screen_Class() : Object_Class()
{
}

Screen_Class::Screen_Class(const Software_Type *Owner_Software)
{
    Log_Verbose("Screen", "Owner_Software : %p", Owner_Software);
    this->Create(Owner_Software);
}

Screen_Class::Screen_Class(const Object_Class &Object_To_Copy)
{
    if (Set_Pointer(Object_To_Copy.Get_Pointer()))
        this->Set_User_Data(Object_To_Copy.Get_User_Data());
    else
        Log_Verbose("Screen", "Invalid object");
}

// - - Manipulation

void Screen_Class::Create(const Software_Type *Owner_Software)
{
    Log_Trace();
    if (Owner_Software != NULL)
    {
        {
            
            Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
            this->LVGL_Object_Pointer = lv_obj_create(NULL);
            
            Log_Trace();
            
            if (this->LVGL_Object_Pointer == NULL)
            {
                Log_Trace();
                return;
            }

            this->LVGL_Object_Pointer->class_p = &Screen_Class::Class;
        }

        Log_Trace();

        this->Set_User_Data(const_cast<Software_Type *>(Owner_Software));

        Log_Trace();

        this->List.push_back(this);
    }
}

void Screen_Class::Delete()
{
    if (!this->Is_Valid())
        return;

    {
        Auto_Semaphore_Class Semaphore = Graphics.Take_Semaphore_Auto();
        lv_obj_del_async(Get_Pointer());
    }

    this->List.remove(this);
}

void Screen_Class::Load()
{
    if (this->Is_Valid())
        lv_scr_load(Get_Pointer());
}

bool Screen_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
        return false;

    Object_Type Object(LVGL_Object_Pointer);


    if (!Object.Check_Class(&Screen_Class::Class))
        return false;

    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

Screen_Type Screen_Class::Get_Active()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return Object_Type(lv_scr_act());
}

Screen_Type Screen_Class::Get_User_Screen(const Accounts_Types::User_Type *User)
{
    if (User == NULL)
        return Screen_Type();

    Software_Type *Owner_Software;

    for (auto& Screen : List)
    {
        Owner_Software = static_cast<Software_Type *>(Screen->Get_User_Data());
     
        if (Owner_Software != NULL && Owner_Software->Get_Owner_User() == User)
            return *Screen;
    }

    return Screen_Type();
}