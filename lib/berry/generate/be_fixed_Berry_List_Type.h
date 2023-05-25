#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_8B8E71A3_6DE6_4FCC_ACC3_8EF7B15ECF06) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_F00A9CF4_DD10_4BA7_A309_D800DA996201) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_3BA8B1C5_C847_4EC9_91D9_F265DD2C3D27) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_8B292B07_0113_4836_9052_0601EAF3DF29) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_91282296_7A41_4CE1_8832_F6DBBF617019) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_71C51BDB_6002_4876_B961_58BE5846A1FA) },
    { be_const_key(_p, 0), be_const_var(0) },
};

static be_define_const_map(
    Berry_List_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_List_Type,
    1,
    (bclass *)&Berry_Object_Type,
    List_Type
);
