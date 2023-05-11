#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_BD8DC7CA_9611_49C9_9383_07A3C2860975) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_D39CFC35_63E7_4513_B0D4_12ABB92543E1) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_5F1741C9_6037_4A81_96CE_E803C97CCD0F) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_8A19C36F_AB03_471B_ADFD_1FA51BE274B5) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_EC0AD2FD_2C07_43CF_B374_C6EEA96B40C6) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_23F4193B_C223_4541_B309_15F5FE6569C7) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_9AB2CCF9_DCA5_4FA2_99FE_07A3A88A266C) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_A1FEE8DF_4521_4837_908D_9B91B893060A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_D4D922BC_5209_4B91_B155_F2E0EDB3604D) },
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
