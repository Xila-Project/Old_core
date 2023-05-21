#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_464A1C4F_812F_426F_9BE3_394AE3999A4E) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_65CB16D5_4DE2_4955_9A13_2964C869B945) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_05977ED9_D939_4E4F_BECB_DAB989C93092) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_AE4CEBF1_6BC1_4827_9B08_624FC5FC886D) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_9892DD28_F6C5_4C4A_98B6_836CCE46595C) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_2BF1B2A2_74D8_4048_A235_00CA3C3239BF) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_DF5055D0_D319_41C4_B41B_AC74E28F8CC1) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_C453F27E_7A9C_4796_B3BB_BD437B99BE28) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_5551542D_1637_4CEF_8F91_E3ABB15BF3AE) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_81FE7C85_3A5E_4191_BDF3_4FD87876A510) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_4CA69DD0_F617_4AD0_8C4F_63581C8FBFAB) },
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
