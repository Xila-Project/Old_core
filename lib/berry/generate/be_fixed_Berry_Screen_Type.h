#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_7650DAA2_C306_47CD_920A_8FD2F9E52888) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_B93EC354_5CBA_4E2E_AB30_547D3F18669E) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_A6C0B9D6_F5FE_4E6B_9C8E_0D50F3F03E7E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_2D61C1E8_9138_43B7_AD44_91C24D195EB9) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_7C3B9007_41F0_4F33_9F23_6D0B5379E173) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_6A9A04D0_92A5_49CB_9FFC_E56F16F91DAF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_C9D864EE_FCB8_49FB_B6B3_6F0D269BDF91) },
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
