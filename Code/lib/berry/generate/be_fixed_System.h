#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_0037E22D_E273_439E_8DEC_8792CC968F53) },
    { be_const_key(Get_Chip_Cores, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_BBB09D17_7C28_47B3_9857_A4C235895621) },
    { be_const_key(Get_Chip_Model, 36), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_8AE00E06_432A_4553_978B_A20DB0581AA9) },
    { be_const_key(Panic_Failed_To_Start_Sound, 7), be_const_int(7) },
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_F1C2C8F7_3DAE_40E4_83EA_07506F3B7C56) },
    { be_const_key(Get_Up_Time_Milliseconds, 35), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_012A68B5_C1ED_4B4E_8C77_688A38E6D916) },
    { be_const_key(Get_eFuse_MAC, 5), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_B25640B8_80DB_4A96_A61D_4C171A6060B3) },
    { be_const_key(Get_Pointer, 12), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_EF937B62_36DB_4D57_91CE_D4AF6B25C68C) },
    { be_const_key(Get_UTC_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_322D0CD2_FA56_4E0B_B7CD_84CF5F3BB82F) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_4DFF1713_940E_4012_8061_368468E3E684) },
    { be_const_key(Panic_Low_Memory, 23), be_const_int(13) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_3B6D6FDB_7AB3_44E9_8C88_20651CB37DDF) },
    { be_const_key(Get_NTP_Server, 8), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_40394837_73CC_4525_A824_EAA069FBA9C0) },
    { be_const_key(Task_Function, 27), be_const_ctype_func(Berry_System_Class_Task_Function_4BED4CD3_9588_4B2B_B2DE_4501C8DE4EDD) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_5881DC70_1BA5_4C5B_91CA_E3F084157FDB) },
    { be_const_key(Panic_Installation_Conflict, -1), be_const_int(3) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 4), be_const_int(10) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_ADE0F606_502A_4788_9A00_BB01776D6EA7) },
    { be_const_key(Panic_Failed_To_Start_Drive, 17), be_const_int(11) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_55457997_4809_4731_AC02_289AD9ACA7D4) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Power, -1), be_const_int(8) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_49C41B7C_FB68_4950_B551_C408ACB4D70E) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_C1658943_C685_46F2_9F5B_084B73973274) },
    { be_const_key(Get_Up_Time_Microseconds, 34), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_B3E79BAE_FB51_4A56_95AD_AACB2A81633A) },
    { be_const_key(Panic_Failed_To_Start_Display, 31), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_7EA5E25E_CA42_40D9_889B_3ED6F08A8A70) },
    { be_const_key(Panic_Memory_Corruption, 9), be_const_int(14) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_6B3F530A_88BA_4EF9_93A5_2964259526F8) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_AF793BBB_D851_4E91_920B_0459B509F40B) },
    { be_const_key(Get_CPU_Frequency, -1), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_9072C43A_7585_4064_9EA3_0641CA607E53) },
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
