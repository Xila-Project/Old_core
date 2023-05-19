#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_CB441C1E_3A21_4652_B114_EA013F085713) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_7AD9567E_04CE_4A34_8E8D_CB71DC7A302F) },
    { be_const_key(Set_Title, 13), be_const_ctype_func(Berry_Window_Class_Set_Title_589FB5CE_F607_4AD4_9167_B0A1BD020A48) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_947AD918_A3F6_4E6E_BC2C_9EA4C8968871) },
    { be_const_key(Get_Header, 7), be_const_ctype_func(Berry_Window_Class_Get_Header_91035338_7B81_4EAE_A59E_B7A28F0A968B) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Window_Class_Initialize_5310A321_923B_4723_B984_D7AFDB8A690D) },
    { be_const_key(Get_Body, 8), be_const_ctype_func(Berry_Window_Class_Get_Body_6E57D73A_1C43_4935_AF39_7452035408FB) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_D1AF21DF_B7F7_492C_99B6_E3DF8E5F04D1) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, -1), be_const_ctype_func(Berry_Window_Class_Set_State_EE89D2D7_1DEE_4C11_8C2F_C0A6043AABEE) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_B35F4E8F_5F42_4669_A3B5_BD57EB64A825) },
    { be_const_key(Get_Owner_Software, 9), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_240FEDBB_3E37_4EB9_B2A3_80E3369A84D8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_712643B9_9A74_4D41_A45C_E6BF0F5771CB) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_41673720_7578_4DB4_8B3D_CBFF5BDCE4C2) },
};

static be_define_const_map(
    Berry_Window_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Window_Type
);
