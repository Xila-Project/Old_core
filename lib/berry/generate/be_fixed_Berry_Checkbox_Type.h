#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_1D84624F_03E9_4C68_9D9B_2DDB8D93CC98) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_4913FEF9_368D_4E46_920B_4233943F96E4) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_A92140A8_81BC_45D0_8484_ABCE6FFEC240) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_4DE01767_BFB3_4660_998D_592B537D0598) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_6ADC83AD_61AD_42F1_BDF5_3064A42DE0F4) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_47054A67_84DD_4605_9295_31BE30C2C42B) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Checkbox_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Checkbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Checkbox_Type
);
