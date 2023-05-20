#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_F0F89CF4_5449_499E_87B3_F1A585D803F0) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_FA0C7930_E156_4077_91CE_B478F176712A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_880E9D3F_50EB_44BB_B84D_F6ECB9E0E2D8) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_F1FACB3B_5D8F_40CB_8939_79F4F23B2D98) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_08B8F1F2_02D7_444D_B1EA_61E68443F816) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_EB186B1E_BAF7_4B96_92A0_704DA5C2C7F3) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_0DAAFEE4_BAAA_4DF7_90F9_09FE3B847651) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_3CBF3076_A87E_414A_B1F2_630FA1A73DC3) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_B2456C03_AEBC_4525_B666_12DD7E6070B1) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_50AC5415_E265_4C57_B11D_D39E989612AF) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_C65DC08E_8CAF_4A86_8A1E_49121C300805) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_E53BD9C7_1122_41F9_97C2_C93C13165959) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_F075733E_4731_47E4_8AC6_D6BE39B25281) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_DAF4E9CB_619B_4518_B555_8D1C8710BEA2) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_7C93A3B9_20F9_4B4F_AB1B_3119A3355B63) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_59AF7B66_9983_49A3_A609_E25789712E62) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_30C6AA55_8294_499B_85CE_FD4AFB38BA4F) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_EEA2052C_2C88_4E61_A813_B0F460A86B25) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_EA2C3740_B2D6_4847_A457_536FD19F8CF9) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_C8DDD56C_EF46_4D0F_A80A_C42BF70892FE) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_C3FB872D_AFDA_474D_BB1D_84298BA0D715) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_0C20DFF2_DF3D_4E79_AAEC_F37BC1BB9758) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_F2AA94F0_3B5F_4EAD_BC6F_F0698A81F0BD) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_84613CFC_04DB_4BE3_8E52_3A5B177E126F) },
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
