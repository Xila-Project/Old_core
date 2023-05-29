#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_A34806DC_3217_4C97_82C9_58A7687330C0) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_84972749_4DA0_4DD3_9774_6D123FA1EE20) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_89A7E542_BB2F_4D92_A4A3_60FCA8F953D3) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_EE424BE4_BC6B_4ADF_BBDE_761EE21F2EC8) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_CFE23275_149B_4461_8C3B_AA560C6A38BF) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_CC538CD0_949D_475F_9D03_3FA96EC35051) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_66466CC9_D5BD_4866_B290_0C9D7A35BE90) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_688AB8C8_C6B5_4A6E_9C4C_A9461E5CBCF8) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_BB363AD4_49C9_457E_BB58_0A87ABB369B8) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_2FDCC8EE_D2D0_4E31_A9B6_F67AD1DA72E5) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_41396E12_6D2C_4C87_B024_AF5ACA8EBF95) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_A2ACBD97_FBF6_44B9_9BA0_5677C75D9C34) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_7823862D_C11A_4F4B_A4CF_CA6BAE39104D) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_4D8EDD77_7E0F_488C_9CA1_99CBAF073562) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_9BBC372A_5EE2_4BF8_8B7B_11CB61F9C47A) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_A026CDAE_0D3F_4C19_831C_B9D077D57E85) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_2FC3CDE6_6048_4DD8_B133_EA6ECFBD024E) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_E4869DEF_042E_487B_AE0A_5AD148FB10F1) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_10E31D47_B762_45B8_8722_0CBA52FE0F37) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_B156FFF2_1A1C_4BB9_8B65_CB219935C787) },
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
