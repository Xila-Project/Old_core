///
/// @file Object.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 05-05-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Core.hpp"

#define Class Xila_Class::Display_Class::Object_Class

Class::Object_Class(Object_Class& Parent_Object)
{
    this.LVGL_Object_Pointer = lv_obj_create(Parent_Object.Get_Pointer());
}

Class::~Object_Class()
{
    Delete();
}


LVGL_Object_Type Class::operator =(const Object_Class Parent_Object)
{
    Parent_Object.set
}


IRAM_ATTR void Class::Event_Handler(Class::Event_Type Event)
{
    


    Xila.Software_Management.Send_Instruction(Xila.Software_Management.);
}

