#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_584574D9_E6BA_4969_A856_412BFED5E415) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_9619D2D9_6BF3_4739_9D3C_31701AAC3A77) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_3FAC7E6E_38B0_4371_9A12_74C1DF8CEE1C) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_5F9494BF_6834_4F10_8A67_048AAD0DE815) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_61020146_5103_4953_B920_6BB8C29CFE5A) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_BABFCCF4_EE45_4C9E_809D_E7419BE52A9F) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_2569CB4F_07F5_4051_9112_A0BA4F0A2C1D) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_B1EE5702_50D8_4693_8179_0A91392525A4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_C8D62024_C843_4E9C_AE0C_770EA44438CC) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_D2597C00_019E_450F_BC52_F91583E43344) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_7B7CEF84_8C37_41A2_9796_9F2F6FBCDC4C) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_D5E6620C_5B8D_4479_894D_81079965FC54) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_E54F8FC4_B8CE_41F4_A153_8CAB00C7CC46) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_B85F7291_8B24_4475_8F13_9723AF01F8BD) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_C88B8CAA_FC3A_4DEC_AE72_F077FEF333F0) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_3FEAD9BB_384A_4189_845B_A7B068B68096) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_82DFC033_B0A9_41E0_865E_EFF581D8A812) },
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
