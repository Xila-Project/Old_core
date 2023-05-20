#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_EE66D70E_5BEC_4230_9F8F_D82C52FAC23C) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_173DDE44_4EFB_4AD7_909C_68BE444294C5) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_CED433C0_01B3_4A73_A153_E7568BC7944E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_4D3BEE05_3F65_4F11_97A0_F459B5BB5552) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_83FB738C_5052_45F2_B0B3_EDED227A2074) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_95335BF6_7B1A_4232_A198_376B60189938) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_EB8134E7_4206_4319_8E72_9F11A1818DB2) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_AC0394E8_CADD_4C89_A840_B287772D55B1) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_07F4B7E0_7E32_490D_81EC_7BBC2A829003) },
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
