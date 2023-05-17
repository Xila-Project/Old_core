#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_AECC5EA0_FE1C_4DEE_B013_1DEA2F3452CF) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_FA3BBE35_8704_4F9E_9B00_1CB37A6D8963) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_2452FB2D_DB5F_438A_8063_6CF08BBC5513) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_69F32724_34CC_4626_9B3B_78CE2BC26923) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_A6911F92_5CEE_4174_B9E7_7F7500053B81) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_7B7C3E5A_5FEA_4332_BFE9_D4A22D4D08CB) },
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
