#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_1A033F8D_B463_4654_8F8C_4A000473615E) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_BB75AD5A_D1F7_4822_987F_09E3AFF0066A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_C26B665D_10BB_4CC0_BC3E_9965926E9E95) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_60A29136_C20A_47E5_81CB_11D385544E89) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_2F0EB9C9_E9A6_4D11_9A14_4AFC8CC1CD1B) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_8BC9B826_5C08_492E_86CE_8A802C725BEE) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_03AC7356_012C_4F0A_8FFF_A6BB6B9C533D) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_62FE2365_5D16_4635_BB5A_7668C4C6B74F) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_616EE6BC_B51D_4624_91D7_2DF21E37B5D9) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_A61F5D6D_A588_4E24_8800_6303384EFF69) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_4D1FE2E4_F49A_4260_A460_0C41BBB0BEA2) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_CB071040_4934_49BC_9C5A_9BFEEF2D310A) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_1879D5FD_ED86_4B27_8DBD_84A9D6FA69BC) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_1CBBD5A5_8F0F_40A9_A5E5_3FC8AD4C48FD) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_11700FB8_3B10_4E07_AAC0_D6B0DDD3D9C8) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_F686CD6D_76B7_402D_BBB4_6ECD47E7C22B) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_A2D846C8_E6A9_45B6_82E6_193B2806B023) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_5F1C9969_0BD7_480C_8454_4D8C1C05E437) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_E3017607_09C5_4213_96B8_BA1A7308C650) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_29D2118F_6D51_43A1_8AAD_0C73807DEB16) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_8A37B6FE_7BFC_4C26_AF66_27DB1C0CF3A3) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_7123F590_FDBD_4481_8907_01139B33F7EA) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_DFA6140E_5279_4E83_881D_F056E9308621) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_632BCD59_CE0A_4BAE_A4E9_C07E474B9C94) },
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
