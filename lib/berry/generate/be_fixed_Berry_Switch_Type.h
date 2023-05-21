#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_14CF6BCB_293D_4892_A208_8009BD300812) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_AC00058C_5756_4E38_AE03_1258B1672364) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_8F983881_1957_4802_B810_F3144B35D08F) },
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
