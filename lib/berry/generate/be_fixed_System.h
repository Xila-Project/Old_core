#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_044C946C_2915_410B_A92B_A8B8173E8296) },
    { be_const_key(Panic_Memory_Corruption, -1), be_const_int(14) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_22506037_0E15_4A61_906F_C7D5D4D1CE0B) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_B421E14A_93B4_481B_846F_98A748CC4B3B) },
    { be_const_key(Panic_Failed_To_Start_Display, -1), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Start_Sound, 23), be_const_int(7) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 34), be_const_int(10) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_B435F3D7_9E32_4D89_A1DA_5440F5B191CD) },
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_306FA328_7EE4_4383_B695_6E9428C2F693) },
    { be_const_key(Refresh_NTP_Client, -1), be_const_ctype_func(Berry_System_Class_Refresh_NTP_Client_05EE08AD_25A3_46B6_BC9A_073E6BAC0FB8) },
    { be_const_key(Panic_Low_Memory, 38), be_const_int(13) },
    { be_const_key(Panic_Failed_To_Start_Power, 28), be_const_int(8) },
    { be_const_key(Get_Chip_Model, 33), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_917D9805_B703_4253_8147_E6376BF0C353) },
    { be_const_key(Panic_Installation_Conflict, 22), be_const_int(3) },
    { be_const_key(Get_NTP_Server, 25), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_089F154E_C9AC_4D49_AD83_B0F6F7FC5884) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Get_CPU_Frequency, 10), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_4132F486_1653_469E_A43E_F442817438C8) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_9D3699F7_B2B1_4114_9C48_10CAC9BCC128) },
    { be_const_key(Get_UTC_Offset, 3), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_6259F093_7F48_463B_A035_B30AD28FC9C7) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_0D12C598_BA77_4765_9D91_19D9B322A84F) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_7184E1E8_489C_458A_8E1C_23305784199A) },
    { be_const_key(Get_Up_Time_Microseconds, 37), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_38F2A950_B37F_4A39_96DE_DADF1B0DA6E3) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_B7322BAE_7C9B_4DA8_B478_F776BB4A92E4) },
    { be_const_key(Panic_Failed_To_Start_Drive, 18), be_const_int(11) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_986B3BC6_086D_4464_948D_B8C10326FFCB) },
    { be_const_key(Get_Up_Time_Milliseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_1A1F70EC_1D3B_4E4A_BA39_868D41B263C5) },
    { be_const_key(Task_Function, 35), be_const_ctype_func(Berry_System_Class_Task_Function_9F1E21A5_6E95_43E0_B789_40A856EC24BE) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_B4606E8D_90E3_46A8_829B_09AD1EA8EC16) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_eFuse_MAC, -1), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_38171789_0BEE_4367_8E4C_91267174A3FC) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Chip_Cores, 31), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_BBC6E096_A0F3_4755_9F83_532C17A1B969) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_1FF7F295_07E0_4DD8_A127_55343E673106) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_449B9741_6503_4022_A1EC_06451984B6D5) },
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
