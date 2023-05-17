#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_58846B99_2E64_4706_8DDD_830F51F59767) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_53F17CFF_7524_4DEC_835C_5963058CCA4A) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_2B7E3D4D_8BA1_4EAE_B41B_6C8A92BDC095) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_D54BD273_4EFC_4415_9153_3FA18D367BA7) },
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
