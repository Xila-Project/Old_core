#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_E371B807_9B06_4BF6_B1BE_6D7A635D5F32) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_43C8B55E_954B_4F03_90CC_F3F486E6481C) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_0FD17A5D_B990_4E93_A85C_2148990FD34E) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_B1EA22CF_AA6E_4489_BCF3_45B11B7C75AE) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_F6ADED24_5DBC_4BF7_8D6C_797B42FBD7A6) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_56D9C87B_7761_4C50_9946_9A90DC66A4E6) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_597DE81F_3A63_4569_9EE5_DE3E1B306531) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_8279A767_4CCD_447F_83AB_38F8FF03FC3A) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_858632FD_F119_4C46_85E4_0294585F246F) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_4877D3F6_56F7_4BCC_880D_657958182742) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_5A518A4E_350E_45A6_9E78_E3FF8F54CCE7) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_5D7C086A_BE4E_4784_8E3F_F0B5C12EE71D) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_C1028B05_9817_4249_9E2D_8C97BF6E8D77) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_DA851EBE_89BB_4C43_A7D8_30403C9F723A) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_94164BCE_5F8B_4279_B3EA_690592195108) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_517B674C_5964_4498_A071_7F65DA4EA4A2) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_EB599A42_B17C_445D_BB31_997146427367) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_14C164E3_2A53_47D0_916A_402B5A2A8FC3) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_CEEB8F46_711A_4A67_B034_F0A7A3781C7C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_CE8BCEFC_4942_48B3_BB05_7C551AC839AD) },
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
