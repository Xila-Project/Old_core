#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_189EFFA7_E8E9_4F86_AF97_71F0CBC98D00) },
    { be_const_key(Get_Chip_Cores, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_BFAE5E9C_2F6F_479B_B4B0_812BC94F9EDA) },
    { be_const_key(Get_Chip_Model, 36), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_030BD4CC_B979_4CC1_A6EF_1339AD553D6C) },
    { be_const_key(Panic_Failed_To_Start_Sound, 7), be_const_int(7) },
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_C9A4C48F_51BE_488A_9DEB_8966A4EC6140) },
    { be_const_key(Get_Up_Time_Milliseconds, 35), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_80016800_6042_4704_A1D3_1504243AF5DF) },
    { be_const_key(Get_eFuse_MAC, 5), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_AA82D0D9_8BB1_439F_826D_964033EC4144) },
    { be_const_key(Get_Pointer, 12), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_26DF0D38_556C_4396_8D66_86EF584587D0) },
    { be_const_key(Get_UTC_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_EE2D4543_8186_4249_AA62_B1901DF187B2) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_0A79B8DB_19D7_4B90_B860_2076A57C7A0A) },
    { be_const_key(Panic_Low_Memory, 23), be_const_int(13) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_5A115C81_77DF_417C_9F42_74C9B6701F6A) },
    { be_const_key(Get_NTP_Server, 8), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_007F9C35_EB30_4E30_897C_C21DAB77E8EF) },
    { be_const_key(Task_Function, 27), be_const_ctype_func(Berry_System_Class_Task_Function_85A5E8F7_FF51_47E2_922F_2B63272220C3) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_DDD18C36_41F8_4519_8BCF_6635E7757F1A) },
    { be_const_key(Panic_Installation_Conflict, -1), be_const_int(3) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 4), be_const_int(10) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_3A477467_BB3F_4190_89CE_EDE6F70D9A9C) },
    { be_const_key(Panic_Failed_To_Start_Drive, 17), be_const_int(11) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_199C6FCB_2FEB_47A8_B0FB_157BD6097541) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Power, -1), be_const_int(8) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_F20F08A6_5A14_4348_99AB_2CF7C4610383) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_3BB97140_E92C_4928_A32C_3359BB2DFF37) },
    { be_const_key(Get_Up_Time_Microseconds, 34), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_0D1CCA25_D749_4175_B0C9_CDAA506D7A45) },
    { be_const_key(Panic_Failed_To_Start_Display, 31), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_036A0634_0A04_4B8B_B265_76498EB1D6E5) },
    { be_const_key(Panic_Memory_Corruption, 9), be_const_int(14) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_113FDF05_2B34_4277_911C_D50E083A0BB0) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_E908FF37_32F8_4EAB_BF27_B660C7B101B2) },
    { be_const_key(Get_CPU_Frequency, -1), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_C27DBCA9_B0B5_4D60_94BF_B5CA4CA8ABFC) },
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
