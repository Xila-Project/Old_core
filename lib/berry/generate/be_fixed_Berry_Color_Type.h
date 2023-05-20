#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_363C8927_FCDB_4803_AD58_8B6ABC10C6D0) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_CB5AABE6_08C4_4DE0_9257_61698DF34689) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_42B8D30F_409F_425A_8D73_44E2BF3D8E40) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_3A555EEC_E209_4A22_B40F_2E6105F92DC0) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_102A5ECA_7E4D_487F_B417_431229191C45) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_942F6D5D_82A6_45AB_8E85_62003EC2525F) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_1CE879FD_1A29_46CE_A282_B71747A70DC3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_65E2AAD8_A0BF_40F0_A016_79990552A4CF) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_D6BE8EB5_6C6F_4205_98DA_7696F97D8953) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_EDEAA1D3_08A7_4821_80EF_B38CAD009542) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_5FB7B247_93D6_4A5C_8115_221FBDC5C34D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_A0FFB28B_8BCA_41A0_8200_D5581DC91748) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_2A7BFA69_71D8_4F97_9FF2_E6B15CB4A5C3) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_B1B73B8F_0CA0_403A_BED2_819C5A21DDD1) },
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
