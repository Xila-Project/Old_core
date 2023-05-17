#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_D71861AD_6E64_46E9_B1D6_41ED98ED74D5) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_DF74408E_E893_4389_A6EB_17767485E363) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_7BB4464A_A35E_47C4_9A67_FCEA1711F7F0) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_BB858350_CAB4_4509_9570_3F3D377FA43D) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_EA871E8B_B5EC_4C31_961B_11747CBA18A1) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_3EDB5143_C347_4D5F_B338_A77A9908933F) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_A41DE907_E9CC_43DD_8446_DEFA57E563FD) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_52469351_8C4E_4AF1_AFAF_99F9E9B84509) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_AED71CEA_AD76_4574_852E_B33D51FC2FD5) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_775064BA_93EF_413E_BA8A_7FCDF8A8E313) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_41C1A5B4_C7E6_4203_9F7A_A73916E04035) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_34F78E3F_3792_4913_99AE_C9CEC0C5375E) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_D71F63E8_9027_4318_95D3_6180B37B3115) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_00D0DE2E_54CD_4057_B640_AAE60621402B) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_1DCB1A74_1915_4B46_B845_21F12DFDA900) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_37547934_75C6_4689_9DB5_FB3CC463C769) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_7AF44339_6CAC_442A_B29A_59345A420CB9) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_BA54E799_4145_4BEC_9A18_B4F72D6457DB) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_0DFA8D04_A213_4CD8_ACC4_E239DE2F4952) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_12F6DC52_18C5_42A3_BBE3_07120D73D775) },
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
