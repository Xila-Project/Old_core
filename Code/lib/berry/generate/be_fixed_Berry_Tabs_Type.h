#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_513B91E6_81B2_494C_8C60_2B5FA93CD923) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_D0DA6FF1_BC1F_4A1E_83F0_C324C17CDB3C) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_C576A74C_A192_4670_A483_4937AA881C25) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_603B7A35_9D6E_4241_A703_801F08FD5F30) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_C4BA4069_CC41_4724_8D4B_1F9E9A338443) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_EC80A55D_9812_4F85_AC5F_3ACB102125F9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_DBA4F38D_EBED_49CE_B632_9E378C990219) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_CBB64484_5554_4135_A15F_1A8993F28984) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_8A977791_F83E_4424_917F_4D08B305F337) },
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
