#include "be_constobj.h"

static be_define_const_map_slots(m_libMemory_map) {
    { be_const_key(Get_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_PSRAM_9E8051B7_0EEF_43F7_AE7F_A1AF4AADFE39) },
    { be_const_key(Get_Heap_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_Heap_Size_37326FD4_D9A8_4A26_823D_DA23988C8C3C) },
    { be_const_key(Get_Free_Heap, 5), be_const_ctype_func(Berry_Memory_Class_Get_Free_Heap_F9834C7E_5AD7_47CB_B4B8_8950732B93A0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Memory_Class_Get_Pointer) },
    { be_const_key(Get_PSRAM_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_PSRAM_Size_82AC37B6_D4C7_468B_B327_2847276EEF4F) },
    { be_const_key(Get_Minimum_Free_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_Heap_3A8FED0B_E514_4714_9BBB_DA6F8BD9E3A7) },
    { be_const_key(Get_Minimum_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_PSRAM_6E8B4508_6B95_4395_A3FD_E287D227D34B) },
    { be_const_key(Get_Maximum_Allocated_PSRAM, 2), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_PSRAM_96C47AA0_ABDA_4A03_A236_8A305D1B3E19) },
    { be_const_key(Get_Maximum_Allocated_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_Heap_C11548BF_1B46_4668_8394_66480923C3BB) },
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
