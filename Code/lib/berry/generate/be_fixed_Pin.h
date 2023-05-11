#include "be_constobj.h"

static be_define_const_map_slots(m_libPin_map) {
    { be_const_key(Digital_Write, 8), be_const_ctype_func(Berry_Pin_Class_Digital_Write_C562A786_6BB0_4E12_95F2_95ACD82EEB00) },
    { be_const_key(Analog_Read_Milli_Volts, -1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_Milli_Volts_BC3E77EC_C927_4793_936F_06A19C19092F) },
    { be_const_key(Digital_Read, 3), be_const_ctype_func(Berry_Pin_Class_Digital_Read_CF1CE1FC_8DA5_4B6A_A390_528A4F445DC6) },
    { be_const_key(Mode_Input_Pull_Down, -1), be_const_int(5) },
    { be_const_key(Mode_Analog, -1), be_const_int(8) },
    { be_const_key(Mode_Input, 9), be_const_int(0) },
    { be_const_key(Mode_Input_Pull_Up, -1), be_const_int(3) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Pin_Class_Get_Pointer) },
    { be_const_key(Mode_Pull_Up, -1), be_const_int(2) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Pin_Class_Set_Mode_1DED5378_1A6C_4EF8_936B_5879285E8ABC) },
    { be_const_key(Digital_State_High, -1), be_const_int(1) },
    { be_const_key(Interrupt_Mode_On_Low_WE, 15), be_const_int(6) },
    { be_const_key(Digital_State_Low, -1), be_const_int(0) },
    { be_const_key(Interrupt_Mode_Rising, 17), be_const_int(1) },
    { be_const_key(Set_Clock_Divider, -1), be_const_ctype_func(Berry_Pin_Class_Set_Clock_Divider_67753FF8_C579_4CD6_BFCF_C92F0922A260) },
    { be_const_key(Detach_Interrupt, 32), be_const_ctype_func(Berry_Pin_Class_Detach_Interrupt_BCBAC674_D5A5_4754_9692_EA4A5F7504EA) },
    { be_const_key(Set_Read_Resolutions, -1), be_const_ctype_func(Berry_Pin_Class_Set_Read_Resolutions_B1D1761B_48D5_4677_9734_977034C66FE9) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Pin_Class_Set_Width_6F199650_E9B3_4A81_A122_F767F2A19DB9) },
    { be_const_key(Valid_Output_Pin, 26), be_const_ctype_func(Berry_Pin_Class_Valid_Output_Pin_7C9A45D0_ACCE_483C_9E75_099185A269D3) },
    { be_const_key(Interrupt_Mode_Disabled, -1), be_const_int(0) },
    { be_const_key(Set_Voltage_Reference_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Set_Voltage_Reference_Pin_369B93B4_556D_417D_BB8B_AB7698334B3C) },
    { be_const_key(Interrupt_Mode_On_High, 16), be_const_int(5) },
    { be_const_key(Mode_Output, 18), be_const_int(1) },
    { be_const_key(Valid_Digital_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Valid_Digital_Pin_C9056EE2_9787_4544_A8A5_AEA1058A8F09) },
    { be_const_key(Mode_Pull_Down, -1), be_const_int(4) },
    { be_const_key(Analog_Read, 12), be_const_ctype_func(Berry_Pin_Class_Analog_Read_634C18C0_0166_444E_A416_1E994ABD6134) },
    { be_const_key(Set_Attenuation, 30), be_const_ctype_func(Berry_Pin_Class_Set_Attenuation_6B240C5A_0F3E_4797_A203_754C70BE75B5) },
    { be_const_key(Mode_Open_Drain, 7), be_const_int(6) },
    { be_const_key(Interrupt_Mode_On_High_WE, -1), be_const_int(7) },
    { be_const_key(Interrupt_Mode_Falling, 1), be_const_int(2) },
    { be_const_key(Mode_Output_Open_Drain, -1), be_const_int(7) },
    { be_const_key(Interrupt_Mode_On_Low, -1), be_const_int(4) },
    { be_const_key(Interrupt_Mode_Change, -1), be_const_int(3) },
};

static be_define_const_map(
    m_libPin_map,
    33
);

static be_define_const_module(
    m_libPin,
    "Pin"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Pin);
