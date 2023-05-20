#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_9E982D26_E839_4EE0_9C9E_1F6EE4955A3F) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_61FF4A68_BBE0_47AE_9C15_B0F455B4FCF9) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_53AC522D_60B7_4A35_B560_8583DAE78FF7) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_F7073D2F_195B_4E5E_8EBB_8EF5AF95FBEF) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_E6DD5E1D_E32A_4B03_BEA4_C5D805187D6C) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_A120A385_A103_49CA_8088_51952BF75A5C) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_A3F58AFE_C302_483F_9119_D385785814E3) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_4C0BB4B5_0A0E_463A_B912_4EA422BB65D9) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_849AE808_D08C_4955_AE64_BF8782F43F7E) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_771E21D1_73E9_4972_94C8_424872A1FC80) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_F44C1ADE_49CB_4217_AA3C_AEA28F5055D8) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_6F7AB68B_30A7_49CD_B046_AEFFB86B115E) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_0C264D53_AA62_48A3_93FF_C5CCF7D93E68) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_BAD981BC_0A31_4220_8FBF_F1A33A88B1AD) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_6215A251_A7A8_4CF2_8E35_5D9EAF7C00F3) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_E6F63721_C8FA_4E1C_AFCB_EE7FC5B305FD) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_BD0814F4_DC5A_497E_B0E6_05110A1F1B55) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_6CAB19EA_5D62_49F2_988A_EAE2946CD75B) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_F0AF7627_8BFC_4711_9C32_E6C0416FB9FE) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_240BCE5E_EFEE_4BB0_9745_50743876EE56) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_6263D32D_A359_4A64_A81B_2858262EFCE7) },
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
