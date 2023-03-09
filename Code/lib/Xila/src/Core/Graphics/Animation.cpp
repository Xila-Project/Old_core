///
/// @file Animation.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Animation.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// ------------------------------------------------------------------------- //
//
//                                  Constructor
//
// ------------------------------------------------------------------------- //

Animation_Class::Animation_Class()
{
}

void Animation_Class::Create()
{
    LVGL_Animation_Pointer = new lv_anim_t;
    Initialize();
}

void Animation_Class::Delete()
{
    delete LVGL_Animation_Pointer;
}

// - Manipulation

void Animation_Class::Initialize()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_init(Get_Pointer());
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
    Animation.Set_Pointer(lv_anim_get(Variable, Execution_Callback));
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
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_path_bounce(Animation);
}

int32_t Animation_Class::Path_Ease_In(const lv_anim_t *Animation)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_path_ease_in(Animation);
}

int32_t Animation_Class::Path_Ease_In_Out(const lv_anim_t *Animation)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_path_ease_in_out(Animation);
}

int32_t Animation_Class::Path_Ease_Out(const lv_anim_t *Animation)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_path_ease_out(Animation);
}

int32_t Animation_Class::Path_Linear(const lv_anim_t *Animation)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_path_linear(Animation);
}

int32_t Animation_Class::Path_Overshoot(const lv_anim_t *Animation)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_path_overshoot(Animation);
}

int32_t Animation_Class::Path_Step(const lv_anim_t *Animation)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
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
    lv_anim_start(Get_Pointer());
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Animation_Class::Set_Pointer(lv_anim_t *Animation_Pointer)
{
    LVGL_Animation_Pointer = Animation_Pointer;
}

void Animation_Class::Set_Execution_Callback(Execution_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_exec_cb(Get_Pointer(), Execution_Callback);
}

void Animation_Class::Set_Delay(uint32_t Delay)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_delay(Get_Pointer(), Delay);
}

void Animation_Class::Set_Early_Apply(bool Enable)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_early_apply(Get_Pointer(), Enable);
}

void Animation_Class::Set_Get_Value_Callback(Get_Value_Callback_Type Get_Value_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_get_value_cb(Get_Pointer(), Get_Value_Callback);
}

void Animation_Class::Set_Path_Callback(Path_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_path_cb(Get_Pointer(), Execution_Callback);
}

void Animation_Class::Set_Playback_Delay(uint32_t Delay)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_playback_time(Get_Pointer(), Delay);
}

void Animation_Class::Set_Playback_Time(uint32_t Time)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_playback_time(Get_Pointer(), Time);
}

void Animation_Class::Set_Ready_Callback(Ready_Callback_Type Ready_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_ready_cb(Get_Pointer(), Ready_Callback);
}

void Animation_Class::Set_Repeat_Count(uint16_t Count)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_repeat_count(Get_Pointer(), Count);
}

void Animation_Class::Set_Repeat_Delay(uint32_t Delay)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_repeat_delay(Get_Pointer(), Delay);
}

void Animation_Class::Set_Start_Callback(Start_Callback_Type Start_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_start_cb(Get_Pointer(), Start_Callback);
}

void Animation_Class::Set_Time(uint32_t Time)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_time(Get_Pointer(), Time);
}

void Animation_Class::Set_User_Data(void *User_Data)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_user_data(Get_Pointer(), User_Data);
}

void Animation_Class::Set_Values(int32_t Start, int32_t End)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_values(Get_Pointer(), Start, End);
}

void Animation_Class::Set_Variable(void *Variable)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_anim_set_var(Get_Pointer(), Variable);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

lv_anim_t *Animation_Class::Get_Pointer()
{
    return LVGL_Animation_Pointer;
}

Animation_Class Animation_Class::Get(void *Variable, Execution_Callback_Type Execution_Callback)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    Animation_Class Animation;
    Animation.Set_Pointer(lv_anim_get(Variable, Execution_Callback));
    return Animation;
}

uint32_t Animation_Class::Get_Delay()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_get_delay(Get_Pointer());
}

uint32_t Animation_Class::Get_Playtime()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_get_playtime(Get_Pointer());
}

void *Animation_Class::Get_User_Data()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_anim_get_user_data(Get_Pointer());
}
