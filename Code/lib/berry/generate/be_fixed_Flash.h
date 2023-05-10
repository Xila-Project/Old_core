#include "be_constobj.h"

static be_define_const_map_slots(m_libFlash_map) {
    { be_const_key(Get_Sketch_MD5, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_MD5_DC4E0D76_570E_4E3E_A6D8_30E61A8E10C4) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Maximum, 17), be_const_int(32) },
    { be_const_key(Get_Sketch_Free_Space, 16), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Free_Space_99EB3F39_B747_4E25_AE1F_0E52262F3553) },
    { be_const_key(Partition_Subtype_Enumeration_Data_PHY, 13), be_const_int(1) },
    { be_const_key(Partition_Subtype_Enumeration_Data_ESPHTTPD, 20), be_const_int(128) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_1, -1), be_const_int(17) },
    { be_const_key(Get_Speed, -1), be_const_ctype_func(Berry_Flash_Class_Get_Speed_AFC91DFB_D9CE_4F4A_A401_49FDE2D41289) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_9, -1), be_const_int(25) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Core_Dump, -1), be_const_int(3) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_2, 19), be_const_int(18) },
    { be_const_key(Partition_Subtype_Enumeration_Application_Test, -1), be_const_int(32) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Flash_Class_Get_Size_6E23EB1E_487D_4C01_9943_23EF092DBCFA) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_13, 5), be_const_int(29) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_14, -1), be_const_int(30) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_12, 28), be_const_int(28) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_4, 3), be_const_int(20) },
    { be_const_key(Partition_Subtype_Enumeration_Data_SPIFFS, -1), be_const_int(130) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_7, 22), be_const_int(23) },
    { be_const_key(Partition_Subtype_Enumeration_Data_NVS, -1), be_const_int(2) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Flash_Class_Read_13B07DFA_F34A_484D_B793_B3FD941EDEE7) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_Minimum, -1), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_X_ila_Partition, 0), be_const_int(16) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_15, -1), be_const_int(31) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_3, 30), be_const_int(19) },
    { be_const_key(Get_Pointer, 11), be_const_ctype_func(Berry_Flash_Class_Get_Pointer) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Undefined, 27), be_const_int(6) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_6, 14), be_const_int(22) },
    { be_const_key(Get_Sketch_Size, -1), be_const_ctype_func(Berry_Flash_Class_Get_Sketch_Size_6C57A11B_B341_4B42_A306_849FAB7224CA) },
    { be_const_key(Partition_Subtype_Enumeration_Data_Fat, -1), be_const_int(129) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_5, 33), be_const_int(21) },
    { be_const_key(Partition_Subtype_Enumeration_OTA_11, -1), be_const_int(27) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Flash_Class_Get_Mode_3ED4D12D_16EA_47A5_8B11_68E54D20E990) },
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
