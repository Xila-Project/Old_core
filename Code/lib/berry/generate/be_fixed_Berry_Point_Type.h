#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_01EDA2E4_E3CA_4E06_93F2_3BBD8BC76C2F) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_9DA9A6D3_5981_4923_92A9_C41E989F6C1E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_5BD866B9_BB2E_428F_A3AF_F652DB82A0FF) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_E7EBCC27_AE7B_4152_8895_6FBEA64D68F8) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_1CD72F7C_610B_45F9_9338_F83CA5E2D30C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_980B4B7B_0E27_4AA0_948C_6E664B1E5C27) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_5CC18D2E_28C2_45ED_BE51_7580413A6246) },
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
