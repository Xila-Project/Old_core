#include "Core/Graphical_Interface/Object.hpp"
#include "Core/Graphical_Interface/Animation.hpp"

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

Object_Class &Object_Class::operator=(const Object_Class Object_To_Copy)
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

void Object_Class::Create(Object_Class &Parent_Object)
{
    // Parent object is required (windows, containers, etc.)
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_obj_create(Parent_Object.Get_Pointer()));
    }
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

bool Object_Class::Check_Type(const Class_Type *Class_To_Check)
{
    return lv_obj_check_type(Get_Pointer(), Class_To_Check);
}

bool Object_Class::Has_Class(const Class_Type *Class_To_Check)
{
    return lv_obj_has_class(Get_Pointer(), Class_To_Check);
}

bool Object_Class::Is_Valid()
{
    if (Get_Pointer() == NULL)
    {
        return false;
    }
    return lv_obj_is_valid(Get_Pointer());
}

Object_Class::Coordinate_Type Object_Class::DPX(Coordinate_Type Pixels_To_Scale)
{
    return lv_obj_dpx(Get_Pointer(), Pixels_To_Scale);
}

void Object_Class::Add_Style(Style_Type *Style, Style_Selector_Type Style_Selector)
{
    lv_obj_add_style(Get_Pointer(), Style, Style_Selector);
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

void Object_Class::Set_Alignment(Alignment_Type Alignment)
{
    lv_obj_set_align(Get_Pointer(), Alignment);
}

void Object_Class::Set_Alignment(Alignment_Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset)
{
    lv_obj_align(Get_Pointer(), Alignment, X_Offset, Y_Offset);
}

void Object_Class::Set_Alignment(Object_Class Object_To_Align_With, Alignment_Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset)
{

    lv_obj_align_to(Get_Pointer(), Object_To_Align_With.Get_Pointer(), Alignment, X_Offset, Y_Offset);
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

bool Object_Class::Set_Pointer(LVGL_Object_Type *LVGL_Object_Pointer)
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

void Object_Class::Set_Flex_Align(Flex_Alignment_Type Main_Place_Alignment, Flex_Alignment_Type Cross_Place_Alignment, Flex_Alignment_Type Track_Cross_Place)
{
    lv_obj_set_flex_align(Get_Pointer(), (lv_flex_align_t)Main_Place_Alignment, (lv_flex_align_t)Cross_Place_Alignment, (lv_flex_align_t)Track_Cross_Place);
}

void Object_Class::Set_Flex_Flow(Flex_Flow_Type Flow)
{
    lv_obj_set_flex_flow(Get_Pointer(), (lv_flex_flow_t)Flow);
}

void Object_Class::Set_Flex_Grow(uint8_t Grow)
{
    lv_obj_set_flex_grow(Get_Pointer(), Grow);
}

void Object_Class::Set_Grid_Alignment(Grid_Alignment_Type Column_Alignment, Grid_Alignment_Type Row_Alignment)
{
    lv_obj_set_grid_align(Get_Pointer(), (lv_grid_align_t)Column_Alignment, (lv_grid_align_t)Row_Alignment);
}

void Object_Class::Set_Grid_Cell(Grid_Alignment_Type Column_Alignment, uint8_t Column_Position, uint8_t Column_Span, Grid_Alignment_Type Row_Alignment, uint8_t Row_Position, uint8_t Row_Span)
{
    lv_obj_set_grid_cell(Get_Pointer(), (lv_grid_align_t)Column_Alignment, Column_Position, Column_Span, (lv_grid_align_t)Row_Alignment, Row_Position, Row_Span);
}

void Object_Class::Set_Grid_Descriptor_Array(const Coordinate_Type Column_Descriptor[], const Coordinate_Type Row_Descriptor[])
{
    lv_obj_set_grid_dsc_array(Get_Pointer(), Column_Descriptor, Row_Descriptor);
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

Object_Class::State_Type Object_Class::Get_State()
{
    return lv_obj_get_state(Get_Pointer());
}

Object_Class Object_Class::Get_Child(uint16_t Index)
{
    Object_Class Child_Object;
    Child_Object.Set_Pointer(lv_obj_get_child(Get_Pointer(), Index));
    return Child_Object;
}

uint32_t Object_Class::Get_Child_Count()
{
    return lv_obj_get_child_cnt(Get_Pointer());
}

Object_Class Object_Class::Get_Parent()
{
    Object_Class Parent_Object;
    Parent_Object.Set_Pointer(lv_obj_get_parent(Get_Pointer()));
    return Parent_Object;
}

void *Object_Class::Get_Group()
{
    return lv_obj_get_group(Get_Pointer());
}

const Object_Class::Class_Type *Object_Class::Get_Class()
{
    return lv_obj_get_class(Get_Pointer());
}

inline bool Object_Class::Get_Object_Visibility()
{
    return lv_obj_is_visible(Get_Pointer());
}

// -- Style

Object_Class::Alignment_Type Object_Class::Get_Style_Align(uint32_t Part)
{
    return lv_obj_get_style_align(Get_Pointer(), Part);
}

/*
const Animation_Class Object_Class::Get_Style_Animation(uint32_t Part)
{
    Animation_Class Animation;
    Animation.Set_Pointer(lv_obj_get_style_anim(Get_Pointer(), Part));
    return Animation;

}*/

uint32_t Object_Class::Get_Style_Animation_Time(uint32_t Part)
{
    return lv_obj_get_style_anim_time(Get_Pointer(), Part);
}

uint32_t Object_Class::Get_Style_Animation_Speed(uint32_t Part)
{
    return lv_obj_get_style_anim_speed(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Arc_Color(uint32_t Part)
{
    return lv_obj_get_style_arc_color(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Arc_Color_Filtered(uint32_t Part)
{
    return lv_obj_get_style_arc_color_filtered(Get_Pointer(), Part);
}

const void *Object_Class::Get_Style_Arc_Image_Source(uint32_t Part)
{
    return lv_obj_get_style_arc_img_src(Get_Pointer(), Part);
}

Object_Class::Opacity_Type Object_Class::Get_Style_Arc_Opacity(uint32_t Part)
{
    return lv_obj_get_style_arc_opa(Get_Pointer(), Part);
}

bool Object_Class::Get_Style_Arc_Rounded(uint32_t Part)
{
    return lv_obj_get_style_arc_rounded(Get_Pointer(), Part);
}

Object_Class::Coordinate_Type Object_Class::Get_Style_Arc_Width(uint32_t Part)
{
    return lv_obj_get_style_arc_width(Get_Pointer(), Part);
}

Object_Class::Base_Direction_Type Object_Class::Get_Style_Base_Direction(uint32_t Part)
{
    return lv_obj_get_style_base_dir(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Background_Color(uint32_t Part)
{
    return lv_obj_get_style_bg_color(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Background_Color_Filtered(uint32_t Part)
{
    return lv_obj_get_style_bg_color_filtered(Get_Pointer(), Part);
}

Object_Class::Opacity_Type Object_Class::Get_Style_Background_Opacity(uint32_t Part)
{
    return lv_obj_get_style_bg_opa(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Background_Gradient_Color(uint32_t Part)
{
    return lv_obj_get_style_bg_grad_color(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Background_Gradient_Color_Filtered(uint32_t Part)
{
    return lv_obj_get_style_bg_grad_color_filtered(Get_Pointer(), Part);
}

Object_Class::Gradient_Direction_Type Object_Class::Get_Style_Background_Gradient_Direction(uint32_t Part)
{
    return lv_obj_get_style_bg_grad_dir(Get_Pointer(), Part);
}

Object_Class::Coordinate_Type Object_Class::Get_Style_Background_Main_Stop(uint32_t Part)
{
    return lv_obj_get_style_bg_main_stop(Get_Pointer(), Part);
}

Object_Class::Coordinate_Type Object_Class::Get_Style_Background_Gradient_Stop(uint32_t Part)
{
    return lv_obj_get_style_bg_grad_stop(Get_Pointer(), Part);
}

const Object_Class::Gradient_Descriptor_Type *Object_Class::Get_Style_Background_Gradient(uint32_t Part)
{
    return lv_obj_get_style_bg_grad(Get_Pointer(), Part);
}

Object_Class::Dither_Mode_Type Object_Class::Get_Style_Background_Dither_Mode(uint32_t Part)
{
    return lv_obj_get_style_bg_dither_mode(Get_Pointer(), Part);
}

const void *Object_Class::Get_Style_Background_Image_Source(uint32_t Part)
{
    return lv_obj_get_style_bg_img_src(Get_Pointer(), Part);
}

Object_Class::Opacity_Type Object_Class::Get_Style_Background_Image_Opacity(uint32_t Part)
{
    return lv_obj_get_style_bg_img_opa(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Background_Image_Recolor(uint32_t Part)
{
    return lv_obj_get_style_bg_img_recolor(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Background_Image_Recolor_Filtered(uint32_t Part)
{
    return lv_obj_get_style_bg_img_recolor_filtered(Get_Pointer(), Part);
}

Object_Class::Opacity_Type Object_Class::Get_Style_Background_Image_Recolor_Opacity(uint32_t Part)
{
    return lv_obj_get_style_bg_img_recolor_opa(Get_Pointer(), Part);
}

bool Object_Class::Get_Style_Background_Image_Tiled(uint32_t Part)
{
    return lv_obj_get_style_bg_img_tiled(Get_Pointer(), Part);
}

Object_Class::Blend_Mode_Type Object_Class::Get_Style_Blend_Mode(uint32_t Part)
{
    return lv_obj_get_style_blend_mode(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Border_Color(uint32_t Part)
{
    return lv_obj_get_style_border_color(Get_Pointer(), Part);
}

Object_Class::Color_Type Object_Class::Get_Style_Border_Color_Filtered(uint32_t Part)
{
    return lv_obj_get_style_border_color_filtered(Get_Pointer(), Part);
}

Object_Class::Opacity_Type Object_Class::Get_Style_Border_Opacity(uint32_t Part)
{
    return lv_obj_get_style_border_opa(Get_Pointer(), Part);
}

Object_Class::Coordinate_Type Object_Class::Get_Style_Border_Width(uint32_t Part)
{
    return lv_obj_get_style_border_width(Get_Pointer(), Part);
}

Object_Class::Border_Side_Type Object_Class::Get_Style_Border_Side(uint32_t Part)
{
    return lv_obj_get_style_border_side(Get_Pointer(), Part);
}

bool Object_Class::Get_Style_Border_Post(uint32_t Part)
{
    return lv_obj_get_style_border_post(Get_Pointer(), Part);
}

bool Object_Class::Get_Style_Clip_Corner(uint32_t Part)
{
    return lv_obj_get_style_clip_corner(Get_Pointer(), Part);
}

const Object_Class::Color_Filter_Descriptor_Type *Get_Style_Color_Filter_Descriptor(uint32_t Part)
{
    return lv_obj_get_style_color_filter_dsc(Get_Pointer(), Part);
}

Object_Class::Opacity_Type Object_Class::Get_Style_Color_Filter_Opacity(uint32_t Part)
{
    return lv_obj_get_style_color_filter_opa(Get_Pointer(), Part);
}

Object_Class::Flex_Flow_Type Object_Class::Get_Style_Flex_Flow(uint32_t Part)
{
    return (Flex_Flow_Type)lv_obj_get_style_flex_flow(Get_Pointer(), Part);
}

Object_Class::Flex_Alignment_Type Object_Class::Get_Style_Flex_Main_Place(uint32_t Part)
{
    return (Flex_Alignment_Type)lv_obj_get_style_flex_main_place(Get_Pointer(), Part);
}

Object_Class::Flex_Alignment_Type Object_Class::Get_Style_Flex_Cross_Place(uint32_t Part)
{
    return (Flex_Alignment_Type)lv_obj_get_style_flex_cross_place(Get_Pointer(), Part);
}

Object_Class::Flex_Alignment_Type Object_Class::Get_Style_Flex_Track_Place(uint32_t Part)
{
    return (Flex_Alignment_Type)lv_obj_get_style_flex_track_place(Get_Pointer(), Part);
}

uint8_t Object_Class::Get_Style_Flex_Grow(uint32_t Part)
{
    return lv_obj_get_style_flex_grow(Get_Pointer(), Part);
}
