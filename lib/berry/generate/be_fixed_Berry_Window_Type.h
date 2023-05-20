#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_EDFF7DB6_3F79_4214_BE97_EB3656066DFC) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_DCD992BF_4ADA_4935_ABE9_B73A67683083) },
    { be_const_key(Set_Title, 13), be_const_ctype_func(Berry_Window_Class_Set_Title_565907B5_6181_481C_A666_15989C24542E) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_EBA52025_3F5E_4375_B350_F40B367DD29A) },
    { be_const_key(Get_Header, 7), be_const_ctype_func(Berry_Window_Class_Get_Header_A55394FE_0AE9_4468_90F8_7DE8B0E07D3C) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Window_Class_Initialize_6F5D1AEC_1DA5_48FB_AF83_6735F487975B) },
    { be_const_key(Get_Body, 8), be_const_ctype_func(Berry_Window_Class_Get_Body_114BEE55_4FC9_4B8C_B4BA_C90707775A08) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_A56FDF9B_E53E_4E6C_A93C_CB4FF3BF3A6A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, -1), be_const_ctype_func(Berry_Window_Class_Set_State_4F6E9871_35B7_46E5_A8D4_D9561C68FD53) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_403F974D_1FAB_4154_8157_9A88E49623EF) },
    { be_const_key(Get_Owner_Software, 9), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_71840C1D_647A_47F2_8965_9A1C7C9068EA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_55717712_3626_4C07_9E30_4AAD665DE365) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_E13F4232_A0A1_47AA_90D2_792AE5B7E0C8) },
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
