#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Wheel_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Color_195DC2C5_24D4_4B9A_A69C_D329DDF74817) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Color_36864991_888C_4694_8486_F1933BC12E54) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Color_Wheel_Class_Deinitialize_F7F1DAC2_3512_43E6_B2CF_E0062BDBDA0E) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_ADA1618D_DC95_4333_937B_4B30FA4340B0) },
    { be_const_key(Get_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_Fixed_5CA45320_4E54_42DA_AC2B_367784B2617F) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Initialize_620CA8B2_2D39_455A_BBE5_9CD95B9B9906) },
    { be_const_key(Set_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_Fixed_3E980572_2C57_4288_80F6_C60749CA45B8) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_6F77FE2B_93AB_4D5D_92EC_35E188463364) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Wheel_Class_Create_9553758D_F14D_40F6_AC10_FF944110A894) },
};

static be_define_const_map(
    Berry_Color_Wheel_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Wheel_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Color_Wheel_Type
);
