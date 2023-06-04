///
/// @file Label.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Graphics/Label.hpp"
#include "Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Label_Class::Class = lv_label_class;

// - Methods

// - - Constructors / destructors

Label_Class::Label_Class() : Object_Class()
{
}

Label_Class::Label_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy);
}

// - - Manipulation

void Label_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_label_create(Parent_Object);
    }
}

void Label_Class::Create(Object_Class Parent_Object, const char* Text, Coordinate_Type Width, Coordinate_Type Height)
{
    if (Parent_Object)
    {
        this->Create(Parent_Object);
        if (Width != 0)
            this->Set_Width(Width);

        if (Height != 0)
            this->Set_Height(Height);

        if (Text != "")
            this->Set_Text(Text);
    }
}

void Label_Class::Insert_Text(uint32_t Position, const char *Text)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_ins_text(Get_Pointer(), Position, Text);
}

void Label_Class::Cut_Text(uint32_t Position, uint32_t Length)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_cut_text(Get_Pointer(), Position, Length);
}

bool Label_Class::Is_Char_Under_Position(Point_Type& Position)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_is_char_under_pos(Get_Pointer(), Position);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Label_Class::Set_Text(const char *Text)
{
    auto Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text(Get_Pointer(), Text);
}

void Label_Class::Set_Text_Format(const char *Format, ...)
{
    va_list Arguments;
    va_start(Arguments, Format);

    va_list Arguments_Copy;
    va_copy(Arguments_Copy, Arguments);

    Size_Type Text_Length = vsniprintf(NULL, 0, Format, Arguments_Copy);

    va_end(Arguments_Copy);

    char* Buffer = static_cast<char*>(lv_mem_alloc(Text_Length + 1));

    vsnprintf(Buffer, Text_Length + 1, Format, Arguments);

    auto Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text(Get_Pointer(), Buffer);

    lv_mem_free(Buffer);

    va_end(Arguments);
}

void Label_Class::Set_Text_Static(const char *Format)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text_static(Get_Pointer(), Format);
}

void Label_Class::Set_Long_Mode(Long_Type Long_Mode)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_long_mode(Get_Pointer(), static_cast<lv_label_long_mode_t>(Long_Mode));
}

void Label_Class::Set_Recolor(bool Recolor)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_recolor(Get_Pointer(), Recolor);
}

void Label_Class::Set_Selection_Start(uint32_t Index)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_label_set_text_sel_start(Get_Pointer(), Index);
}

void Label_Class::Set_Selection_End(uint32_t Index)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
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
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&Class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

char *Label_Class::Get_Text()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_text(Get_Pointer());
}

Long_Type Label_Class::Get_Long_Mode()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return static_cast<Long_Type>(lv_label_get_long_mode(Get_Pointer()));
}

bool Label_Class::Get_Recolor()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_recolor(Get_Pointer());
}

void Label_Class::Get_Letter_Position(uint32_t Index, Point_Type& Position)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_letter_pos(Get_Pointer(), Index, Position);
}

uint32_t Label_Class::Get_Letter_On(Point_Type &Position)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_letter_on(Get_Pointer(), Position);
}

uint32_t Label_Class::Get_Selection_Start()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_text_selection_start(Get_Pointer());
}

uint32_t Label_Class::Get_Selection_End()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_label_get_text_selection_end(Get_Pointer());
}