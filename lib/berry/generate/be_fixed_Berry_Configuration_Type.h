#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_583D1074_3BED_40A7_BCC0_292CD2F8FF5D) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_A733187A_8D73_4709_B9E6_B09932AEB3A3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_7A771BF1_08DA_46B9_BD25_503F3CC45411) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_FE38109A_5308_4560_B96D_BE4647CD01B9) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_A230BE9B_D7CC_4E56_BCED_257600D6949A) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_F9A73294_44AE_4E99_89FF_86C328FC43D5) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_8EA03F90_5347_4AD1_B42A_985152A52550) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_D3639712_CA49_4589_8452_035CE274B22C) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_B4F3CE66_ECA4_4DBA_9286_407D73C36B87) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_95485A33_2168_45EA_ADC5_084243E17CB1) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_999E60A9_7238_46DA_81B4_3B1BE3888597) },
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
