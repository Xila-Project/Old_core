#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_CF544C09_C036_4ECA_B85A_063F29A6B73B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_093AF65A_C697_4BFD_A9F8_41A802317FA8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_2BE2C11E_7DB3_438C_8BCF_253308AA6B67) },
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
