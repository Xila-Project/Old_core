#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_06C52118_A19B_4550_99D6_E2E693FD7B63) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_BF3B29D5_0BAB_4B73_99A4_3F71E31DB28D) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_A05F0065_688C_4FE4_948A_0827E6F4E6DA) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_7B700901_671E_4672_A1B9_F841AA24E1F5) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_7217134E_F28F_4BF7_846B_D48313E86F20) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_6B40A2A7_E3F0_4BAE_AB6D_64F2DD6336F3) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_3E919A7E_FDB4_4CD7_80F9_C73EB39184DB) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_18FF6AD3_8DF6_4D69_A0EF_33A5F5107DA4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_FA2A7BBC_5299_4B09_8711_332335C5754A) },
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
