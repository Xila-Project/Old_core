#include "be_constobj.h"

static be_define_const_map_slots(Berry_Message_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Create_94B73A38_5D5E_4FCE_AC2F_C143EB1DADB6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Deinitialize_CBE8DE19_31E1_481F_A5B1_CAAE1E1D2BCF) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Message_Dialog_Type_map,
    3
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Message_Dialog_Type,
    1,
    (bclass *)&Berry_Dialog_Type,
    Message_Dialog_Type
);
