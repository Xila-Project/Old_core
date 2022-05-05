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

inline Class::Create(Xila_Class::Object_Type Parent_Object, Xila_Class::Object_Type Copy)
{
    return lv_obj_create(Parent_Object, Copy);
}

inline Class::Delete(Xila_Class::Object_Type Object_Type)
{
    lv_obj_del(Object_Type);
}

inline Class::Clean(Xila_Class::Object_Type Object_Type)
{
    lv_obj_clean(Object_Type);
}

inline Class::Set_Position(Xila_Class::Object_Type Object_Type, Coordinates X, Coordinates Y)
{
    if (X != Keep)
    {
        lv_obj_set_x(Object_Type, X);
    }
    else if (Y != Keep)
    {
        lv_obj_set_y(Object_Type, Y);
    }
}

inline Class::Set_Size(Xila_Class::Object_Type Object_Type, Coordinates Width, Coordinates Height, char Fit)
{
    switch (Fit)
    {
    case 'M':
    case 'm':
        if (Width != Keep)
        {
            lv_obj_set_width_margin(Object_Type, Width);
        }
        else if (Height != Keep)
        {
            lv_obj_set_height_margin(Object_Type, Height);
        }
        break;
    case 'P':
    case 'p':
        if (Width != Keep)
        {
            lv_obj_set_width_fit(Object_Type, Width);
        }
        else if (Height != Keep)
        {
            lv_obj_set_height_fit(Object_Type, Height);
        }
    default:
        if (Width != Keep)
        {
            lv_obj_set_width(Object_Type, Width);
        }
        else if (Height != Keep)
        {
            lv_obj_set_height(Object_Type, Height);
        }
        break;
    }  
}


inline void Class::Set_Alignment(Xila_Class::Object_Type Object_Type, Alignment Align)
{
    lv_obj_set_align(Object_Type, Align);
}

inline void Class::Set_User_Data(Object_Type Object, void* User_Data)
{
    lv_obj_set_user_data(Object, User_Data);
}

inline void* Class::Get_User_Data(Object_Type Object)
{
    lv_obj_get_user_data(Object);
}

inline uint16_t Class::Get_Identifier(Object_Type Object)
{
    if (Get_User_Data(Object) != NULL)
    {
        return *(uint16_t*)Get_User_Data(Object);
    }
    else
    {
        return 0;
    }
}

inline Object_Type Get_Child(Object_Type Parent_Object, uint16_t Index)
{
    return lv_obj_get_child(Parent_Object, Index);
}


inline uint16_t Get_Child_Count(Object_Type Parent_Object)
{
    return lv_obj_get_child_count(Parent_Object);
}

inline void Set_Parent(Object_Type Object, Object_Type Parent_Object)
{
    lv_obj_set_parent(Object, Parent_Object);
}

inline void Move_Foreground(Object_Type Object)
{
    lv_obj_move_foreground(Object);
}

inline void Move_Background(Object_Type Object)
{
    lv_obj_move_background(Object);
}

inline void Set_Child_Index(Object_Type Object, uint16_t Index)
{
    
}

 #endif