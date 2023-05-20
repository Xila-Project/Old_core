#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_A9A7ADDB_B523_4F54_801D_9F437E09CC19) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_67D0A0C6_5013_4D41_9FC6_1DACB5E213B9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_A6F291E1_E6D6_4C29_A0CC_F2301AD421A9) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_08AA2736_D34E_4E8E_A7E7_35EB4B92F578) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_6D601869_D1CA_40B4_8734_90567BDB8476) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_80FA9224_167F_4F29_BFA3_98DB7ACEE1B7) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_1B502DBF_C1AA_4B66_840E_EF69BAAC0987) },
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
