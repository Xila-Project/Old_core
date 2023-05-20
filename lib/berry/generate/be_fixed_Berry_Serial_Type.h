#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_A884F157_158A_42DB_9297_547BE58297E9) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_98659FBA_CEAE_4C15_8BF0_75F33F2632D3) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_D2CE01EE_854B_4DA4_9501_9A11F355963F) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_9B813278_9252_4287_B609_E474ECBDE654) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_A17BD6D9_F074_4EBC_8574_AA5547C37AFE) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_2DAF2602_D8A3_4D68_8CE4_084802DFF1A4) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_9C54040D_9C3A_437C_819D_14E1A89A8C2F) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_DB1EF47A_2EA6_4E10_AD2B_6DB1362A9534) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_8C5340D6_89D7_4F43_9718_7FD3AA99D0D7) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_BDF30008_A5F1_4915_A7F9_CE4351583938) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_53EE9BF0_39F0_483B_8EC0_EC3B07ECC1F2) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_BA6A2A39_184E_4C3C_87BD_6421A00289B4) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_FBE18D64_E8CC_439F_8FAE_3073A43EA80B) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_CD528D0B_5484_4DFF_86E5_B95CE6FC1453) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_EBE6D7ED_97F3_4398_A17C_0DAC6C806B9D) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_3BFD2E00_CA6B_48A5_AC9A_5B9ADAD983D0) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_92C07E2E_A639_4949_A641_D41C89505214) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_E4CA8B41_2FB0_4B6F_9410_A8394AEBCD61) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_03BD53FB_30AF_4C4E_89BD_46BDE391E576) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_53F81A79_EB77_4F47_90A3_0F8D769BF31C) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_DD451635_61CB_4C9C_B598_ED7551BCE1E7) },
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
