#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_B99C3AEE_4873_4802_92EE_DBE4FFA76BA0) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_9B286C3E_DC81_4B78_8E8D_E4DEFC9B9FEB) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_EDB73AE0_F28F_49EE_90C9_B431A46310AD) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_D3E8039A_B87C_4735_A807_8284E3EB3B77) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_BCAD4E7E_A202_4786_B55A_219A6A697127) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_BEE1B6B8_6C14_4776_93D4_78483B5BE0E5) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_1BC52AA3_414A_440C_9970_9D2ECF05C878) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_FCF9463E_F5D1_4665_8B3D_D58C3982EDD0) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_BA6D00A8_66BC_4B01_A81B_A6F31CF76B9D) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_7B4B8C6F_A45F_41F8_B19F_687DBD724839) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_6FAC2F01_C929_431E_A5A0_1D0D2DAB6B4A) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_E967F304_864B_4301_8CE4_2C662D7FD315) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_89B540BE_163F_4128_839A_83F8B7E408D9) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_5C1F86E1_74FA_4AB5_B44F_727B379B4B4D) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_CB62A40E_D08E_484E_BAE4_F1058A2E9ED5) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_024031EC_FEE3_4BDA_B5C6_B28768C30087) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_CF0ED2EF_C3CB_4CA0_86E6_4DA3839004F9) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_E195714C_E596_4F74_9638_44A7A23A0A0C) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_29DFDCCD_D885_4D12_803D_4BE00F445881) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_67F949F7_AC42_401A_A493_E62375F1330B) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_WiFi_Client_Type_map,
    21
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_WiFi_Client_Type,
    1,
    NULL,
    WiFi_Client_Type
);
