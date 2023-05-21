#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_7AA15EE6_FEBE_44B3_8F1F_911333A6D4EF) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_297D0DF4_B7E9_4BF6_9CB4_6B3846B17DC1) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_C8308A0B_8CA3_4DCC_B305_8452F25970A0) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_44B51BAA_B66D_41C4_879C_D13F44597E64) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_EFC664E8_870A_4072_A5D0_39771BC568F2) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_C006013D_FCCD_4BC0_B5D7_4CF2A2DF0B6C) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_633DF247_7049_4D3F_B2D9_92A19083E4B0) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_FD84A8C0_D757_4083_BED7_E7DFEF4E9A61) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_0A0C91BE_8868_4DA7_A9B7_35B9DFAC3BAA) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_F6D1519C_DAB6_4C03_AE05_3AA39D0028D3) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_5FFCDD0E_9544_43B0_987E_FFA5DE813ACF) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_C2967539_0262_41F1_B07F_06E1229AE981) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_71CED893_1B1B_49F1_BF22_14D3760BB78D) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_7ED9202B_2B16_4E78_BFC5_18871AA2562D) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_2F87997C_50AA_4158_88F1_1F0AD1E4555C) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_9A5C94D3_FB12_40EF_BC57_03B54EE00F8C) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_72A6CA01_255A_434B_BB14_9D55457B6EA9) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_BF619EE7_ADE5_4116_9A0B_34FCAA944078) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_F669297C_2840_4800_BBA9_C9857E88F422) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_5A275175_77CA_4637_878B_B79FA59395E8) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_C8F579FA_8EEE_4B94_BD75_8B4369D8D391) },
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
