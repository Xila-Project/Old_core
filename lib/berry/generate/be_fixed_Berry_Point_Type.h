#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_1CE787BD_4E3F_4D1A_8400_09D9A78EB549) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_45CD888C_3349_43BB_975C_8DF8EE5C7764) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_83D07506_2FD5_4978_921B_B0FB64436F1D) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_F5C7419A_F312_4EB5_864B_53D4C2A8E998) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_249AC658_5E2F_469E_9D91_5016A36F7797) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_0092D962_AA26_4935_8645_D9F675226EAE) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_5A2DB2AB_A536_495B_A98A_A3722FE9E061) },
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
