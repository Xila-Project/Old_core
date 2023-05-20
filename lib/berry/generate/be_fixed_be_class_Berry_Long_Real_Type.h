#include "be_constobj.h"

static be_define_const_map_slots(be_class_Berry_Long_Real_Type_map) {
    { be_const_key(_X25, 15), be_const_ctype_func(Berry_Long_Real_Type_Modulo) },
    { be_const_key(From_Integer, -1), be_const_ctype_func(Berry_Long_Real_Type_From_Integer) },
    { be_const_key(_X2D, -1), be_const_ctype_func(Berry_Long_Real_Type_Subtract) },
    { be_const_key(To_String, -1), be_const_ctype_func(Berry_Long_Real_Type_To_String) },
    { be_const_key(From_String, -1), be_const_ctype_func(Berry_Long_Real_Type_From_String) },
    { be_const_key(_X2D_X2A, -1), be_const_ctype_func(Berry_Long_Real_Type_Negate) },
    { be_const_key(_X2F, -1), be_const_ctype_func(Berry_Long_Real_Type_Divide) },
    { be_const_key(_X2B, -1), be_const_ctype_func(Berry_Long_Real_Type_Add) },
    { be_const_key(_X3E_X3D, 6), be_const_ctype_func(Berry_Long_Real_Type_Greater_Equal) },
    { be_const_key(_X3E, 17), be_const_ctype_func(Berry_Long_Real_Type_Greater) },
    { be_const_key(_X2A, -1), be_const_ctype_func(Berry_Long_Real_Type_Multiply) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Long_Real_Type_Equal) },
    { be_const_key(init, 10), be_const_ctype_func(Berry_Long_Real_Type_Initialize) },
    { be_const_key(_X3C, -1), be_const_ctype_func(Berry_Long_Real_Type_Less) },
    { be_const_key(To_Integer, -1), be_const_ctype_func(Berry_Long_Real_Type_To_Integer) },
    { be_const_key(_X3C_X3D, -1), be_const_ctype_func(Berry_Long_Real_Type_Less_Equal) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Long_Real_Type_Not_Equal) },
    { be_const_key(To_Bytes, -1), be_const_ctype_func(Berry_Long_Real_Type_To_Bytes) },
    { be_const_key(From_Bytes, -1), be_const_ctype_func(Berry_Long_Real_Type_From_Bytes) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Long_Real_Type_Deinitialize) },
    { be_const_key(_p, 13), be_const_var(0) },
};

static be_define_const_map(
    be_class_Berry_Long_Real_Type_map,
    21
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_Berry_Long_Real_Type,
    1,
    NULL,
    Long_Real_Type
);
