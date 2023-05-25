#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_8BDF4889_5D11_4378_86EE_8FD50CEFD964) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_82B9681D_6209_49A1_8327_356B4F9C9B3C) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_AEA651A1_7D06_4B7B_9E55_F39C8F2A04BB) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_1E04F306_52AA_4AAA_9801_7092A291D513) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_6D6B93CC_9149_4282_A6D4_D4A1A4690C4B) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_98E94C42_BDC1_4F89_8C1C_3CA614DCFD19) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_D9B6EF39_C431_4BD6_B5B7_3E124936A5B0) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_03FC3062_3017_4892_92AE_4252C66BDECF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_EADC02F0_5757_478B_A38A_7105131C549E) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_FEAFE3D8_964F_44FB_AF62_ECD1F8B08B7F) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_B3C737E0_5578_40BB_9E12_885498E8253F) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_962ED627_C424_4643_B24E_EDAC9DED4283) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_D7B5D7FC_3B5B_4719_9664_08293A693F85) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_17F3024A_789D_40F0_893C_ACFC6B5291A2) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_0B0FF77F_9D43_4C15_81EB_1DB4C39786D0) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_8FF69CB6_E67D_45ED_B7B0_4B8D5F26E9EC) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_2E293554_B912_4BFE_BBC9_BC9BFFC90FFF) },
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
