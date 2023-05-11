#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_C53700B8_E35B_4CA8_942B_8EB7F18E7268) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_5D559AA4_91AD_4767_BF2B_7C13186D6EDB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_081786E3_AB6E_4500_8861_0093A401E67F) },
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
