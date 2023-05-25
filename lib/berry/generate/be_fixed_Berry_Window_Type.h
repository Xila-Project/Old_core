#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_C22DFC76_0A09_431C_A2BE_4A0D5F56A8EC) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_3DC598FE_A4DD_42D1_965C_2FA300197663) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_4BCDD510_E991_44A9_8AC4_6D3BE14EB244) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_7EEFE4B9_0DCD_4D42_972D_9FEAC29F0A6E) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_35ECB4E7_CD0A_431D_A806_49B50C666AAD) },
    { be_const_key(Set_State, 5), be_const_ctype_func(Berry_Window_Class_Set_State_2BEF5380_E13F_48F7_8F9D_CFF009E826A2) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_FBE649AF_C9A1_4B06_876D_13A7FBFB2DC3) },
    { be_const_key(Get_Owner_Software, 12), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_DD06E318_3FD8_4BC7_9D62_DB793E628AF8) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_7089D7C9_3639_4221_A4AC_3E3383A4E666) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_E2FE9871_1964_40E1_A5B9_55FAA944E16B) },
    { be_const_key(Set_Close_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Close_Button_Hidden_C0901741_A3D5_4E63_B48C_9967D364D2E0) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_03D417F9_DC04_4A8A_A239_F6EF5DEBE820) },
    { be_const_key(Get_Body, -1), be_const_ctype_func(Berry_Window_Class_Get_Body_5AE9F173_7C27_4B9D_B3E1_6A388F528B42) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_D3F9B6A1_8626_4C02_9B7A_7C6E01B0BE70) },
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
