#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_FC0368E5_1C0D_4EBF_8A50_B356C1834E80) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_1117EE15_A8FE_4098_AFD8_95ED494FB631) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_4CB67688_B2E8_4C11_9A19_0B37CDE2766D) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_0A457179_A570_4CD7_B6E5_005DB86C7F37) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_I2S_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_I2S_Type,
    1,
    NULL,
    I2S_Type
);
