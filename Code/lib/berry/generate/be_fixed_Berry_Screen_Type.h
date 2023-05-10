#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_77D66321_381A_4117_9C3D_BE02941B4195) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_65B82B09_4DD3_4B20_8285_9B77F1BF8919) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_900545E5_3C87_4B06_8449_FFCDFF15ACF9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_0B3E55B9_CC62_4B3B_96E0_F8EB7678659E) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_9F791C5D_C400_42C5_87D9_5F0F2F5AD949) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_9A3A9D99_C237_4104_80AA_74C05F2C750D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_9336E8D8_18D2_45CB_B51E_4F290989E082) },
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
