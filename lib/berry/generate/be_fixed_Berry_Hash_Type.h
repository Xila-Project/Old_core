#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_7CF0F72C_28F2_4BC6_AA17_3F8A37BF241A) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_5180BD61_3ADE_420B_A78A_D51C713C2592) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_F2758DA7_B504_446C_AFC7_84ECEB52BA28) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_B91B59F8_7839_46AB_8827_1586661E1740) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_3D7DD52A_C3F3_4AAD_86A5_90DE13DB87D7) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_6D56DEFB_FB19_424C_8B39_8FE1B736C3CA) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_57BCC807_1FB3_45C9_9145_6149740880A4) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_4F21E2B9_145E_4803_BD2F_A568AD20C746) },
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
