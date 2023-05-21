#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_9E59727D_176B_4BCE_8A99_9685BA1875CD) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_5598F489_6983_4C76_9581_C96F2842F1BE) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_8FBD3B32_6929_4975_8A1A_A9FF4913EA51) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_56B8D4D1_B5D1_458F_8346_E54D1827A5E4) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_28C94D1F_8EC5_4EE4_98F0_E05F9439D1E7) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_61139E59_114A_4612_9170_206887BFF8D4) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_1D27DF1B_ACA7_4E17_A09D_69D9F66720CC) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_2C539702_318A_41B7_A24F_7F2348D9AFC1) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_59B33D04_5F6B_47EA_BC55_1077F2008432) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_7C195F74_7E53_415D_A524_A84313D367F4) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_F48405C1_129A_4A34_86B0_F8E5FB94422B) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_FA1D8BF7_8D77_4DCB_8283_DF35B7DC38EC) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_EE07C07D_B8B3_48B4_81F6_A1FAC352C54F) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_EDDDCDD8_58F0_4C10_9BAF_B09A6B7926F8) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_D98B3D04_1252_4595_919E_9959B6B50DCB) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_1FD37F7F_513E_4F78_8642_1C0D7393E380) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_E4084754_4A04_4431_AE6A_F45624759B00) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_A0668B89_879D_441D_82E4_A7DB6DFACFAB) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_31127B13_5480_45C8_94E1_F0B95B81B3C2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_61C593D0_297F_49C5_81A3_F915C574F178) },
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
