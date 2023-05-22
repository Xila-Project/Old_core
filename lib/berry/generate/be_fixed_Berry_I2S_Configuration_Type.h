#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_EE5E75DE_DCAF_466C_9A2A_059B7B56AB34) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_325C539A_8236_4421_9231_86B18E508F42) },
    { be_const_key(Get_Data_Pin, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Data_Pin_F64E3A2F_2313_4EFC_85CF_AA8A3D096476) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_BB049DE1_8F25_4035_9A04_55A0D4D91FF1) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_9E8854CC_6CE5_4CFB_81AF_9BA3B451830F) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_57392AD0_86CA_4CF3_B759_8E4BC2C7F33B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_F8BEB072_324D_4AC4_9D4C_99A000839CC4) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_3F1C49FF_7CAE_4B4D_A1CF_5C04C4C04EA5) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_D2CD4B95_3A46_4BC7_83E5_6F0FB2BB0C77) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_4B86D454_068C_4AA0_88F9_1612B3A7204C) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_77715A7B_5A36_4F7C_828E_DE924F658680) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_EE02122E_3FBA_4CEC_B689_55DBEF3E6B11) },
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
