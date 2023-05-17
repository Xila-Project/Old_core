#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_F9AFA45A_FCE4_46F2_9BD2_B9D1CC7C9FAD) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_D9CC0E5A_3DDA_4FCF_91D3_C8B30953DF18) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_DAE32204_55FC_4325_8B5C_35185AB9181B) },
    { be_const_key(Get_Clock_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Clock_Data_Pin_D12D74F7_0E8C_439E_9711_7EF7D7804C5D) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_3FC8A909_5EE7_4E3F_879B_47793E1E0351) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_82BA00F0_7FFF_4880_AE47_040F8D9067D7) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_A448FE75_8C13_4A63_A03F_9C01DE85AE7D) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_C1D0EB08_94F3_4DC2_83EC_07ED36A9F607) },
    { be_const_key(Set_Mode, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_D5DB0605_AAD5_4435_A89C_96F63720AFA9) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_98EE2755_2C89_4700_BD70_27AEB7190230) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_9FEFAE40_39F2_4555_A66B_C38218116715) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_060C588B_03C2_452F_9AFA_163EEEBA0FD7) },
};

static be_define_const_map(
    Berry_I2S_Configuration_Type_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_I2S_Configuration_Type,
    1,
    NULL,
    I2S_Configuration_Type
);
