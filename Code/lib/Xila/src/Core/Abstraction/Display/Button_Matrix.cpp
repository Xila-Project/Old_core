///
 /// @file Button_Matrix.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 07-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #include "Core/Core.hpp"

 #define Class Xila_Class::Display_Class::Button_Matrix_Class

Class::Button_Matrix_Class(Object_Type& Parent_Object)
{
    LVGL_Object_Type = lv_btnmatrix_create(Parent_Object.Get_Pointer());
}

 #undef Class