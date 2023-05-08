#include "be_constobj.h"

static be_define_const_map_slots(m_libFlash_map) {
    { be_const_key(Get_Sketch_Free_Space, 24), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Free_Space_BC83956D_F9D7_4CAA_A2CE_BEFF0224C19C) },
    { be_const_key(Partition_Subtype_Enumeration_Bootloader_Partition, 3), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_15, -1), be_const_int(31) },
    { be_const_key(Get_Sketch_MD5, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_MD5_811E667A_8107_4D88_9B6B_2ACAAA03165C) },
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
    { be_const_key(Get_Sketch_Size, 22), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Size_E60BFF3F_E182_473F_9576_FB2775FEF8B6) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_12, -1), be_const_int(28) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Maximum, 36), be_const_int(32) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS, -1), be_const_int(2) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_1, -1), be_const_int(17) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_7, -1), be_const_int(23) },
    { be_const_key(Partition_Subtype_Enumeration_Application_Test, -1), be_const_int(32) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Flash_Class_Get_Mode_C73CE7F1_EC85_4CE6_8DD6_C66C96F5555F) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_8, -1), be_const_int(24) },
    { be_const_key(Partition_Subtype_Enumeration_X_ila_Partition, -1), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_Data_ESPHTTPD, -1), be_const_int(128) },
    { be_const_key(Partition_Subtype_Enumeration_Data_PHY, 31), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_Data_SPIFFS, -1), be_const_int(130) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Fat, 17), be_const_int(129) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Undefined, 9), be_const_int(6) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Flash_Class_Get_Size_86E2E20A_7C78_4428_BF5C_2A9597C84ECC) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_4, -1), be_const_int(20) },
    { be_const_key(Partition_Subtype_Enumeration_Any, 28), be_const_int(255) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_11, -1), be_const_int(27) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Flash_Class_Read_E6EE061C_CABC_4B53_8221_D8F35665DBCA) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_13, -1), be_const_int(29) },
    { be_const_key(Get_Speed, 20), be_const_ctype_func(Berry_Flash_Class_Get_Speed_FA95E450_F0D5_4D80_BE3B_EDB9A80E268C) },
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
