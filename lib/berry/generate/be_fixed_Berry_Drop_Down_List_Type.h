#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_010419F2_93FF_4243_842B_57C2748EEAA3) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_D6589E3A_9C31_4B78_ADC9_776E90A49417) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_04E3294F_30BC_4E61_B470_52833296D3BA) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_24E8BCCC_BEF5_4ACA_92AE_68DE2D0AA1AC) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_978DD855_C653_47BC_BE38_62A08EFF6887) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_B606D6CF_76F1_489B_B8D1_A8EE054DBD2E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_04038030_DDB8_4558_9721_0EAF5AE99684) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_BE16E400_BD83_450F_BFEA_CB4889FEBAA9) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_884DA86E_42F5_4404_9682_A4E0898F2D5C) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_B4AA9F7F_44CE_438F_9C5B_F5B42283264C) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_F775FD07_CBF8_46DA_8B8C_0946B107B09D) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_578D0E5B_E2DE_482B_8027_C71761C408E2) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_B09A9540_E0D3_48DA_94D2_1CA3148758C9) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_35463CE5_9449_4B80_AE53_59961E0253BE) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_A10E4963_73E6_4557_9012_42A343A065FB) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_16A9AE7B_FEC0_41F7_B8B2_ED981FD77F7A) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_B0545B7C_8012_4953_B326_C06248085BC6) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_648099A8_315F_4752_AB8E_EB40797AAC81) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_5A90F3A2_5C2C_4BED_9705_8C9A167366E2) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_7D58E3F3_F105_4BC8_BEBF_88B2723946CE) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_2836089E_FCA5_43ED_8A1A_23FF08F4AF83) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_26DFF3B1_2321_406C_A39F_0F35E5F59ADF) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_525DDF3B_2541_44B8_A1FE_19BE2273E76C) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_168AF492_41BE_4FF1_AADF_242AB60BE563) },
};

static be_define_const_map(
    Berry_Drop_Down_List_Type_map,
    25
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Drop_Down_List_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Drop_Down_List_Type
);
