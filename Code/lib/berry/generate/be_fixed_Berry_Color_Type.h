#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_A9C68430_D832_4B6A_BB11_C4DE8F8A0D81) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_09A3FD2C_1E37_4314_BC0C_5F61BF7004D0) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_8310F6D2_4D36_4D08_8FB9_84473BBE4DAB) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_6F7DBC01_0333_4D65_95DD_6671FBF4CBC3) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_92F6EC5E_93F0_48DB_A86C_10E618D41BBD) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_2D01B53B_131E_43FE_A6E9_F95CC8CAA2AB) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_01B86A21_204D_4DCF_B37F_6B8D77882614) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_9C92A35C_DA5F_4D73_877E_7646F2B8DCCC) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_DECBE15D_C818_41C6_8536_7E2E6F18C803) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_45C3AE12_9F03_4A1F_8B12_B275EC464B12) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_78EDCA0E_6CC5_4A39_8D3C_64FAC7013E41) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_FBFD8F23_7CB3_4910_AFEC_3A2E4E3DCF8E) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_1912F61E_6614_4074_A114_F1590E49CE15) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_89576DBA_BDD9_4712_A979_1BC171DB7B93) },
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
