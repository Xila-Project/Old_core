#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_AF8509C6_5C21_4306_88D8_60EE0CF9BCC9) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_4A3515B7_1D8B_4DDF_B539_4C3F55AD820B) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_75B3EC1D_E285_4C9C_A7CF_91AD1EEC1BDB) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_7E2254E2_9820_42BE_840C_55BA2D74523F) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_65153EBD_3ED5_44F8_9F21_74A06C25805D) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_14C99000_21EF_4D1A_8B56_03D8423D008A) },
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
