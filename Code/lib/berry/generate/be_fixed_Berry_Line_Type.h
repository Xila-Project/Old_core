#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_2F35C032_3FE3_4BFB_9C4F_E275A7BED917) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_63E25751_97B9_45A5_A56B_4D11CE046D64) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_3EAF9BE2_E2D1_4DA3_BA3C_C9825745F5AE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_1CF8242A_5D20_4AAF_ACA2_037D2C05017E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_0A11D394_FCA4_4CEE_A77A_F916761937C3) },
};

static be_define_const_map(
    Berry_Line_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Line_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Line_Type
);
