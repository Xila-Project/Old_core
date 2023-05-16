#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_F9A0BBD5_793B_43CE_9DF8_0EBF81EF48A6) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_D6AF9BA8_C3D9_48E3_B8D8_1144BBAAF4AF) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_D348B69C_62B8_4F88_923E_F390F66048E6) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_23F2C91D_2F6B_4EA3_A2DB_66AB4E4AB7B5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_A42487AC_6B4A_4C94_83B6_81CCC7B98D8E) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_DD7FB940_8146_43C1_99FF_33D832A30FB3) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_822967DA_037E_4A17_A728_0AFD58AA8B5C) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_C69464B2_0D1F_4408_BCE0_FDA9963582E8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_28536A62_C1B3_4A3A_9205_ABEDDB2EAEC2) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_DA70D7E3_922B_4DE2_A799_520C0426480E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_D8537372_FB8C_474D_B1D7_1FF7A1B1B20E) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_743E7445_2015_4706_90EF_1F85D7708F87) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_AC32E133_4690_429A_9860_414C918AA8D7) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_AE146037_2738_4B28_A9F0_F8C0A0A78980) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_288F3424_AB4A_4CA7_86A1_CACF3AD073D7) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_89225032_2790_4FE5_8121_35393DD379C5) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_CED6C806_677A_4FC8_BCEE_2759683D9A1B) },
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
