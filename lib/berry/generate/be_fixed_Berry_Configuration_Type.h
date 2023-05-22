#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_6DF93316_7B7A_4633_8BC0_0CB107CF1238) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_216A92FB_DAAD_41A3_AC25_2B185D2C8CD8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_E31ADF48_4510_4F21_B2B2_3717B0CEFA02) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_6035A0C6_8DDA_40A0_A708_AE378FE57D38) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_5D708B48_04B6_43F0_AFF0_F32DEA44FD26) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_5AD9E2FE_569C_4243_AF6D_1FA6364751A7) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_45781474_4651_47EF_A3CE_9C8E086BFC38) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_A264477F_041B_40C2_A75B_4F45EC94DB09) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_33764F5D_E3BB_46CC_B45B_317096EC91BA) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_9A719E4C_E47C_4EB0_AB30_AE749F520759) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_67252603_3D04_40A5_A347_4FBF2CC2E6B8) },
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
