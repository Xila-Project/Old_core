#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_E8E587DB_67C4_4E6B_BBA2_4B9B4D30FEDA) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_E4D2EC87_EDE1_48F4_9431_FD1D6EF5A3A2) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_E96A8762_D426_419A_A8AC_BB9131E2F03A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_104F015F_C2D1_4E1D_8BD1_544C61724074) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_EE78D981_5C04_4A48_A7DC_3B24F26895A7) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_80406094_494F_48BA_936C_D2FCF8B1AB48) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_9A15325F_35C9_46F7_ADED_F5A71BD277AC) },
};

static be_define_const_map(
    Berry_Screen_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Screen_Type
);
