#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_1379B685_32EA_45FF_94CF_3340AFC414B4) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_2CA83FED_BF5B_497E_B4AD_E9759A7949D8) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_0087F14F_43C7_4680_B505_DC1B5DC589C0) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_8F45D900_DCC1_443E_BC24_66D24C21B521) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_3FBB7482_4B1F_4803_8B49_60C169E126ED) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_50ACF0D7_05E9_467D_9D88_7125B21EA7E2) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_A42D6582_AC3B_4F58_949F_DEF6A0FC2B1B) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_C2BAC32A_1F35_4F53_983B_856F28776FC6) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_9963414A_0835_46E9_B85B_613D07CE0B0E) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_3E21D8FB_1FA9_4C22_BC70_E5AA9D643930) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_E2D881EC_4EA6_40AD_BF37_51F1CED22FCD) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_F71135F2_0F87_473C_8918_9F72579A7EB6) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_9DDEC978_2391_461F_A476_DD2BAF52EA35) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_BF1C8E7F_3B57_485C_A25F_DA586149E91E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_BAC0D694_E9FE_4FFF_81D7_C99C8B8EEB47) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_0706B45E_31B8_46D8_9A84_E77CE40077DE) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_63A94E48_0325_47E3_B987_06A560F80F3D) },
};

static be_define_const_map(
    Berry_Spinbox_Type_map,
    18
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Spinbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Spinbox_Type
);
