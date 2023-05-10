#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_DCE0467E_7027_4AF7_BA1C_13AF6B21C228) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_00A44A01_4367_4BD7_AE4D_EF67AA2C3F63) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_7043FC68_34D2_4304_B4D7_490E93EAD3D4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_6BE62A99_D697_4DC9_9F72_746DBF62B087) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_F352EC37_4F6E_4E8A_AF8E_172DE460728F) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_6F82E46B_90AD_428A_AAD1_06DBB25028BC) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_60B44FA2_3739_45B4_8EC4_182F8C37DC5C) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_EAC09768_7BCB_42F6_A18A_1B35AA1ECEE4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_1FA3C08F_3CEF_41B2_A806_3ADF47F38431) },
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
