#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_028170FB_1D6D_44CE_909F_4B3DD6387FF6) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_9398C700_DD3F_4E09_AB1D_F4EC28393002) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_806D8D26_099C_4745_8509_95933911E247) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_5C9BC975_5968_4C12_9C99_C675BB493DA7) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_D945115A_0202_4542_813C_2518A9273E11) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_FF57125E_8326_447A_8B77_C2028C5628BA) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_895E6041_6EA4_49C0_8F9B_C0D3189BA84C) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_5111E3C6_FA26_4DD0_8AAB_ED8538A1E277) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_A3DEF1A9_511D_4126_B4D7_CF335CBE3CF2) },
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
