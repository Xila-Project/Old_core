#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_1306FFEB_7FB5_4005_890A_87113FB5E650) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_C454D392_D767_4329_8209_9A1B2D04C2A9) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_D31D2304_EE99_41B7_BE03_1CCF9912C021) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_E014962C_24AA_4CE2_9A45_E615AD46980F) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_5EEEF1F8_F01D_4AAE_B19A_52082A34881E) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_F3A9E759_1CC0_48FA_9191_C0BE5DE6FAF0) },
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
