#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_F3B9F9F1_9B8E_4FDD_AD9A_36B1161957A2) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_2A7816B4_83F2_4A3C_965C_7CEF14AE61D7) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_C5689A40_F9AA_4049_B92F_5A4C902DD8A4) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_B7B1BD13_5977_407C_ACC7_58A23B0741FA) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_2F4386DA_E3D0_455E_8E9E_E57AF000736D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_5322B090_23D8_4446_A571_CBF0A99E9BAD) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_F81D3574_615F_4F84_8F4D_C0F0E5D836D2) },
};

static be_define_const_map(
    Berry_Screen_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Screen_Type
);
