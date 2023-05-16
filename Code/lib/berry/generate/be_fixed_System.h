#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_0F4E2F9E_0255_4985_AC68_427A2FE120D9) },
    { be_const_key(Get_Chip_Cores, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_60BCA5A5_3282_41E6_9E55_D7B555A534F2) },
    { be_const_key(Get_Chip_Model, 36), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_365FED32_BB87_4FD9_80A0_E6031CC7978F) },
    { be_const_key(Panic_Failed_To_Start_Sound, 7), be_const_int(7) },
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_43A63151_F05F_4BDA_8FD6_6CF899548F31) },
    { be_const_key(Get_Up_Time_Milliseconds, 35), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_9A27FAF3_E411_49A1_B7D1_FCF14601AC5D) },
    { be_const_key(Get_eFuse_MAC, 5), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_E7456571_78B4_40A7_85B3_0050E1335FF7) },
    { be_const_key(Get_Pointer, 12), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_8E32EE6C_FD00_4D60_9575_2A39B552902D) },
    { be_const_key(Get_UTC_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_451D2CD5_E5A8_473E_9E0C_FE9108471692) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_800C049A_E249_4CCB_A3CE_4C5F17228C94) },
    { be_const_key(Panic_Low_Memory, 23), be_const_int(13) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_DC157E1C_1218_47A9_B9A3_C07BDC97F8CD) },
    { be_const_key(Get_NTP_Server, 8), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_4F2E3010_0295_4B9E_8A56_F475BA0184F7) },
    { be_const_key(Task_Function, 27), be_const_ctype_func(Berry_System_Class_Task_Function_BDD76BF2_A623_4129_9425_D03DF3A9BA09) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_FF65E543_FBEE_45F1_A725_90F930A6EE29) },
    { be_const_key(Panic_Installation_Conflict, -1), be_const_int(3) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 4), be_const_int(10) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_37CEFF8B_CFCB_4A34_A715_541B93C9D979) },
    { be_const_key(Panic_Failed_To_Start_Drive, 17), be_const_int(11) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_BAF28839_A9D4_4F48_AE88_A778DA1FA8F8) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Power, -1), be_const_int(8) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_0133079B_69AF_47BC_9F1F_445ED908568F) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_B8EE0536_688E_47E0_B047_D2AFB334DF77) },
    { be_const_key(Get_Up_Time_Microseconds, 34), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_6E9D97E8_E93D_4F78_B5DE_99D1FEDFA1BC) },
    { be_const_key(Panic_Failed_To_Start_Display, 31), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_D120D58B_A7FB_44B5_9FD3_2942E2BC5C31) },
    { be_const_key(Panic_Memory_Corruption, 9), be_const_int(14) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_0D76B718_2BCC_449A_8835_E6D7598FD50B) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_9F789697_2FEA_4B14_BF87_5D93A853768D) },
    { be_const_key(Get_CPU_Frequency, -1), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_E33CB724_E693_4BB5_A6E6_85FB21886AD8) },
};

static be_define_const_map(
    m_libSystem_map,
    38
);

static be_define_const_module(
    m_libSystem,
    "System"
);

BE_EXPORT_VARIABLE be_define_const_native_module(System);
