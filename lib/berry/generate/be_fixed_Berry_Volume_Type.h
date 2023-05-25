#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_A2584887_A626_4082_A9C1_7F39E8D34073) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_956BEE1C_38F3_4576_A937_46B1E5E0744A) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_6AB2625A_3EDD_46EF_8384_E86905857759) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_7CBEE0BE_7F49_4948_891F_5418167BC311) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_B6ACCD89_545F_46DE_B601_EE3496A19A1C) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_B9FE2887_8D9B_4D9E_9E12_6EDD17AF2824) },
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
