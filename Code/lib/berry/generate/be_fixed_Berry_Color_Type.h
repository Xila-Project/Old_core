#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_92DF4A9D_1742_48D7_AB34_8C6B0126D67C) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_BA3C7268_81F7_43B4_8D26_34ED7B2480DD) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_85E408D5_8994_4CC0_B313_9B6BCC57C295) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_BBCCA6F7_3B88_44E1_B63D_0EF2CFC8CC03) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_A34BDD94_A8B0_4A65_A881_6261129CEC54) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_B7BA30A0_30AD_403B_8B29_687F1648EA14) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_FC1248E4_82C9_4161_80DF_83715E22D84E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_20FEA52B_B6C6_49AF_A0E4_BA942CBF69C6) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_286F9264_F095_4A82_9046_51ED16864050) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_7A7506A5_DD97_4620_9444_19D59EB89F70) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_9D5A3B22_884D_44B3_A6A9_CF40DA3F36B4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_25A4A0CB_E58F_47D7_A6C8_6705D57C54B3) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_1D711EB3_251B_4CF3_93AC_23BFAD177D5E) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_B480205B_ECE6_4A1C_B33B_1CBC570F94FB) },
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
