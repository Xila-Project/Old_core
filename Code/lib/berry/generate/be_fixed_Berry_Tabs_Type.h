#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_39F9E8E6_A827_4917_ADE6_E130FC505BEF) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_FA200DD0_4F6F_4E73_BD81_804AD147D016) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_D4AD945D_06BB_4E07_BD7B_26A844E3AE3F) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_23670371_978F_46EA_AEE0_AB0AA3AA90B6) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_0C9CFD9E_8E0C_4C05_B563_2BCF8FD748F1) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_6C1F7A20_BAF6_46BD_BB68_6FC9C100C8F5) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_40998CF7_6E8E_4B26_A8D0_7FCEC826E5B2) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_D1F4C15F_0590_478E_85E4_9AE0E21907DB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_A5346E32_609D_4276_A0AD_263F48ED7B2C) },
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
