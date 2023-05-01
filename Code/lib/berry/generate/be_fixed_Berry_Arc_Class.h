#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Class_map) {
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_void_uint16_t) },
    { be_const_key(Get_Angle_End, 9), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_void) },
    { be_const_key(Set_Rotation, 10), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_void_uint16_t) },
    { be_const_key(init, 4), be_const_ctype_func(Berry_Arc_Class_Initialize_Graphics_TypesArc_Class) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_void) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Arc_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_void) },
    { be_const_key(Get_Mode, 18), be_const_ctype_func(Berry_Arc_Class_Get_Mode_void) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_void) },
    { be_const_key(Set_Background_Angles, 11), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_void_uint16_t_uint16_t) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Range, 20), be_const_ctype_func(Berry_Arc_Class_Set_Range_void_int16_t_int16_t) },
    { be_const_key(Set_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Angles_void_uint16_t_uint16_t) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Arc_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Set_Background_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_void_uint16_t) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Arc_Class_Deinitialize_void) },
    { be_const_key(Get_Angle_Start, 15), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_void) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Value_void) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_void_uint16_t) },
    { be_const_key(Set_Background_Start_Angle, 7), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_void_uint16_t) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_void_uint16_t) },
    { be_const_key(Set_Value, 5), be_const_ctype_func(Berry_Arc_Class_Set_Value_void_int16_t) },
    { be_const_key(Get_Background_Angle_End, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_void) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_void_Graphics_TypesArc_ClassModeType) },
};

static be_define_const_map(
    Berry_Arc_Class_map,
    24
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Arc_Class,
    1,
    NULL,
    Arc_Type
);
