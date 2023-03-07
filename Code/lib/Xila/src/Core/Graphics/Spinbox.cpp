///
/// @file Spinbox.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 23-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Graphics/Spinbox.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;

// - Methods

void Spinbox_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Set_Pointer(lv_spinbox_create(Parent_Object.Get_Pointer()));
    }
}

// - - Manipulation.

void Spinbox_Class::Step_Next()
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_step_next(Get_Pointer());
}

void Spinbox_Class::Step_Previous()
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_step_prev(Get_Pointer());
}

void Spinbox_Class::Increment()
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_increment(Get_Pointer());
}

void Spinbox_Class::Decrement()
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_decrement(Get_Pointer());
}

// - - Getters.

bool Spinbox_Class::Get_Rollover()
{
    Graphics.Take_Semaphore_Auto();
    return lv_spinbox_get_rollover(Get_Pointer());
}

int32_t Spinbox_Class::Get_Value()
{
    Graphics.Take_Semaphore_Auto();
    return lv_spinbox_get_value(Get_Pointer());
}

int32_t Spinbox_Class::Get_Step()
{
    Graphics.Take_Semaphore_Auto();
    return lv_spinbox_get_step(Get_Pointer());
}

// - - Setters.

bool Spinbox_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_spinbox_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Spinbox_Class::Set_Value(int32_t Value)
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_set_value(Get_Pointer(), Value);
}

void Spinbox_Class::Set_Rollover(bool Rollover)
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_set_rollover(Get_Pointer(), Rollover);
}

void Spinbox_Class::Set_Digit_Format(uint8_t Digit_Count, uint8_t Separator_Position)
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_set_digit_format(Get_Pointer(), Digit_Count, Separator_Position);
}

void Spinbox_Class::Set_Step(uint32_t Step)
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_set_step(Get_Pointer(), Step);
}

void Spinbox_Class::Set_Range(int32_t Minimum_Value, int32_t Maximum_Value)
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_set_range(Get_Pointer(), Minimum_Value, Maximum_Value);
}

void Spinbox_Class::Set_Cursor_Position(uint8_t Cursor_Position)
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_set_cursor_pos(Get_Pointer(), Cursor_Position);
}

void Spinbox_Class::Set_Digit_Step_Direction(Direction_Type Direction)
{
    Graphics.Take_Semaphore_Auto();
    lv_spinbox_set_digit_step_direction(Get_Pointer(), static_cast<lv_dir_t>(Direction));
}