#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_7298A6C1_9493_46EF_BCF2_CE8B00781FDB) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_EBB42F48_DFFB_487F_8162_2A36BD814657) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_ECB8E49A_BD39_4BC3_BD33_4FEFD34D8736) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_DC3476F3_81D4_4E2E_A2C4_C14D64AC2197) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_424FDCF0_607F_4848_BD46_6DF06E46E0EA) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_72D1B1A3_C5FA_40A3_88C6_6C7CEB2D265A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_2A0A6142_FC8A_4E8E_8F06_6280D5090358) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_59C6D5DB_8012_4BFD_B7AE_9F99B205D9B9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_3979F249_39B2_4AE5_AF23_BA72FBDD4167) },
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
