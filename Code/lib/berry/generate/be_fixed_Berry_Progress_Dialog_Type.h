#include "be_constobj.h"

static be_define_const_map_slots(Berry_Progress_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Create_47F0FFA0_1C96_46E3_8133_A4840A1EDE15) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Deinitialize_99576339_D714_4B08_B1EF_6D41EC3EE878) },
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
