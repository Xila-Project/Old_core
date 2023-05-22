#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Type_map) {
    { be_const_key(Get_Handle, 1), be_const_ctype_func(Berry_Software_Class_Get_Handle_A9237B2B_3A37_4975_8DDF_4D53199910B8) },
    { be_const_key(Get_Owner_User, -1), be_const_ctype_func(Berry_Software_Class_Get_Owner_User_6D6FDD25_0099_4206_9778_0E0C9CBE4CF0) },
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
