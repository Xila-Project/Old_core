#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_3F3B7E24_2EAA_4E0B_BE23_7EB577652146) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_A2A8F67F_30CD_4A3A_A9F7_5107859609B7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_9046DD73_5A9B_476C_B036_CA04FFC3F8C4) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_9A04EC14_E299_4FF5_A249_F9388ACD8933) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_17D25BD7_B303_4255_A314_573EFD89C78E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_326ED9E3_84EF_46DE_B7AB_4A298C981DED) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_380D1C96_822B_40AB_BEF5_DFED06263053) },
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
