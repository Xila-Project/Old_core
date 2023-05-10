#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_01E10CED_BE81_415C_AFEA_605E6A62E174) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_483F1F1C_4A6E_49F6_8362_7A3523DF7AC1) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_1197D7A4_B966_4249_8B87_82F3A9FF080D) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_372C5D60_FCB6_4DCD_91AA_E6560B85AFB6) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_C31E6816_9E7F_4A7F_9EAA_2E1E546FD89B) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_00168779_EE92_4C81_99BC_632F883FBD81) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_9B765D48_FE94_46D8_B866_A6DC353501D8) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_7484F8E4_A242_402B_8EAD_236D36C7EE65) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_C671A51B_3208_4E6B_8DF0_DE4150CD97CF) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_66C9F7BE_50AF_4E1C_A51F_36B0EFED07CA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_C2977163_B043_4774_9C07_D1BBA3D5A6F5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_5080A650_3FAB_4943_839D_A7941D05C495) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_A21A8F21_D754_42E8_8E4F_1A109D222C65) },
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
