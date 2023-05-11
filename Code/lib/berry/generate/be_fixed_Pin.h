#include "be_constobj.h"

static be_define_const_map_slots(m_libPin_map) {
    { be_const_key(Digital_Write, 8), be_const_ctype_func(Berry_Pin_Class_Digital_Write_CD14F28B_3E51_4E9E_9BFE_3B7DAD8AA456) },
    { be_const_key(Analog_Read_Milli_Volts, -1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_Milli_Volts_FD589238_DA04_48A0_8F5E_626E9C2B2A83) },
    { be_const_key(Digital_Read, 3), be_const_ctype_func(Berry_Pin_Class_Digital_Read_8E3A6272_6EB8_4A46_A23F_57085FC4CFB3) },
    { be_const_key(Mode_Input_Pull_Down, -1), be_const_int(5) },
    { be_const_key(Mode_Analog, -1), be_const_int(8) },
    { be_const_key(Mode_Input, 9), be_const_int(0) },
    { be_const_key(Mode_Input_Pull_Up, -1), be_const_int(3) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Pin_Class_Get_Pointer) },
    { be_const_key(Mode_Pull_Up, -1), be_const_int(2) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Pin_Class_Set_Mode_A53CB9F7_4B56_4022_AE98_1D5B1870BF2F) },
    { be_const_key(Digital_State_High, -1), be_const_int(1) },
    { be_const_key(Interrupt_Mode_On_Low_WE, 15), be_const_int(6) },
    { be_const_key(Digital_State_Low, -1), be_const_int(0) },
    { be_const_key(Interrupt_Mode_Rising, 17), be_const_int(1) },
    { be_const_key(Set_Clock_Divider, -1), be_const_ctype_func(Berry_Pin_Class_Set_Clock_Divider_F01C4E65_7379_4CA8_96F2_4A88E819A88A) },
    { be_const_key(Detach_Interrupt, 32), be_const_ctype_func(Berry_Pin_Class_Detach_Interrupt_C17F69D7_8D58_4D26_94AA_2D25587792C5) },
    { be_const_key(Set_Read_Resolutions, -1), be_const_ctype_func(Berry_Pin_Class_Set_Read_Resolutions_5B5A9B41_B914_42B0_8615_F114E75BE6F9) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Pin_Class_Set_Width_BC5E3BC3_3252_4384_9328_301A26811D9D) },
    { be_const_key(Valid_Output_Pin, 26), be_const_ctype_func(Berry_Pin_Class_Valid_Output_Pin_2BB0446F_B399_4AC1_BFAA_EDF7D864EF94) },
    { be_const_key(Interrupt_Mode_Disabled, -1), be_const_int(0) },
    { be_const_key(Set_Voltage_Reference_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Set_Voltage_Reference_Pin_142261F9_9E67_413E_80AF_EA4C995C29FD) },
    { be_const_key(Interrupt_Mode_On_High, 16), be_const_int(5) },
    { be_const_key(Mode_Output, 18), be_const_int(1) },
    { be_const_key(Valid_Digital_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Valid_Digital_Pin_9BE26057_6EE1_45A5_A836_F516A4DBB257) },
    { be_const_key(Mode_Pull_Down, -1), be_const_int(4) },
    { be_const_key(Analog_Read, 12), be_const_ctype_func(Berry_Pin_Class_Analog_Read_723C4253_4D99_4CFE_8F8B_109B5B2CEA07) },
    { be_const_key(Set_Attenuation, 30), be_const_ctype_func(Berry_Pin_Class_Set_Attenuation_A50095A1_BED7_4FEB_9D66_FA6440D45D55) },
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
