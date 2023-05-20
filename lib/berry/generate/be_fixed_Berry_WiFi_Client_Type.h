#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_7CC3F2AD_558F_4A84_B233_01C969E63924) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_102F120D_9777_45C2_84D8_F25F81E92D5C) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_0320BCEA_8AF0_4DF8_9A78_3DEA67D4B0BE) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_F7CAA55F_6EC4_4283_B02B_740CE9940587) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_9BDD8EFB_8828_4324_A8C6_70F9713BEF72) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_F61B0014_EB18_4512_BC33_2566C595B350) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_49D312B2_E1DC_4582_8BB1_F5C2267330B6) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_15B4E9CB_C8EE_473E_A3A4_A83828E8AB81) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_61C4F9A8_05F1_47E9_AE56_E6E264FB9728) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_9FB22C4D_8049_4508_9E42_3E16FA6B73A6) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_C3F60A04_D3D1_4950_9ECB_6461B6D9E248) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_5D39B95C_C5C3_40D7_AE87_D141426897B3) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_D1325362_E30E_4617_861A_1D7CC817CDA2) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_C4617B37_92DE_4967_A2BB_0BF1C04CEEF9) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_5C1F3DAD_577A_4D77_B776_B07838A2610F) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_1CA38511_E715_4AE0_B2DA_7C7B56284B46) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_5A8AD354_8C18_4261_88B5_1AE5BE2401E6) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_5B88FF4B_920A_4443_B3B1_B61EB2F9E92A) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_161F7F8B_119D_42CE_8239_A724B507DABF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_82997744_0414_4D77_8B08_FDBF6D12AF2C) },
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
