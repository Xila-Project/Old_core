#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_59CD9336_5758_4B4F_B71A_B6B49AF302A1) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_CDD92D4D_25DA_4A65_8AB5_DA289B21EE3E) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_4C40E9EC_9317_4907_B88E_9B688953CA5B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_4204187A_6940_48F0_B4AF_0BFCD32AB518) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_5CC4465E_3825_43DB_AA0A_9ECA18020AF9) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_242D79C9_5610_4997_8C98_EC43E9A25700) },
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
