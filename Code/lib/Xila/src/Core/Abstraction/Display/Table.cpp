///
 /// @file Table.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 10-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #include "Core/Core.hpp"

 #define Class Xila_Class::Display_Class::Table_Class

 Class::Table_Class(const Object_Type& Parent_Object) :
{
    LVGL_Object_Pointer = lv_create_table(Parent_Object.Get_Pointer());
}