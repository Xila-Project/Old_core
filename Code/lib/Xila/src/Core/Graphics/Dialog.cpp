///
 /// @file Dialog.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 13-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#include "Core/Graphics/Dialog.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

const Class_Type Dialog_Class::Class = {
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

void Dialog_Class::Create(const Software_Type* Owner_Software)
{
 
 /*   if (Owner_Software == NULL)
    {
        return;
    }

    Screen_Type User_Screen = Screen_Type::Get_User_Screen(Owner_Software->Get_Owner_User());

    if (Parent_Window == NULL)
    {
        return;
    }

    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->Set_Pointer(lv_obj_create(Parent_Window->Get_Pointer()));
        this->LVGL_Object_Pointer->class_p = &Dialog_Class::Class;
    }

    this->Owner_Software = Owner_Software;
    this->Set_Interface();
    this->Set_Size(Percentage(75), Percentage(75));
*/
}

void Dialog_Class::Create(Object_Class Parent_Object)
{
    if (!Parent_Object)
    {
        return;
    }

    this->Set_Pointer(lv_obj_create(Parent_Object.Get_Pointer()));
    this->Set_Interface();
    this->Set_Size(Percentage(75), Percentage(75));
}

bool Dialog_Class::Is_Overlay()
{
    return Overlay;
}

void Dialog_Class::Set_Overlay(bool Enable)
{
    if (Enable)
    {
        Overlay.Create(this->Get_Parent());
        Overlay.Set_Size(Percentage(100), Percentage(100));
        Overlay.Move_Foreground();
        Overlay.Add_Flag(Flag_Type::Clickable);
        this->Move_Foreground();

        Move_Foreground();
    }
    else
    {
        Overlay.Delete();
    }
}