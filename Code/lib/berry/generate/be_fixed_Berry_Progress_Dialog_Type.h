#include "be_constobj.h"

static be_define_const_map_slots(Berry_Progress_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Create_25AB670C_F556_4A04_B1E1_B9EFE87D34BE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Deinitialize_A90A6070_6DBC_4F19_9414_0F93836BA28E) },
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
