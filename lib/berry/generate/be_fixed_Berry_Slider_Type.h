#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_04C6080E_C884_4569_85C1_4037585AD4CA) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_42887936_880A_4196_BC2C_62F3A3DB823D) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_80802B3A_483E_4017_9FD4_605EFD0AA578) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_5D8BD9F2_3E83_4521_A6DE_A851116E9067) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_026A0017_B755_4D04_9F22_C0CFE56408E2) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_C0F9E4F6_EF58_4B34_9C28_2557DC2C4571) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_2C5728A5_D5D6_4904_96D0_4AD823E0E55A) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_DE259D71_CD66_413A_BC4E_4CCC26B7C578) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_CB08CF64_6E21_4640_A6B9_CDE348D845B6) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_461387A2_5A84_4366_B7B9_2B296FE67837) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_AF7D8184_E2E9_4F39_BDA3_21C37237A2DE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_1BD47677_B6DC_4D23_AA58_637D15F533FE) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_448864CD_E638_457C_A0E3_8489DBBE1164) },
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
