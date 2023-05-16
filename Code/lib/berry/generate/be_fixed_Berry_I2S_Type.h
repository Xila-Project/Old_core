#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_575EC2C9_EE82_4BA1_98D9_6FEBDCC96995) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_33270310_BDF9_41E1_9FF6_64035C06FA08) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_F32986D2_DD63_4BAC_9A62_599D971455B1) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_FA6C3964_FF11_4E2D_847A_ACE609F0398D) },
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
