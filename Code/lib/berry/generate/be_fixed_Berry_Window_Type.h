#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_87A9F98A_A058_4421_BF3D_D41D39E72759) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_651425AD_B317_4DA9_8370_E08DB560AF7A) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_600DEBAF_F079_4EF7_95B7_E29350958BA3) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_EF3250E0_2026_4675_ACDD_843747491837) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_1CBFA1E8_4BE5_4FC5_941E_024E486460F1) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_504BE28F_BA33_415A_A7BF_1588EDD44F51) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_111C9930_39ED_4DB7_A9F0_0257B2258229) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_5873E98B_1142_409C_B422_65770A87D3FE) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_EBFDF0EF_EFC9_49AF_8860_DB217BFA7B1E) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_4873954D_6AE3_44C3_8E67_09795C583FAB) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_1EA702E7_33CF_4629_B6BA_61A25D728DA9) },
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
