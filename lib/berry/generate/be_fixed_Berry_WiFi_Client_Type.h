#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_F86419D3_229A_4129_B856_48D390E0A467) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_0483C42A_401C_4356_83A0_654469D82D8C) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_C91281F9_2D85_4129_944F_1EBFCAFBD5A8) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_7367CB31_85BA_4693_AA54_A5D49E5E2CB5) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_F178DD00_5983_4786_8790_0A1018267AC1) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_0B4E37E2_AE02_438E_B041_45E0FB9E1D05) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_BF315ED5_3704_4574_9DFE_55BAE084C793) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_FD25E639_4452_4C57_ABA4_1A5D0CCFC167) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_DEED5B14_3BDE_49FD_9975_D7FA7DC7CFE5) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_5C5C1C85_C7FB_4BB3_AA5C_12E57A06B08F) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_6C5303C2_DA7B_4EEF_A415_99A2E4DEC8D4) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_3243A228_E559_42EF_BB46_1F553F7DABD1) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_B2A51B79_3554_4424_820B_6A8DBA1E8826) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_92E073D3_1804_4ADE_97D5_1031475600D0) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_AE7FD966_2B77_4FC8_A802_4DEBE8140702) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_25738A6D_98A9_4D17_8C45_5964F9A35E82) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_892C40F0_23D2_4260_AB78_F554B66FA1BC) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_EBA2EDEC_E2A3_42C1_B713_B3989560C008) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_F0A53CBD_20FA_4D73_87EE_CF6EF6AAF0D0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_F3F5CB09_C349_4CAD_B59D_417915BF6D82) },
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
