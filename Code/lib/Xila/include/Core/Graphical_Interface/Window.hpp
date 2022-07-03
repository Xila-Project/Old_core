///
 /// @file Window.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 06-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef WINDOW_HPP_INCLUDED
 #define WINDOW_HPP_INCLUDED

#include "Arduino.h"
#include "lvgl.h"

#define Class Xila_Class::Display_Class::Window_Class

Object_Type Class::Create()
{
    return lv_win_create(Xila_Class::Display_Class::Screen_Class::Get(), NULL);    
}

inline void Class::Set_Title(Object_Type Object_Type, String Title)
{
    lv_win_set_title(Object_Type, Title.c_str());
}



#endif