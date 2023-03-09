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

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

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