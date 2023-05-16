#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_14E262E6_29DF_44B9_8476_2FAE1AFC1A1C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_20F3B927_0BD0_4D87_B888_4DB35085826D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_DA197A76_1520_4DC3_A0E0_0FC006A3E097) },
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
