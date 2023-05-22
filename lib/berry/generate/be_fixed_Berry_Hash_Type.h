#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_01D6A89D_9BCB_45B4_ACD7_5DCE038F2D7F) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_99EC0265_B2F5_4460_B3A6_B80D220785B9) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_05B1C58D_E0D6_4380_96A4_7BDECFDAC38E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_0E293011_0066_44CC_818C_023B6F8DAD4F) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_3E74F68A_70A5_4A29_ABCD_D0273BC36BB0) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_60A76F7B_FFB8_4F0F_BBBF_064C8C74DFEF) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_475525D2_E225_42DE_B1CE_408E83DC2994) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_9956FDA0_D4C6_41FA_A146_3EE55D3847E2) },
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
