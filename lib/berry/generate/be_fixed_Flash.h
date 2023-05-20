#include "be_constobj.h"

static be_define_const_map_slots(m_libFlash_map) {
    { be_const_key(Get_Sketch_MD5, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_MD5_C5E62C99_D8FE_42D8_BEB2_1F06A6EA0A35) },
    { be_const_key(Partition_Subtype_Enumeration_Application_Test, 35), be_const_int(32) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_13, 24), be_const_int(29) },
    { be_const_key(Flash_Mode_QIO, -1), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_Data_PHY, -1), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_1, 36), be_const_int(17) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_10, -1), be_const_int(26) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Fat, -1), be_const_int(129) },
    { be_const_key(Get_Pointer, 29), be_const_ctype_func(Berry_Flash_Class_Get_Pointer) },
    { be_const_key(Get_Mode, 6), be_const_ctype_func(Berry_Flash_Class_Get_Mode_DC44AF17_4621_4992_B10F_D43E655158FC) },
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
    { be_const_key(Get_Sketch_Size, 42), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Size_90714B4D_3096_4F48_992F_2D820A40438E) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Flash_Class_Read_B6E13DF3_7949_4F8A_8799_F8F669887F40) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_5, -1), be_const_int(21) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_8, -1), be_const_int(24) },
    { be_const_key(Partition_Subtype_Enumeration_Bootloader_Partition, 8), be_const_int(0) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_2, 21), be_const_int(18) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_14, 15), be_const_int(30) },
    { be_const_key(Get_Sketch_Free_Space, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Free_Space_F1712220_ACD2_45A0_AAED_2C2D1006A9EC) },
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
    { be_const_key(Get_Size, 4), be_const_ctype_func(Berry_Flash_Class_Get_Size_40109B36_F26F_4D5D_B25B_DC7693C32651) },
    { be_const_key(Partition_Subtype_Enumeration_Data_ESPHTTPD, -1), be_const_int(128) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_9, 13), be_const_int(25) },
    { be_const_key(Partition_Subtype_Enumeration_Data_OTA, -1), be_const_int(0) },
    { be_const_key(Flash_Mode_QOUT, 45), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_6, -1), be_const_int(22) },
    { be_const_key(Get_Speed, -1), be_const_ctype_func(Berry_Flash_Class_Get_Speed_D4FD9D2B_9DB4_444A_BF35_E5B6D2B55214) },
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
