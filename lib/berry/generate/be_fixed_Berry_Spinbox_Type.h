#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_44B1E62B_DB9B_4E57_9C55_7E6D35CABA34) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_40B0C1BE_999E_471B_84D0_E5C8DBE119B7) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_F88A8F0C_0432_4316_BF1D_0F8AFA715AE2) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_98456757_30E5_46FD_9146_0475BC4EF045) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_683CC965_42B7_4BE3_96D2_72E6C0A059AC) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_DC770E6F_6C37_40F4_9B03_14C913A6AF65) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_A523AAF2_2BFD_4DC1_B30D_4455ECFDB7D3) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_ABD47936_10CC_4708_8A64_1A7749DA40B1) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_AD929A1C_D079_4FF7_95DB_1788CD6B2962) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_40843619_867C_4517_8BF9_1BDAF1AB3E5B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_75B8D8A1_0439_4A7E_813D_6C306D44483F) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_26523E8E_A891_4A8E_AEE7_BF04F1553A1D) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_1203F78D_B1F4_4C98_A34D_8DC380C43427) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_97C722C0_E8B4_4C3A_85F7_77CA3A8AD936) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_B4FF791F_555E_4579_AEC7_5B26885177FC) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_333381FE_F4DC_4F48_BC47_79B5DC618C32) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_E0C31302_43D9_4933_AB61_DBDD90646B82) },
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
