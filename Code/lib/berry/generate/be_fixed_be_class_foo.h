#include "be_constobj.h"

static be_define_const_map_slots(be_class_foo_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Be_Foo_Deinit) },
    { be_const_key(Clap, -1), be_const_ctype_func(Be_Foo_Clap) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Be_Foo_Init) },
};

static be_define_const_map(
    be_class_foo_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_foo,
    1,
    NULL,
    Foo
);
