#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_3E0E8E4D_FAC0_4E8C_8194_AE03EB01926C) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_8ECDC128_F1DC_4EB1_B6FC_8522793EF58B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_DF80FC8E_A555_429E_88BE_50FB01E69B80) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_96B7D7A0_6E2A_4357_A6DB_E3360DF2C4F5) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_9B0B1811_5390_4526_943E_B1841C964C22) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_818D7A12_ECD0_42AF_802D_ADF2E6DAC518) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_AC912EE2_4BE6_4B39_801C_2B4FF117BD81) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_7BAEA4D0_3582_441A_A2F1_31FC96654543) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_1B5EF17E_FB8F_4E86_880F_228777341557) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_C5231A6A_B1BD_4C97_87F2_E415DFFCECC5) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_2EBFABC5_5B54_414D_B685_804F2F168689) },
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
