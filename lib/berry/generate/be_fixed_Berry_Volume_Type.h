#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_FC394608_89C1_4497_8D5D_313589D5AAB0) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_738D9DAA_C2A8_44A7_AF64_11BFF56A3B0B) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_02DC0D76_D6E3_418D_B64D_F487DF49A9D8) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_E444C993_7ACB_4287_9982_EC923DDECCC7) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_DA0C7A1D_254D_4174_BABB_E9B0F5FA00C7) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_89C41D84_17BA_4508_B1BB_3DD5E6FA57D1) },
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
