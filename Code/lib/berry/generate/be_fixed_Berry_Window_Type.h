#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_E2B92598_3566_4CBF_A8C6_E28B5FD61D18) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_0B26067B_B6D1_4853_AF8C_461967744A8A) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_80B505FD_BF47_4CB5_B25A_51B6EC65C541) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_2E0D6CD6_B37D_493B_B778_2A370167CC6C) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_307AAB2C_5C2A_441A_AF93_645C96E65870) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_212068D9_1FE0_4812_A65F_DD311EC0A727) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_CDC0A367_8502_4F57_B709_6439CAEB96CA) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_AAEBAEDC_FE31_4AAC_98F4_320EA6B043A2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_99FA8DFB_724B_44A9_AE5E_9F5042558B63) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_3677DF23_C552_423D_BE5B_9A85A1686741) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_E6D74E29_25A5_4CEE_8D16_869967CCD1B1) },
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
