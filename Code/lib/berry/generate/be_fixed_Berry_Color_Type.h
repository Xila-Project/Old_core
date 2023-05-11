#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_00671757_6760_47DD_9EEC_2495E77E98A6) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_3143B29D_7D1A_4C5B_B8FD_0BD3601D0302) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_1DEF5AD4_F00E_46AD_8D0A_D00C39F57865) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_C990510F_15A9_4600_BFEA_73EC580B5BA8) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_AAFE12A9_A7AB_41DC_9618_18766432528F) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_F0566832_88A4_48B8_B97C_A58A59DDD2C5) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_22C8777C_87EE_42C6_BDAC_E08B51BC89A0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_EC2E1A11_00FC_49DC_9944_1D542340D837) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_D06B9895_862E_4D67_BBC0_2AD8ABA2B102) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_1F2B8955_247F_40AE_976A_8CD9DA553689) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_A47C1BD3_D1A5_4934_A3BC_A222B0933944) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_A99B0B16_9F59_40D5_859E_B5FE51ABE1F1) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_158A254A_4491_4FF2_88B9_F675745DB0ED) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_6B34F18B_E0F3_41A4_986B_9276F474EC4E) },
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
