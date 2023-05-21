#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_ABC176C0_7271_40A0_A825_22E6137EB4C0) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_97D57424_E5DE_4143_9DEB_3907A4FA1692) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_8DA0B8C1_5F8A_41DE_BDBA_5390916A4BA5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_905F1D86_9D52_47C5_88D8_55128C5B3979) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_F8AF3350_D251_4661_9AAA_AC0279DDA0E1) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_57EE297B_E690_4E40_8047_99CE2DE96888) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_DD684DD2_5B41_4340_91B3_B3A1DE6160F0) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_91577C55_9296_459D_9D74_ECA9466AEE6F) },
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
