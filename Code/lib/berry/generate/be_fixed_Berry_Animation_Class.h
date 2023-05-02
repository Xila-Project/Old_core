#include "be_constobj.h"

static be_define_const_map_slots(Berry_Animation_Class_map) {
    { be_const_key(Set_Variable, 25), be_const_ctype_func(Berry_Animation_Class_Set_Variable_void_void) },
    { be_const_key(Set_Ready_Callback, -1), be_const_ctype_func(Berry_Animation_Class_Set_Ready_Callback_void_Graphics_TypesReady_Callback_Type) },
    { be_const_key(Path_Step, 1), be_const_ctype_func(Berry_Animation_Class_Path_Step_void_lv_anim_t) },
    { be_const_key(Set_User_Data, -1), be_const_ctype_func(Berry_Animation_Class_Set_User_Data_void_void) },
    { be_const_key(Custom_Delete, 34), be_const_ctype_func(Berry_Animation_Class_Custom_Delete_void_void_Graphics_TypesExecution_Callback_Type) },
    { be_const_key(Get_User_Data, 14), be_const_ctype_func(Berry_Animation_Class_Get_User_Data_void) },
    { be_const_key(Custom_Get, 8), be_const_ctype_func(Berry_Animation_Class_Custom_Get_void_void_Graphics_TypesExecution_Callback_Type) },
    { be_const_key(Set_Playback_Delay, 22), be_const_ctype_func(Berry_Animation_Class_Set_Playback_Delay_void_uint32_t) },
    { be_const_key(Set_Repeat_Count, -1), be_const_ctype_func(Berry_Animation_Class_Set_Repeat_Count_void_uint16_t) },
    { be_const_key(deinit, 33), be_const_ctype_func(Berry_Animation_Class_Deinitialize_void) },
    { be_const_key(Path_Ease_Out, 13), be_const_ctype_func(Berry_Animation_Class_Path_Ease_Out_void_lv_anim_t) },
    { be_const_key(Set_Get_Value_Callback, -1), be_const_ctype_func(Berry_Animation_Class_Set_Get_Value_Callback_void_Graphics_TypesGet_Value_Callback_Type) },
    { be_const_key(Get_Playtime, 9), be_const_ctype_func(Berry_Animation_Class_Get_Playtime_void) },
    { be_const_key(Delete_All, -1), be_const_ctype_func(Berry_Animation_Class_Delete_All_void) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Animation_Class_Delete_void_void_Graphics_TypesExecution_Callback_Type) },
    { be_const_key(Set_Playback_Time, -1), be_const_ctype_func(Berry_Animation_Class_Set_Playback_Time_void_uint32_t) },
    { be_const_key(Get_Delay, -1), be_const_ctype_func(Berry_Animation_Class_Get_Delay_void) },
    { be_const_key(Speed_To_Time, -1), be_const_ctype_func(Berry_Animation_Class_Speed_To_Time_void_uint32_t_int32_t_int32_t) },
    { be_const_key(Set_Values, 12), be_const_ctype_func(Berry_Animation_Class_Set_Values_void_int32_t_int32_t) },
    { be_const_key(Set_Early_Apply, -1), be_const_ctype_func(Berry_Animation_Class_Set_Early_Apply_void_bool) },
    { be_const_key(Get, 30), be_const_ctype_func(Berry_Animation_Class_Get_void_void_Graphics_TypesExecution_Callback_Type) },
    { be_const_key(Set_Start_Callback, 20), be_const_ctype_func(Berry_Animation_Class_Set_Start_Callback_void_Graphics_TypesStart_Callback_Type) },
    { be_const_key(Set_Time, 19), be_const_ctype_func(Berry_Animation_Class_Set_Time_void_uint32_t) },
    { be_const_key(Path_Bounce, 3), be_const_ctype_func(Berry_Animation_Class_Path_Bounce_void_lv_anim_t) },
    { be_const_key(Path_Linear, -1), be_const_ctype_func(Berry_Animation_Class_Path_Linear_void_lv_anim_t) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Animation_Class_Initialize_Graphics_TypesAnimation_Class) },
    { be_const_key(Path_Overshoot, -1), be_const_ctype_func(Berry_Animation_Class_Path_Overshoot_void_lv_anim_t) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Animation_Class_Start_void) },
    { be_const_key(Set_Delay, -1), be_const_ctype_func(Berry_Animation_Class_Set_Delay_void_uint32_t) },
    { be_const_key(Path_Ease_In_Out, -1), be_const_ctype_func(Berry_Animation_Class_Path_Ease_In_Out_void_lv_anim_t) },
    { be_const_key(Path_Ease_In, 28), be_const_ctype_func(Berry_Animation_Class_Path_Ease_In_void_lv_anim_t) },
    { be_const_key(Set_Execution_Callback, -1), be_const_ctype_func(Berry_Animation_Class_Set_Execution_Callback_void_Graphics_TypesExecution_Callback_Type) },
    { be_const_key(Refresh_Now, -1), be_const_ctype_func(Berry_Animation_Class_Refresh_Now_void) },
    { be_const_key(Set_Repeat_Delay, -1), be_const_ctype_func(Berry_Animation_Class_Set_Repeat_Delay_void_uint32_t) },
    { be_const_key(Set_Path_Callback, -1), be_const_ctype_func(Berry_Animation_Class_Set_Path_Callback_void_Graphics_TypesPath_Callback_Type) },
    { be_const_key(Count_Running, -1), be_const_ctype_func(Berry_Animation_Class_Count_Running_void) },
};

static be_define_const_map(
    Berry_Animation_Class_map,
    37
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Animation_Class,
    1,
    NULL,
    Animation_Type
);
