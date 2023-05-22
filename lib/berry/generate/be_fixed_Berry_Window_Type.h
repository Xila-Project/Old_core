#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_BB053CF5_2B65_4EC4_BA73_4A639C526A04) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_FFC452D7_C3CE_4EA0_8E92_50F59F6680D8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_6F4DD80B_9B2E_4B5C_9CA8_376ED177D79E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_8D9599E8_AD42_4109_80BE_58D56E206D62) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_E564DCB4_08E9_449E_B429_BBB2DAE156F1) },
    { be_const_key(Set_State, 5), be_const_ctype_func(Berry_Window_Class_Set_State_B8655956_4D65_46CD_A5D9_AE906A248FA0) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_71596B5E_FD16_4CC0_8A2F_DE3E02A39131) },
    { be_const_key(Get_Owner_Software, 12), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_1E95BEB4_4820_435D_8521_8518F32DB3FD) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_6906C568_87A7_4C15_BB3B_DC09832C9AD2) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_4AADC2AD_60DE_4062_ACAC_8D317B3A022F) },
    { be_const_key(Set_Close_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Close_Button_Hidden_946EDD92_1566_43F3_A001_14C52C783C38) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_D9F17AB1_DE7A_428D_BD38_1C3FAFBAAAB1) },
    { be_const_key(Get_Body, -1), be_const_ctype_func(Berry_Window_Class_Get_Body_247C5AEB_CB35_4316_B85B_0A45F9F10D0A) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_DE8B3B8F_F65C_4A28_9C12_D1654B97A232) },
};

static be_define_const_map(
    Berry_Window_Type_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Window_Type
);
