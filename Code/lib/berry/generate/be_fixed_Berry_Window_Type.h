#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_945A99A4_BBEC_4453_88AB_8B25A2F91135) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_14537D2E_D177_459D_B32C_0423C04C710D) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_2A3E6F81_EF0A_466E_8ED4_31B4879E2192) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_A3F0CA69_5515_401D_A65A_4A2647700131) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_C6335200_5C56_4E21_90F0_586408D94BBF) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_F2723E8B_8592_4EE3_A967_7875B604FDAB) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_DF2CE1A0_B503_4D67_963B_55160BAC23C7) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_B211BD70_B03F_4900_B600_14B95FB00226) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_1DFF64B5_9EC7_4480_B737_E500B5FEBB6D) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_6B845BAB_B1DA_47EE_9FFA_4DE8CF2E59A6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_D429F1A9_6A75_40E1_93A3_DA82D983C4B7) },
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
