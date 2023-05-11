#include "be_constobj.h"

static be_define_const_map_slots(Berry_Message_Dialog_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Create_43F0FA8C_AFAE_433C_AF24_87F1103EA3AA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Message_Dialog_Class_Deinitialize_D5037235_B429_43E5_9C8A_B242975B951B) },
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
