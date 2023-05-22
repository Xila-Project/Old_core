#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_AA629169_91D5_4747_A0ED_E7F595CA1096) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_9500112B_DB6F_4277_A37F_C0A9D7BCE483) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_F70702C1_7C12_4F11_AC09_812A9AC84040) },
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
