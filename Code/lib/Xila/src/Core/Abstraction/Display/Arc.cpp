///
 /// @file Arc.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 07-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

#include "Core/Core.hpp"

#define Class Xila_Class::Display_Class::Arc_Class  // Shortcut

Class::Arc_Class(Object_Class& Parent_Object)
{
    this.LVGL_Object_Pointer = lv_arc_create(Parent_Object.Get_Pointer());
}


#undef Class