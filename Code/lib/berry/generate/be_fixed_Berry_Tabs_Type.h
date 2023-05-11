#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_43AC013A_21FF_410C_9290_B76F4DB0C12F) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_B256BCA0_0160_45C9_8592_B46322F7BCB0) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_B05ACD73_A8A5_479B_89D8_C71F75FC3632) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_B25F263E_A1AD_4710_A07D_5337A987BFBD) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_BAE9862B_5E23_4EE0_A78A_E45843A7BB35) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_BF7138B7_4072_45CA_9966_823063680544) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_1090A1D6_094E_4CC3_AD8E_8844B4FA6046) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_3F628D0F_1F95_4AD1_B86D_0C90D1CBE66C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_2AAA626F_298C_4141_A443_69317103C09C) },
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
