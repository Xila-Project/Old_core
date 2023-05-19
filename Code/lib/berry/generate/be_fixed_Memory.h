#include "be_constobj.h"

static be_define_const_map_slots(m_libMemory_map) {
    { be_const_key(Get_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_PSRAM_68D143BF_1B9C_4234_A7CD_35015868B6FB) },
    { be_const_key(Get_Heap_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_Heap_Size_2883C1B1_EB39_4AF1_B222_874C2DF316A4) },
    { be_const_key(Get_Free_Heap, 5), be_const_ctype_func(Berry_Memory_Class_Get_Free_Heap_7E0AC19E_5873_407A_B4EA_532B233A002A) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Memory_Class_Get_Pointer) },
    { be_const_key(Get_PSRAM_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_PSRAM_Size_EEA10617_2E08_4E4D_A70A_4D30FA5F7E21) },
    { be_const_key(Get_Minimum_Free_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_Heap_41BAA8A9_8D0D_46CA_ABE0_F75ACEB57120) },
    { be_const_key(Get_Minimum_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_PSRAM_9C07681F_9E81_498D_94D7_54DB3C819520) },
    { be_const_key(Get_Maximum_Allocated_PSRAM, 2), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_PSRAM_EB22F847_7DEE_4C2B_916F_FB528ED23848) },
    { be_const_key(Get_Maximum_Allocated_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_Heap_B7E80025_46CC_4F6A_8AC9_F5BF11034D3C) },
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
