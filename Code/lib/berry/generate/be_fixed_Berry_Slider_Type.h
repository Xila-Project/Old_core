#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_9D9736D2_C419_4164_8F70_113EFD4EF66B) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_B9D3C0EC_E4FE_4D6E_9A93_E36A8096416C) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_72275B97_4184_45A2_8CFD_D08DBE6606C7) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_670E55FD_7FF7_4DD3_B726_5B3D6AD4201E) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_2531970B_1683_45C7_BFA0_DA167A6D3ED8) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_D3712290_2F3D_4463_A1DC_8EFD99D038AF) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_AF56DBC5_5098_497D_8C73_277E6C20E30F) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_4D2B6934_9603_4737_BCF1_45A7E7B2171F) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_6C4918E6_A0BD_4146_A1A6_FE32554B342A) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_C2C6900D_44C8_41B4_91B0_77C22CFB4CD8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_D0480B26_D6BB_4755_AD06_5D6D91A43953) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_6AFEB93F_9292_4071_A9FF_631F962B3869) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_218C88C0_C7FF_4027_8541_D2BC07AB130D) },
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
