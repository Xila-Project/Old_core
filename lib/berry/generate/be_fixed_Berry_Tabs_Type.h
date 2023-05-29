#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_E7F3A7D8_E434_4699_B4A8_EEE3765EE60F) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_4E26EAD4_7AEF_482A_BA13_52FFA0F496EA) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_C5756AEA_BBDB_45C7_8DD6_7D9A5058212B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_A7E557B5_F5C9_47E6_93DE_E29B85579463) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_A1C76EDC_B783_4FCB_9526_033EBACDDC81) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_DDFC647C_89BB_40EB_B8FD_35019039D2FC) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_15E9913C_1C9A_44AC_9581_6BDABBBD011E) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_9F6CF274_6063_4EF4_BCEF_E88A4F494F91) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_0A595C8A_D2C5_4F9A_AEB8_8DA0A0E99454) },
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
