#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Configuration_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Volume_AC1B307D_6F6B_4EE1_91CE_002B34CF8404) },
    { be_const_key(Get_Allow_Boost, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Allow_Boost_17F5D734_62FA_4F9B_9C76_39FF7042C76E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Initialize_ECE47289_BAA8_41A7_9733_6A68CB09A272) },
    { be_const_key(Set_Allow_Boost, 3), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Allow_Boost_0A359594_E048_4C71_9C21_9927BB33CDB3) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Configuration_Class_Deinitialize_A8C2319E_FC66_41EB_9899_A3DFC510FBA9) },
    { be_const_key(Set_Volume, 2), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Volume_E2808A8C_A692_4F12_96B3_038DEEE68BE9) },
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
