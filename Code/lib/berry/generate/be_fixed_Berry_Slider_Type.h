#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_E365D653_0211_4CED_BCE0_A0F6E62A8FDD) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_76E401E9_7806_4027_9255_BCCC7AC96E1B) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_CB2A6E8C_1D94_4D01_A9DD_27730217E191) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_CD7B3E7C_555A_4C21_921C_D8BB52B9F443) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_F98FA36B_7BDD_4D12_AC33_DBE8EA0FB731) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_13859BAB_E78F_4D37_999A_F842DE028FDE) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_02386C72_9443_46AE_A077_C0EE649FB2D2) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_0A6A0DE9_1342_4A91_B732_30FE6E8D875D) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_F4E331E2_BFAD_4AFF_9975_1AF169A4E8F9) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_AEE74BEB_2711_44E1_8536_B135CF852837) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_6B10F2AF_5199_4524_8222_C9524493D5DC) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_AA112740_59A8_42F5_B2E4_AFBCD62F2F15) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_88071E0E_FB72_4B16_B75D_2803854344BA) },
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
