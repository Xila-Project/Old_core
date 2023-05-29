#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_FF03CBE8_47C6_4362_AB2E_84D68028CEDA) },
    { be_const_key(Panic_Memory_Corruption, -1), be_const_int(14) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_952ED08A_2F43_4434_9C6F_0C444242E28A) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_4E6EECE6_CC0F_45F0_973B_928F2DC9535C) },
    { be_const_key(Panic_Failed_To_Start_Display, -1), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Start_Sound, 23), be_const_int(7) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 34), be_const_int(10) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_EC07D76D_8F99_440E_84F3_F5D2FBC6F402) },
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_4F28C013_823F_4ECF_BC79_4B41BFAC13FA) },
    { be_const_key(Refresh_NTP_Client, -1), be_const_ctype_func(Berry_System_Class_Refresh_NTP_Client_92640C1F_4475_4A59_A9CF_B1D6B46A024A) },
    { be_const_key(Panic_Low_Memory, 38), be_const_int(13) },
    { be_const_key(Panic_Failed_To_Start_Power, 28), be_const_int(8) },
    { be_const_key(Get_Chip_Model, 33), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_C991465B_5508_493E_8E6C_892E3DB55231) },
    { be_const_key(Panic_Installation_Conflict, 22), be_const_int(3) },
    { be_const_key(Get_NTP_Server, 25), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_086BD856_2421_45DA_BBBF_74D8D77458D1) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Get_CPU_Frequency, 10), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_75014EF7_FB41_4E1E_88F7_DB6FF9424D1C) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_B8F1C12E_AE6F_4F0A_9D36_B9CDB2E86BD0) },
    { be_const_key(Get_UTC_Offset, 3), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_D09AE669_2827_469B_AC64_C7B031711AA3) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_70C77289_54B3_4254_87F8_D6AB3BC46089) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_2499BB24_F481_402B_B4EB_EB17FAA9ED62) },
    { be_const_key(Get_Up_Time_Microseconds, 37), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_4FC83691_37C5_4F93_AD0A_2B941617DE04) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_01938D1C_3BF0_4DAB_942A_AC62E39A1129) },
    { be_const_key(Panic_Failed_To_Start_Drive, 18), be_const_int(11) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_8CAB348E_4084_4AE8_BE12_52A92A4758D0) },
    { be_const_key(Get_Up_Time_Milliseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_CBA6BB53_ED87_45D5_A122_CC90AD850D15) },
    { be_const_key(Task_Function, 35), be_const_ctype_func(Berry_System_Class_Task_Function_6D96226D_570C_4DD0_805C_1EB02245AC3F) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_00667D62_6952_422D_B268_35345395512B) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_eFuse_MAC, -1), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_7A2CD11B_5810_473E_8DD5_D2679E60265F) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Chip_Cores, 31), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_BBA002AA_F82C_4B3A_9B7A_F6FA6B2487F0) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_3F1B2175_2B0F_43CB_A926_D4091AE05008) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_6502820E_C437_4C6D_B930_C792B1318035) },
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
