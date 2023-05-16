#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Type_map) {
    { be_const_key(init, 14), be_const_ctype_func(Berry_Color_Class_Initialize_C085289D_59A3_431E_A8B1_3FF6578F32B3) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_BCE35989_3206_43EF_8AF3_81FEB1E5D80E) },
    { be_const_key(Get_RGB_16_Bits, 11), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_69A55D23_73C4_47FA_9780_FA6937F6F8D6) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_32312762_1245_4B6E_83E3_6D9BE39EF853) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_22F7703C_2404_4D36_BD56_5379D479B970) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_022F931F_C482_4F5F_A3F1_9C627099701F) },
    { be_const_key(Set_Darker, -1), be_const_ctype_func(Berry_Color_Class_Set_Darker_01F5B0F4_1489_48CA_94A2_EB8ACF86C9F1) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_46552349_4B7D_4775_A74D_42DE26172980) },
    { be_const_key(Get_RGB_8_Bits, 9), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_E9F2044A_8CDD_4B80_8F2E_F0C1B93F2BE6) },
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_58103B5F_8318_4981_B84B_32921CAFC7FA) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_CA13EDE2_D0C0_43F5_8F49_A56880D75A88) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_AACE9EEC_4186_47B2_AE22_948266809776) },
    { be_const_key(Set_To_White, -1), be_const_ctype_func(Berry_Color_Class_Set_To_White_0FFF931F_3067_429D_B62C_5AD3BF332E3E) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_E3E25E1B_141E_404B_9A63_DB6A512F0A04) },
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
