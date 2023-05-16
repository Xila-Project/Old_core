#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_83AFC323_4C73_41D6_86BE_24CE8FDD854D) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_5B0A4BD0_0D11_4147_AB48_45F29083D87B) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_79C65774_EF4A_47B8_846C_A62F013904BC) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_3031CE88_2656_49FA_82AE_48F5AC086D2E) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_6A35C18E_E3A1_4777_8DD1_2F0B67BE980E) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_BA790EDE_15F3_4BBC_8AF0_FF74AFB3F066) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_2694FEA5_9B92_4736_AB8E_3AD1D050E6F4) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_814D3DB2_237D_42D6_9FA7_22BFE9C5D91B) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_6026ADB7_7808_430A_886F_F461A4779ABB) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_77D2D1FD_841E_4C6B_8327_CA1B9A186C4B) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_37ECD380_5099_468D_A1D6_A60F584B5E7D) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_D102BC52_898B_456B_9020_5D619F74EA75) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_2B6A26E4_EC30_4EB0_B686_B551C6B90B60) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_C109C49B_56AB_4499_B984_E5CADB9DA2E9) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_F3E9B2A6_8B98_474A_8C7A_D479BF9D934E) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_61C3C33A_0786_433C_82A0_616E9918E816) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_D8960DC3_CD1E_468A_9DD9_9304719607A0) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_09F57C41_0ECF_437E_A1DC_C2924DE24D78) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_FC5B5F72_83D9_491B_99EB_572145CAC6EE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_A5C40C15_2AE9_4D26_8C81_2E55330472CA) },
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
