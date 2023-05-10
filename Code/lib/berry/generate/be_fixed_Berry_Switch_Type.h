#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_014C5EAD_14F0_4E26_9022_6FC17BDD39B5) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_25B91C4A_BE3B_46F5_93AE_8F89945F0443) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_2A3987CE_5E38_466C_80EA_420B9ECC993B) },
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
