#include "be_constobj.h"

static be_define_const_map_slots(Berry_Progress_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Create_F3F8EAF7_9741_41EF_874D_4A52571EB40D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Deinitialize_7C6EDABF_13FA_4519_A4D3_D8B2FE87A2EA) },
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
