///
/// @file Text_Area.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Text_Area.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Text_Area_Class::Class = lv_textarea_class;

// - Methods

// - - Constructors / Destructors

Text_Area_Class::Text_Area_Class() : Object_Class()
{
}

/// @brief Copy constructor from object.
/// @param Object_To_Copy 
Text_Area_Class::Text_Area_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy.Get_Pointer());
}

// - - Manipulation

void Text_Area_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_textarea_create(Parent_Object.Get_Pointer());
    }
}

void Text_Area_Class::Add_Char(uint32_t Character)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_add_char(Get_Pointer(), Character);
}

void Text_Area_Class::Add_Text(const char *Text)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_add_text(Get_Pointer(), Text);
}

void Text_Area_Class::Clear_Selection()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_clear_selection(Get_Pointer());
}

void Text_Area_Class::Cursor_Right()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_cursor_right(Get_Pointer());
}

void Text_Area_Class::Cursor_Left()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_cursor_left(Get_Pointer());
}

void Text_Area_Class::Cursor_Up()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_cursor_up(Get_Pointer());
}

void Text_Area_Class::Cursor_Down()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_cursor_down(Get_Pointer());
}

void Text_Area_Class::Delete_Character()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_del_char(Get_Pointer());
}

void Text_Area_Class::Delete_Character_Forward()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_del_char_forward(Get_Pointer());
}

// - - Setters

bool Text_Area_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&lv_textarea_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Text_Area_Class::Set_Accepted_Characters(const char *Accepted_Characters)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_accepted_chars(Get_Pointer(), Accepted_Characters);
}

void Text_Area_Class::Set_Text_Alignment(Text::Alignment_Type Alignment)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_align(Get_Pointer(), Alignment);
}

void Text_Area_Class::Set_Cursor_Position(int32_t Position)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_cursor_pos(Get_Pointer(), Position);
}

void Text_Area_Class::Set_Cursor_Click_Position(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_cursor_click_pos(Get_Pointer(), Enabled);
}

void Text_Area_Class::Set_Insert_Replace(const char *Text)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_insert_replace(Get_Pointer(), Text);
}

void Text_Area_Class::Set_Maximum_Length(uint32_t Maximum_Length)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_max_length(Get_Pointer(), Maximum_Length);
}

void Text_Area_Class::Set_One_Line(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_one_line(Get_Pointer(), Enabled);
}

void Text_Area_Class::Set_Password_Mode(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_password_mode(Get_Pointer(), Enabled);
}

void Text_Area_Class::Set_Password_Show_Time(uint16_t Time)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_password_show_time(Get_Pointer(), Time);
}

void Text_Area_Class::Set_Placeholder_Text(const char *Text)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_placeholder_text(Get_Pointer(), Text);
}

void Text_Area_Class::Set_Text(const char *Text)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_text(Get_Pointer(), Text);
}

void Text_Area_Class::Set_Text_Selection(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_textarea_set_text_selection(Get_Pointer(), Enabled);
}

// - - Getters

const char *Text_Area_Class::Get_Accepted_Characters()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_accepted_chars(Get_Pointer());
}

bool Text_Area_Class::Get_Cursor_Click_Position()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_cursor_click_pos(Get_Pointer());
}

uint32_t Text_Area_Class::Get_Cursor_Position()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_cursor_pos(Get_Pointer());
}

Label_Class Text_Area_Class::Get_Label()
{
    lv_obj_t* Label_Pointer;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Label_Pointer = lv_textarea_get_label(Get_Pointer());
    }
    return Label_Class(Object_Type(Label_Pointer));
}

uint32_t Text_Area_Class::Get_Maximum_Length()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_max_length(Get_Pointer());
}

bool Text_Area_Class::Get_One_Line()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_one_line(Get_Pointer());
}

bool Text_Area_Class::Get_Password_Mode()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_password_mode(Get_Pointer());
}

uint16_t Text_Area_Class::Get_Password_Show_Time()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_password_show_time(Get_Pointer());
}

const char *Text_Area_Class::Get_Placeholder_Text()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_placeholder_text(Get_Pointer());
}

const char *Text_Area_Class::Get_Text()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_text(Get_Pointer());
}

bool Text_Area_Class::Get_Text_Selection()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_textarea_get_text_selection(Get_Pointer());
}
