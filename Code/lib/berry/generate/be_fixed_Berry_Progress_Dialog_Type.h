#include "be_constobj.h"

static be_define_const_map_slots(Berry_Progress_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Create_D0C890A1_96A7_416A_AE24_0D02F244DAF3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Progress_Dialog_Class_Deinitialize_9B1AF934_77FD_4BC5_8E45_F5636BD6DB2C) },
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
