#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Type_map) {
    { be_const_key(Get_Handle, 1), be_const_ctype_func(Berry_Software_Class_Get_Handle_9228CC4A_CC88_4566_8730_8CBDC6BCBAE0) },
    { be_const_key(Get_Owner_User, -1), be_const_ctype_func(Berry_Software_Class_Get_Owner_User_603E8264_EA0A_4E4B_B6BF_777A0BD4B985) },
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
