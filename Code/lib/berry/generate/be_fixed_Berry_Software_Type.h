#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Type_map) {
    { be_const_key(Get_Handle, 1), be_const_ctype_func(Berry_Software_Class_Get_Handle_8F45B5B7_68E0_4C21_904C_49C58183B6E2) },
    { be_const_key(Get_Owner_User, -1), be_const_ctype_func(Berry_Software_Class_Get_Owner_User_E711B826_9C19_452D_B176_06CB2F4D43C4) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Software_Type_map,
    3
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Software_Type,
    1,
    NULL,
    Software_Type
);
