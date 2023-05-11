#include "be_constobj.h"

static be_define_const_map_slots(m_libMemory_map) {
    { be_const_key(Get_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_PSRAM_905E93CA_3197_446F_9D54_A0D56089CF65) },
    { be_const_key(Get_Heap_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_Heap_Size_86BB1A82_7336_40AE_915B_C3BA18FA68B8) },
    { be_const_key(Get_Free_Heap, 5), be_const_ctype_func(Berry_Memory_Class_Get_Free_Heap_CAD6FB23_CC37_4C91_B12D_E5F2FE80C207) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Memory_Class_Get_Pointer) },
    { be_const_key(Get_PSRAM_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_PSRAM_Size_926AB2D0_BB79_462C_B138_79EABB1AA17B) },
    { be_const_key(Get_Minimum_Free_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_Heap_5A96B4E1_4CE1_451F_84AD_3DE7352991CE) },
    { be_const_key(Get_Minimum_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_PSRAM_80B10C23_CBD7_4400_85F3_74FBBEA22382) },
    { be_const_key(Get_Maximum_Allocated_PSRAM, 2), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_PSRAM_1AB0BE13_530B_4DCD_9785_44119486D17E) },
    { be_const_key(Get_Maximum_Allocated_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_Heap_C4C6779B_1D3D_4D58_90E1_0ECD07977DCD) },
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
