///
/// @file Animation.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Graphics/Animation.hpp"
#include "Graphics/Graphics.hpp"
#include "System/System.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Methods

// - - Manipulation

Animation_Class::Animation_Class()
{
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        lv_anim_init(&LVGL_Animation);
    }
}

Animation_Class::Animation_Class(lv_anim_t *Animation_To_Copy) : LVGL_Animation(*Animation_To_Copy)
{
}

Animation_Class::~Animation_Class()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_del(LVGL_Animation.var, LVGL_Animation.exec_cb);
}

uint16_t Animation_Class::Count_Running()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_count_running();
}

bool Animation_Class::Custom_Delete(void *Variable, Execution_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_del(Variable, Execution_Callback);
}

Animation_Class Animation_Class::Custom_Get(void *Variable, Execution_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    Animation_Class Animation;
    // Animation.Set_Pointer(lv_anim_get(Variable, Execution_Callback));
    return Animation;
}

bool Animation_Class::Delete(void *Variable, Execution_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_del(Variable, Execution_Callback);
}

void Animation_Class::Delete_All()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_del_all();
}

int32_t Animation_Class::Path_Bounce(const lv_anim_t *Animation)
{
    return lv_anim_path_bounce(Animation); // No semaphore needed since it's only calculus and no display
}

int32_t Animation_Class::Path_Ease_In(const lv_anim_t *Animation)
{
    return lv_anim_path_ease_in(Animation);
}

int32_t Animation_Class::Path_Ease_In_Out(const lv_anim_t *Animation)
{
    return lv_anim_path_ease_in_out(Animation);
}

int32_t Animation_Class::Path_Ease_Out(const lv_anim_t *Animation)
{
    return lv_anim_path_ease_out(Animation);
}

int32_t Animation_Class::Path_Linear(const lv_anim_t *Animation)
{
    return lv_anim_path_linear(Animation);
}

int32_t Animation_Class::Path_Overshoot(const lv_anim_t *Animation)
{
    return lv_anim_path_overshoot(Animation);
}

int32_t Animation_Class::Path_Step(const lv_anim_t *Animation)
{
    return lv_anim_path_step(Animation);
}

void Animation_Class::Refresh_Now()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_refr_now();
}

uint32_t Animation_Class::Speed_To_Time(uint32_t Speed, int32_t Start, int32_t End)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_speed_to_time(Speed, Start, End);
}

void Animation_Class::Start()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_start(&LVGL_Animation); // No semaphore needed
}

// - - Setters

void Animation_Class::Set_Execution_Callback(Execution_Callback_Type Execution_Callback)
{
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        lv_anim_set_exec_cb(&LVGL_Animation, Execution_Callback);
    }
    this->Execution_Callback = Execution_Callback;
}

void Animation_Class::Set_Delay(uint32_t Delay)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_delay(&LVGL_Animation, Delay);
}

void Animation_Class::Set_Early_Apply(bool Enable)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_early_apply(&LVGL_Animation, Enable);
}

void Animation_Class::Set_Get_Value_Callback(Get_Value_Callback_Type Get_Value_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_get_value_cb(&LVGL_Animation, Get_Value_Callback);
}

void Animation_Class::Set_Path_Callback(Path_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_path_cb(&LVGL_Animation, Execution_Callback);
}

void Animation_Class::Set_Playback_Delay(uint32_t Delay)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_playback_time(&LVGL_Animation, Delay);
}

void Animation_Class::Set_Playback_Time(uint32_t Time)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_playback_time(&LVGL_Animation, Time);
}

void Animation_Class::Set_Ready_Callback(Ready_Callback_Type Ready_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_ready_cb(&LVGL_Animation, Ready_Callback);
}

void Animation_Class::Set_Repeat_Count(uint16_t Count)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_repeat_count(&LVGL_Animation, Count);
}

void Animation_Class::Set_Repeat_Delay(uint32_t Delay)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_repeat_delay(&LVGL_Animation, Delay);
}

void Animation_Class::Set_Start_Callback(Start_Callback_Type Start_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_start_cb(&LVGL_Animation, Start_Callback);
}

void Animation_Class::Set_Time(uint32_t Time)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_time(&LVGL_Animation, Time);
}

void Animation_Class::Set_User_Data(void *User_Data)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_user_data(&LVGL_Animation, User_Data);
}

void Animation_Class::Set_Values(int32_t Start, int32_t End)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_values(&LVGL_Animation, Start, End);
}

void Animation_Class::Set_Variable(void *Variable)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_var(&LVGL_Animation, Variable);
}

// - - Getters

Animation_Class Animation_Class::Get(void *Variable, Execution_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    Animation_Class Animation(lv_anim_get(Variable, Execution_Callback));
    return Animation;
}

uint32_t Animation_Class::Get_Delay()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_get_delay(&LVGL_Animation);
}

uint32_t Animation_Class::Get_Playtime()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_get_playtime(&LVGL_Animation);
}

void *Animation_Class::Get_User_Data()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_get_user_data(&LVGL_Animation);
}
