#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_E968EE98_FCD3_4190_BF7E_2BC5C935654D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_69AA6EF3_069E_4ED7_B308_ED57B3737708) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_065045CC_FD9F_4B2C_8301_08D617768E37) },
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
