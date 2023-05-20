#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_34725E9A_5850_4080_AA32_6425EAB22D59) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_A0757974_A330_4F10_ACA7_8785D3CB93D4) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_40C9377D_EBB7_4B77_B93F_095510C2D0E3) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_1128C93E_0F38_49D0_9639_BBD76B197FE8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_F1B78915_F1C2_45B0_998E_CE196D88D805) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_B96147B6_98B9_4A2C_B030_19C4A0DE9C8C) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_6EEAF031_CF34_4D45_8B1C_04AC85F74FBA) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_FA563F6B_CDD4_4CC5_918D_8C16CACDBA9E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_325E28A7_1D0A_4573_9EA2_58611D4F7067) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_40D05367_D871_49C6_A5CD_008E47889426) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_C0399A17_0994_4BF2_8A8C_B863BD6A9535) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_781238EB_CFB9_4FDD_B845_02800C204A3E) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_C70A4443_80ED_4C90_A58D_594896C81E85) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_21947152_13B5_459E_B7F9_9FBB9E5A0261) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_12D98C51_0A13_43AA_8ACB_083C8C128EEA) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_0F84B538_6DAD_47CF_9C6B_27B822227069) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_87FE4C3E_9E74_4E5B_82B5_14B06B2FA59C) },
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
