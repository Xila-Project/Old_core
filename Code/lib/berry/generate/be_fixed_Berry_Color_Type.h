#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_4746C8DA_3FF5_485E_AEC6_DC509E8AABDF) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_D3D9B0FC_D433_410F_ACCA_D7993AF4FFC5) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_496DE18D_66D0_410F_8184_E384D0C9A72A) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_829D96F4_823B_46C1_8894_0B6AEDCC7A50) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_D22FC23F_F599_42A5_B330_F87C46B455AC) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_93714501_3D1D_49C8_93F9_84B3900F4105) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_6855251F_0E2A_4532_A8B9_EDB493628301) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_0C7E41F4_0BB8_457D_9A10_CD833B83E823) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_A7478F8C_59C1_4F8E_94ED_49D38EB276DD) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_1E1F5414_E5FB_40EF_88B9_949D9C1CACA5) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_6C7F8339_3A5B_4B2F_B780_2E3C60E8B86C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_99F12D2B_EFB1_4F83_AFB3_35D0399B7916) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_BE289C1C_7971_4735_B21B_32D948C13EDB) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_DDC6084F_1795_48FE_8CD8_4FC9701157B7) },
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
