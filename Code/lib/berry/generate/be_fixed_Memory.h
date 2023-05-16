#include "be_constobj.h"

static be_define_const_map_slots(m_libMemory_map) {
    { be_const_key(Get_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_PSRAM_7776DB13_4820_4DE3_9235_41D5B222C2F0) },
    { be_const_key(Get_Heap_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_Heap_Size_BA55FA4A_2889_4F39_A8F9_6C17BFFBFB69) },
    { be_const_key(Get_Free_Heap, 5), be_const_ctype_func(Berry_Memory_Class_Get_Free_Heap_0CB68CBC_7570_459E_9B16_09E05BFC70E7) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Memory_Class_Get_Pointer) },
    { be_const_key(Get_PSRAM_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_PSRAM_Size_0C69E93E_CAFE_41BC_8636_03B85DD40149) },
    { be_const_key(Get_Minimum_Free_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_Heap_B2E43B55_688F_4196_99CE_915201670F8F) },
    { be_const_key(Get_Minimum_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_PSRAM_10567E5A_7759_4E0B_9A79_E5AB3A7E8614) },
    { be_const_key(Get_Maximum_Allocated_PSRAM, 2), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_PSRAM_FEEB5E8F_4D59_48C8_947D_DB9CD94048EA) },
    { be_const_key(Get_Maximum_Allocated_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_Heap_73549726_DA69_4C5E_AF0C_77622B26D375) },
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
