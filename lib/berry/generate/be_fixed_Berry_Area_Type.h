#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_A35F7CFA_E720_4F94_9426_D0C40E5EBC75) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_F08AC4E3_5E7B_4F22_B3BE_942145A586BA) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_B899350C_02B7_4502_AEA0_EAF008363E06) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_F3B6BDAB_38FF_41E9_AC42_6C2EDEA68B0F) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_23CAF80F_117D_4758_96D8_906884CCA3D6) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_E8AE233C_A809_4258_A530_5C299ABAD6FE) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_9D7597AF_5B2C_4D84_8972_D4D073950917) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_0AB1FC83_6EED_4D67_9555_CCEE4A72D697) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_292AFCEB_8F5B_4E22_817A_ABD914D2492A) },
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
