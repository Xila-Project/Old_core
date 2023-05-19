#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Configuration_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Volume_AFF1AEC2_3D26_4460_A7F0_31A25EE59189) },
    { be_const_key(Get_Allow_Boost, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Allow_Boost_5E17A40D_7195_47EE_8E58_C859A205577B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Initialize_0D04292F_5313_4044_8D18_7BDE0FFD3B03) },
    { be_const_key(Set_Allow_Boost, 3), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Allow_Boost_A92877F8_1EE0_4464_92ED_67D1B949423A) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Configuration_Class_Deinitialize_770A539C_0BED_436F_8B14_11424E5B6DB1) },
    { be_const_key(Set_Volume, 2), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Volume_7DD80509_F487_4E89_9560_D3FB4D9DAF37) },
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
