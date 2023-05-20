#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_11D08A80_5D2C_43A6_9B57_D73860750B25) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_23D9105C_8133_4318_AA40_749145893652) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_6942D809_DFAB_4CA8_B3AD_0E0DEFE55534) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_3D24ADF7_2ED5_4A23_9BB9_D5670EB2EC32) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_B004A89A_A47C_4212_9377_859AE8967B20) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_B55D5EC5_E992_49F6_99BB_F05877F2AFD4) },
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
