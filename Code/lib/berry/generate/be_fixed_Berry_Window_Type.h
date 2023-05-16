#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_41CB66C2_6A19_4DF1_996F_12B61681FFA6) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_2C79F012_8FE2_4AB9_90A6_8F6283073EF7) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_E3B8AD08_4892_48D0_B482_31F5BB6AE277) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_5C5B0C0F_3E0E_4E96_85D0_9D9DDE004F00) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_709B4B64_ED01_4CA3_AE3B_226EF024D37E) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_2284FD09_1D6E_45EB_8C35_33851C543454) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_F0BE0526_DC33_4768_880A_4B379C3CC3D8) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_338D3A3B_2506_4689_B5C3_5ED94C1689DA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_D2FF7803_9C29_4D5F_AE27_4F12B32DFADF) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_53D18DAA_61B4_49B5_83FB_9E43BE4EEB4F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_8332A4AD_E82D_4E88_967D_89B3697A37E8) },
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
