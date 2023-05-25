#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_A9E0BCC1_AD07_40A5_8D9F_57599C5A907D) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_3655796E_8D51_46EB_B1C4_EA97320B91F6) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_E4A87B5D_BA93_41CC_AFB7_81965FCF3CC4) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_2AFAF497_FD83_4F63_8ADF_8BC695F0701F) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_8EBE126F_D9BE_4774_9E73_CDFFC61A35D9) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_CD115652_1F0F_4B3A_8019_F51E2E559859) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_446EBCB4_5EE5_45AC_BCB8_25E240F41B2F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_2F9756B6_840D_479B_8A08_9D6EB7B31333) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_0484B2DD_7F28_4D6B_905A_857B3E0523E9) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_CB48329D_2971_4269_A919_4AE41F86667B) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_DCC23DE0_7BD6_4C1A_B89C_DD257BC3C3A9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_06657FFF_1802_4A22_B5AF_425A8CC90F04) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_89530B32_8C75_4AA4_A8A3_C52730091D5A) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_E1D29845_7354_4552_A867_9D1B608998C0) },
};

static be_define_const_map(
    Berry_Color_Type_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Type,
    1,
    NULL,
    Color_Type
);
