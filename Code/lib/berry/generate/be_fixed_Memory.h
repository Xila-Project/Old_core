#include "be_constobj.h"

static be_define_const_map_slots(m_libMemory_map) {
    { be_const_key(Get_Maximum_Allocated_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_PSRAM_EB2A0C81_E364_4A6A_8481_4889F750095F) },
    { be_const_key(Get_PSRAM_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_PSRAM_Size_4D6A5576_E78F_4121_AF1E_4767204684E0) },
    { be_const_key(Get_Heap_Size, -1), be_const_ctype_func(Berry_Memory_Class_Get_Heap_Size_1E171482_8034_42CF_A8C3_986DD6684359) },
    { be_const_key(Get_Maximum_Allocated_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Maximum_Allocated_Heap_300EC7CD_4398_43FC_88BA_461E9B38FD16) },
    { be_const_key(Get_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_PSRAM_8BBDF67E_67EB_42C0_9D7F_41FA77179B62) },
    { be_const_key(Get_Free_Heap, -1), be_const_ctype_func(Berry_Memory_Class_Get_Free_Heap_2188365B_1148_47F4_BD45_070596E84BE3) },
    { be_const_key(Get_Minimum_Free_Heap, 4), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_Heap_6717C4A3_77DB_40CB_8BA7_1CD477105338) },
    { be_const_key(Get_Minimum_Free_PSRAM, -1), be_const_ctype_func(Berry_Memory_Class_Get_Minimum_Free_PSRAM_8CCA7415_8DFE_4A0E_A11B_A24253EF5252) },
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
