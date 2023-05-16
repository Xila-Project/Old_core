#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_7A213BF5_EC64_4DD9_BA6B_12161E683AA5) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_D2DC0DC3_B264_4ABE_A49A_94C8F9F9C121) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_D19268B4_147B_4980_8467_B80ABFECDD12) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_524CEDB7_DA79_4470_90E6_4876C7C39E97) },
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
