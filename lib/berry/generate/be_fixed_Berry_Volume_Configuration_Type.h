#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Configuration_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Volume_D3EE44ED_478D_4CB3_8635_2C564AF80F55) },
    { be_const_key(Get_Allow_Boost, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Allow_Boost_C78F03CE_3C8B_45BB_90C4_52B9B0EB8AEF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Initialize_3B4958F6_8E26_4B39_A63B_24E5C141CBF6) },
    { be_const_key(Set_Allow_Boost, 3), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Allow_Boost_1774B985_B281_4B23_ADA9_CB1FB477CC42) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Configuration_Class_Deinitialize_540931A9_FF52_493B_8663_EE843371ABF5) },
    { be_const_key(Set_Volume, 2), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Volume_45E2C77B_C143_47DF_87F6_A944F8FBA948) },
};

static be_define_const_map(
    Berry_Volume_Configuration_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Volume_Configuration_Type,
    1,
    NULL,
    Volume_Configuration_Type
);
