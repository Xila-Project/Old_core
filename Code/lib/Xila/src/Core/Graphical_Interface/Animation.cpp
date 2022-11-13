///
 /// @file Animation.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 04-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

#include "Core/Graphical_Interface/Animation.hpp"

using namespace Xila_Namespace;

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

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Animation_Class::Initialize()
{
    lv_anim_init(Get_Pointer());
}

uint16_t Animation_Class::Count_Running()
{
    return lv_anim_count_running();
}

bool Animation_Class::Custom_Delete(void* Variable, Execution_Callback_Type Execution_Callback)
{
    return lv_anim_del(Variable, Execution_Callback);
}

Animation_Class Animation_Class::Custom_Get(void* Variable, Execution_Callback_Type Execution_Callback)
{
    Animation_Class Animation;
    Animation.Set_Pointer(lv_anim_get(Variable, Execution_Callback));
    return Animation;
}

bool Animation_Class::Delete(void *Variable, Execution_Callback_Type Execution_Callback)
{
    return lv_anim_del(Variable, Execution_Callback);
}

void Animation_Class::Delete_All()
{
    lv_anim_del_all();
}

int32_t Animation_Class::Path_Bounce(Animation_Class Animation)
{
    return lv_anim_path_bounce(Animation.Get_Pointer());
}

int32_t Animation_Class::Path_Ease_In(Animation_Class Animation)
{
    return lv_anim_path_ease_in(Animation.Get_Pointer());
}

int32_t Animation_Class::Path_Ease_In_Out(Animation_Class Animation)
{
    return lv_anim_path_ease_in_out(Animation.Get_Pointer());
}

int32_t Animation_Class::Path_Ease_Out(Animation_Class Animation)
{
    return lv_anim_path_ease_out(Animation.Get_Pointer());
}

int32_t Animation_Class::Path_Linear(Animation_Class Animation)
{
    return lv_anim_path_linear(Animation.Get_Pointer());
}

int32_t Animation_Class::Path_Overshoot(Animation_Class Animation)
{
    return lv_anim_path_overshoot(Animation.Get_Pointer());
}

int32_t Animation_Class::Path_Step(Animation_Class Animation)
{
    return lv_anim_path_step(Animation.Get_Pointer());
}

void Animation_Class::Refresh_Now()
{
    lv_anim_refr_now();
}

uint32_t Animation_Class::Speed_To_Time(uint32_t Speed, int32_t Start, int32_t End)
{
    return lv_anim_speed_to_time(Speed, Start, End);
}

void Animation_Class::Start()
{
    lv_anim_start(Get_Pointer());
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Animation_Class::Set_Pointer(lv_anim_t* Animation_Pointer)
{
    LVGL_Animation_Pointer = Animation_Pointer;
}

void Animation_Class::Set_Custom_Execution_Callback(Execution_Callback_Type Execution_Callback)
{
    lv_anim_set_exec_cb(Get_Pointer(), Execution_Callback);
}

void Animation_Class::Set_Delay(uint32_t Delay)
{
    lv_anim_set_delay(Get_Pointer(), Delay);
}

void Animation_Class::Set_Early_Apply(bool Enable)
{
    lv_anim_set_early_apply(Get_Pointer(), Enable);
}

void Animation_Class::Set_Get_Value_Callback(Get_Value_Callback_Type Get_Value_Callback)
{
    lv_anim_set_get_value_cb(Get_Pointer(), Get_Value_Callback);
}

void Animation_Class::Set_Path_Callback(Path_Callback_Type Execution_Callback)
{
    lv_anim_set_path_cb(Get_Pointer(), Execution_Callback);
}

void Animation_Class::Set_Playback_Delay(uint32_t Delay)
{
    lv_anim_set_playback_time(Get_Pointer(), Delay);
}

void Animation_Class::Set_Playback_Time(uint32_t Time)
{
    lv_anim_set_playback_time(Get_Pointer(), Time);
}

void Animation_Class::Set_Ready_Callback(Ready_Callback_Type Ready_Callback)
{
    lv_anim_set_ready_cb(Get_Pointer(), Ready_Callback);
}

void Animation_Class::Set_Repeat_Count(uint16_t Count)
{
    lv_anim_set_repeat_count(Get_Pointer(), Count);
}

void Animation_Class::Set_Repeat_Delay(uint32_t Delay)
{
    lv_anim_set_repeat_delay(Get_Pointer(), Delay);
}

void Animation_Class::Set_Start_Callback(Start_Callback_Type Start_Callback)
{
    lv_anim_set_start_cb(Get_Pointer(), Start_Callback);
}

void Animation_Class::Set_Time(uint32_t Time)
{
    lv_anim_set_time(Get_Pointer(), Time);
}

void Animation_Class::Set_User_Data(void* User_Data)
{
    lv_anim_set_user_data(Get_Pointer(), User_Data);
}

void Animation_Class::Set_Values(int32_t Start, int32_t End)
{
    lv_anim_set_values(Get_Pointer(), Start, End);   
}

void Animation_Class::Set_Variable(void* Variable)
{
    lv_anim_set_var(Get_Pointer(), Variable);
}




// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

lv_anim_t* Animation_Class::Get_Pointer()
{
    return LVGL_Animation_Pointer;
}

Animation_Class Animation_Class::Get(void* Variable, Execution_Callback_Type Execution_Callback)
{
    Animation_Class Animation;
    Animation.Set_Pointer(lv_anim_get(Variable, Execution_Callback));
    return Animation;
}

uint32_t Animation_Class::Get_Delay()
{
    return lv_anim_get_delay(Get_Pointer());
}

uint32_t Animation_Class::Get_Playtime()
{
    return lv_anim_get_playtime(Get_Pointer());
}

void* Animation_Class::Get_User_Data()
{
    return lv_anim_get_user_data(Get_Pointer());
}
