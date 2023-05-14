#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_E46C8243_E436_48DD_9A14_453331C766BA) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_33C50D4B_D96B_42A0_A26B_E7F2FA98160A) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_DDA1971D_6371_4BD5_93D4_34B9832136F6) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_FFEFD16C_BAAE_4B86_9B3C_AF479C5877FA) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_DD93D045_166B_4CB2_B64B_447DEC718466) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_A4733588_957C_440F_B0C9_01DB32E00C8C) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_FFE4AAA9_E8B3_4D2B_B5A6_3D78236FE89D) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_8DE62A4B_036D_4AB4_ACE8_B77DA7C6A795) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_1D2DFC97_31B6_4CA1_9233_0F2B12F1E142) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_8A14E16B_B8EA_4284_AC55_FE35BBB1AE37) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_20DFA4A8_D0AD_485F_B2F9_16E26557543E) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_B16E115E_ACCB_4C69_913A_2A576778E943) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_A3C016A4_E35B_47D9_B562_699A5E58EA07) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_335F0E95_E37D_4C00_AC01_313CA88F8FDE) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_5602D4E9_A815_422F_ABD0_46F552F21079) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_3BDCC18D_4B5B_4F62_818D_041577BA6E7E) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_00044BDD_8231_42CA_A2F0_D1A7198CB68F) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_9E6F7B53_5F5A_4B49_B076_C03DA29BBF9E) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_395C3E2C_D79B_40D3_AB9C_C9881832889D) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_35BF0607_40B1_4754_9B53_2328BDB3CFA9) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_98939C55_E62E_4162_B2C6_E5B61D152651) },
};

static be_define_const_map(
    Berry_Serial_Type_map,
    22
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Serial_Type,
    1,
    NULL,
    Serial_Type
);
