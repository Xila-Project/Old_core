#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_8DB89FEF_9634_4027_931B_E2E21A66A058) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_B7A52A6A_AA4F_49A0_865B_8B437A3DDD3C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_27627F23_1D2B_4479_971A_45DA4F190F2C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_F8D8B33B_075C_441E_A4B2_8A945E3B2EC9) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_4AA9CE2D_1509_4418_A038_3EC1C758CCD6) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_94275D30_7C50_47D6_A42B_92F1F606DD95) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_D8FC70D1_71FA_47E6_9DCD_9E49550AA154) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_BB74E7B3_4F37_4352_9FD0_AE73818CD88D) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_8BD4936B_118D_48F6_A677_EA2906519792) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_BAA54565_638D_4E72_90B4_111558DB9881) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_9A95558D_E900_443E_999B_5ABD9A0025E8) },
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
