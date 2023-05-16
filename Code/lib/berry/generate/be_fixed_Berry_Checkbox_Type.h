#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_4BDF76DA_86A9_4BCC_B1D1_27E1E55504B5) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_B96E5939_1ECD_4F27_A16B_6F9DC1A79CDC) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_E53DED6E_E079_4E6F_96D1_A4278E76DA36) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_1DA196CF_47AF_4F58_90CA_DD021600DB54) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_2352DEB4_B655_4EED_B81A_D75D638BCAD5) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_D7A58DF0_E717_4777_9BA8_D92C013777BF) },
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
