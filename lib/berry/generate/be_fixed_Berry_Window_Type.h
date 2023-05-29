#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_B6697D9F_0386_4DAD_BFA0_1EDA5AB8AB76) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_DDACDAB0_49FD_4192_A2E6_CEFECF817263) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_04622B5B_E051_4618_9B55_7288783E9D27) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_F0C1B581_85B9_43A1_AAB6_78FE403C3539) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_F7C1EA72_23CC_40F8_9D42_CAE865A0577B) },
    { be_const_key(Set_State, 5), be_const_ctype_func(Berry_Window_Class_Set_State_7D83104F_48E7_4416_991D_2807A9986D6E) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_0C33F133_7ED8_4E21_9F28_981B8F7835AD) },
    { be_const_key(Get_Owner_Software, 12), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_5B47009B_EA31_4EA1_9501_4D66549104D6) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_2382FF1C_6AAF_4838_B440_752785F44821) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_AE8D155A_51A5_4EE3_AD5E_1348F9F2B531) },
    { be_const_key(Set_Close_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Close_Button_Hidden_72A96716_0D70_4FA7_833E_3E6EDE52758E) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_EAAA8454_B18E_439B_AFC2_A6E9D906EE91) },
    { be_const_key(Get_Body, -1), be_const_ctype_func(Berry_Window_Class_Get_Body_29D6C556_BD33_4674_9DF4_29D3816222FC) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_62FC36A8_4D24_4478_8562_9E4D3E5BFB4A) },
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
