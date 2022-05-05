///
 /// @file Display.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 06-04-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

#include "Display/Bar.hpp"




inline uint16_t Display_Class::Get_Horizontal_Definition()
{
    return Display_Horizontal_Definition;
}

inline uint16_t Display_Class::Get_Vertical_Definition()
{
    return Display_Vertical_Definition;
}

inline State Display_Class::Get_Object_Visibility(Xila_Class::Object_Type Object_Type)
{
    if (lv_obj_is_visible(Object_Type))
    {
        return Visible;
    }
    else
    {
        return Hidden;
    }
}


inline uint8_t Display_Class::Get_State()
{
    return State;
}

inline void Display_Class::Set_State(uint8_t State)
{
    this->State = State;
}



#endif