///
 /// @file Display.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 06-04-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#include "Arduino.h"

#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

inline Xila_Class::Create_Object(Xila_Class::Object Parent_Object, Xila_Class::Object Copy)
{
    return lv_obj_create(Parent_Object, Copy);
}

inline Xila_Class::Delete_Object(Xila_Class::Object Object)
{
    lv_obj_del(Object);
}

inline Xila_Class::Clean_Object(Xila_Class::Object Object)
{
    lv_obj_clean(Object);
}

inline Xila_Class::Set_Object_Position(Xila_Class::Object Object, Coordinates X, Coordinates Y)
{
    if (X != Keep)
    {
        lv_obj_set_x(Object, X);
    }
    else if (Y != Keep)
    {
        lv_obj_set_y(Object, Y);
    }
}

inline Xila_Class::Set_Object_Size(Xila_Class::Object Object, Coordinates Width, Coordinates Height, char Fit)
{
    switch (Fit)
    {
    case 'M':
    case 'm':
        if (Width != Keep)
        {
            lv_obj_set_width_margin(Object, Width);
        }
        else if (Height != Keep)
        {
            lv_obj_set_height_margin(Object, Height);
        }
        break;
    case 'P':
    case 'p':
        if (Width != Keep)
        {
            lv_obj_set_width_fit(Object, Width);
        }
        else if (Height != Keep)
        {
            lv_obj_set_height_fit(Object, Height);
        }
    default:
        if (Width != Keep)
        {
            lv_obj_set_width(Object, Width);
        }
        else if (Height != Keep)
        {
            lv_obj_set_height(Object, Height);
        }
        break;
    }  
}

inline uint16_t Xila_Class::Display_Class::Get_Horizontal_Definition()
{
    return Display_Horizontal_Definition;
}

inline uint16_t Xila_Class::Display_Class::Get_Vertical_Definition()
{
    return Display_Vertical_Definition;
}

inline State Xila_Class::Display_Class::Get_Object_Visibility(Xila_Class::Object Object)
{
    if (lv_obj_is_visible(Object))
    {
        return Visible;
    }
    else
    {
        return Hidden;
    }
}


inline uint8_t Xila_Class::Display_Class::Get_State()
{
    return State;
}

inline void Xila_Class::Display_Class::Set_State(uint8_t State)
{
    this->State = State;
}



#endif