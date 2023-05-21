#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_355EE9B1_6AEA_4B22_9ACD_8FAF14932E23) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_A3944553_7E7E_4E1B_A1C7_ED253ADF2A3B) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_6FB620C3_B13F_4235_8945_0A69E2BF190D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_4BDCD01D_FF5F_4682_A40A_C622BF507A15) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_AC058D53_8CDE_4C9D_9C64_A3E480922A62) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_699A1135_E6B5_4C70_A0A7_901499F481BA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_358DA48A_777A_406C_B38C_14BEF7DBB8C6) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_CB1A9BE9_2F64_49E9_B166_3C0DA3420678) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_0AFEBE22_DA30_4DAB_A12D_33CB70E2381E) },
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
