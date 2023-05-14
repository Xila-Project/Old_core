#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_640B524D_671B_4A2B_AEA5_9C4AE9787158) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_7809C9BE_A506_4C08_96B6_ECD9DE370CE4) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_0A281AC8_C4C8_4265_A902_F9E8E58A881E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_19767A71_B8F9_4A39_88D9_F0EBA3988C0B) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_ECCF1FCA_1DCF_4142_AA3C_F44DF6DDE6E1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_B8067B00_0451_4259_B210_80E49D08973F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_562D4D26_DBA2_400F_A226_1DF04E7626DB) },
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
