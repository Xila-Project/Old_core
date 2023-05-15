#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_49FA6F50_9490_4E04_8C35_E18EE4FF9CED) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_5F529B7B_E38E_44E3_86F9_02CC0BC56F55) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_347173B4_4459_4A7B_BFB2_FB9D72ECD06C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_91328079_B038_4970_8656_5C9C97D8BBC0) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_19B9CB67_D4E0_4A90_8D11_2EA31047FF28) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_59AB8793_E57E_4FD7_9C95_4E13086ED9C3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_6AD48E0C_382B_452C_B7CB_7FAD4A756DE0) },
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
