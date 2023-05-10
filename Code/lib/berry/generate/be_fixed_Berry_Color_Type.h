#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_81E38BCD_8DA1_4587_8E74_3EFB8001DFCF) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_2BA11FAF_EB4B_463E_8B7E_E24FCEF6C24F) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_1ED48FA3_4CD3_4C50_A022_EC6C374C210F) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_88F90D64_BF9B_4A63_A641_256B4600A133) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_3CD987D7_DFA8_4F17_9479_E92E92BFFC18) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_39395433_5E27_4650_872B_4738ED29DBCE) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_FD3F8B0C_92EA_4BA4_A161_BA16812311F5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_45D98360_12ED_4A4A_A869_15B978964946) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_26C430B6_D971_4B16_88BA_3F3A7BDE8109) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_27E968D5_EFB7_4D96_9D03_CDF03A2512EF) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_BD709525_7FB4_49C3_91C7_2825D6CBF06F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_A4211B4E_0B24_43C0_B180_AA84B0F7AE53) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_26C44AF0_7A94_4EC1_84E3_24CDA21B00E4) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_D95B6170_934E_4BBE_8BCB_FEFD03D65C33) },
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
