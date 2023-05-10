#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_AF0ECA0C_4A18_4F97_822E_51B5E2C063CF) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_449B6FEE_8DED_4C68_83DA_4CCB0BE4BC36) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_535C62C5_EA90_4E6F_B443_216EB07250B1) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_AD2FB0EA_FFC4_436C_BD96_3470851218D3) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_116D6C98_14A5_47AB_A093_82853A3463DA) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_2B8EFAEF_3D3E_439E_B5E0_A424D54185BE) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_3A8D9E06_6D3F_422E_8AC8_B47D6370B916) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_3AFD11BD_3FC2_4185_A254_7C99EB272B5E) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_361BE979_16E9_417B_B243_0062F99CF4B6) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_51F2501C_3EEC_473F_BD59_2F8CF692C9A8) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_295195C5_8533_4739_8B59_9201BCC85ABE) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_CD5E529D_298F_4F61_9424_132B0C48017B) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_1D39B148_E2C9_43F8_9DD7_F0DC7A9E4AD8) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_FB2D5BC3_7092_47B3_85DB_5680F4C20646) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_5F9138C5_8BBD_4847_94C5_DC5137E310DF) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_F09BB089_CBE3_4F9D_872F_B5BCCA72D742) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_4B6BEBD6_B250_4569_9F00_572E82774519) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_37822377_4218_4D00_8C9F_D03A2AEBD5CE) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_81C626EA_6003_4487_8319_BA2F5130A6D8) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_929D285D_D008_40A6_9E46_950518B78AAA) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_B2818298_3541_44E4_86B4_85F258F15D24) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_1A5C39CE_C9E0_4BFB_9D91_6E9AAAFB7F13) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_B6FE6921_BF26_40DD_8C7B_C2536E8DF020) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_CE6CE065_42DC_4408_9A66_384FCBADB750) },
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
