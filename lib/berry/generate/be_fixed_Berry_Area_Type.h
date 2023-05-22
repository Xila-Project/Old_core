#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_27FD049F_C247_4531_B85B_A83861A0ED95) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_8FAEAD93_93BB_4E2C_8707_625FC3C64E4D) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_0632F385_4A7E_4E14_B497_0160F4C8CB63) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_8A20D4C7_4E12_4F2B_8D30_F5AF52456E9F) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_4FD68DF9_2CD2_4116_AC03_ADA8F45F9AA3) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_DEF8C4A6_1F8D_42BF_B00F_FF36F89D3EAE) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_C24A92D0_167C_44D8_A283_9A88BADA4EAD) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_808904E5_A51C_4027_A606_49622D1091F5) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_16B5A963_EE0F_4DA2_A444_CF5A6C7C0115) },
};

static be_define_const_map(
    Berry_Area_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Type,
    1,
    NULL,
    Area_Type
);
