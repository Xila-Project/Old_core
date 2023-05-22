#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_B04672EC_7B06_48B7_AC3E_16E7AB49D2FB) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_035E64BA_91D8_4CF4_9454_6DEDC656DBFB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_5D1D86A6_1C53_4FBC_BAA0_81C95C7A518B) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_07B39C27_A9EE_4209_B5E7_AC10D38C5262) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_2C66D13D_2BCC_4924_AA20_D407A7F8FEC2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_7FBE73EA_180C_4380_878C_76B310DF8387) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_64CFEF3C_C5DB_420D_BE6A_90ABA780699D) },
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
