#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Type_map) {
    { be_const_key(Get_Handle, 1), be_const_ctype_func(Berry_Software_Class_Get_Handle_F50F4563_7EF7_4D43_9790_E5EB55CA8C14) },
    { be_const_key(Get_Owner_User, -1), be_const_ctype_func(Berry_Software_Class_Get_Owner_User_BA445262_4F60_4A86_8F8B_CC9BC92C9C27) },
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
