#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_25F52692_7C54_41E9_8FF7_F6F2281D88B7) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_09C07206_9BAF_4470_AB72_B3D4B10D4F0A) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_7E4D8F73_96FF_465D_AF45_36ED7BE6BF85) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_12E1F49A_4F78_4CB1_8A6D_79B63AB16EBD) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_FFD4F21A_817B_4EBC_B580_CC22632520C3) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_535AA10A_AF78_4108_9678_7EB69152C1E3) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_E1B6B43D_E64F_4358_84AB_8E28F52ECA4E) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_8C0814F2_9D78_4B1E_9FF7_315A5EC4B05A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_421B907C_3EC0_4367_A6F1_8420C9419737) },
};

static be_define_const_map(
    Berry_Tabs_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Tabs_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Tabs_Type
);
