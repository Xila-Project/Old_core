#include "be_constobj.h"

static be_define_const_map_slots(Berry_Message_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Create_EA64D139_C7A1_467D_9308_F62DB80AF5E5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Deinitialize_EBAA5883_67DF_4D92_BF73_80F6D673942B) },
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
