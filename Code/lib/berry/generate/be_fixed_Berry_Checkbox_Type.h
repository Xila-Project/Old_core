#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_3C6CF261_3642_44F6_AE73_CE8AE1B51C5E) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_F599145F_E4BD_4E6B_8B03_FD4B2E857B29) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_6A2CFBB9_F84D_4D07_B8FA_0C16C3F20E0E) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_C6E14114_B33E_42D9_8D8C_4ACC6136A8D4) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_10A60691_ABD0_48CE_88EC_60C1D9E21B8A) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_5EAC7860_EE18_44E9_B68E_3BA502AD604A) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Checkbox_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Checkbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Checkbox_Type
);
