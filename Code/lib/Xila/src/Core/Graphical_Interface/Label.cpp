///
/// @file Label.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Label.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Label_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_label_create(Parent_Object.Get_Pointer()));
    }
}

void Label_Class::Insert_Text(uint32_t Position, const char *Text)
{
    lv_label_ins_text(Get_Pointer(), Position, Text);
}

void Label_Class::Cut_Text(uint32_t Position, uint32_t Length)
{
    lv_label_cut_text(Get_Pointer(), Position, Length);
}

bool Label_Class::Is_Char_Under_Position(Point_Type *Position)
{
    return lv_label_is_char_under_pos(Get_Pointer(), Position);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Label_Class::Set_Text(const char *Text)
{
    lv_label_set_text(Get_Pointer(), Text);
}

void Label_Class::Set_Text_Format(const char *Format, ...)
{
    va_list Arguments;
    lv_label_set_text_fmt(Get_Pointer(), Format, Arguments);
}

void Label_Class::Set_Text_Static(const char *Format)
{
    lv_label_set_text_static(Get_Pointer(), Format);
}

void Label_Class::Set_Long_Mode(Long_Mode_Type Long_Mode)
{
    lv_label_set_long_mode(Get_Pointer(), Long_Mode);
}

void Label_Class::Set_Recolor(bool Recolor)
{
    lv_label_set_recolor(Get_Pointer(), Recolor);
}

void Label_Class::Set_Selection_Start(uint32_t Index)
{
    lv_label_set_text_sel_start(Get_Pointer(), Index);
}

void Label_Class::Set_Selection_End(uint32_t Index)
{
    lv_label_set_text_sel_end(Get_Pointer(), Index);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

bool Label_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
     if (Get_Pointer() == NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_label_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

char *Label_Class::Get_Text()
{
    return lv_label_get_text(Get_Pointer());
}

Label_Class::Long_Mode_Type Label_Class::Get_Long_Mode()
{
    return lv_label_get_long_mode(Get_Pointer());
}

bool Label_Class::Get_Recolor()
{
    return lv_label_get_recolor(Get_Pointer());
}

void Label_Class::Get_Letter_Position(uint32_t Index, Point_Type *Position)
{
    return lv_label_get_letter_pos(Get_Pointer(), Index, Position);
}

uint32_t Label_Class::Get_Letter_On(Point_Type *Position)
{
    return lv_label_get_letter_on(Get_Pointer(), Position);
}

uint32_t Label_Class::Get_Selection_Start()
{
    return lv_label_get_text_selection_start(Get_Pointer());
}

uint32_t Label_Class::Get_Selection_End()
{
    return lv_label_get_text_selection_end(Get_Pointer());
}