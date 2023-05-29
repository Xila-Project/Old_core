#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_D277AB96_3A5C_4140_AD44_358250E58D9F) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_AA4D7B61_FF35_45A4_BABF_BE4E96A84047) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_A4CAE5ED_AA11_46A6_9FC4_0C5D4A1F2DDF) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_B8582A71_D5F1_47E9_97E3_8301B872BC4F) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_9EE336AC_7DF1_48B7_86CD_CC4B0FA4DE83) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_A33819BF_7925_4574_BBD1_45B566BCACD1) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_C8CCF388_6C1F_4E10_880F_5083DE7996AC) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_13283213_B46C_4D92_8E65_167FD29D1BD0) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_F7B242E0_345A_4B5A_98CD_0D5F02AEEBED) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_9673FBBB_7378_4B69_97C7_CEA2D0C6002B) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_05C8BA86_9A90_4A79_8F82_CD2229B6F67B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_1230C854_31C9_4FB1_AD4A_E49629EE34CE) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_F1F5B29A_F5E5_4FBC_96CA_44F2948B5D3D) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_25CC1C40_4F0D_42A2_8F6E_C6983957961D) },
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
