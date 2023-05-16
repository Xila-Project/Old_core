#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_92FA17F6_F0FA_4910_B6D2_C8B17D0DBBA8) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_32CD4B4A_F4C3_4F24_A5DB_92C62E3C5C77) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_4682C132_E1A3_414B_891A_06D54B1B253F) },
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
