#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_FF6CCCF2_595D_403F_B93B_C7651070D782) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_461168B1_B7E5_48FA_AB11_2D544E22EAF3) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_831A729A_18ED_410E_A428_736CD1BF1E1C) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_3D79B805_23DC_4B0A_8574_AA9FE4C2AC1A) },
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
