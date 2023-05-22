#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_67CA4112_C37C_4943_A2FB_F1BE7F0E5EA7) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_7A8A35AC_1A81_4E0D_BD93_783E7B822AAB) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_F4F28851_C176_4C5C_AFAD_548B6430A45C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_AD6B33C6_63A3_4D6E_8F91_815A54C8190C) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_C2C0D754_395A_4D3E_9FB9_23CF95A446EC) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_3A9C78B1_4AF6_419C_9A3D_A2AC92D915DE) },
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
