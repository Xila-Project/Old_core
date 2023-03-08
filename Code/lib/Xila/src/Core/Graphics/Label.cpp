///
/// @file Label.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Label.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Label_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Set_Pointer(lv_label_create(Parent_Object.Get_Pointer()));
    }
}

void Label_Class::Insert_Text(uint32_t Position, const char *Text)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_ins_text(Get_Pointer(), Position, Text);
}

void Label_Class::Cut_Text(uint32_t Position, uint32_t Length)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_cut_text(Get_Pointer(), Position, Length);
}

bool Label_Class::Is_Char_Under_Position(Point_Type *Position)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_is_char_under_pos(Get_Pointer(), Position);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Label_Class::Set_Text(const char *Text)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text(Get_Pointer(), Text);
}

void Label_Class::Set_Text_Format(const char *Format, ...)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    va_list Arguments;
    lv_label_set_text_fmt(Get_Pointer(), Format, Arguments);
}

void Label_Class::Set_Text_Static(const char *Format)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text_static(Get_Pointer(), Format);
}

void Label_Class::Set_Long_Mode(Long_Type Long_Mode)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_long_mode(Get_Pointer(), static_cast<lv_label_long_mode_t>(Long_Mode));
}

void Label_Class::Set_Recolor(bool Recolor)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_recolor(Get_Pointer(), Recolor);
}

void Label_Class::Set_Selection_Start(uint32_t Index)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text_sel_start(Get_Pointer(), Index);
}

void Label_Class::Set_Selection_End(uint32_t Index)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text_sel_end(Get_Pointer(), Index);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

bool Label_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
     if (Get_Pointer() != NULL)
    {
        return false;
    }
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_label_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

char *Label_Class::Get_Text()
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_text(Get_Pointer());
}

Long_Type Label_Class::Get_Long_Mode()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return static_cast<Long_Type>(lv_label_get_long_mode(Get_Pointer()));
}

bool Label_Class::Get_Recolor()
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_recolor(Get_Pointer());
}

void Label_Class::Get_Letter_Position(uint32_t Index, Point_Type *Position)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_letter_pos(Get_Pointer(), Index, Position);
}

uint32_t Label_Class::Get_Letter_On(Point_Type *Position)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_letter_on(Get_Pointer(), Position);
}

uint32_t Label_Class::Get_Selection_Start()
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_text_selection_start(Get_Pointer());
}

uint32_t Label_Class::Get_Selection_End()
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_text_selection_end(Get_Pointer());
}