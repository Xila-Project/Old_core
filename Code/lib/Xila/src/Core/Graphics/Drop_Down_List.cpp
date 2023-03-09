///
/// @file Drop_Down_List.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 11-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Drop_Down_List.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Drop_Down_List_Class::Class = lv_dropdown_class;

// - Methods

// - - Constructors / destructors

Drop_Down_List_Class::Drop_Down_List_Class(const Object_Class &Object_To_Copy) : Object_Class(Object_To_Copy)
{
}

// - - Manipulation

void Drop_Down_List_Class::Create(Object_Class& Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Auto_Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_dropdown_create(Parent_Object.Get_Pointer());
    }
}

void Drop_Down_List_Class::Add_Option(const char *Option, uint32_t Position)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_add_option(Get_Pointer(), Option, Position);
}

void Drop_Down_List_Class::Clear_Options()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_clear_options(Get_Pointer());
}

void Drop_Down_List_Class::Open()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_open(Get_Pointer());
}

void Drop_Down_List_Class::Close()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_close(Get_Pointer());
}

bool Drop_Down_List_Class::Is_Open()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_is_open(Get_Pointer());
}

// - - Setters

bool Drop_Down_List_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    if (!Has_Class(&lv_dropdown_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Drop_Down_List_Class::Set_Text(const char *Text)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_set_text(Get_Pointer(), Text);
}

void Drop_Down_List_Class::Set_Options(const char *Options)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_set_options(Get_Pointer(), Options);
}

void Drop_Down_List_Class::Set_Options_Static(const char *Options)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_set_options_static(Get_Pointer(), Options);
}

void Drop_Down_List_Class::Set_Selected(uint16_t Selected_Option)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_set_selected(Get_Pointer(), Selected_Option);
}

void Drop_Down_List_Class::Set_Direction(Direction_Type Direction)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_set_dir(Get_Pointer(), static_cast<lv_dir_t>(Direction));
}

void Drop_Down_List_Class::Set_Symbol(const void *Symbol)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_set_symbol(Get_Pointer(), Symbol);
}

void Drop_Down_List_Class::Set_Selected_Highlight(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_dropdown_set_selected_highlight(Get_Pointer(), Enabled);
}

// - - Getters

Direction_Type Drop_Down_List_Class::Get_Direction()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return static_cast<Direction_Type>(lv_dropdown_get_dir(Get_Pointer()));
}

List_Class Drop_Down_List_Class::Get_List()
{
    lv_obj_t *List_Pointer;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        List_Pointer = lv_dropdown_get_list(Get_Pointer());
    }
    return List_Type(Object_Type(List_Pointer));
}

uint16_t Drop_Down_List_Class::Get_Option_Count()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_get_option_cnt(Get_Pointer());
}

const char *Drop_Down_List_Class::Get_Options()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_get_options(Get_Pointer());
}

uint16_t Drop_Down_List_Class::Get_Selected_Option()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_get_selected(Get_Pointer());
}

bool Drop_Down_List_Class::Get_Selected_Highlight()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_get_selected_highlight(Get_Pointer());
}

void Drop_Down_List_Class::Get_Selected_String(char *Buffer, size_t Buffer_Size)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_get_selected_str(Get_Pointer(), Buffer, Buffer_Size);
}

const char *Drop_Down_List_Class::Get_Symbol()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_get_symbol(Get_Pointer());
}

const char *Drop_Down_List_Class::Get_Text()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_dropdown_get_text(Get_Pointer());
}
