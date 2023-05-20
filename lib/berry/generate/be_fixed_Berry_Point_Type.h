#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_AD972F73_25CF_460E_A1F8_95EE9529A11A) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_E6643E5A_C554_4B75_B244_C4129030E337) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_B6C1F284_CAD5_4AAF_BA0B_5E59253A926B) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_7DA3ACF8_B8DA_4BDC_B2F0_B5F1921D3C8E) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_06FC670E_0471_4DB3_A55D_7BF424F2F38C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_2EDFF31D_EB43_4B9D_8DE7_146D3AAA3856) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_47DE1E28_6FD9_4D42_856E_342DB29BB8A7) },
};

static be_define_const_map(
    Berry_Point_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Point_Type,
    1,
    NULL,
    Point_Type
);
