#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_0D3A331F_8CE2_413C_9659_92462A36A33B) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_B782B6BD_B322_45A7_A70F_B47EB9D37FD2) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_E46C1AD4_4D2F_4449_9DB4_3528635B9F94) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_BF382030_3BF1_43E9_BB93_A5C042FED3F7) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_8E66C055_4434_4A28_80D1_DCBA1B75C24B) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_46B9F9A4_99E4_437C_B7D8_227CC7C79385) },
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
