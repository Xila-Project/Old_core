#include "be_constobj.h"

static be_define_const_map_slots(m_libPin_map) {
    { be_const_key(Digital_Read, 10), be_const_ctype_func(Berry_Pin_Class_Digital_Read_D589C479_9BFC_46EE_9DD3_C2BF8AD1D88E) },
    { be_const_key(Interrupt_Mode_Disabled, -1), be_const_int(0) },
    { be_const_key(Interrupt_Mode_Falling, -1), be_const_int(2) },
    { be_const_key(Interrupt_Mode_On_High, -1), be_const_int(5) },
    { be_const_key(Set_Attenuation, 12), be_const_ctype_func(Berry_Pin_Class_Set_Attenuation_E49F5627_5314_42E9_B8B7_910F29915C24) },
    { be_const_key(Mode_Pull_Down, -1), be_const_int(4) },
    { be_const_key(Mode_Open_Drain, -1), be_const_int(6) },
    { be_const_key(Mode_Input_Pull_Down, -1), be_const_int(5) },
    { be_const_key(Set_Read_Resolutions, -1), be_const_ctype_func(Berry_Pin_Class_Set_Read_Resolutions_CAFA20EC_C2BD_4119_A3F4_CB8F33811880) },
    { be_const_key(Digital_State_High, 19), be_const_int(1) },
    { be_const_key(Interrupt_Mode_On_Low_WE, 17), be_const_int(6) },
    { be_const_key(Valid_Output_Pin, 28), be_const_ctype_func(Berry_Pin_Class_Valid_Output_Pin_354B35FE_D6BD_44C6_8FE2_CE66CACAC3DE) },
    { be_const_key(Set_Clock_Divider, 8), be_const_ctype_func(Berry_Pin_Class_Set_Clock_Divider_1512BB2D_DF40_45F2_9C80_AA6D6FE6E025) },
    { be_const_key(Interrupt_Mode_On_Low, -1), be_const_int(4) },
    { be_const_key(Mode_Input_Pull_Up, -1), be_const_int(3) },
    { be_const_key(Mode_Analog, 13), be_const_int(8) },
    { be_const_key(Set_Width, 24), be_const_ctype_func(Berry_Pin_Class_Set_Width_9C60B1D8_EAF9_4EB1_8FF3_312D770CD444) },
    { be_const_key(Set_Voltage_Reference_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Set_Voltage_Reference_Pin_4FBEC102_9E6A_4821_9BBA_04FD31411478) },
    { be_const_key(Detach_Interrupt, 9), be_const_ctype_func(Berry_Pin_Class_Detach_Interrupt_EE515A90_27C2_4403_A913_CD5E0F7B6D31) },
    { be_const_key(Analog_Read, -1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_CADEA075_D9F7_414D_BE40_E6BD20502337) },
    { be_const_key(Interrupt_Mode_On_High_WE, -1), be_const_int(7) },
    { be_const_key(Mode_Input, -1), be_const_int(0) },
    { be_const_key(Valid_Digital_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Valid_Digital_Pin_953B4502_8E3B_4D71_8A74_20981B0E942E) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Pin_Class_Set_Mode_E7220124_9777_47F3_B414_D0950DDC8DB1) },
    { be_const_key(Digital_State_Low, 25), be_const_int(0) },
    { be_const_key(Mode_Pull_Up, -1), be_const_int(2) },
    { be_const_key(Mode_Output, -1), be_const_int(1) },
    { be_const_key(Digital_Write, -1), be_const_ctype_func(Berry_Pin_Class_Digital_Write_FE40A826_6A1D_47D4_A8FB_F3F6A13A6CD8) },
    { be_const_key(Interrupt_Mode_Change, 14), be_const_int(3) },
    { be_const_key(Interrupt_Mode_Rising, -1), be_const_int(1) },
    { be_const_key(Mode_Output_Open_Drain, 7), be_const_int(7) },
    { be_const_key(Analog_Read_Milli_Volts, 1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_Milli_Volts_0251D9BC_7505_4D91_B6BF_FFB7D027B097) },
};

static be_define_const_map(
    m_libPin_map,
    32
);

static be_define_const_module(
    m_libPin,
    "Pin"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Pin);
