#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_429B8396_AF81_4965_B4F1_6713C5C2CD85) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_C4562C78_B15A_4808_9B13_1C11F129E102) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_47374D92_839F_4280_BBC7_F615EA9978C8) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_64326788_15C9_4DE8_8CAE_D18B477AEA4E) },
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
