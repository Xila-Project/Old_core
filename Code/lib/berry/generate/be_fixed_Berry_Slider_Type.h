#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_9D24C3EA_044E_4A24_B5F5_E083A6915610) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_97062DC3_993E_40AB_AC60_2742C2748071) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_27AAF6B1_6C72_4EAC_802C_1A1166CDB100) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_DEF811A2_32FD_4CC7_BD4C_3F934E369761) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_534BAF62_FB95_437F_9F6A_F148DD824B3A) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_E92B8F08_B484_414B_82BB_E9D3F087286D) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_41E8724D_B16B_421C_A281_FF5B14F743BF) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_1E46A1D4_38D4_43CC_93EA_348605C3B868) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_D5D4F38A_CDE0_4E92_BD86_0326588D7C57) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_BD1FD4C3_C998_47EE_850D_59600277D6E7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_23518551_8B15_48EF_9260_4799D5FE9341) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_FDE84EB6_114A_483B_9084_E96F0FA4AEC1) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_3FF0F335_76E8_4DDD_8934_D9A0924A8A0E) },
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
