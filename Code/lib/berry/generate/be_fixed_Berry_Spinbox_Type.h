#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_0B9B4B2F_7194_4067_8AEB_F7A87DBC124A) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_FB3BFA25_ADD0_4BCD_98B2_20F6C32ACBC6) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_FCA14975_24DB_4DF4_A3FC_0F6C11853467) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_A1055B0A_D3B9_4D4D_A520_C611F70865C4) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_617F4012_9FEC_43C6_A6B4_FF93FBC18241) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_307063FE_34A4_449D_849F_D1A097180B18) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_598DC89A_7AE1_4CF4_A06E_F3F7574951DA) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_C55A72DC_E221_4477_BF28_BB716881F72D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_1E0F202C_81BA_4A78_930D_30F9FA3B7323) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_0CD701D3_417D_4494_B98C_6A9A9E65126F) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_5DB86CC9_BC9B_4845_9371_41EAA6B71490) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_C4658A90_F13C_4815_B6F5_75455BD68207) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_C414DE6B_DEC3_46B5_ADD7_4883FC5F441E) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_3C1DCA63_7C29_4297_AF8B_7E2B5528767C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_55FC8BD5_E091_4D21_A6C7_CA2B2B5A99DD) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_27EB7037_CA24_4242_9477_A449797FBE02) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_D84C5CA3_E4F1_4351_B5F5_9F45ADD0F75B) },
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
