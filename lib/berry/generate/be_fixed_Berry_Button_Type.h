#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_4C62268F_E5A0_4131_A2EB_243930ECB310) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_28CACDD6_9723_4C1A_8E9A_E5B8D9D0781C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_9AEDAEF1_9E70_4CAD_B69C_3355E4D4CB69) },
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
