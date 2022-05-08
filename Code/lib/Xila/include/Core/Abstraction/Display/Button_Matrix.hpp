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

// -- Action methods -- //

inline void Class::Clear_Button_Control(uint16_t Button_Identifier, Control_Type Control)
{
    lv_btnmatrix_clear_btn_ctrl(Get_Pointer(), Button_Identifier, Control);
}

inline void Class::Clear_All_Buttons_Control(Control_Type Control)
{
    lv_btnmatrix_clear_btn_ctrl_all(Get_Pointer(), Control);
}

inline bool Class::Has_Button_Control(uint16_t Button_Identifier, Control_Type Control)
{
    return lv_btnmatrix_has_btn_ctrl(Get_Pointer(), Button_Identifier, Control);
}

// -- Set attributes values -- //

inline void Class::Set_Width(uint16_t Button_Identifier, uint8_t Width)
{
    lv_btnmatrix_set_btn_width(Get_Pointer(), Button_Identifier, Width);
}

inline void Class::Set_Map(const char* Map[])
{
    lv_btnmatrix_set_map(Get_Pointer(), Map);
}

inline void Class::Set_Control_Map(Control_Type Map[])
{
    lv_btnmatrix_set_ctrl_map(Get_Pointer(), Map);
}

inline void Class::Set_Selected_Button(uint16_t Button_Identifier)
{
    lv_btnmatrix_set_selected_btn(Get_Pointer(), Button_Identifier);
}

inline void Class::Set_Button_Control(uint16_t Button_Identifier, Control_Type Control)
{
    lv_btnmatrix_set_btn_ctrl(Get_Pointer(), Button_Identifier, Control);
}

inline void Class::Set_One_Checked(bool Enabled)
{
    lv_btnmatrix_set_one_checked(Get_Pointer(), Enabled);
}

// -- Get attributes values -- //

inline const char** Class::Get_Map()
{
    return lv_btnmatrix_get_map(Get_Pointer());
}

inline uint16_t Class::Get_Selected_Button()
{
    return lv_btnmatrix_get_selected_btn(Get_Pointer());
}

inline const char** Class::Get_Button_Text(uint16_t Button_Identifier)
{
    return lv_btnmatrix_get_btn_text(Get_Pointer(), Button_Identifier);
}

inline bool Class::Get_One_Checked()
{
    return lv_btnmatrix_get_one_checked(Get_Pointer());
}

#undef
 #endif