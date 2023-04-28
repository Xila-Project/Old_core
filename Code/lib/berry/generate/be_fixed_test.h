#include "be_constobj.h"

static be_define_const_map_slots(m_libtest_map) {
    { be_const_key(addint, -1), be_const_func(f_addint) },
    { be_const_key(ftoc, 2), be_const_func(f_ftoc) },
    { be_const_key(yesno, -1), be_const_func(f_yesno) },
};

static be_define_const_map(
    m_libtest_map,
    3
);

static be_define_const_module(
    m_libtest,
    "test"
);

BE_EXPORT_VARIABLE be_define_const_native_module(test);
