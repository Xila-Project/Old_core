#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_E28A45CF_76EF_427D_81C5_BBDD064F16EC) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_F9460E5E_785C_41CF_B749_849BDF290EA3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_702DAAA4_9ED5_480F_95A0_D141AF73BF62) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_831FC2A9_8C4E_4AEB_BB43_8E78936D9273) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_1A93ABE3_64E1_4B62_8E06_7C16C6D187C8) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_B537F645_7265_4FEF_917C_7BDBBFB3E606) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_9B2BA571_3F37_4371_A78F_2B10F4AF4F1E) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_60811DD2_EF0B_4CD8_A9E5_DF7C47A27444) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_7861F5E8_EF9D_4BE7_A682_DD1BF8C52B91) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_A6632D5F_E916_47DB_8846_8B9C849D2F60) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_5F3D9242_182E_4FA8_A6AA_BAC4DDC45FD5) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_B8446B68_5330_4ECC_8822_9A93E6526837) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_56B372B2_24DE_4572_9F3A_37F9B5814244) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_F72D48F6_2236_4A7A_B0B0_C8390448E5EB) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_F094DE3D_60B4_4991_B942_2C184C20D07D) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_BD0F553F_09B5_46EC_BE4A_15DC4FDC47CF) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_AD9B8CCB_EDA7_4B75_B9F5_D5C654BA6669) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_675F2E0E_6DD7_45E3_BC19_F2AFB9666EB8) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_C4BB1152_AEAD_4DDA_AE35_A3D046E09E27) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_37AA3E92_C6A6_49F2_B03A_DD4702040C13) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_73EBBE68_5AC9_449E_8DBE_E3C47F869FDC) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_C906C90B_DE85_4918_82F9_7D2ED3B29D19) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_DC6B93E6_E664_4B49_B780_2E65899E2F71) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_CDDE615C_F1A7_483E_8024_47120AA1D25D) },
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
