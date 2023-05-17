#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_36C08B82_B9EC_40B0_93ED_D7D5A8FFDB14) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_0A8F9C88_5832_409A_9403_0FF5C2F385E7) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_F7C93BF8_66D5_4D9F_99EF_518986B37A0C) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_F89AFD5E_9ED5_4CB7_9B0A_2606BCB7F8CF) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_26B5C265_495A_4CA3_8D51_A8D1EB615C71) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_C88AA321_05F5_4A91_A35A_A5642F79C743) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_064CE556_2C59_487A_8EC8_BD41F9A8CE5C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_BD4E7270_345A_4DD5_8690_539F7F7EAA70) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_397C2E4D_9A10_4D12_B57D_39C5AAC32DDA) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_0F097E72_874F_48CF_9DA4_E590B3C92C64) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_96E8B7AF_238A_462B_989E_AD222BEFA846) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_E438972D_0A16_430F_926D_155C3DF2FB40) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_FEC02BBE_01A6_4EE3_8008_0665A20EDCBA) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_7411564E_CF96_40FB_8C1A_E09D7270C5A0) },
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
