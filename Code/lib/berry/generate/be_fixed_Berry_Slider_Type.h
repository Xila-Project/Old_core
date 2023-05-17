#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_08322497_FEE4_4165_9FC0_3450B88F35F4) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_B8978EB1_CAD8_419E_AD60_24926D60AAE3) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_9529FAB2_57E4_404E_964C_BDB021480875) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_6D4D817E_E5DF_461B_9E11_A6BA84964F98) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_31A92EAE_60DE_40EC_AD2C_6758A0CE5DCF) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_2A02AD7A_BB39_4714_BB3C_193802303BAB) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_F92D7216_E91F_480A_AE3A_1E0B8CB80FF9) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_077B833F_FBDD_4F36_BCA4_005E820C7AA7) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_0C9D0054_22B1_466D_ADC3_3D21E32CD572) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_E5EDDAFC_0925_4BD9_9D3C_682FD1A22D83) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_439F4754_BDC2_4516_BB6F_1DBF55110F04) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_6D8453C2_9E17_4CCA_8879_B544CE348DA0) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_80316560_890A_4577_A2BD_09C40DD2F33F) },
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
