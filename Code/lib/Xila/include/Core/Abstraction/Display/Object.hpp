///
 /// @file Object.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 04-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #include "Arduino.h"

 #ifndef OBJECT_HPP_INCLUDED
 #define OBJECT_HPP_INCLUDED

#define Class Xila_Class::Display_Class::Object_Class // Shortcut

inline Class::Create(Xila_Class::Object Parent_Object, Xila_Class::Object Copy)
{
    return lv_obj_create(Parent_Object, Copy);
}

inline Class::Delete(Xila_Class::Object Object)
{
    lv_obj_del(Object);
}

inline Class::Clean(Xila_Class::Object Object)
{
    lv_obj_clean(Object);
}

inline Class::Set_Position(Xila_Class::Object Object, Coordinates X, Coordinates Y)
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

inline Class::Set_Size(Xila_Class::Object Object, Coordinates Width, Coordinates Height, char Fit)
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


inline void Class::Set_Alignment(Xila_Class::Object Object, Alignment Align)
{
    lv_obj_set_align(Object, Align);
}

 #endif