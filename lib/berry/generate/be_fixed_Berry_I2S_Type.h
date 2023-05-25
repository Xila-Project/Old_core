#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_0D112FD6_4A8C_4884_9420_385254378F30) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_0E82D688_839B_4FBF_B0DE_5E47973EB6B5) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_F590F951_5E80_4077_A44E_9736AEC1C5F4) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_133F5C7E_CD19_4E12_BC94_6983CDBB8CA3) },
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
