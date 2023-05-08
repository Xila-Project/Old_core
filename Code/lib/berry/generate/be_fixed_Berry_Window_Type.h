#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_2B487F7C_2D67_4453_A540_B927C1C91F7F) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_2D36F85E_0635_401A_A17C_48C3BF4818D9) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_C23F9DDE_9C33_4280_B91B_8F6E6808A3C7) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_E96EEDEF_02D3_4CFF_81F6_C95D66FFD8CD) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_08593BD8_BC27_4529_9C0F_B46F66BE75C2) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_2903D7F4_0F0B_41BB_B102_58BDC0759847) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_B7B9C58E_01AC_466F_8801_95BB53F6527F) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_55950AA9_FBA5_4368_AB6E_91D69EB8207D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_BCA3F2C1_8715_4C27_A291_D8FE2960F845) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_BC921BDE_1284_4319_B22D_8A7025E1FDB9) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_0EEC0E1A_43E8_4957_89BE_CA2ED00F8C40) },
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
