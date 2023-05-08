#include "be_constobj.h"

static be_define_const_map_slots(Berry_Message_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Create_C1C29915_B64C_4C99_B5A9_B0C1C7F1C4F2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Deinitialize_1460E75E_DA32_4537_83D7_0382156ACA1F) },
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
