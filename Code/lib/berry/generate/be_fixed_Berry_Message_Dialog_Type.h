#include "be_constobj.h"

static be_define_const_map_slots(Berry_Message_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Create_9EDC0BFC_1BA5_4FFC_A909_DE6C05099219) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Deinitialize_928AF5B6_DCBF_47A3_BA07_1BA3AC3CCF71) },
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
