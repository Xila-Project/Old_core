#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Type_map) {
    { be_const_key(Get_Handle, 1), be_const_ctype_func(Berry_Software_Class_Get_Handle_1F8935B7_A189_40E3_A688_D79DB9B4247B) },
    { be_const_key(Get_Owner_User, -1), be_const_ctype_func(Berry_Software_Class_Get_Owner_User_95AB03B4_171A_40C9_9C21_485B4BA2993C) },
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
