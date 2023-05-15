#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_81A289E4_A9FD_4114_9416_5B7EB3C07992) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_79F626F5_5102_4633_AF66_82A2AFE5FD69) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_A701E97D_B538_4728_BD9A_D17A35147485) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_9E1F6AE2_7E0D_4ED5_B982_322F80FA5EA9) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_FB4C7319_0A00_4521_860E_585652E9381A) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_8116AB4A_24B1_4BFF_B67C_06881C5857CE) },
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
