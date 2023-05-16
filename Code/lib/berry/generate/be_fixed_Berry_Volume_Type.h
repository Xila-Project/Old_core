#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_BED7CA09_3F30_4A82_B45C_D2310A74BECE) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_07301DF9_74A2_41C0_915F_C3A55644335B) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_193D0E0B_FC33_4DBE_A560_6090A6FAF84C) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_35CBCCE0_66E8_48B9_B4DB_B638C6AF2C59) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_9234C6A9_9CC9_47F3_B68E_8D7CA1E0948C) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_019BAAAB_120E_4202_ADC4_135B26C75A46) },
    { be_const_key(_p, 2), be_const_var(0) },
};

static be_define_const_map(
    Berry_Volume_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Volume_Type,
    1,
    NULL,
    Volume_Type
);
