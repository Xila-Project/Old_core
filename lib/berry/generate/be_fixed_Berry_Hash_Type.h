#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_09EB699D_6C54_489D_8609_08F439B4CDC2) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_9ED8FBD2_5EFC_469A_9EEC_96CDE7A7C7E6) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_B569D486_8E32_4723_908B_067C847EDE52) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_921D91CD_9A0E_49C6_B6CA_576E287D666A) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_DEDDB584_C1D3_43DE_B82A_46FF27521213) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_69E03B26_743B_4D38_8A00_1B9762AAE465) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_E05F204B_49D9_4EBB_A7EB_0DAA48C837AD) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_042BA89C_7476_48ED_88A3_D7F826B1876A) },
};

static be_define_const_map(
    Berry_Hash_Type_map,
    9
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Hash_Type,
    1,
    NULL,
    Hash_Type
);
