#include "Core/Graphical_Interface/Object.hpp"


// ------------------------------------------------------------------------- //
//
//                                  Constructor
//
// ------------------------------------------------------------------------- //

Object_Class::Object_Class::Object_Class() : LVGL_Object_Pointer(NULL)
{
}

// ------------------------------------------------------------------------- //
//
//                                  Operators
//
// ------------------------------------------------------------------------- //

Object_Class& Object_Class::operator=(const Object_Class Object_To_Copy)
{
    Set_Pointer(Object_To_Copy.Get_Pointer());
    return *this;
}

Object_Class::operator bool() const
{
    if (Get_Pointer() == NULL)
    {
        return false;
    }
    else
    {
        return Is_Valid();
    }
}

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //


void Object_Class::Create(const Object_Class& Parent_Object)
{
    // Parent object is required (windows, containers, etc.)
    if (Parent_Object.Get_Pointer() == NULL)
    {
        return;
    }
    Set_Pointer(lv_obj_create(Parent_Object.Get_Pointer()));
}

void Object_Class::Delete()
{
    lv_obj_del_async(Get_Pointer());
    Set_Pointer(NULL);
}

void Object_Class::Clean()
{
    lv_obj_clean(Get_Pointer());
}

void Object_Class::Add_Flag(Flag_Type Flag)
{
    lv_obj_add_flag(Get_Pointer(), Flag);
}

void Object_Class::Clear_Flag(Flag_Type Flag)
{
    lv_obj_clear_flag(Get_Pointer(), Flag);
}

bool Object_Class::Has_Flag(Flag_Type Flag)
{
    return lv_obj_has_flag(Get_Pointer(), Flag);
}

bool Object_Class::Has_Any_Flag(Flag_Type Flag)
{
    return lv_obj_has_flag_any(Get_Pointer(), Flag);
}

void Object_Class::Add_State(State_Type State)
{
    lv_obj_add_state(Get_Pointer(), State);
}

void Object_Class::Clear_State(State_Type State)
{
    lv_obj_clear_state(Get_Pointer(), State);
}

bool Object_Class::Has_State(State_Type State)
{
    return lv_obj_has_state(Get_Pointer(), State);
}

void Object_Class::Allocate_Special_Data()
{
    lv_obj_allocate_spec_attr(Get_Pointer());
}

void Object_Class::Swap(Object_Class Object_To_Swap_With)
{
    lv_obj_swap(Get_Pointer(), Object_To_Swap_With.Get_Pointer());
}

void Object_Class::Add_Event(Event_Type Event)
{
    lv_obj_add_event_cb(Get_Pointer(), Xila_Class::Display_Object_Class::Event_Handler, Event, NULL);
}

void Object_Class::Remove_Event(Event_Type Event)
{
    lv_obj_remove_event_cb(Get_Pointer(), Event);
}

void Object_Class::Send_Event(Event_Type Event)
{
    lv_event_send(Get_Pointer(), Event, NULL);
}

void Object_Class::Move_Foreground()
{
    lv_obj_move_foreground(Get_Pointer());
}

void Object_Class::Move_Background()
{
    lv_obj_move_background(Get_Pointer());
}

bool Object_Class::Check_Type(const Class_Type* Class_To_Check)
{
    return lv_obj_check_type(Get_Pointer(), Class_To_Check);
}

bool Object_Class::Has_Class(const Class_Type* Class_To_Check)
{
    return lv_obj_has_class(Get_Pointer(), Class_To_Check);
}

const Object_Class::Class_Type* Object_Class::Get_Class()
{
    return lv_obj_get_class(Get_Pointer());
}

bool Is_Valid()
{
    if (Get_Pointer() == NULL)
    {
        return false;
    }
    return lv_obj_is_valid(Get_Pointer());
}

bool Is_Focused()
{
    return lv_obj_is_focused(Get_Pointer());
}

Coordinate_Type Object_Class::DPX(Coordinate_Type Pixels_To_Scale)
{
    return lv_obj_dpx(Get_Pointer(), Pixels_To_Scale);
}

void Object_Class::Add_Style(Style_Type *Style, Style_Selector_Type *Style_Selector)
{
    lv_obj_add_style(Get_Pointer(), Style);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Object_Class::Set_User_Data(void *User_Data)
{
    lv_obj_set_user_data(Get_Pointer(), User_Data);
}

void Object_Class::Set_Parent(Object_Class Parent_Object)
{
    lv_obj_set_parent(Get_Pointer(), Parent_Object.Get_Pointer());
}

// -- Position and size.

void Object_Class::Set_Alignment(Xila_Class::Object_Type Object_Type, Alignment Align)
{
    lv_obj_set_align(Object_Type, Align);
}



void Object_Class::Set_Position_X(Coordinate_Type X)
{
    lv_obj_set_x(Get_Pointer(), X);
}

void Object_Class::Set_Position_X(Coordinate_Type Y)
{
    lv_obj_set_y(Get_Pointer(), Y);
}

void Object_Class::Set_Position(Coordinate_Type X, Coordinate_Type Y)
{
    lv_obj_set_pos(Get_Pointer(), X, Y);
}



Object_Class::Set_Size(Xila_Class::Object_Type Object_Type, Coordinates Width, Coordinates Height, char Fit)
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



bool Object_Class::Set_Pointer(LVGL_Object_Type* LVGL_Object_Pointer)
{
    if (LVGL_Object_Pointer == NULL)
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Object_Class::Set_Index(uint32_t Index)
{
    lv_obj_move_to_index(Get_Pointer(), Index);
}


// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

void *Object_Class::Get_User_Data()
{
    return lv_obj_get_user_data(Get_Pointer());
}

State_Type Object_Class::Get_State()
{
    return lv_obj_get_state(Get_Pointer());
}

LVGL_Object_Type *Get_Pointer()
{
    return LVGL_Object_Pointer;
}

Object_Type Get_Child(uint16_t Index)
{
    return lv_obj_get_child(Parent_Object, Index);
}

uint16_t Get_Child_Count(Object_Type Parent_Object)
{
    return lv_obj_get_child_count(Parent_Object);
}

LVGL_Object_Class Object_Class::Get_Parent()
{
    return lv_obj_get_parent(Object_Pointer);
}

void *Get_Group()
{
    return lv_obj_get_group(Get_Pointer());
}