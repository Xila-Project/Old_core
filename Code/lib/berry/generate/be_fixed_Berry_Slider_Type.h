#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_68F48094_8BE3_4CD1_93D5_0ED9AB73C854) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_D034B6FB_7B85_457D_840B_7FE93247DD09) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_CA507E3D_A8E1_4656_811F_7E580361D4F0) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_5C223A3B_8D4B_496A_A673_FEEBDD43E871) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_9546BCFC_4F90_423D_B3D6_20F6D73FA8AC) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_D1B3814D_5DA3_4F73_BCE8_DD5D40B8AD53) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_4C8A8432_32F1_465D_ADAA_CDD03BA71674) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_E21C80C3_5AFC_4B7F_982A_8B18745D0879) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_7F921CCD_933F_4B3A_B1AC_F3EC76C33E3C) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_7C84CBC1_6A15_4E0F_B5F5_F7F2A85D60CB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_2097BF58_1DF4_45FD_9ECF_C1C38305AEEE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_557B77BA_7A27_4ABF_B762_13218831C1A3) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_954BCFDD_8839_4089_B7AE_B8C602E9C244) },
};

static be_define_const_map(
    Berry_Slider_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Slider_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Slider_Type
);
