#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Wheel_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Color_02A5AE7B_D8AD_4BEC_97D6_61B9ED39906C) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Color_A43039DF_319B_4E31_8B79_EAB79240008F) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Color_Wheel_Class_Deinitialize_6C9F9A6F_A395_4C32_8569_897D7F58537E) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_4AC65BA7_F888_44EE_A2AF_15F97A705BAE) },
    { be_const_key(Get_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_Fixed_A09F3D57_B031_44C4_9D9B_FFAF17ECD4D8) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Initialize_13B66B73_B4F0_4779_B648_48286B167CA9) },
    { be_const_key(Set_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_Fixed_CBC16833_BC07_437D_A2A2_DEE4A21C4054) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_D6657621_1C1C_4A2F_A252_76CB6567CB69) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Wheel_Class_Create_9B569D4D_4073_45E9_845A_F85FB8AFD269) },
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
