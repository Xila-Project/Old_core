#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Dialog_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Get_Color_696B3631_141B_4DA7_9413_180623D51F47) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Set_Color_D6CCCFA1_2F77_45D0_9A8C_1FB1AF7B17DB) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_Color_Dialog_Class_Deinitialize_1FE505D5_8C5F_4870_9339_6AEEF8F1D80E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Dialog_Class_Create_9AFC7D99_DA7E_44A0_A293_91DA0ACBDD97) },
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
