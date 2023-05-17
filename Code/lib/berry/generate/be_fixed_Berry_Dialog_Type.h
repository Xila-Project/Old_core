#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_10FF9EB7_5268_41BB_A1DA_DA3EB99121FC) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_187657AE_B8A3_4E8D_A9E6_F779AF0A0E02) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_5F8138D6_8E14_4411_AAD3_DF93219C1902) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_EFADC0E3_0C2B_4F76_A4AE_7BF4901535BC) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_2A2B9BBC_32A7_4B04_A2D7_073A788CCD4D) },
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
