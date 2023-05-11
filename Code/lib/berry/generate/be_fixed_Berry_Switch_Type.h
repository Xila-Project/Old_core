#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_F29369F8_2CE9_4775_9A3E_205D7182DD67) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_0E0BCEAD_356C_4724_8110_2DD703BF0DE9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_0D9BEBFF_E697_4A28_8076_C9E16CCBB494) },
};

static be_define_const_map(
    Berry_Switch_Type_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Switch_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Switch_Type
);
