#include "be_constobj.h"

static be_define_const_map_slots(Berry_WiFi_Client_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_7CF9F918_1778_4BF6_9611_D31CEB4A996C) },
    { be_const_key(Read_String, 7), be_const_ctype_func(Berry_WiFi_Client_Class_Read_String_3B884734_450A_46FC_AB2B_E6EBBE89FF23) },
    { be_const_key(Connect, 9), be_const_ctype_func(Berry_WiFi_Client_Class_Connect_96166EDD_EB03_4CAA_8E42_5F9A9EB440D2) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_Bytes_49388892_EA54_4CAB_926A_B11116A248BD) },
    { be_const_key(Set_Handshake_Timeout, 8), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_AF77D864_E6E2_42D6_AFDD_4BE7D0B24D0D) },
    { be_const_key(Stop, 3), be_const_ctype_func(Berry_WiFi_Client_Class_Stop_77ABE04F_A181_460F_B7AE_0F5D2BF737DE) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Flush_229622AE_4AEF_4CAC_A9FF_1D818C3A8EAC) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_0B9F2F2C_DBDF_4FB1_9498_C75ED1BE85FA) },
    { be_const_key(Set_Insecure, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Insecure_69E1B3BC_8C96_46DA_9781_0CAD73AB542E) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Available_1A750A35_D19E_4041_8825_B4937EFA84A8) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Read_Bytes_4CEBBC37_0366_42BF_AC02_2322CA82D84F) },
    { be_const_key(_X3D_X3D, 6), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_C7A00CA3_7B48_411B_A941_E85F8AB4D9A1) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_WiFi_Client_Class_Initialize_4F79E032_EAD8_4EC8_A367_C5E90DEF9225) },
    { be_const_key(Connected, 15), be_const_ctype_func(Berry_WiFi_Client_Class_Connected_D779895D_10FB_4B97_A38F_77479BF4B254) },
    { be_const_key(Last_Error, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Last_Error_00AE7CAF_83FA_48AB_AB76_63E5B9DC6858) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Write_String_F4AF44BC_440A_4675_9592_922C18D49C5D) },
    { be_const_key(_X21_X3D, 10), be_const_ctype_func(Berry_WiFi_Client_Class_Operator_63B4CB38_3FAD_4BFF_85E8_40C8069BA8A2) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Peek_D4B66429_9D54_491E_A3D8_8A3131E8D9C7) },
    { be_const_key(Set_Timeout, 14), be_const_ctype_func(Berry_WiFi_Client_Class_Set_Timeout_2B4DDAA6_1F4D_4C37_B2A9_04E60E68BB5C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WiFi_Client_Class_Deinitialize_140EEA4C_15B9_41DD_8C0B_2CD09329FBF9) },
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
