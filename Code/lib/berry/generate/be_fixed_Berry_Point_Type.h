#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_9AC26FF1_C90F_44B8_8BD5_24B81DBCAFF8) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_78107879_0B1E_44FD_A8D2_A3506523443F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_19F8820B_3440_4CDB_8636_C4E1B13426AB) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_63601006_AD6D_4A88_957B_84C2A8379B60) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_8BCBF30C_2AD2_4928_800D_2EBE9B605E75) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_E9950549_6211_44F7_A2A2_4C8161E4CC16) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_196F3E39_2241_4917_869B_22A44A19F8D4) },
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
