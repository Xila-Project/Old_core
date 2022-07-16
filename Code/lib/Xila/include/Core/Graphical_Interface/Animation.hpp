///
/// @file Animation.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Animation_Hpp_Included
#define Animation_Hpp_Included

#include "lvgl.h"

class Animation_Class
{
public:
    // - Types

    typedef lv_anim_path_cb_t Animation_Path_Callback_Type;

    typedef lv_anim_custom_exec_cb_t Custom_Execution_Callback_Type;

    typedef lv_anim_exec_xcb_t Execution_Callback_Type;

    typedef lv_anim_path_cb_t Path_Callback_Type;

    typedef lv_anim_get_value_cb_t Get_Value_Callback_Type;

    typedef lv_anim_ready_cb_t Ready_Callback_Type;

    typedef lv_anim_start_cb_t Start_Callback_Type;

    // - Methods

    // - - Management
    Animation_Class();

    void Create();
    void Delete();
    void Initialize();

    static uint16_t Count_Running();
    static bool Custom_Delete(void* Variable, Execution_Callback_Type Execution_Callback);
    static Animation_Class Custom_Get(void* Variable, Execution_Callback_Type Execution_Callback);
    static bool Delete(void *Variable, Execution_Callback_Type Execution_Callback);
    static void Delete_All();

    static int32_t Path_Bounce(Animation_Class Animation);
    static int32_t Path_Ease_In(Animation_Class Animation);
    static int32_t Path_Ease_In_Out(Animation_Class Animation);
    static int32_t Path_Ease_Out(Animation_Class Animation);
    static int32_t Path_Linear(Animation_Class Animation);
    static int32_t Path_Overshoot(Animation_Class Animation);
    static int32_t Path_Step(Animation_Class Animation);

    static void Refresh_Now();
    static uint32_t Speed_To_Time(uint32_t Speed, int32_t Start, int32_t End);
    void Start();

    // - - Getters
    lv_anim_t* Get_Pointer();

    Animation_Class Get(void *Variable, Execution_Callback_Type Execution_Callback);
    uint32_t Get_Delay();
    uint32_t Get_Playtime();
    void *Get_User_Data();

    // - - Setters
    void Set_Pointer(lv_anim_t* Animation_Pointer);

    void Set_Custom_Execution_Callback(Execution_Callback_Type Execution_Callback);
    void Set_Delay(uint32_t Delay);
    void Set_Early_Apply(bool Enable);
    void Set_Get_Value_Callback(Get_Value_Callback_Type Get_Value_Callback);
    void Set_Path_Callback(Path_Callback_Type Execution_Callback);
    void Set_Playback_Delay(uint32_t Delay);
    void Set_Playback_Time(uint32_t Time);
    void Set_Ready_Callback(Ready_Callback_Type Ready_Callback);
    void Set_Repeat_Count(uint16_t Count);
    void Set_Repeat_Delay(uint32_t Delay);
    void Set_Start_Callback(Start_Callback_Type Start_Callback);
    void Set_Time(uint32_t Time);
    void Set_User_Data(void* User_Data);
    void Set_Values(int32_t Start, int32_t End);
    void Set_Variable(void* Variable);
    

private:
    lv_anim_t* LVGL_Animation_Pointer;
};

#endif