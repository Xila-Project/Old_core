#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_5D5584E9_4554_4A4E_B3C0_C99AC555185D) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_99DCCDBE_477E_437A_AAC1_7CFDBE448EF6) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_44306994_435F_4E5E_8855_13AA29E49FB4) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_2067CE29_5658_49B3_89DA_2E18A141F7AA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_8DB04AE8_B3A7_495C_8CA8_915CA78E6BED) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_EFFB1113_FCBD_4C2E_9617_A1A4A6EFC5B0) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_30C29DB4_847C_4F14_A775_29FD8CC4D946) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_409E64D9_6FE5_42D3_BAA2_BA8516ADD9FB) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_A37F0DD0_CA1C_4CFC_B100_820C00B5ECD8) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_748E1607_69C5_4C6A_823E_50EF8B627D47) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_58B63065_459C_4167_87FF_773B4AE2350C) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_76EE3FBD_075D_450A_9278_F383BCF4F1C7) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_47F9DC01_5587_4638_9AAB_DBDFE20C97BC) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_5589CB52_3E87_4A24_9578_348110974CF4) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_70F76E0D_3DBF_427F_8B0E_B821DFDCB5A7) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_0D746751_AE5D_4E07_AEDD_ED57A6E840B6) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_7FCAF89B_BEDC_41F3_B17E_4EE0830ADF6E) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_659F8A26_1518_462F_BC11_31B33CA8DD40) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_E2D3B766_572E_4335_A5CD_E88E88AA78C3) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_74F8FBBC_DE5C_49B4_AEE3_2EB262F64619) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_2838AF43_7CBA_4496_B16D_30D1FFCDCCCB) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_28294092_E5BF_460D_9DF6_A7BDC5A78473) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_91F75CFE_FEDB_4DB8_9D13_4CEF36191578) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_AE3E1DA3_0850_4049_B27D_E3F915F97785) },
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
