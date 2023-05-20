#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_A973C1CF_796E_48BD_B879_AF1A09135490) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_691FB143_FD47_4948_AD0F_6D6925E34997) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_16F8C9A5_DE3A_4170_9FF5_4C1AF1E4F623) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_82BE25EF_7263_47D1_BB51_4BEFBA6CAD23) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_3E2BDF24_4EA0_40E9_B13D_EB08D9B140F7) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_50BFABAA_BC28_412E_92FE_4A5258B372CF) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_B5513582_DD9B_4862_9E62_7DA340A49573) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_A793F933_63C9_4D19_8F6B_835E74AD7867) },
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
