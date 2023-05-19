#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_2DF2D8A5_4C51_4C48_8A29_68A493B9E12E) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_446091D7_7D12_4878_B87D_890E12D7DFEA) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_554DECDB_CC61_461D_8BDA_B677161CC84E) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_A3A34259_8E50_44C3_809C_5999C0A63E78) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_ED632C74_1122_492E_9CEA_EDB9AAB6755A) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_F060D784_97CC_4FAF_9DD6_E2E113CF4777) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_CB32612A_BE1B_4EE3_8E4C_82ECCF10A693) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_2FC833FB_550F_4AC8_8E3F_5BC6E9385898) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_3EB81BA1_C0B5_4348_9D12_8D1247CA2018) },
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
