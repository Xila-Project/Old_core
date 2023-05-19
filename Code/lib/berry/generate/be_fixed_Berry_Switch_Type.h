#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_48E7EB95_1ABF_4657_8B41_8E0FB0C992EB) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_393BA8A9_8F89_4CF9_B0F0_3FE3480F57FC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_2A780C5E_1125_4CA7_8D88_B8E21B2B4DC2) },
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
