#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Switch_Type_map,
    1
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Switch_Type,
    1,
    NULL,
    Switch_Type
);
