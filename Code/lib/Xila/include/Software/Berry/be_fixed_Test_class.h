
extern "C"
{
    #include "be_constobj.h"
}

#include "Test.hpp"


static be_define_const_map_slots(Test_class_map) {
    { be_const_key(init, 1), be_const_func(m_init) },
    { be_const_key(_X2Etest_var, -1), be_const_var(0) },
    { be_const_key(Hello, -1), be_const_func(m_Hello) },
};

static be_define_const_map(
    Test_class_map,
    3
);

BE_EXPORT_VARIABLE be_define_const_class(
    Test_class,
    1,
    NULL,
    bytes
);
