#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_B1E12F3A_2A3A_4F3F_BA01_D3118C0EE616) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_A39AEDE8_A8F3_4B3A_880E_751CB78BD743) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_0820DBD3_52B7_4980_8DF7_28F5653D4D87) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_B18D8729_0B67_4167_80D5_FF1F4DED5E9E) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_6060C5D6_0759_49E2_BF94_6D8FC1076320) },
};

static be_define_const_map(
    Berry_Dialog_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Dialog_Type,
    1,
    (bclass *)&Berry_Window_Type,
    Dialog_Type
);
