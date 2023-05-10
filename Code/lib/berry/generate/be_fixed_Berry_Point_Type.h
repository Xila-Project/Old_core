#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_669F17BB_6EA8_41D7_B1EC_05C4947CCAAB) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_917D6B75_F32E_4D54_A7C0_6A44AF52C555) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_E94C4D99_C967_438A_B796_4B723B2A83F5) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_F33B6E4A_5B02_4C1B_9867_592DDA68D7AD) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_660435AA_7432_41B7_9128_5E3F9FA8AD09) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_233E7275_5944_45E1_B9BB_E64B1DFA24A4) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_AB952FD6_65A3_4290_9255_24AB1E1CB95F) },
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
