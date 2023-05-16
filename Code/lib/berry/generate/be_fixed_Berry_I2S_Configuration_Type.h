#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_4CF52A01_E460_4D12_8A76_E20B9975BF99) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_36A85073_F93B_4684_95EE_E73AF2CD23DE) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_70CE389E_AA46_4B4F_88C0_5FE2DD97E362) },
    { be_const_key(Get_Clock_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Clock_Data_Pin_AA652BF3_265E_4BD3_A7C7_243ACE5D35C4) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_E60C8086_A3F3_4D18_9C61_708F2E625F92) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_265A6F47_0C51_4D52_B094_6701ECCB5002) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_53155D70_8E73_4735_8E5F_05C0C6204D7F) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_C961A0CB_DC71_432F_8CA5_B18DAC7AFFA1) },
    { be_const_key(Set_Mode, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_E27BFA1F_1484_481F_81CD_FF93D39C1715) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_1B513518_A476_48D9_A89A_9F2408847ECB) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_8A693EAF_C200_4F62_8CFD_14FE8EB65026) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_1B7D664A_B696_46DC_85A6_2FE15CCFA5E0) },
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
