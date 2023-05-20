#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_4392D037_6062_4931_9980_4A9C1196AB58) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_3BFB86E6_4AE5_4A5B_B305_933182386F64) },
    { be_const_key(Get_Data_Pin, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Data_Pin_1C77C6AA_710D_4E2C_95EA_905CE2225CF7) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_E4B85CF3_99D6_4B35_929C_D87860FF1E92) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_A6519F21_56B2_43A9_B8E3_0E3D36728B3C) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_6F3E55D7_64D5_4EE5_98BD_7159D110EAFB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_90C2F53A_B440_4B34_B84F_027DF2E2B112) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_ECE8CE60_15B2_4403_A416_AA069FF227BD) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_B3BCD48A_3BCB_4E16_8528_F084C13859E8) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_D887E5D7_CF16_40C2_9BF7_A2DF31B130EA) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_CE1AFF76_C94E_4FB0_9200_36F33B309D74) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_77C88E84_F0DE_4167_8ED6_AB8F08A6E636) },
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
