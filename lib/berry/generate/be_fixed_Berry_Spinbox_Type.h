#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_5D9B6A7A_7F74_456A_BAF0_0C525BAABD1C) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_FC033E74_99B3_4C5D_BA45_F831CB316783) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_6D416971_E58C_4A04_9C04_F25329754BA2) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_4C58C887_3224_4F76_BE51_ADDAA5EE2F1F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_0683DD6B_6DFE_4363_97D9_6E808958FB1E) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_9C17DB03_C054_4720_9847_D866E53A5661) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_F0365984_C8BF_42A5_9E50_D3C2F2B30F0C) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_D55A5E0F_CDB0_43E2_AA02_AD763F6918B2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_5AC816BF_53CE_490F_AD76_6154E3F95EDA) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_D822553A_563D_4CD3_90C4_85D2B106ACD6) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_1BCC2E22_512C_4E02_828D_8844ABC5B1DC) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_55D8AB85_9393_40D9_A809_F46B76E66D31) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_596C26A8_E25D_4A78_A331_E8D0BB2B2C4D) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_5024DA72_25FB_4F35_8D98_49A41D630BCA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_49F54AF5_0FDE_4AFD_8A29_1E927F195AF9) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_887F7913_0686_4C0F_BAB9_6E6422B26232) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_4905C2FB_0713_4038_963D_1CE441AC5069) },
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
