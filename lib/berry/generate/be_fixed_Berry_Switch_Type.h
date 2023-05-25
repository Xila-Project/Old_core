#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_C4B44936_2A78_4B9B_85B7_77E649374903) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_F37B01CA_7AD7_4FBB_A2CB_D6D197D71B6A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_EC177DAC_D34E_457C_868D_6933F8E612EF) },
};

static be_define_const_map(
    Berry_Switch_Type_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Switch_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Switch_Type
);
