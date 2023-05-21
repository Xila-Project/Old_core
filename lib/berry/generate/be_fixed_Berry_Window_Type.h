#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_1DB91F2E_6A47_408C_9066_D31FF884C025) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_26074BE9_F15C_445C_A88E_7972BFC43D75) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_04F6DB9D_4DD1_4705_A17D_792A79A3B4EF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_1F1E2175_5602_46FE_9560_33845BD883F4) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_4A1CC6F9_EB48_450F_868D_16480DE3888E) },
    { be_const_key(Set_State, 5), be_const_ctype_func(Berry_Window_Class_Set_State_D4DA22AC_063C_4C8D_84D3_55F30F711A38) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_E2B74863_9C9F_41C8_A19F_42E08575CF28) },
    { be_const_key(Get_Owner_Software, 12), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_4BD884DF_7D29_4035_98A8_9C01C262D3C9) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_BE304FA6_C0EC_49C4_B744_814912FD1F96) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_6976C032_9DF8_48DD_BB18_451D2BB703F1) },
    { be_const_key(Set_Close_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Close_Button_Hidden_89E396D4_BF24_43D9_A389_0EC15694C06A) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_136B21C2_B21E_4751_B20B_3FF21C558C56) },
    { be_const_key(Get_Body, -1), be_const_ctype_func(Berry_Window_Class_Get_Body_49BE085A_18B1_4A64_A306_675FBEEE75CC) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_5DA97FF0_EE19_4F16_9E14_28252552C682) },
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
