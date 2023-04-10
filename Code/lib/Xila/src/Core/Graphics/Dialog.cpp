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
#include "Core/Log/Log.hpp"

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

Dialog_Class::Dialog_Class() : Window_Class()
{
}

Dialog_Class::Dialog_Class(const Object_Class &Object_To_Copy)
{
    if (Object_To_Copy.Get_User_Data() != NULL && Object_To_Copy.Is_Valid() && Set_Pointer(Object_To_Copy.Get_Pointer()))
        Data = static_cast<Data_Type *>(Object_To_Copy.Get_User_Data());
}

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
    if (!Parent_Object.Is_Valid())
        return;
    

    {
        Auto_Semaphore_Class Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(Parent_Object.Get_Pointer());

        if (!Is_Valid())
        {
            Log_Trace();
            return;
        }

        this->LVGL_Object_Pointer->class_p = &Dialog_Class::Class;
    }

    Data = new Data_Type;
    Set_User_Data(Data);
    Data->Owner_Software = NULL;
        
    this->Set_Interface();
    this->Set_Size(Percentage(75), Percentage(75));
    this->Set_Alignment(Alignment_Type::Center);
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