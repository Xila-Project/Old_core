#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_860B6767_DA45_4A07_923C_DFB34E41C8A3) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_FE9BFF6B_62A9_47F4_9B45_C02CB9D3AFBA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_AEC9F025_96B8_4225_848B_22EB4D0697B4) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_6918FC13_3547_4718_A38A_AAD6AEF7D887) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_864F9024_3ADC_4BDB_B81B_CB108517A2A0) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_C647B90C_5BF4_48C0_9680_5514FCBAAF7B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_A4E935DA_A3F7_4B4F_8970_465FF6F50C20) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_6F83D120_FF4C_473C_A112_9D0A7B7859BE) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_3E5692F9_4C0A_4414_9027_82458170CA47) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_D0E2AC7C_61E1_4B83_98EB_7DED6D21372D) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_5F8D9525_28B7_47A8_B03B_216FBB774D1A) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_4CAFF579_6C58_4EEA_BA7A_41C0F71B5DDC) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_33219AFB_92B0_4306_A3BD_89CB76549CF3) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_339E62E1_2B21_4F30_992B_008A0EA20453) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_3E220EAA_17AC_4497_8AEC_60DE244FCAC7) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_43FF1DF2_6292_4925_A61C_4D49A880C130) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_5DAEE527_B056_4AAF_92CB_E8C8AD84E378) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_829B705B_07F0_43A5_B6FA_4F85BE2682CC) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_7495490B_E9BE_4C3B_ABF4_C11ED8FA85C3) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_77E25ACA_1CA8_43E0_9486_6D2B72784263) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_02996838_4472_47AC_A5AC_5B938C59F6CD) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_EF178ACF_2C71_446D_8F66_A1FC1F90008D) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_929F3CBF_629E_4936_9278_93ACBEEA1173) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_1D86EA97_8921_4B89_876F_11D5CD546F69) },
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
