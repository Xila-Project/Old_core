#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_04FB062A_4CF3_4AFC_BE1B_705DB308DE0A) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_702878D3_3422_46F3_8B70_F340C2D9D63A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_A3DD7DF1_7A68_453C_9658_1B5C45BF8AD1) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_A151F713_7C10_41E2_9F46_3917EF467B43) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_5EADF18B_305E_4A84_92E8_CD01447A5C23) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_C662B08A_E9C1_403A_8FE7_47F0CB3BDF31) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_CDD8858D_90DD_4AC4_92D3_9E8C7B99C9FE) },
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
