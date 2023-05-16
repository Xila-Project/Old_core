#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_BCAC6FAF_CC49_4603_BE33_3CB98D954C4C) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_817FA05E_AAA2_4F44_9E55_4D39DAE77FD3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_E6C6516C_E3D9_462B_A5D7_F323FE31FF5F) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_2E9C01D0_464D_4D8D_B985_911564AB5917) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_C2F5C810_A8AD_4B39_A72C_50F794CE168C) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_8AEDB9F5_F4CA_451D_BCA5_90384DC0ECF3) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_E8DB437F_18D4_4EF0_B051_3EE119BD459F) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_F1AF5F68_5361_42E7_8C51_FE2C4E993623) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_A35DAEB0_267B_4C20_A070_44C34B513B0A) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_1F76103D_6D6A_49C8_9E1E_611341A697DD) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_D9C71918_C05C_41F5_B10D_964CDF319C3E) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_C8949C90_D148_4549_86FD_F7737B9A07A4) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_756F78F8_64B8_435C_92D8_DDFD7750080F) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_0C0B8FF0_DFBF_47B6_AE31_B31664048E3B) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_7E81B37E_6BA2_41EC_868D_576FB08A2E44) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_619F813E_CC95_43C6_8315_8FB21EC4CC03) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_3FB1EA3D_1FE9_4AFF_B429_B8D0FAF90C44) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_4E02D523_67D4_4D06_905B_575A35DF06B9) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_6E30E706_4488_4408_A7FC_BE4045E0F65B) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_C390B689_D5FD_4B90_B09E_BA2BC8424393) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_5C09C06D_0E97_4454_94A2_35A9BD99DABF) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_DA1FB1EB_CEEB_4DBF_9766_22AF3655F3D0) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_0E9620FD_DDA6_4013_B8F7_53A7BD4DF0F4) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_A36EC0D3_B707_4DD2_BA97_62F4624E5012) },
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
