#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_6BBA0FDA_5FEB_4CE7_8F9A_2BC062317B71) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_FA15E3EA_FA2D_4C79_B329_C7B75805F906) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_7BA7FA10_5423_4384_A81A_FE95EFFE6E98) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_F4412440_ED83_48D2_981D_E55977C412E1) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_B0A400AB_1ACD_4D43_ABE9_8155E0240C1D) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_84FC4F87_FA91_4D92_B421_2F06148DE297) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_C8319328_AB3A_482A_A5D1_4CBA425648E0) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_EEE8B96A_8833_4735_AFD4_E0AA3561ECDB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_F46607BC_702A_4815_816E_60608FEAABB0) },
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
