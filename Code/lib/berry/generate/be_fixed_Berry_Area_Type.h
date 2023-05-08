#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_80017176_E47A_4A9B_8DCF_96D320738F2A) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_205D436F_2FCC_489C_B01C_B9D38C56C8EF) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_3FFD16E8_4306_4C56_AE91_B10521A74284) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_D53686B1_DDEB_406D_A53D_4F1513366795) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_B031E540_6B04_4130_9D73_4F2DC44499C5) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_83655CF9_49E0_421D_AC8B_7AF834C7B2D7) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_E09E649C_1BD6_4223_8CCE_E6F72FDBAB66) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_58C122BB_FF43_42DF_8BDF_19FCD007FF32) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_7CFD4772_6774_48B5_A036_E8123F7E58A8) },
};

static be_define_const_map(
    Berry_Area_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Type,
    1,
    NULL,
    Area_Type
);
