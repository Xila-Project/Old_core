#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Configuration_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Volume_FDDCD9BC_F721_4AA3_8974_FA5E7FF10969) },
    { be_const_key(Get_Allow_Boost, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Allow_Boost_4CB00EC0_7797_4D32_A8A9_A1724AA6FE57) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Initialize_561202FF_1560_4EF8_ACE2_56444C20AC5D) },
    { be_const_key(Set_Allow_Boost, 3), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Allow_Boost_609E13F7_C7A7_4995_8CB9_9439EA2C5DF3) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Configuration_Class_Deinitialize_88A045CC_EB5F_414A_AEF3_4495B6B1F62E) },
    { be_const_key(Set_Volume, 2), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Volume_A6BCC9C2_3468_45C0_801C_927DBF08AF6B) },
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
