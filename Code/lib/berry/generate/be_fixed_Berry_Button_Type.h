#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_80E8374C_BDDE_4668_B915_900D9F55556C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_B98AFFE6_A78B_404C_9A3C_EBAA5B629BED) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_5D8383EB_DA2E_408E_8CD3_7214F8581CF0) },
};

static be_define_const_map(
    Berry_Button_Type_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Button_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Button_Type
);
