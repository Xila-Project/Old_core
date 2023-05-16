#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_BA938A38_A38B_4B2E_9CA1_681CB2A4F187) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_AE252AED_90F4_45E1_8B25_2D9E1D3FF6FE) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_3BB695C5_D03F_42BB_81AF_CF365F6F0CB4) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_C3712E7A_41D4_4215_8D73_0BC7718A7FBF) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_AA133B83_D0EB_47BE_9E31_32C86D328A84) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_51D4111D_7FC8_46C4_97BC_E394CE57F0C0) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_69D07B9F_45D1_496D_8F00_00FD3B627C4E) },
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
