#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_0C462471_FA61_4B68_B5E9_A978C6D2AEB2) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_E20F1EFD_6987_48D1_AB40_97332140DADB) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_66959ECF_9E24_427F_ABDD_8299F1FED6F2) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_71B166CB_2C30_4588_9DCD_B7590C094594) },
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
