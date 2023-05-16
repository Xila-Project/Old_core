#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_65B54B38_0D00_4BE9_86D1_1E322DA96077) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_C370DE74_6F1C_4489_8DC7_FB3DB5A9E3C5) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_CFBB445E_E0A1_4862_9518_BC33B30B3701) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_B2AF8314_0582_4367_9011_1EEFF1814F5E) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_5304F37A_5DA1_4103_9ADF_42DF949D8C68) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_F5184313_4945_4E9D_AB87_0EF287D46C50) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_2285570E_B404_406E_8ACD_8BD59B754192) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_FBE50612_06E4_414E_97E1_FBF5CD941552) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_0851ADEC_E214_4BE5_A35A_42B1C30C0D04) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_44EFBC1C_078C_4795_AC60_994F13A002CE) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_E285634D_7F9C_4892_ABC3_78666BD41A56) },
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
