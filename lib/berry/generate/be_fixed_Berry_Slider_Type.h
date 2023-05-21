#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_6AFAEC01_6E34_4536_961A_128EFE30C3D3) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_02109D51_59AF_4E9F_A261_2BDC558DA140) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_6042BDC6_493A_4698_A2DA_98723FE1158D) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_D69928AE_233B_4AE2_B6D0_F2C58F3E7CB6) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_39744A17_F00A_4B40_AF39_FF4278AF97B0) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_7E004984_8FF1_4F50_8373_0CBD633E0B8F) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_919DF024_8E91_4085_949E_6C13E9CE76D2) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_2C499FA7_B82A_4276_8305_F010E788F585) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_23741CC6_B208_4907_A55A_0819AA316479) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_006FB0DA_6C0B_4A60_AB4E_6DC3B09F193A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_43528D51_8F98_41B4_B8E5_95243FAE2F0B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_3CCA703D_31C4_46E9_BA4C_70DE69F8DD9C) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_C84F0658_18F2_444B_84F8_21B94B9AFACD) },
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
