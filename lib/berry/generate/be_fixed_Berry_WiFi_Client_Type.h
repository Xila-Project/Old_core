#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_786BBEBB_2E06_4FB1_8834_CD2D50A36FE3) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_9DF0503B_24ED_408A_B7E5_89633BF38303) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_3B0BF050_E294_468A_9A60_32A3B292BBF9) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_78CCCE8A_1C98_4AD8_B6BF_EF1D5506F68F) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_D19B3061_ED13_4C7D_B3EB_860241D393A7) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_18788748_63EC_4972_B6C8_D122056AACDF) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_8349D581_8114_4439_812B_60CF74FBE63B) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_35B6B2FA_A0F3_4381_9BE7_3586790B2549) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_D3B30E1C_19D8_4E1B_B976_B7004655859A) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_352E42A5_2CEA_4A26_A6BD_C84D942179D7) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_5E0D7D97_D891_4390_9B57_6AE93A3A091F) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_F725B515_394F_485F_B9EA_9DBD65269BD9) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_E9EAB374_68DB_4015_8672_88F87F277E06) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_B2B4A9ED_4FEF_4B5B_97D1_5D4B18D3BEE4) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_9410FB87_A0AA_4FDF_BD99_5CF62D3521BF) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_A35B6E48_0B33_4350_9BDC_4B50E1D1DBCE) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_EB491347_9076_4F0F_9568_AB807D92AD2E) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_3F66FEF8_A673_471B_B290_63D4D457B581) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_0A4EFCD5_D4F2_45E4_84F5_1EBC030C936F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_57666CA0_CD94_4455_BA64_C528B60485EE) },
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
