#include "be_constobj.h"

static be_define_const_map_slots(m_libTest_map) {
    { be_const_key(Test, -1), be_const_class(Test_class) },
};

static be_define_const_map(
    m_libTest_map,
    1
);

static be_define_const_module(
    m_libTest,
    "Test"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Test);
