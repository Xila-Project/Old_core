#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_B7F75433_EEC1_4642_9A6B_22DBC84001EA) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_3EEE1895_97BD_4D9C_A644_16AAEF62DD74) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_BA6EB8B1_3F10_4605_AFC1_58D826F781D2) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_45E35A76_4172_4751_B6A6_3DE8328DC6C6) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_FCD0BDC0_8B27_4899_9342_9542337D47BB) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_6FFF7ED2_D859_40F3_A1DA_26CFF6CF90FA) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_748DD7EF_35E8_4ED4_BFA2_0869D84E6353) },
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
