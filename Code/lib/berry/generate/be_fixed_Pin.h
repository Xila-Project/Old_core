#include "be_constobj.h"

static be_define_const_map_slots(m_libPin_map) {
    { be_const_key(Digital_Write, 8), be_const_ctype_func(Berry_Pin_Class_Digital_Write_1D4B6CAC_2582_47E2_AAFA_55AD59D560D7) },
    { be_const_key(Analog_Read_Milli_Volts, -1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_Milli_Volts_EB302342_4745_4EDD_8BBC_356ABBB3A88B) },
    { be_const_key(Digital_Read, 3), be_const_ctype_func(Berry_Pin_Class_Digital_Read_4750A6AD_5BDF_496F_9601_88DE8B880245) },
    { be_const_key(Mode_Input_Pull_Down, -1), be_const_int(5) },
    { be_const_key(Mode_Analog, -1), be_const_int(8) },
    { be_const_key(Mode_Input, 9), be_const_int(0) },
    { be_const_key(Mode_Input_Pull_Up, -1), be_const_int(3) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Pin_Class_Get_Pointer) },
    { be_const_key(Mode_Pull_Up, -1), be_const_int(2) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Pin_Class_Set_Mode_FB938C4D_7DC8_4826_B83A_43FB7BE262D5) },
    { be_const_key(Digital_State_High, -1), be_const_int(1) },
    { be_const_key(Interrupt_Mode_On_Low_WE, 15), be_const_int(6) },
    { be_const_key(Digital_State_Low, -1), be_const_int(0) },
    { be_const_key(Interrupt_Mode_Rising, 17), be_const_int(1) },
    { be_const_key(Set_Clock_Divider, -1), be_const_ctype_func(Berry_Pin_Class_Set_Clock_Divider_9B22A638_4C9C_4E6A_B53F_547371D6A5F6) },
    { be_const_key(Detach_Interrupt, 32), be_const_ctype_func(Berry_Pin_Class_Detach_Interrupt_69F2197D_B8FD_4625_BC0B_7922E357A985) },
    { be_const_key(Set_Read_Resolutions, -1), be_const_ctype_func(Berry_Pin_Class_Set_Read_Resolutions_DC75BB3D_5CBB_4602_92FC_D29D0459C711) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Pin_Class_Set_Width_52C3E0A4_79CA_4F20_A0FA_BC1E9CC62A8A) },
    { be_const_key(Valid_Output_Pin, 26), be_const_ctype_func(Berry_Pin_Class_Valid_Output_Pin_15B59AC8_14AC_4BBA_8092_6EF475442008) },
    { be_const_key(Interrupt_Mode_Disabled, -1), be_const_int(0) },
    { be_const_key(Set_Voltage_Reference_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Set_Voltage_Reference_Pin_A1F0CA61_C65E_44F3_8B81_738CE90309F5) },
    { be_const_key(Interrupt_Mode_On_High, 16), be_const_int(5) },
    { be_const_key(Mode_Output, 18), be_const_int(1) },
    { be_const_key(Valid_Digital_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Valid_Digital_Pin_E92F8826_FBAA_4BB1_86C8_BAF89405E017) },
    { be_const_key(Mode_Pull_Down, -1), be_const_int(4) },
    { be_const_key(Analog_Read, 12), be_const_ctype_func(Berry_Pin_Class_Analog_Read_6F92B8DF_F279_43AE_ADED_024077F0BE36) },
    { be_const_key(Set_Attenuation, 30), be_const_ctype_func(Berry_Pin_Class_Set_Attenuation_110A08B9_D952_477B_AF5D_3EDA66B9D235) },
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
