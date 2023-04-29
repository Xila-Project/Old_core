#include "be_constobj.h"

static be_define_const_map_slots(m_libtest_map) {
    { be_const_key(Foo, -1), be_const_class(be_class_foo) },
    { be_const_key(addint, 2), be_const_ctype_func(addint) },
    { be_const_key(ftoc, -1), be_const_ctype_func(ftoc) },
    { be_const_key(yesno, 0), be_const_ctype_func(yesno) },
};

static be_define_const_map(
    m_libtest_map,
    4
);

static be_define_const_module(
    m_libtest,
    "test"
);

BE_EXPORT_VARIABLE be_define_const_native_module(test);
