#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Wheel_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Color_960439D9_D6BE_4D40_B112_2A8937BD587D) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Color_C17F90A6_C9EB_43BF_B44D_59386049400F) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Color_Wheel_Class_Deinitialize_A84B6165_7E8B_4D44_93E7_1CE6400451F6) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_98EDCF20_EA41_4C3E_96FF_79CB47E933EA) },
    { be_const_key(Get_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_Fixed_8BA08789_AC3D_4247_B17B_E2B720E07F70) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Initialize_5716112C_A562_4AEB_B34A_2CE5BB560D55) },
    { be_const_key(Set_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_Fixed_4851E2C5_D463_4345_98D0_5BDF57ECEA04) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_6B7B293D_4743_4944_9E25_948DCE787F44) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Wheel_Class_Create_A5501503_FFB1_4821_BC88_54473845E5A2) },
};

static be_define_const_map(
    Berry_Color_Wheel_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Wheel_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Color_Wheel_Type
);
