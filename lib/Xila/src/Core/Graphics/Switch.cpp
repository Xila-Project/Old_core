///
 /// @file Switch.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 14-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #include "Core/Graphics/Switch.hpp"
 #include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type& Switch_Class::Class = lv_switch_class;

// - Methods

// - - Constructors / Destructors

Switch_Class::Switch_Class() : Object_Class()
{
}

Switch_Class::Switch_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy);
}

// - - Manipulation

void Switch_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_switch_create(Parent_Object);
    }
}

// - - Setters

bool Switch_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
     if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class( &lv_switch_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}