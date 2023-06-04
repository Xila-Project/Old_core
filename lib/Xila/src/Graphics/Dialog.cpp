///
 /// @file Dialog.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 13-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#include "Graphics/Dialog.hpp"
#include "Graphics/Graphics.hpp"
#include "Log/Log.hpp"

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
    if (Object_To_Copy.Get_User_Data() != NULL && Object_To_Copy.Is_Valid() && Set_Pointer(Object_To_Copy))
        Data = static_cast<Data_Type *>(Object_To_Copy.Get_User_Data());
}

void Dialog_Class::Create(const Softwares_Types::Software_Type* Owner_Software)
{
    if (Owner_Software == NULL)
        return;

    Screen_Type User_Screen = Screen_Type::Get_User_Screen(Owner_Software->Get_Owner_User());

    if (!User_Screen.Is_Valid())
        return;

    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(User_Screen);
        if (!Is_Valid())
            return;
    
        this->LVGL_Object_Pointer->class_p = &Dialog_Class::Class;
    }

    Data = new Data_Type;
    Set_User_Data(Data);
    Data->Owner_Software = Owner_Software;

    this->Set_Interface();
    this->Set_Size(Percentage(70), Percentage(65));
    Data->Header.Set_Style_Radius(5, 0);
    this->Set_Alignment(Alignment_Type::Center);
    this->Set_Minimize_Button_Hidden(true);
    this->Set_Style_Radius(5, 0);

    this->Set_Style_Shadow_Opacity(Opacity_Type::Opacity_20_Percent, 0);
    this->Set_Style_Shadow_Width(50, 0);
    this->Set_Style_Shadow_Color(Color_Type::White, 0);
}

void Dialog_Class::Create(Object_Class Parent_Object)
{
    if (!Parent_Object.Is_Valid())
        return;
    

    {
        Auto_Semaphore_Class Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(Parent_Object);

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
    this->Set_Size(Percentage(65), Percentage(65));
    this->Set_Alignment(Alignment_Type::Center);
    this->Set_Minimize_Button_Hidden(true);
    this->Set_Style_Radius(5, 0);
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
        Overlay.Set_Style_Opacity(0, 0);
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

bool Dialog_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
        return false;
    

    Object_Type Object(LVGL_Object_Pointer);

    if (!Object.Check_Class(&Dialog_Class::Class))
        return false;

    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;

}

void Dialog_Class::Set_State(Window_State_Type State)
{
    switch (State)
    {
    case Window_State_Type::Maximized:
        Clear_Flag(Flag_Type::Hidden);
        Move_Foreground();
        break;
    case Window_State_Type::Minimized:
        Add_Flag(Flag_Type::Hidden);
        break;
    }
}