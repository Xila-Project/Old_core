#include "be_constobj.h"

static be_define_const_map_slots(m_libMemory_map) {
    { be_const_key(Get_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_PSRAM_A2C02805_CF98_40B7_A708_FB6F49763F2B) },
    { be_const_key(Get_Heap_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_Heap_Size_5A77C00F_0C36_40D5_8A89_AB3B8DBB8B06) },
    { be_const_key(Get_Free_Heap, 5), be_const_ctype_func(Berry_Memory_Class_Get_Free_Heap_FFC51841_4DDB_4AA3_A37D_318083CAF5D8) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Memory_Class_Get_Pointer) },
    { be_const_key(Get_PSRAM_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_PSRAM_Size_3A35C477_5E16_470B_A796_8E9A76E45FCD) },
    { be_const_key(Get_Minimum_Free_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_Heap_91034744_A1FC_4519_9B4B_9F93A90A13EB) },
    { be_const_key(Get_Minimum_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_PSRAM_E6F34965_F38A_41C6_ABED_77925CFB03B8) },
    { be_const_key(Get_Maximum_Allocated_PSRAM, 2), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_PSRAM_5B7E99FD_3A05_43C4_AC7F_5E7CAAB007F4) },
    { be_const_key(Get_Maximum_Allocated_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_Heap_5B3115A2_8752_4230_8DE4_CE8328417A5B) },
};

static be_define_const_map(
    m_libMemory_map,
    9
);

static be_define_const_module(
    m_libMemory,
    "Memory"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Memory);
