#include "be_constobj.h"

static be_define_const_map_slots(be_class_Berry_Long_Integer_Type_map) {
    { be_const_key(_X2B, 4), be_const_ctype_func(Berry_Integer_Type_add) },
    { be_const_key(_X2A, -1), be_const_ctype_func(Berry_Integer_Type_mul) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Integer_Type_deinit) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Integer_Type_Set) },
    { be_const_key(_X3E_X3D, -1), be_const_ctype_func(Berry_Integer_Type_gte) },
    { be_const_key(To_String, -1), be_const_ctype_func(Berry_Integer_Type_To_String) },
    { be_const_key(_X3C_X3D, -1), be_const_ctype_func(Berry_Integer_Type_lte) },
    { be_const_key(To_Integer, 17), be_const_ctype_func(Berry_Integer_Type_To_Integer) },
    { be_const_key(_X25, 5), be_const_ctype_func(Berry_Integer_Type_mod) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Integer_Type_init) },
    { be_const_key(From_Integer, -1), be_const_static_ctype_func(Berry_Integer_Type_From_Integer) },
    { be_const_key(_X3C, -1), be_const_ctype_func(Berry_Integer_Type_lt) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(_X3E, -1), be_const_ctype_func(Berry_Integer_Type_gt) },
    { be_const_key(_X2D_X2A, -1), be_const_ctype_func(Berry_Integer_Type_neg) },
    { be_const_key(From_Bytes, -1), be_const_ctype_func(Berry_Integer_Type_From_Bytes) },
    { be_const_key(_X2D, -1), be_const_ctype_func(Berry_Integer_Type_sub) },
    { be_const_key(From_String, -1), be_const_static_ctype_func(Berry_Integer_Type_From_String) },
    { be_const_key(_X2F, -1), be_const_ctype_func(Berry_Integer_Type_div) },
    { be_const_key(_X21_X3D, 7), be_const_ctype_func(Berry_Integer_Type_nequals) },
    { be_const_key(To_Bytes, -1), be_const_ctype_func(Berry_Integer_Type_To_Bytes) },
    { be_const_key(_X3D_X3D, 3), be_const_ctype_func(Berry_Integer_Type_equals) },
};

static be_define_const_map(
    be_class_Berry_Long_Integer_Type_map,
    22
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_Berry_Long_Integer_Type,
    1,
    NULL,
    Long_Integer_Type
);
