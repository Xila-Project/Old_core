#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_43291D6D_2E10_4423_9D54_A13F3367DE2C) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_D645D814_AAA6_4CFF_9A5D_7B0F3525536D) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_177F0078_D3EF_48EC_9B70_BC5E8D35F9BC) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_D08802D7_A98F_4A3B_A568_97C9DF3CD4D4) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_F8E1F22D_008A_4DCE_AA71_3C07104F7B4B) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_D511BF2C_8E7E_4E48_A466_547135765662) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_C7C727BF_9991_406C_9738_9B423BE6D386) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_2CCDD7E6_0A50_403C_B7E4_D9F8A598A2A6) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_C99E5B74_380A_480E_8F1F_00265E57F0BE) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_55D670B5_0BB8_4E3A_9B13_15866438EB10) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_D3A9D15C_DF94_4DAA_9489_C10F1DD8DE8B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_0E89F40F_BDC7_4A5C_967D_33A3EDB3A635) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_55307408_1795_40BB_8AE4_FF6340135239) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_047AA031_BAC1_471B_B6A2_BB14F5161128) },
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
