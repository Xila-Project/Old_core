#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_DF2F00B0_38B8_40CE_BD79_2A8F4D23EBEC) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_6829B31D_DF2E_4E34_AAE9_D3B18AE4FE99) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_505B2D5A_3D23_4BCD_A130_48AC5CB0506D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_B74911AC_E01A_47D9_8B40_217B4530895C) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_B2856622_08C2_4BC2_BCA6_41452F14AF81) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_F8639761_52E7_42E7_914F_A2E2469CB97D) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_A5058526_5BDF_44E1_8484_53E814918D24) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_73FE0F41_28F3_4B17_AD56_6750C51BB7A1) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_F85C6163_9918_4C0E_91B5_40D32CB98276) },
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
