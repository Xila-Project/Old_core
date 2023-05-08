#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Panic_Low_Memory, -1), be_const_int(13) },
    { be_const_key(Set_Time_Zone, 6), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_64DDEB4A_56F8_40C7_AF36_3BD11CD7313F) },
    { be_const_key(Get_Cycles_Count, 14), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_ED446BCB_4AFD_4B99_A519_F2DC9F0EB688) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Daylight_Offset, 36), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_E1B9DD30_DB18_4D1F_B709_EF87A2084753) },
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_A952097C_BDA7_4C79_BD00_2C25AAA06516) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_CC163317_36A6_4B60_8016_3CAD67B175D5) },
    { be_const_key(Get_Up_Time_Milliseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_14565F92_615E_42EB_AC44_29D3110D730C) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_3969308F_416A_40BB_AF47_D28F37B17D56) },
    { be_const_key(Get_Chip_Model, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_9ED40D4C_A0D0_4AFE_8E3F_156F9075B6EE) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Get_eFuse_MAC, -1), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_9B148782_E9EF_42E2_9B70_2A85C18461AE) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_47BF5EDB_6FFF_4FDB_A21D_01462C93EFF8) },
    { be_const_key(Start, 4), be_const_ctype_func(Berry_System_Class_Start_623821FC_B37F_4823_9986_CAEBBE553806) },
    { be_const_key(Panic_Memory_Corruption, -1), be_const_int(14) },
    { be_const_key(Get_CPU_Frequency, -1), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_F0BAE1D4_9491_46E9_ACAA_E2D71E098EF9) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 24), be_const_int(10) },
    { be_const_key(Get_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_FE18BAA4_26F0_4610_955F_75BEF98AA7EA) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_EF3F928D_1A09_4213_9BE9_3FA894E45337) },
    { be_const_key(Get_Up_Time_Microseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_61C239DE_0954_47E6_8C03_C4C6E87E069A) },
    { be_const_key(Panic_Damaged_System_Registry, 8), be_const_int(2) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_91B1A5B8_0155_4735_8FB8_D9C4DCA46A86) },
    { be_const_key(Panic_Failed_To_Start_Drive, 13), be_const_int(11) },
    { be_const_key(Get_Up_Time, 28), be_const_ctype_func(Berry_System_Class_Get_Up_Time_B0449CDE_C7F1_466F_9AE0_9E42B6715183) },
    { be_const_key(Panic_Failed_To_Start_Power, -1), be_const_int(8) },
    { be_const_key(Panic_Failed_To_Start_Sound, -1), be_const_int(7) },
    { be_const_key(Task_Function, 25), be_const_ctype_func(Berry_System_Class_Task_Function_30B6ECD4_DCB4_4293_B623_4664DBBE5EE3) },
    { be_const_key(Panic_Failed_To_Start_Graphics, 29), be_const_int(6) },
    { be_const_key(Panic_Failed_To_Start_Communication, 19), be_const_int(9) },
    { be_const_key(Get_Device_Name, 7), be_const_ctype_func(Berry_System_Class_Get_Device_Name_DEBA7708_A4F2_445C_908B_9085118A56B4) },
    { be_const_key(Panic_Failed_To_Start_Display, 2), be_const_int(5) },
    { be_const_key(Panic_Installation_Conflict, -1), be_const_int(3) },
    { be_const_key(Get_Chip_Cores, 20), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_C54F0894_1233_4437_856A_2C22B8BB4056) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_D72B7CFA_239D_436F_B3A1_8DD8F4FD4519) },
    { be_const_key(Get_UTC_Offset, 11), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_C2C7B6AE_F459_41DB_B976_21231B98230F) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
};

static be_define_const_map(
    m_libSystem_map,
    37
);

static be_define_const_module(
    m_libSystem,
    "System"
);

BE_EXPORT_VARIABLE be_define_const_native_module(System);
