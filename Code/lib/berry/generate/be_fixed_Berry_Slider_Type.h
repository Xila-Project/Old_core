#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_EA3E70FE_FDF1_4D13_9CC0_9EE7EAD20488) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_A4498738_379C_44F1_B526_9195820939C9) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_B96EC0F4_AED2_48D4_8B8B_48BB1BB9019C) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_670DA491_643C_4521_B829_E87BFC4A100F) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_D1E79A57_BCA3_46BC_A1E1_BAC9B31885FF) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_52CA7862_901D_414F_9E84_4905B22E8181) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_42FF820C_9F08_42FE_BF99_C65D8696B959) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_2C1856A3_6EDB_4834_AF5A_F328708644C4) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_A41BFEAE_ACE6_4FE2_AF9A_333AEFA756AE) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_A9421F52_6E12_4BF7_86B6_347AEAD818C8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_D5FAD7D9_B341_45A5_A7E0_3EF30C8486F8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_2D2EFB08_4473_40DA_9E1A_3F2596D71645) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_E0ED92A2_6CC3_4BB8_A944_ED9887893490) },
};

static be_define_const_map(
    Berry_Slider_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Slider_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Slider_Type
);
