///
/// @file Text_Area.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Text_Area.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Text_Area_Class::Create(Object_Class &Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_textarea_create(Parent_Object.Get_Pointer()));
    }
}

void Text_Area_Class::Add_Char(uint32_t Character)
{
    lv_textarea_add_char(Get_Pointer(), Character);
}

void Text_Area_Class::Add_Text(const char* Text)
{
    lv_textarea_add_text(Get_Pointer(), Text);
}

void Text_Area_Class::Clear_Selection()
{
    lv_textarea_clear_selection(Get_Pointer());
}

void Text_Area_Class::Cursor_Right()
{
    lv_textarea_cursor_right(Get_Pointer());
}

void Text_Area_Class::Cursor_Left()
{
    lv_textarea_cursor_left(Get_Pointer());
}

void Text_Area_Class::Cursor_Up()
{
    lv_textarea_cursor_up(Get_Pointer());
}

void Text_Area_Class::Cursor_Down()
{
    lv_textarea_cursor_down(Get_Pointer());
}

void Text_Area_Class::Delete_Character()
{
    lv_textarea_del_char(Get_Pointer());
}

void Text_Area_Class::Delete_Character_Forward()
{
    lv_textarea_del_char_forward(Get_Pointer());
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Text_Area_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_textarea_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Text_Area_Class::Set_Accepted_Characters(const char *Accepted_Characters)
{
    lv_textarea_set_accepted_chars(Get_Pointer(), Accepted_Characters);
}

void Text_Area_Class::Set_Text_Alignment(Text::Alignment_Type Alignment)
{
    lv_textarea_set_align(Get_Pointer(), Alignment);
}

void Text_Area_Class::Set_Cursor_Position(int32_t Position)
{
    lv_textarea_set_cursor_pos(Get_Pointer(), Position);
}

void Text_Area_Class::Set_Cursor_Click_Position(bool Enabled)
{
    lv_textarea_set_cursor_click_pos(Get_Pointer(), Enabled);
}

void Text_Area_Class::Set_Insert_Replace(const char* Text)
{
    lv_textarea_set_insert_replace(Get_Pointer(), Text);
}

void Text_Area_Class::Set_Maximum_Length(uint32_t Maximum_Length)
{
    lv_textarea_set_max_length(Get_Pointer(), Maximum_Length);
}

void Text_Area_Class::Set_One_Line(bool Enabled)
{
    lv_textarea_set_one_line(Get_Pointer(), Enabled);
}

void Text_Area_Class::Set_Password_Mode(bool Enabled)
{
    lv_textarea_set_password_mode(Get_Pointer(), Enabled);
}

void Text_Area_Class::Set_Password_Show_Time(uint16_t Time)
{
    lv_textarea_set_password_show_time(Get_Pointer(), Time);
}

void Text_Area_Class::Set_Placeholder_Text(const char* Text)
{
    lv_textarea_set_placeholder_text(Get_Pointer(), Text);
}

void Text_Area_Class::Set_Text(const char* Text)
{
    lv_textarea_set_text(Get_Pointer(), Text);
}

void Text_Area_Class::Set_Text_Selection(bool Enabled)
{
    lv_textarea_set_text_selection(Get_Pointer(), Enabled);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

const char* Text_Area_Class::Get_Accepted_Characters()
{
    return lv_textarea_get_accepted_chars(Get_Pointer());
}

bool Text_Area_Class::Get_Cursor_Click_Position()
{
    return lv_textarea_get_cursor_click_pos(Get_Pointer());
}

uint32_t Text_Area_Class::Get_Cursor_Position()
{
    return lv_textarea_get_cursor_pos(Get_Pointer());
}

Label_Class Text_Area_Class::Get_Label()
{
    Label_Class Label;
    Label.Set_Pointer(lv_textarea_get_label(Get_Pointer()));
    return Label;
}

uint32_t Text_Area_Class::Get_Maximum_Length()
{
    return lv_textarea_get_max_length(Get_Pointer());
}

bool Text_Area_Class::Get_One_Line()
{
    return lv_textarea_get_one_line(Get_Pointer());
}

bool Text_Area_Class::Get_Password_Mode()
{
    return lv_textarea_get_password_mode(Get_Pointer());
}

uint16_t Text_Area_Class::Get_Password_Show_Time()
{
    return lv_textarea_get_password_show_time(Get_Pointer());
}

const char* Text_Area_Class::Get_Placeholder_Text()
{
    return lv_textarea_get_placeholder_text(Get_Pointer());
}

const char* Text_Area_Class::Get_Text()
{
    return lv_textarea_get_text(Get_Pointer());
}

bool Text_Area_Class::Get_Text_Selection()
{
    return lv_textarea_get_text_selection(Get_Pointer());
}