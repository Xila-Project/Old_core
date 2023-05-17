#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_1C83B06E_2D0A_493F_A709_9E946B0B8F49) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_509AA3C2_A6E6_4AE1_AA78_B671B9B16C28) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_F67EC30E_FBE3_4C9F_AEBA_CF541E697C71) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_D007959C_42BF_4575_B85C_C1C6E55C485B) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_89FC3250_F353_46A8_960E_D247E415E6A7) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_D35CE5D0_E9F7_41A5_80DD_67E0A84B1602) },
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
