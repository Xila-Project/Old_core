#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_0C710D3B_8C99_4FD1_9FC3_1456E4339D9C) },
    { be_const_key(Panic_Memory_Corruption, -1), be_const_int(14) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_3B774246_9051_4D14_AC77_872D583D76F5) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_BF811CBE_2FE9_43AB_8194_EC01948BF87F) },
    { be_const_key(Panic_Failed_To_Start_Display, -1), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Start_Sound, 23), be_const_int(7) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 34), be_const_int(10) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_6503FD9A_AD54_4B9B_8FC4_F800BA76A1D8) },
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_C82DE63B_15DB_4ECC_A098_13CEF2E6AEB1) },
    { be_const_key(Refresh_NTP_Client, -1), be_const_ctype_func(Berry_System_Class_Refresh_NTP_Client_8FDAD862_1A71_441F_88A8_9170E23B557B) },
    { be_const_key(Panic_Low_Memory, 38), be_const_int(13) },
    { be_const_key(Panic_Failed_To_Start_Power, 28), be_const_int(8) },
    { be_const_key(Get_Chip_Model, 33), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_2E4A3B3B_37CE_4B43_B4F7_C7F5CD5A4F62) },
    { be_const_key(Panic_Installation_Conflict, 22), be_const_int(3) },
    { be_const_key(Get_NTP_Server, 25), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_56102630_C201_49D8_A411_80405CD9C295) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Get_CPU_Frequency, 10), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_052776AD_F125_420C_9198_C82255973180) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_79BFF290_37F4_4B92_A5BD_A3824BBA195B) },
    { be_const_key(Get_UTC_Offset, 3), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_4245B630_52DD_41EC_A20D_361C2163F9D9) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_8EDF4518_AE86_4921_AD75_6541947F5322) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_E4A74266_3B6D_4C15_8DE1_ECB99146B102) },
    { be_const_key(Get_Up_Time_Microseconds, 37), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_5F330F81_B3D6_42E1_B878_984B3BF1CCBE) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_C1F76F18_5EE6_4B4A_A447_A5C54FE3D8E2) },
    { be_const_key(Panic_Failed_To_Start_Drive, 18), be_const_int(11) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_1647FD15_10AE_43A6_99D8_64D92009EB46) },
    { be_const_key(Get_Up_Time_Milliseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_FB12606F_0001_4756_94F9_D0E283775EA2) },
    { be_const_key(Task_Function, 35), be_const_ctype_func(Berry_System_Class_Task_Function_2DB8E837_DDA0_4428_8306_6BCCE2C26633) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_BE3EF6B6_0739_46C1_A3E2_5174728B6E8F) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_eFuse_MAC, -1), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_B7087059_3248_48EA_8694_97E64E8417B0) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Chip_Cores, 31), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_C5613061_F339_4006_9146_2004ADCA4AE6) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_9A1C80A4_854C_438F_BB9E_E5D9C5F27C5F) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_1151B93E_714D_4530_BE8E_7DB5113593EF) },
};

static be_define_const_map(
    m_libSystem_map,
    39
);

static be_define_const_module(
    m_libSystem,
    "System"
);

BE_EXPORT_VARIABLE be_define_const_native_module(System);
