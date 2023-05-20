#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_7332BB76_39AF_4ADF_87E2_35E22DFF05A2) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_739C1B3D_E42C_48C2_867A_85D4F580ABD4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_E1BDDE11_E149_4E50_BEC6_138E32A54C64) },
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
