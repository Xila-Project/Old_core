#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Wheel_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Color_BC27F320_2230_4535_B76C_B662BE2786EB) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Color_BEB2E2EA_C6C6_4F63_9005_8FB501EA5A77) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Color_Wheel_Class_Deinitialize_6E15E133_CC1D_4427_BB20_D0B600B7582F) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_576E98D4_C5E7_4CB6_A129_ABDDC23CDC64) },
    { be_const_key(Get_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_Fixed_038E4A1E_7ABA_4EE5_AB11_EEF04C6F3F0E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Initialize_FC4909C5_5C48_4C79_A84A_5E5A23F9E468) },
    { be_const_key(Set_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_Fixed_D787E914_40E0_47C1_9E09_1D998939005F) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_578C1F02_B6E9_4808_A50A_1261FA80A165) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Wheel_Class_Create_09EFF188_B160_418C_B1D9_36409C40434A) },
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
