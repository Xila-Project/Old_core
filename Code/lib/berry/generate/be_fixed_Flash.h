#include "be_constobj.h"

static be_define_const_map_slots(m_libFlash_map) {
    { be_const_key(Get_Sketch_Free_Space, 24), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Free_Space_4177C172_0A1A_40E1_9BC8_1E60ADA7E08F) },
    { be_const_key(Partition_Subtype_Enumeration_Bootloader_Partition, 3), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_15, -1), be_const_int(31) },
    { be_const_key(Get_Sketch_MD5, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_MD5_4F5F3DC5_73E7_41D7_BC67_F2D2EEA5672F) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_2, -1), be_const_int(18) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_5, 35), be_const_int(21) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Core_Dump, -1), be_const_int(3) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_10, -1), be_const_int(26) },
    { be_const_key(Partition_Subtype_Enumeration_Data_eFuse, -1), be_const_int(5) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS_Keys, 25), be_const_int(4) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_6, -1), be_const_int(22) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_9, -1), be_const_int(25) },
    { be_const_key(Partition_Subtype_Enumeration_Data_OTA, -1), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_14, -1), be_const_int(30) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Minimum, -1), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_3, -1), be_const_int(19) },
    { be_const_key(Get_Sketch_Size, 22), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Size_F6A7E846_F67C_44E8_B13E_AC927BB17226) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_12, -1), be_const_int(28) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Maximum, 36), be_const_int(32) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS, -1), be_const_int(2) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_1, -1), be_const_int(17) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_7, -1), be_const_int(23) },
    { be_const_key(Partition_Subtype_Enumeration_Application_Test, -1), be_const_int(32) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Flash_Class_Get_Mode_3BF7190D_2034_4CC0_96FE_CA5E8AD081B0) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_8, -1), be_const_int(24) },
    { be_const_key(Partition_Subtype_Enumeration_X_ila_Partition, -1), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_Data_ESPHTTPD, -1), be_const_int(128) },
    { be_const_key(Partition_Subtype_Enumeration_Data_PHY, 31), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_Data_SPIFFS, -1), be_const_int(130) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Fat, 17), be_const_int(129) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Undefined, 9), be_const_int(6) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Flash_Class_Get_Size_B7C85641_D9FD_4E8B_BF4C_4FBCCE257688) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_4, -1), be_const_int(20) },
    { be_const_key(Partition_Subtype_Enumeration_Any, 28), be_const_int(255) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_11, -1), be_const_int(27) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Flash_Class_Read_461AB8A7_E08A_40B4_B783_1DEFE8F312E9) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_13, -1), be_const_int(29) },
    { be_const_key(Get_Speed, 20), be_const_ctype_func(Berry_Flash_Class_Get_Speed_09EA482A_C80D_48A8_ABEF_107BD92E47D6) },
};

static be_define_const_map(
    m_libFlash_map,
    38
);

static be_define_const_module(
    m_libFlash,
    "Flash"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Flash);
