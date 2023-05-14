#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_A294B953_1A21_407A_81AF_155B5F169554) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_3D2526E1_FF79_44A4_96CC_76A92235954A) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_8F816D98_0A8A_415A_8AA3_8E3528527191) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_618F43E4_402E_4EB1_9315_DF264D3440F8) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_DF1ECCE3_5AF6_4CF3_AE29_9B5AFBE90460) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_8062BC5A_4866_4828_89CD_9A561F1A5F02) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_5A77091E_D2C9_457E_920F_BBFB986B2030) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_49DBD6AE_985B_4267_9A9B_B4A3E02E3643) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_FB2AB864_3FE6_4FA8_8DE7_D03F9892DB45) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_CC468E5F_C2B8_4519_9DEF_969535B726AB) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_8E5B03C0_B88C_4E68_BFE7_BD3B69A12610) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_DB09126A_8B9C_4CDD_8B01_E9AED273E123) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_85E5D9DC_EF3A_4EBB_9229_BFE587EC40DF) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_1B0F814E_08F6_4AC7_B1D4_2E7F3193C525) },
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
