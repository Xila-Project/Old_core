#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_7CAC9521_6CBF_4B08_BD63_0D300193CD6C) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_5522734C_EE9C_4EA0_8379_BF1BB3781EA1) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_8FD9BD11_7427_449D_844A_20A6C7A02ABA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_3907DB84_1FDC_4F01_A2A6_EBA6E2F7D961) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_F1A126B4_8FED_43FE_955F_5D41DF6BAD2E) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_B8BB1C52_2CE9_4671_8FB4_B85CB4BF68D7) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_A33C4BEF_B794_4885_B4E9_381FA2233347) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_3FF8BB42_2783_4347_A613_EB7456C6BBC7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_491D49B0_7C92_42FE_ACA0_F4544D2867F7) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_4E69095D_7284_4D44_9593_F5E3367CA04E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_A51505C0_EAE0_4BB9_9F40_0E1271B29B64) },
};

static be_define_const_map(
    Berry_Window_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Window_Type
);
