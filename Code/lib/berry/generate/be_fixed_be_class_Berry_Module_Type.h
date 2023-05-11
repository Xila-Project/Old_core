#include "be_constobj.h"

static be_define_const_map_slots(be_class_Berry_Module_Type_map) {
    { be_const_key(init, 3), be_const_ctype_func(Berry_Module_Type_Initialize) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Module_Type_Not_Equal) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Module_Type_Deinitialize) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Module_Type_Equal) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    be_class_Berry_Module_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_Berry_Module_Type,
    1,
    NULL,
    Module_Type
);
