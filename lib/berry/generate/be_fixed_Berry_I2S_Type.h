#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_59C8550A_C3B5_403B_B81E_F53BD7FBF523) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_2E1972F5_0C9E_44F8_AD24_4E149620CF94) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_F359FA3E_A85E_4F78_9346_783B1A99E45F) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_74340F9A_9BB4_4AAA_BC56_9FCBD695CCAA) },
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
