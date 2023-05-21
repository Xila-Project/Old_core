#include "be_constobj.h"

static be_define_const_map_slots(m_libFlash_map) {
    { be_const_key(Get_Sketch_MD5, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_MD5_53A2B1D5_18F2_4DF3_8010_A5616B66350C) },
    { be_const_key(Partition_Subtype_Enumeration_Application_Test, 35), be_const_int(32) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_13, 24), be_const_int(29) },
    { be_const_key(Flash_Mode_QIO, -1), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_Data_PHY, -1), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_1, 36), be_const_int(17) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_10, -1), be_const_int(26) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Fat, -1), be_const_int(129) },
    { be_const_key(Get_Pointer, 29), be_const_ctype_func(Berry_Flash_Class_Get_Pointer) },
    { be_const_key(Get_Mode, 6), be_const_ctype_func(Berry_Flash_Class_Get_Mode_679B7322_0C8B_4622_81B9_621F2EE7FE70) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Maximum, -1), be_const_int(32) },
    { be_const_key(Flash_Mode_Slow_Read, 40), be_const_int(5) },
    { be_const_key(Partition_Subtype_Enumeration_Data_eFuse, 28), be_const_int(5) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_12, -1), be_const_int(28) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Minimum, 17), be_const_int(16) },
    { be_const_key(Flash_Mode_Fast_Read, 22), be_const_int(4) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Undefined, 1), be_const_int(6) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS_Keys, -1), be_const_int(4) },
    { be_const_key(Partition_Subtype_Enumeration_X_ila_Partition, -1), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_3, -1), be_const_int(19) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Core_Dump, 12), be_const_int(3) },
    { be_const_key(Get_Sketch_Size, 42), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Size_F1356524_40E5_4907_88AB_E63C164E26C4) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Flash_Class_Read_8893B646_A82B_4F5E_BF1E_A22B0472E2B3) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_5, -1), be_const_int(21) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_8, -1), be_const_int(24) },
    { be_const_key(Partition_Subtype_Enumeration_Bootloader_Partition, 8), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_2, 21), be_const_int(18) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_14, 15), be_const_int(30) },
    { be_const_key(Get_Sketch_Free_Space, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Free_Space_B1057850_1D41_48E0_B015_5AE5A54C71FD) },
    { be_const_key(Partition_Subtype_Enumeration_Data_SPIFFS, -1), be_const_int(130) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_4, 33), be_const_int(20) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS, -1), be_const_int(2) },
    { be_const_key(Flash_Mode_Unknown, 11), be_const_int(255) },
    { be_const_key(Flash_Mode_DIO, -1), be_const_int(2) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_15, -1), be_const_int(31) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_11, -1), be_const_int(27) },
    { be_const_key(Partition_Subtype_Enumeration_Any, -1), be_const_int(255) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_7, 0), be_const_int(23) },
    { be_const_key(Flash_Mode_DOUT, -1), be_const_int(3) },
    { be_const_key(Get_Size, 4), be_const_ctype_func(Berry_Flash_Class_Get_Size_65D06208_8F51_47DD_8C20_4C2DE9384F53) },
    { be_const_key(Partition_Subtype_Enumeration_Data_ESPHTTPD, -1), be_const_int(128) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_9, 13), be_const_int(25) },
    { be_const_key(Partition_Subtype_Enumeration_Data_OTA, -1), be_const_int(0) },
    { be_const_key(Flash_Mode_QOUT, 45), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_6, -1), be_const_int(22) },
    { be_const_key(Get_Speed, -1), be_const_ctype_func(Berry_Flash_Class_Get_Speed_AA5BF9DC_B13D_41BB_8CA2_D2E32744A861) },
};

static be_define_const_map(
    m_libFlash_map,
    46
);

static be_define_const_module(
    m_libFlash,
    "Flash"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Flash);
