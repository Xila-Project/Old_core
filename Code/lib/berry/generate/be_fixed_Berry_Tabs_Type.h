#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_2E608997_57FF_4FEF_98E2_F04F123EA3E9) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_FB548B60_488B_4172_81DF_3086B5CF9057) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_9BACCD73_01E3_4D7C_AF9F_1F83AB1D54D9) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_57E5C5B6_955D_453F_A97B_B3B1E9A2FD32) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_F5537085_F599_4282_8809_1A2A6A54CD71) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_5E4FC61F_ECDF_4D2B_8655_3EDD744F0292) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_EA34FD0F_ADF0_42FD_AD1A_0A9E1C9EC583) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_4778AA3B_306A_4C85_89E0_D1842D298D0A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_36B86EDC_5BCF_4E09_80A3_B913173B3F66) },
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
