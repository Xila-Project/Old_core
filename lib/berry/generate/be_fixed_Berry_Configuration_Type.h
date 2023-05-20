#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_47DD3C7D_2107_4B44_A840_1D7153317E1F) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_7471D8F0_F806_4A0A_B044_B92C8F12263D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_8C74E64A_BA92_4F6F_9D00_8DFA3B23D6D3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_9AE37FA4_DF52_40B3_8811_7FD7AD249075) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_5FEBA94A_0CD0_4818_95A4_C86087FC523D) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_6393C833_8D90_4326_9573_02F67D4CB8DD) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_565010ED_83E5_48A4_BB8C_432E7314D760) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_DDCB4A0B_2F03_48EB_AD4D_C13266F753A2) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_D1132D05_FF55_44E7_A815_FF26075A964F) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_EAB2AE19_204D_4179_BDDF_F5F182C457C3) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_BFE89471_8C5C_4767_85D6_1790024D6148) },
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
