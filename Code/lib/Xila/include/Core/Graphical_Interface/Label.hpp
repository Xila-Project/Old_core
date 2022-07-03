///
 /// @file Label.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 10-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef LABEL_HPP_INCLUDED
 #define LABEL_HPP_INCLUDED

#include "Arduino.h"
#include "lvgl.h"

 #define Class Xila_Class::Display_Class::Label_Class

// -- Methods

// -- Action methods -- //

inline void Class::Insert_Text(uint32_t Position, const char* Text)
{
    lv_label_ins_text(Get_Pointer(), Position, Text);
}

inline void Class::Cut_Text(uint32_t Position, uint32_t Length)
{
    lv_label_cut_text(Get_Pointer(), Position, Length);
}

inline bool Class::Is_Char_Under_Position(Point_Type* Position)
{
    return lv_label_is_char_under_pos(Get_Pointer(), Position);
}

// -- Setters -- //

inline void Class::Set_Text(const char* Text)
{
    lv_label_set_text(Get_Pointer(), Text);
}

inline void Class::Set_Text_Format(const char* Format, ...)
{
    lv_label_set_text_fmt(Get_Pointer(), Format, ...);
}

inline void Class::Set_Text_Static(const char* Format)
{
    lv_label_set_text_static(Get_Pointer(), Format);
}

inline void Class::Set_Long_Mode(Long_Mode_Type Long_Mode)
{
    lv_label_set_long_mode(Get_Pointer(), Long_Mode);
}

inline void Class::Set_Recolor(bool Recolor)
{
    lv_label_set_recolor(Get_Pointer(), Recolor);
}

inline void Class::Set_Selection_Star(uint32_t Index)
{
    lv_label_set_text_sel_start(Get_Pointer(), Index);
}

inline void Class::Set_Selection_End(uint32_t Index)
{
    lv_label_set_text_sel_end(Get_Pointer(), Index);
}

// -- Getters -- //

inline char* Class::Get_Text()
{
    return lv_label_get_text(Get_Pointer());
}

inline Long_Mode_Type Class::Get_Long_Mode()
{
    return lv_label_get_long_mode(Get_Pointer());
}

inline bool Get_Recolor()
{
    return lv_label_get_recolor(Get_Pointer());
}

inline void Class::Get_Letter_Position(uint32_t Index, Point_Type* Position)
{
    return lv_label_get_letter_pos(Get_Pointer(), Index, Position);
}

inline void Class::Get_Letter_On(Point_Type* Position)
{
    return lv_label_get_letter_on(Get_Pointer(), Position);   
}

inline uint32_t Class::Get_Selection_Start()
{
    return lv_label_get_text_selection_start(Get_Pointer());
}

inline uint32_t Class::Get_Selection_End()
{
    return lv_label_get_text_selection_end(Get_Pointer());
}

#undef Class

 #endif