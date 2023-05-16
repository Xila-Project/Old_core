#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_B463109C_7F07_44C4_A21E_0A07B94B7BB9) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_0C5FA0AF_3E67_420A_8821_DAF02934E4E4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_5BF27A80_4A52_4987_8D10_43B45B1F40B8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_659F2AE8_63E8_4EA0_AC16_60B57CD09683) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_F564F018_842D_4BBE_B19A_73D741A61013) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_D4A11CD7_6D22_46ED_AF0D_1E483D630DAF) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_D04617B2_CCE2_476D_9614_165436BDB579) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_70AE7B7A_EBAA_409F_B679_C79CB53D9807) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_365F8D37_DD4D_4EA0_94D3_F13897310A0C) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_3665E477_638B_43A0_B8F0_BBA0735859A5) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_9AC0D0B3_F384_498E_A3B7_3F95B60147F4) },
};

static be_define_const_map(
    Berry_Configuration_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Configuration_Type,
    1,
    NULL,
    Configuration_Type
);
