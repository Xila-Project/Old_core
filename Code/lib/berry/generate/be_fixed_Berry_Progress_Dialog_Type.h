#include "be_constobj.h"

static be_define_const_map_slots(Berry_Progress_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Create_CE0C4233_1433_42A9_9228_74DAE7EC68E0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Deinitialize_7271B594_CB07_43AA_8724_D4A26ED9C2DF) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Progress_Dialog_Type_map,
    3
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Progress_Dialog_Type,
    1,
    (bclass *)&Berry_Dialog_Type,
    Progress_Dialog_Type
);
