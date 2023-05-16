#include "be_constobj.h"

static be_define_const_map_slots(m_libFlash_map) {
    { be_const_key(Get_Sketch_MD5, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_MD5_1A5193AC_8E6A_4399_A15F_CDAA68C94894) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Maximum, 17), be_const_int(32) },
    { be_const_key(Get_Sketch_Free_Space, 16), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Free_Space_24E3770E_6553_4CB8_854E_E3C19B59989C) },
    { be_const_key(Partition_Subtype_Enumeration_Data_PHY, 13), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_Data_ESPHTTPD, 20), be_const_int(128) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_1, -1), be_const_int(17) },
    { be_const_key(Get_Speed, -1), be_const_ctype_func(Berry_Flash_Class_Get_Speed_A79C058F_0B35_4ED6_9E06_569E6D8F65D3) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_9, -1), be_const_int(25) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Core_Dump, -1), be_const_int(3) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_2, 19), be_const_int(18) },
    { be_const_key(Partition_Subtype_Enumeration_Application_Test, -1), be_const_int(32) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Flash_Class_Get_Size_E6E40A40_88DF_4388_A7F9_BDA95E2DCA0D) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_13, 5), be_const_int(29) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_14, -1), be_const_int(30) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_12, 28), be_const_int(28) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_4, 3), be_const_int(20) },
    { be_const_key(Partition_Subtype_Enumeration_Data_SPIFFS, -1), be_const_int(130) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_7, 22), be_const_int(23) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS, -1), be_const_int(2) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Flash_Class_Read_F383016D_F42D_4565_AF6C_AC616C394D2A) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Minimum, -1), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_X_ila_Partition, 0), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_15, -1), be_const_int(31) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_3, 30), be_const_int(19) },
    { be_const_key(Get_Pointer, 11), be_const_ctype_func(Berry_Flash_Class_Get_Pointer) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Undefined, 27), be_const_int(6) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_6, 14), be_const_int(22) },
    { be_const_key(Get_Sketch_Size, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Size_2AC81C45_99BD_4D31_B6C7_35B180ED2072) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Fat, -1), be_const_int(129) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_5, 33), be_const_int(21) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_11, -1), be_const_int(27) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Flash_Class_Get_Mode_ACCA3DC0_DA3D_453E_A110_CABF2F562F4D) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_8, -1), be_const_int(24) },
    { be_const_key(Partition_Subtype_Enumeration_Any, -1), be_const_int(255) },
    { be_const_key(Partition_Subtype_Enumeration_Bootloader_Partition, -1), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS_Keys, -1), be_const_int(4) },
    { be_const_key(Partition_Subtype_Enumeration_Data_OTA, -1), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_10, -1), be_const_int(26) },
    { be_const_key(Partition_Subtype_Enumeration_Data_eFuse, -1), be_const_int(5) },
};

static be_define_const_map(
    m_libFlash_map,
    39
);

static be_define_const_module(
    m_libFlash,
    "Flash"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Flash);
