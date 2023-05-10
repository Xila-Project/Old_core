#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_E2FBFE90_D42F_4D8A_B5CB_06A18A03DC4D) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_B9FAC43C_4193_4DD8_BF81_9B401B6CDFD9) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_01320895_7A00_46EC_8F51_E206787F3083) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_A4B78750_5180_4355_B45F_0ADA44B1F847) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_5C32FFE8_0EAB_4C68_8F39_30FF95CA730A) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_383410E6_B28E_4592_83AA_3854885B43A3) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_B2446B44_759E_4251_9D07_E89ED65638D2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_2E4F2E1A_9777_4E57_8F42_BB93EBC77602) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_95EDF6ED_2030_4AD4_B74E_82A0F57847E1) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_5B4EF431_DCF0_4767_9A0A_C06F977BCC42) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_F28DE5AA_F030_400B_835D_461DF8B08773) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_24B9FFD2_9F78_433A_9062_8326EC230CE4) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_9C97BA42_28CF_4D3B_9FC0_D7534F99180F) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_FA2C4801_534F_4C77_AA2B_897CA45D94BD) },
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
