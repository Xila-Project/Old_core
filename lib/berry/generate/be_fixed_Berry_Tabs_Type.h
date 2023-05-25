#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_94846ACD_7089_4513_8647_34818E0A5E09) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_9FB67614_19E6_408A_A2C6_B68A3401E192) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_592740E1_18E1_4DE1_A20C_FDF70D8D539B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_D609EADB_91E0_4F1E_A744_E9E987C57D87) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_EE3C864A_5C04_4DDB_BF2D_CD0A942598D6) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_E20728BB_072A_4522_BB32_D97AF94A23BF) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_E7ADD7F8_E5DC_4590_A036_FBC22DEBD569) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_CB3FBD95_1927_40D3_851C_552CEAC86CDB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_44D44232_0A11_4B21_8781_5BE23D642B53) },
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
