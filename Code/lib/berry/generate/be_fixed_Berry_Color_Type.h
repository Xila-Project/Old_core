#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_34AFC045_3C71_49F3_92DD_94A16612714C) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_075DA9B0_0BE0_40F8_A554_4E8EF977E39E) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_A6A713E9_4F89_4835_9178_D98491193FC7) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_11FCC2E5_BF3A_4CA5_9FE5_29C696AD4B06) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_4E4ED3E5_1551_405F_BCD6_7787DFFB1488) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_BD820E13_4754_462A_AACD_90BE2C18B1D9) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_C7D6C8CD_924F_4E95_9F79_6BE31E316BCD) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_341FF9C3_2A1A_4231_BB10_B623D4079E8D) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_4C3D97BB_1140_4CA3_8143_9B4F96A7EB3D) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_C2E56BC0_0784_4150_AB0A_61C6E3172A6A) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_55E32BC0_AE8D_4AFC_931D_A2C72C03477C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_3ECBF2FA_628C_42C7_81C4_0DF29FA6B963) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_A9CACCB0_473E_4782_B021_1F49E4DB485E) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_6AADE761_FDB6_4E00_8222_88C79B1F4BF9) },
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
