#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_655B6CB2_7F52_4756_A193_FCCB6FB0F633) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_8D7EADBC_70F4_4B13_AF9C_EC62D094A99C) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_E106CEF1_8ED9_4F3D_9B14_DBF3DE866C76) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_89689215_50FF_4FAD_9E53_73008E84C9BF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_776B734E_9BE9_4E47_80A2_FEE94299DA51) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_A54353AB_49D0_448B_8EE6_F93B1EDB02F1) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_EC80F2FC_1548_4D10_A032_8A0E4FF27876) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_043E7625_5B42_4C68_8216_D74C8B4771F4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_9EABACF0_F72F_4090_A081_7607FFD22F26) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_387D5349_0EDF_4E24_B3D1_B3277A999C1F) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_A30D431E_62F2_4A66_8B1B_04E60B918386) },
};

static be_define_const_map(
    Berry_Calendar_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Calendar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Calendar_Type
);
