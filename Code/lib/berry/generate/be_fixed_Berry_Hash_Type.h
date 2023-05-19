#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_8144229E_F511_4EED_B5AA_DFD43E7F814F) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_7599AF95_7B4E_4085_A599_00CB08E1C087) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_8D19A6EC_2465_47E2_909D_1FD63F81D1A6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_6BDF670B_2DBC_4C09_92CD_FB45858CD2B4) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_8E02BE25_A1DF_4A94_B56A_D1461E0A20FA) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_7BCE6823_CC69_49D1_B626_4F2E32328905) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_9FDD5448_5F32_4C86_B2FB_7D5FD9C76D26) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_B97218A1_C1B7_4D4E_B28E_A308E695896F) },
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
