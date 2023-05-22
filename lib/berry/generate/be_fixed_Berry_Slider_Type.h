#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_8C1A66A5_975A_4214_92BF_12994405DA9D) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_4B8E2813_DB74_4A53_81A1_F0E3C356FD91) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_F5EF9744_AB87_442F_BFD7_A6CD04DE6FDB) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_4BB764B8_5FAE_4023_9431_D4BC8A125AFC) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_B7F02723_80F6_4519_BCA5_A416572465C7) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_A3284188_18F4_4A1C_B48A_2AAEA8C36751) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_58BC76BD_0A8F_4D9B_A568_6FFB3DA38342) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_6644DE13_C618_4968_AD32_103BFB4FE5D7) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_859C5B9C_F4E3_403E_8A01_FC2D759DAC61) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_D465B784_9D29_4940_A5A7_17DB9A698783) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_95699C7B_1F0C_44F5_B668_7B2FAC7B4DCA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_3387B965_63AA_459E_9882_DFA5A2483DA9) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_EF52C8BB_664B_418D_8C63_FA0C6E432F52) },
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
