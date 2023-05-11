#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_C08DF63E_9777_42AA_8F63_6B103AE94495) },
    { be_const_key(Get_Chip_Cores, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_68D1E858_C87A_4B31_822E_25797DF4FB25) },
    { be_const_key(Get_Chip_Model, 36), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_56F144A8_E6AE_458F_95F6_D2A87E431E83) },
    { be_const_key(Panic_Failed_To_Start_Sound, 7), be_const_int(7) },
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_75DF7375_8600_405E_B04A_B5CF6A2DE7E6) },
    { be_const_key(Get_Up_Time_Milliseconds, 35), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_566CF509_EB0C_46E1_82A5_B6B70BC9D0B4) },
    { be_const_key(Get_eFuse_MAC, 5), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_91E7C26B_E200_4286_ABD3_B10176DB8FC4) },
    { be_const_key(Get_Pointer, 12), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_60924786_FC70_4979_9A1C_CC6149CF968A) },
    { be_const_key(Get_UTC_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_B093D654_54FA_40CD_97AF_C9BA67146F6D) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_CAF05E04_5BD3_4F4B_B24B_480B261AA3DC) },
    { be_const_key(Panic_Low_Memory, 23), be_const_int(13) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_36756924_8DB8_4200_866A_1726C690B665) },
    { be_const_key(Get_NTP_Server, 8), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_2722339C_4427_4726_B6F2_E806DAFB7033) },
    { be_const_key(Task_Function, 27), be_const_ctype_func(Berry_System_Class_Task_Function_5E9517B0_9A7D_4E91_A426_4DC7C6F1433B) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_93734F1F_4639_4312_BF13_177B83F07BAE) },
    { be_const_key(Panic_Installation_Conflict, -1), be_const_int(3) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 4), be_const_int(10) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_C1CB3DE5_4A09_417F_9BFA_FBC96B0AA829) },
    { be_const_key(Panic_Failed_To_Start_Drive, 17), be_const_int(11) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_2D21080B_2A0E_4D23_A3B8_F59EA44BDE79) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Power, -1), be_const_int(8) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_C0618702_5940_4E1A_B095_8C3022D4145C) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_F821B458_8BCB_4676_8A39_37E8579EF7E4) },
    { be_const_key(Get_Up_Time_Microseconds, 34), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_B50FD3F9_BA47_42DB_8590_4D27A8CFDD38) },
    { be_const_key(Panic_Failed_To_Start_Display, 31), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_FB934668_5C2E_4A9F_B878_560CBACEF701) },
    { be_const_key(Panic_Memory_Corruption, 9), be_const_int(14) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_9818DED0_3210_44E9_830A_D16560DE923F) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_825D187F_8CDC_4877_991C_1DA630F8C09B) },
    { be_const_key(Get_CPU_Frequency, -1), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_8246E72B_E7D4_41A3_B794_B465947058CF) },
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
