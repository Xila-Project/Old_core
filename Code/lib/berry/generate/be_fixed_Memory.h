#include "be_constobj.h"

static be_define_const_map_slots(m_libMemory_map) {
    { be_const_key(Get_Maximum_Allocated_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_PSRAM_71D1D04C_5CA7_4BC4_B26C_D876366C0A7C) },
    { be_const_key(Get_PSRAM_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_PSRAM_Size_517BCC96_E63C_4930_89BE_C3098EFC3099) },
    { be_const_key(Get_Heap_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_Heap_Size_F5EB8CFB_D02F_4BD1_A0D7_1934307BE2B5) },
    { be_const_key(Get_Maximum_Allocated_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_Heap_940311F0_CA3E_493C_A9AE_624EDAAE52AC) },
    { be_const_key(Get_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_PSRAM_E9D30C91_EB11_4CE1_91AD_530499987B4B) },
    { be_const_key(Get_Free_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_Heap_29FF0A00_45F1_4AC1_B00A_FE5BB5630B70) },
    { be_const_key(Get_Minimum_Free_Heap, 4), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_Heap_A78E828F_DFB1_4024_9899_E1F6BDE28BC1) },
    { be_const_key(Get_Minimum_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_PSRAM_EBB9883B_9F9F_4E87_B31E_F2FFE7B0A965) },
};

static be_define_const_map(
    m_libMemory_map,
    8
);

static be_define_const_module(
    m_libMemory,
    "Memory"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Memory);
