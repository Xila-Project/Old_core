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

// -- Management -- //

inline Class::Delete()
{
    lv_obj_del(this.Get_Pointer());
}

inline Class::Clean()
{
    lv_obj_clean(this.Get_Pointer());
}

inline Class::Add_Flag(Object_Flag_Type Flag)
{
    lv_obj_add_flag(this.Get_Pointer(), Flag);
}

inline Class::Clear_Flag(Object_Flag_Type Flag)
{
    lv_obj_clear_flag(this.Get_Pointer(), Flag);
}

inline bool Class::Has_Flag(Object_Flag_Type Flag)
{
    return lv_obj_has_flag(this.Get_Pointer(), Flag);
}

inline Class::Add_State(Object_State_Type State)
{
    lv_obj_add_state(this.Get_Pointer(), State);
}

inline Class::Clear_State(Object_State_Type State)
{
    lv_obj_clear_state(this.Get_Pointer(), State);
}

inline void Class::Swap(Object_Class Object_To_Swap_With)
{
    lv_obj_swap(this.Get_Pointer(), Object_To_Swap_With.Get_Pointer());
}

inline void Class::Add_Event(Event_Type Event)
{
    lv_obj_add_event_cb(this.Get_Pointer(), Xila_Class::Display_Class::Event_Handler);
}

inline void Class::Move_Foreground()
{
    lv_obj_move_foreground(this.Get_Pointer());
}

inline void Class::Move_Background()
{
    lv_obj_move_background(this.Get_Pointer());
}


// -- Set attributes values -- //

inline void Class::Set_Parent(Object_Class Parent_Object)
{
    lv_obj_set_parent(this.Object_Pointer, Parent_Object.Get_Pointer());
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

inline void Set_Parent(Object_Type Object, Object_Type Parent_Object)
{
    lv_obj_set_parent(Object, Parent_Object);
}

inline void Set_Index(uint32_t Index)
{
    lv_obj_move_to_index(this.Get_Pointer(), Index);
}

inline void Set_Pointer(LVGL_Object_Type LVGL_Object_Pointer)
{
    this.LVGL_Object_Pointer = LVGL_Object_Pointer;
}

// -- Get attributes values -- //

inline LVGL_Object_Type* Get_Pointer()
{
    return LVGL_Object_Pointer;
}

inline Object_Type Get_Child(uint16_t Index)
{
    return lv_obj_get_child(Parent_Object, Index);
}

inline uint16_t Get_Child_Count(Object_Type Parent_Object)
{
    return lv_obj_get_child_count(Parent_Object);
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


inline LVGL_Object_Class Class::Get_Parent()
{
    return lv_obj_get_parent(this.Object_Pointer);
}



 #endif