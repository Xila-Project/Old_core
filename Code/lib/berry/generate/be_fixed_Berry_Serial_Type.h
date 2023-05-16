#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_C2794C4E_F84C_4370_8C59_5DA0E71021C3) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_A9BC49AE_0605_4EE8_A24E_CFD784E38C1E) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_56164BBB_06E8_4430_90B7_C9C96F3781FD) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_3BD0E5D7_B94E_4D1C_9786_3E10ACD79874) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_EA55A2B1_6831_4359_8CFB_8F6BB1FA18EC) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_A3AE4592_7047_4FD5_9FB2_72EF7BBDFBF7) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_2146ED41_37B6_4C80_ABB6_2DFCBA723B1A) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_672F196C_C8FD_4AED_983E_EE7C722F8CC5) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_9DD3C19E_8B32_445F_9957_F6858F9C1D08) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_D319A25F_D5C5_4A85_B4CB_E4D33206D1FB) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_D24BE4A2_B0FA_42CF_80D2_9B95FF2BF7C2) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_D532941D_7988_4169_8814_54208E4B89FF) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_DB1EE2E5_FC3D_4B06_A380_4A56D78284BD) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_3F409DC3_1CA3_4D7C_B29F_3031F24CD27C) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_61B29157_96B9_49DE_B0E2_F90B43A67DEA) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_560C1DE0_9B97_4592_9CF8_80C6BEA62B6E) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_CDA0CE4C_83E2_4173_9240_88294AE2A9F2) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_9A5F4D0E_D54E_43D3_B8DB_F7D57CB57740) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_645C781F_D718_486A_A51B_4729DD785A51) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_29DC03AF_2E48_4CEA_9B05_4F791A96EB36) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_7139A32C_53E7_420D_8107_2D7C7D56D620) },
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
