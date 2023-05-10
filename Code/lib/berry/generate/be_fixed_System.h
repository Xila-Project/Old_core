#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Panic_Low_Memory, -1), be_const_int(13) },
    { be_const_key(Set_Time_Zone, 6), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_3A06A8BD_96D0_4CDD_9B01_43823647EE38) },
    { be_const_key(Get_Cycles_Count, 14), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_2E76B100_7AC9_432E_A020_166ECE1A67B7) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Daylight_Offset, 36), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_CF1B10AA_F8A8_4378_AD29_FF7D242BFDDE) },
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_03032CA2_CAB7_4DAF_ACF1_F9A5A8D56D0F) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_EA3A2A4B_5114_4632_A81B_76A8E6FE369A) },
    { be_const_key(Get_Up_Time_Milliseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_7BD6C562_E8D8_4159_A875_D0E768EAC6A3) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_84A58271_D203_4DE3_BBB0_99D49254270C) },
    { be_const_key(Get_Chip_Model, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_1781A8D7_D7D3_410D_A0A7_9A8323DB2292) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Get_eFuse_MAC, -1), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_5CC40DD8_D4C9_4558_B7AE_77832911B6A9) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_46538952_1E1D_40E8_A8E9_1320422DC106) },
    { be_const_key(Start, 4), be_const_ctype_func(Berry_System_Class_Start_E4D1D168_0D1A_49C4_9E1D_9161DF87F498) },
    { be_const_key(Panic_Memory_Corruption, -1), be_const_int(14) },
    { be_const_key(Get_CPU_Frequency, -1), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_B372E420_0C15_41CB_A7B8_C13C42FADE6D) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 24), be_const_int(10) },
    { be_const_key(Get_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_6ADB3E7F_407F_49C6_B73E_6D6A51920E3D) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_401C2648_248C_45CC_8900_09A897D86ADB) },
    { be_const_key(Get_Up_Time_Microseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_379237F0_225B_4E5A_9394_30A5F5754E48) },
    { be_const_key(Panic_Damaged_System_Registry, 8), be_const_int(2) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_8E73827D_32F8_4AD6_83A9_F6D706B228EC) },
    { be_const_key(Panic_Failed_To_Start_Drive, 13), be_const_int(11) },
    { be_const_key(Get_Up_Time, 28), be_const_ctype_func(Berry_System_Class_Get_Up_Time_9458746A_4FBD_443F_9C95_D883E055F5CC) },
    { be_const_key(Panic_Failed_To_Start_Power, -1), be_const_int(8) },
    { be_const_key(Panic_Failed_To_Start_Sound, -1), be_const_int(7) },
    { be_const_key(Task_Function, 25), be_const_ctype_func(Berry_System_Class_Task_Function_2E9C240D_02D4_4558_92F4_DE9ED6B3BD10) },
    { be_const_key(Panic_Failed_To_Start_Graphics, 29), be_const_int(6) },
    { be_const_key(Panic_Failed_To_Start_Communication, 19), be_const_int(9) },
    { be_const_key(Get_Device_Name, 7), be_const_ctype_func(Berry_System_Class_Get_Device_Name_6C51CF51_FD0E_4AA8_A9CC_0C9DFD6C5A9B) },
    { be_const_key(Panic_Failed_To_Start_Display, 2), be_const_int(5) },
    { be_const_key(Panic_Installation_Conflict, -1), be_const_int(3) },
    { be_const_key(Get_Chip_Cores, 20), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_03B6651C_16C6_4E9A_B3CE_5F5F20C0AD99) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_2ACBA299_A912_4744_8C7C_5A1D2AB70E89) },
    { be_const_key(Get_UTC_Offset, 11), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_542C6D54_A072_41BF_B9C1_331B027A212E) },
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
