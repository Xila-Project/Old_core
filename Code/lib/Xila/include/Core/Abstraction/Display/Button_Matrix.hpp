///
 /// @file Button_Matrix.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 04-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef BUTTON_MATRIX_HPP_INCLUDED
 #define BUTTON_MATRIX_HPP_INCLUDED

#include "Arduino.h"

#define Class Xila_Class::Display_Class::Button_Matrix_Class

void Clear_Button_Control(uint16_t Button_Identifier, Control_Type Control)
{
    lv_btnmatrix_clear_btn_ctrl(Get_Pointer(), Button_Identifier, Control);
}

inline void Class::Set_Map(const char* Map[])
{
    lv_btnmatrix_set_map(Get_Pointer(), Map);
}

inline void Class::Set_Control_Map(Control_Type Map[])
{
    lv_btnmatrix_set_ctrl_map(Get_Pointer(), Map);
}



#undef
 #endif