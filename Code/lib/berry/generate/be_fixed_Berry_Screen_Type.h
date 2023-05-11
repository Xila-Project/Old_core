#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_C4B8BEB8_15AA_4227_BA07_3D402D6EACBA) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_4972F4BE_B59C_460C_ADA1_CACCA29956E4) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_9E2F86DF_64D9_42D1_9B6E_08C2B90BE2C0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_03094CBA_4817_4E7D_AE62_ED5B51B00C12) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_233FF687_5065_4203_B712_79C49963D296) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_D1EAB6FB_D2FD_4947_9344_8AD6DBF5CB9B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_16B0517F_C906_4237_BA32_11422BDFB8B7) },
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
