#include "be_constobj.h"

static be_define_const_map_slots(m_libPin_map) {
    { be_const_key(Digital_Read, 10), be_const_ctype_func(Berry_Pin_Class_Digital_Read_AE90FE58_AEF0_4B71_9EDC_96CA2DA133C1) },
    { be_const_key(Interrupt_Mode_Disabled, -1), be_const_int(0) },
    { be_const_key(Interrupt_Mode_Falling, -1), be_const_int(2) },
    { be_const_key(Interrupt_Mode_On_High, -1), be_const_int(5) },
    { be_const_key(Set_Attenuation, 12), be_const_ctype_func(Berry_Pin_Class_Set_Attenuation_85720950_86D6_44A4_A02F_3FD905BC2D3F) },
    { be_const_key(Mode_Pull_Down, -1), be_const_int(4) },
    { be_const_key(Mode_Open_Drain, -1), be_const_int(6) },
    { be_const_key(Mode_Input_Pull_Down, -1), be_const_int(5) },
    { be_const_key(Set_Read_Resolutions, -1), be_const_ctype_func(Berry_Pin_Class_Set_Read_Resolutions_F59D4AC9_1CB4_47CC_B5E0_78397DFDE665) },
    { be_const_key(Digital_State_High, 19), be_const_int(1) },
    { be_const_key(Interrupt_Mode_On_Low_WE, 17), be_const_int(6) },
    { be_const_key(Valid_Output_Pin, 28), be_const_ctype_func(Berry_Pin_Class_Valid_Output_Pin_785DC0E5_2076_4507_BF90_750E4BECC904) },
    { be_const_key(Set_Clock_Divider, 8), be_const_ctype_func(Berry_Pin_Class_Set_Clock_Divider_88A69B98_F65B_420B_B739_188A97FAEEA7) },
    { be_const_key(Interrupt_Mode_On_Low, -1), be_const_int(4) },
    { be_const_key(Mode_Input_Pull_Up, -1), be_const_int(3) },
    { be_const_key(Mode_Analog, 13), be_const_int(8) },
    { be_const_key(Set_Width, 24), be_const_ctype_func(Berry_Pin_Class_Set_Width_0C90C317_34A6_4ADF_8C6D_89DA646CD0C1) },
    { be_const_key(Set_Voltage_Reference_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Set_Voltage_Reference_Pin_6C4E62ED_B09E_49C8_8D02_F0E0433404BA) },
    { be_const_key(Detach_Interrupt, 9), be_const_ctype_func(Berry_Pin_Class_Detach_Interrupt_9D20D26A_E4ED_4C4F_88F0_B577A15CD8D8) },
    { be_const_key(Analog_Read, -1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_BF9007E3_E08F_4189_94D2_22EA6721B48C) },
    { be_const_key(Interrupt_Mode_On_High_WE, -1), be_const_int(7) },
    { be_const_key(Mode_Input, -1), be_const_int(0) },
    { be_const_key(Valid_Digital_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Valid_Digital_Pin_B6270DA1_DD78_4EBA_B3F4_0918059FD968) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Pin_Class_Set_Mode_A0B0DA0A_BD14_4454_80E0_3BA414AAF9B0) },
    { be_const_key(Digital_State_Low, 25), be_const_int(0) },
    { be_const_key(Mode_Pull_Up, -1), be_const_int(2) },
    { be_const_key(Mode_Output, -1), be_const_int(1) },
    { be_const_key(Digital_Write, -1), be_const_ctype_func(Berry_Pin_Class_Digital_Write_454BDB2C_7100_4F53_97F5_0E0695F61C0A) },
    { be_const_key(Interrupt_Mode_Change, 14), be_const_int(3) },
    { be_const_key(Interrupt_Mode_Rising, -1), be_const_int(1) },
    { be_const_key(Mode_Output_Open_Drain, 7), be_const_int(7) },
    { be_const_key(Analog_Read_Milli_Volts, 1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_Milli_Volts_BE699990_307E_4F30_B0C0_81715B29696F) },
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
