#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_41C5C64C_E0CA_44E3_A66C_1219CB876946) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_08E18F1D_5F5A_4AF5_9B79_59E037DDD8A8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_845A98C3_B933_4DF8_9C83_55D95DF6F051) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_F6C040BB_0DD5_4F43_AA64_11B8AE8439A1) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_6F8CFAE2_C243_47DA_8D26_42BAE9994995) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_6EA36345_8F04_46BE_9E51_78ED9CDB9C80) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_2DC2F0D6_B93E_4D9C_B5CD_19F77C8DF744) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_AC0EC604_0FEF_4443_8892_4BC97E3D7857) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_5DB712E2_EA9E_41B5_A0D9_937AB5101492) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_E45466C5_BD98_4CAB_BEAB_E6A5FEBBC0C6) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_B323AA78_4C85_45EC_96EE_F21A31F00243) },
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
