#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_563AE2EE_2395_4ED3_8FDC_4A3BF8B2874D) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_B080466F_8DF0_4CF3_9A09_E76228A02ABE) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_17283871_4C7C_4CF1_8B66_5FCA1D38FB59) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_18F27D38_E79B_4CBA_907E_10FB2919E55E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_014EBDF0_0736_473B_AE81_ACA49DEB0BF6) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_E314A3B0_D742_4DF8_928E_9238EEF468F7) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_F8C7EF52_1C58_42F2_91B0_B386542BB367) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_50A4483F_783B_4085_9D3E_F068CAA87D54) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_F9656021_7136_48CB_8576_0DB09A584261) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_2D61515A_BE16_4140_8F6A_F0347ACDC8B8) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_0EAD718A_E04C_4F2F_9787_6454A59F1BEF) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_E06E8A8A_AD28_4146_A182_36C5849AC7A5) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_8F95A142_6FF0_4F22_BE1D_A85690F6EDF9) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_AFDDF2AD_3876_44D4_B9C6_96DEF8BFECBE) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_40E09406_A734_4AFA_B4B2_5B5691372A8A) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_05E7E55F_56A0_4396_8D11_3030B214D03D) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_3E50ABFF_1C0C_4EEB_B80D_7DDEB4A41562) },
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
