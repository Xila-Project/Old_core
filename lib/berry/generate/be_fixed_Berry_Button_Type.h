#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_80E07156_A429_432C_98A2_05853CCEE4D1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_1DCE0A35_3B9B_437E_9E8E_9E66286F1CE9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_63C9F3CF_778A_4C58_8EC3_2369F534303C) },
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
