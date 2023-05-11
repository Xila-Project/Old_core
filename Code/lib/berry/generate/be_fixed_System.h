#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_401EBF75_E2FE_4BEF_80E4_8D44D03640B3) },
    { be_const_key(Get_Chip_Cores, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_963BC085_FB4C_4B28_9489_4E3A9C3F8E98) },
    { be_const_key(Get_Chip_Model, 36), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_54C43150_DE31_4366_8EE7_75A398F4EC45) },
    { be_const_key(Panic_Failed_To_Start_Sound, 7), be_const_int(7) },
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_786C03DC_5BED_461D_8165_F659B6F9054E) },
    { be_const_key(Get_Up_Time_Milliseconds, 35), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_EC5368CE_E726_4144_913F_49E525D1EE50) },
    { be_const_key(Get_eFuse_MAC, 5), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_BBEA8CA4_F9D2_459D_8FA1_7A0DE1BDEC67) },
    { be_const_key(Get_Pointer, 12), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_FFBE6BC4_F4D2_4CAB_9586_9E5C02A4C42F) },
    { be_const_key(Get_UTC_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_E0BE7586_B3BA_4995_9EB1_28357CE3CC38) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_FBFCE00F_DC1E_483F_A974_B38F90CFBD96) },
    { be_const_key(Panic_Low_Memory, 23), be_const_int(13) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_C38C8B97_5935_462E_9F2F_011AB671554C) },
    { be_const_key(Get_NTP_Server, 8), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_BEFAFF85_8655_480F_8BFB_C1A6C3F9040F) },
    { be_const_key(Task_Function, 27), be_const_ctype_func(Berry_System_Class_Task_Function_EA7DA2F9_93E2_4609_AD86_B93B1312ED8C) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_ECF5C1D1_015F_4182_9EE5_EF1DFECC586F) },
    { be_const_key(Panic_Installation_Conflict, -1), be_const_int(3) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 4), be_const_int(10) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_FF960957_DA71_4FC0_B879_9A8FDDB0A304) },
    { be_const_key(Panic_Failed_To_Start_Drive, 17), be_const_int(11) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_6303B705_4F61_4575_ABCD_E0CC27CAA2CC) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Power, -1), be_const_int(8) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_63A7CE99_07B0_4CB6_AC1A_94F77144EF2E) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_2D3E8748_E2C8_4442_B2A4_CD9FE8D44302) },
    { be_const_key(Get_Up_Time_Microseconds, 34), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_236942B5_BF00_4B38_B849_A82ED03AB3FE) },
    { be_const_key(Panic_Failed_To_Start_Display, 31), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_B5EF0433_7160_4ED5_B645_A461488276AA) },
    { be_const_key(Panic_Memory_Corruption, 9), be_const_int(14) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_8206AA6C_E76C_4C01_AE89_BF62694706D7) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_4E199EC7_E7D9_4A7B_99CD_8144D46AB52B) },
    { be_const_key(Get_CPU_Frequency, -1), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_0A81968C_E428_46B4_B8B9_DA9A4EF5114A) },
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
