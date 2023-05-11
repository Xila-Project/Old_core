#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Dialog_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Get_Color_04046E14_2712_4D20_A4F8_26BF87FB15DD) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Set_Color_8735E56C_1ACA_4A76_BA7C_ECCEE74B406A) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_Color_Dialog_Class_Deinitialize_9E1FCE36_8262_4F09_A978_A6062ECA80D7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Dialog_Class_Create_451E880A_0841_496B_B62B_C9F03BA827D2) },
};

static be_define_const_map(
    Berry_Color_Dialog_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Dialog_Type,
    1,
    (bclass *)&Berry_Dialog_Type,
    Color_Dialog_Type
);
