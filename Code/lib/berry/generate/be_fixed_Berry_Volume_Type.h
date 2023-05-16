#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_0892BA20_618A_45B4_8D6F_CA180AF84F5B) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_C6021244_4F97_4FFA_A45B_4C7BFAD397A1) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_A14609F9_3874_4BC9_AE97_8BAE7F11307D) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_B143D3A9_B3FE_4AE0_B667_919AA2B91AE5) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_C72D2C48_8593_4AFE_ACA6_C5F1655255B0) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_DBB4BF25_0F02_449E_8C11_D5B053395CC5) },
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
