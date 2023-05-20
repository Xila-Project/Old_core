#include "be_constobj.h"

static be_define_const_map_slots(m_libPin_map) {
    { be_const_key(Set_Clock_Divider, -1), be_const_ctype_func(Berry_Pin_Class_Set_Clock_Divider_37D2C25D_DCA2_4593_AD58_2F381EF34C55) },
    { be_const_key(Mode_Open_Drain, 39), be_const_int(16) },
    { be_const_key(Detach_Interrupt, -1), be_const_ctype_func(Berry_Pin_Class_Detach_Interrupt_8557DD38_AB0F_4E71_805B_F9E0F62F2075) },
    { be_const_key(Serial_Type, -1), be_const_class(Berry_Serial_Type) },
    { be_const_key(Valid_Output_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Valid_Output_Pin_986FD7C0_4799_4631_8D81_FE175A7197FB) },
    { be_const_key(Serial_Configuration_Data_8_Bits_Odd_Parity, -1), be_const_int(134217759) },
    { be_const_key(Set_Attenuation, -1), be_const_ctype_func(Berry_Pin_Class_Set_Attenuation_878F246D_E388_499A_92ED_C834A198A61C) },
    { be_const_key(Serial_Configuration_Data_7_Bits, 36), be_const_int(134217752) },
    { be_const_key(Serial_Configuration_Data_7_Bits_Even_Parity, 57), be_const_int(134217754) },
    { be_const_key(Mode_Input, -1), be_const_int(1) },
    { be_const_key(Digital_State_High, 3), be_const_int(1) },
    { be_const_key(Interrupt_Mode_Rising, -1), be_const_int(1) },
    { be_const_key(Serial_Configuration_Data_8_Bits_Odd_Parity_2_Stop_Bits, -1), be_const_int(134217791) },
    { be_const_key(Serial_Configuration_Data_6_Bits, 35), be_const_int(134217748) },
    { be_const_key(Mode_Output, 51), be_const_int(3) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Pin_Class_Get_Pointer) },
    { be_const_key(Analog_Read_Milli_Volts, -1), be_const_ctype_func(Berry_Pin_Class_Analog_Read_Milli_Volts_3DD9D897_6DA5_4BB2_86FF_95C7A8E46D38) },
    { be_const_key(Digital_Read, -1), be_const_ctype_func(Berry_Pin_Class_Digital_Read_DD4E9EE8_4FC2_4F23_AB2D_FC3E5635B9EE) },
    { be_const_key(Mode_Pull_Down, 25), be_const_int(8) },
    { be_const_key(Serial_Configuration_Data_6_Bits_Even_Parity_2_Stop_Bits, 28), be_const_int(134217782) },
    { be_const_key(Serial_Configuration_Data_8_Bits_Even_Parity_2_Stop_Bits, 62), be_const_int(134217790) },
    { be_const_key(Serial_Configuration_Data_6_Bits_Even_Parity, -1), be_const_int(134217750) },
    { be_const_key(Set_Voltage_Reference_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Set_Voltage_Reference_Pin_8A382AE6_CEB0_488E_971E_78138F8D2811) },
    { be_const_key(Mode_Pull_Up, 46), be_const_int(4) },
    { be_const_key(Serial_Configuration_Data_7_Bits_2_Stop_Bits, -1), be_const_int(134217784) },
    { be_const_key(Interrupt_Mode_On_Low, -1), be_const_int(4) },
    { be_const_key(Serial_Mode_RS485_Custom, -1), be_const_int(4) },
    { be_const_key(Serial_Mode_Regular, -1), be_const_int(0) },
    { be_const_key(Serial_Configuration_Data_5_Bits_2_Stop_Bits, -1), be_const_int(134217776) },
    { be_const_key(Serial_Configuration_Data_8_Bits_Even_Parity, 40), be_const_int(134217758) },
    { be_const_key(Set_Read_Resolutions, -1), be_const_ctype_func(Berry_Pin_Class_Set_Read_Resolutions_CC650653_51CB_43E2_B4E6_63CCD49FD27C) },
    { be_const_key(Interrupt_Mode_Change, -1), be_const_int(3) },
    { be_const_key(Analog_Read, 20), be_const_ctype_func(Berry_Pin_Class_Analog_Read_E877D045_39F8_42A7_A2D3_21AA2BBEE067) },
    { be_const_key(Serial_Configuration_Data_5_Bits, 24), be_const_int(134217744) },
    { be_const_key(Get_Pulse_In, 21), be_const_ctype_func(Berry_Pin_Class_Get_Pulse_In_82607E7D_401A_4495_9259_358650C20FC1) },
    { be_const_key(Serial_Mode_RS485_Collision_Detect, -1), be_const_int(3) },
    { be_const_key(Serial_Configuration_Data_7_Bits_Even_Parity_2_Stop_Bits, -1), be_const_int(134217786) },
    { be_const_key(Interrupt_Mode_Falling, 15), be_const_int(2) },
    { be_const_key(Serial_Mode_IRDA, 55), be_const_int(2) },
    { be_const_key(Mode_Analog, -1), be_const_int(192) },
    { be_const_key(Mode_Input_Pull_Up, -1), be_const_int(5) },
    { be_const_key(Mode_Output_Open_Drain, 42), be_const_int(18) },
    { be_const_key(Serial_Configuration_Data_5_Bits_Odd_Parity_2_Stop_Bits, 43), be_const_int(134217779) },
    { be_const_key(Serial_Configuration_Data_6_Bits_Odd_Parity_2_Stop_Bits, -1), be_const_int(134217783) },
    { be_const_key(Serial_Configuration_Data_7_Bits_Odd_Parity_2_Stop_Bits, 12), be_const_int(134217787) },
    { be_const_key(Interrupt_Mode_On_High_WE, -1), be_const_int(7) },
    { be_const_key(Digital_State_Low, -1), be_const_int(0) },
    { be_const_key(Digital_Write, -1), be_const_ctype_func(Berry_Pin_Class_Digital_Write_5626188F_2473_4C39_A21F_CF4D145AE2AE) },
    { be_const_key(Interrupt_Mode_On_High, -1), be_const_int(5) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Pin_Class_Set_Width_509C1B5C_849C_4244_8F0C_6F0CEC97E832) },
    { be_const_key(Serial_Configuration_Data_8_Bits_2_Stop_Bits, 0), be_const_int(134217788) },
    { be_const_key(Serial_Configuration_Data_5_Bits_Even_Parity_2_Stop_Bits, -1), be_const_int(134217778) },
    { be_const_key(Serial_Configuration_Data_6_Bits_2_Stop_Bits, -1), be_const_int(134217780) },
    { be_const_key(Serial_Configuration_Data_6_Bits_Odd_Parity, 2), be_const_int(134217751) },
    { be_const_key(Serial_Configuration_Data_5_Bits_Odd_Parity, -1), be_const_int(134217747) },
    { be_const_key(Serial_Mode_RS485_Half_Duplex, -1), be_const_int(1) },
    { be_const_key(Serial_Configuration_Data_5_Bits_Even_Parity, -1), be_const_int(134217746) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Pin_Class_Set_Mode_9E2A36B7_35B0_4D90_9B10_CE395D0F5537) },
    { be_const_key(Interrupt_Mode_On_Low_WE, 32), be_const_int(6) },
    { be_const_key(Valid_Digital_Pin, -1), be_const_ctype_func(Berry_Pin_Class_Valid_Digital_Pin_C067D861_D184_4622_8704_5C39AA84D295) },
    { be_const_key(Serial_Configuration_Data_8_Bits, 6), be_const_int(134217756) },
    { be_const_key(Interrupt_Mode_Disabled, 56), be_const_int(0) },
    { be_const_key(Serial_Configuration_Data_7_Bits_Odd_Parity, 27), be_const_int(134217755) },
    { be_const_key(Attach_Interrupt, -1), be_const_ctype_func(Berry_Pin_Class_Attach_Interrupt_C3B8861E_6DE3_4D69_84D4_C8384203B297) },
    { be_const_key(Mode_Input_Pull_Down, 7), be_const_int(9) },
};

static be_define_const_map(
    m_libPin_map,
    65
);

static be_define_const_module(
    m_libPin,
    "Pin"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Pin);