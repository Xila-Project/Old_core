#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_37D8B00A_66E1_4957_A86B_0BB62BBC4232) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_19510D64_8A40_4214_9CB9_526C23034ED9) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_558EF713_C79B_49A3_94C0_302475B5CA6E) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_E7420CE4_939A_4D30_A0BB_2DA06E366437) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_BDC1EE6E_A5F2_43EC_BC01_027AA0EBD984) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_87042EF5_09BA_450E_8F2B_F54EE0B73246) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_3A7CB7CD_6E74_482B_8026_524FBE2676AC) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_78722CC3_4069_4094_81DB_845D8BE5C98E) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_8E63D250_4F48_4E8F_B845_48E449217D7A) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_056DA995_2A73_49C2_9FFA_130BCA800F00) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_B3CEA0F0_77B1_46DA_9024_C3B286D7982F) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_FE80B833_F867_4610_821D_6DCDC90E5266) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_9BE28F49_4E2E_478A_B994_B51321D21051) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_7C22AC4F_925F_45C6_9DC8_FA528B75313A) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_A8FCA7DE_7DC0_4B21_BBD2_0CA9CE2A7F5C) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_8967DFE7_9E20_4ACB_9466_AD868197461F) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_D7D6C564_A088_4354_B553_20666250930F) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_5A76C8BD_4BB4_42EE_B594_50ED474D275E) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_F880A15A_289E_4512_9350_4D2985987324) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_CEFBC64A_2812_453C_A727_752D9BEB3716) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_CA796766_4772_4066_A06F_BF03224BF2F5) },
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
