#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_02FF9DDD_05C4_4288_825D_60E797CD2FC6) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_697E7D62_10AF_480A_B777_9941A7C8FBE3) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_4B738E04_9759_40F2_A2C9_F25F82F673F3) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_743F942D_5720_4B32_BA1A_6D2032432D79) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_29409C74_94C6_41CA_8CAC_8AF2DF11E574) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_79A74EF3_6A2A_4CB4_BDC2_9BC05924F098) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_CD2FF2C3_DD86_4DB3_BE60_9B2D6E048573) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_D7F44F1C_B828_42EB_8FD9_E73FCABA401A) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_43C44703_7547_4D98_A6AD_28BAA2D7E663) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_4F1797D3_0705_4528_87FA_475FAE754E87) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_F708078E_9987_41D1_857D_4F90517A66FE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_3ADF40AB_FF37_46FB_97B3_D17FF9C47F3A) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_452E41B0_F2F2_4F0D_9608_3EC9A7CE91AC) },
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
