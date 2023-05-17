#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Configuration_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Volume_B76FCE6D_BEF1_4B8A_B3B5_FBAB369CA7C9) },
    { be_const_key(Get_Allow_Boost, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Get_Allow_Boost_7D222BA8_3861_43AE_A144_204A543C4688) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Configuration_Class_Initialize_384ECB8D_948A_4BD6_A081_2D0C215CF2AD) },
    { be_const_key(Set_Allow_Boost, 3), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Allow_Boost_C68E5A91_E3F1_41BF_B44F_9D3C9E8449E1) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Configuration_Class_Deinitialize_41DA87D0_8FDC_40F1_BCBC_BA2046ACE98C) },
    { be_const_key(Set_Volume, 2), be_const_ctype_func(Berry_Volume_Configuration_Class_Set_Volume_0FB8DD3D_91E1_485F_8D78_512939C50AA9) },
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
