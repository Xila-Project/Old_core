#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_389FED7C_F2E0_48C5_96D9_946C17C0B9D4) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_E585F832_2254_4E65_86C1_A9B47DD211AB) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_43108888_BE9A_4485_8C98_F82A5D11887C) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_C7F314CA_8AF4_42E6_8774_50244A5BEDD2) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_D3CF9DE3_8397_46EB_836F_2DF677C58C12) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_3C4C9F63_5BD8_4EDB_A731_A620B6EE1594) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_BE7F3D21_1CD5_47D6_87AC_1976302265C3) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_84FAACB5_2225_4E80_885A_D56BA549010A) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_712B3290_52EE_4B40_890A_DB21E9368675) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_63EBC75B_E72F_4E9C_9446_CC79904EB5EA) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_BD1AA6BB_449A_4646_B597_DD11F46FAAF3) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_40ED6208_5E63_458F_B7B0_D064F247592F) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_71D395E0_4AF3_49CD_811D_8967F8454064) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_9F1AAA88_AA09_487B_B8B1_129F58ABD811) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_47C0E567_A586_4228_93AF_059FDA38BBEB) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_29A87DE8_BEB8_40C4_ADEB_88594EBF6476) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_F7A365BF_EE78_4597_9E1A_15D40E209811) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_8E414CD1_8E63_4C7E_A717_8026EDF7EF1A) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_8A4D4DFC_44CB_48A6_9B6A_B712455C7573) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_84BEAF01_0A76_4B92_A02B_815BC7FE2839) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_3B333EC6_AFDE_4DB3_BDA2_E98F6D27AAC5) },
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
