#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_7D07C53C_FA93_4AC4_AAF8_494A71C298AB) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_F4A90C1F_A223_46AE_B239_2C8A1974B431) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_F3B3FA43_ACD3_448C_BF08_B2668A22591E) },
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
