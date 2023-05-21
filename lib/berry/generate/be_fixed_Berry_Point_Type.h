#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_A4C4D231_4FE0_4663_9FA8_DCCFBCB064BD) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_75FC0FC0_905F_4D72_B146_2E71D9D31602) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_8A3F45C4_F47C_48F8_9022_5793C2674E3C) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_566C3D73_FCC1_456F_BD63_47F0E3A82AC6) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_9C23F0C3_D02F_4489_8671_526A56488B26) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_2CB46E3D_5779_4950_AD0A_DB25103A4DD5) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_D8DB3C5D_3017_46B0_8C1E_957E20E079A0) },
};

static be_define_const_map(
    Berry_Point_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Point_Type,
    1,
    NULL,
    Point_Type
);
