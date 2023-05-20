#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_9BD16465_1883_4047_9360_A09E8003AAD4) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_81BA7E4E_0CE4_4727_8714_640908D9782F) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_26397371_31DD_4E14_B06E_D5C1F91F0422) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_F79F6529_0BCE_4DD1_99EB_9B5A7A3B17BC) },
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
