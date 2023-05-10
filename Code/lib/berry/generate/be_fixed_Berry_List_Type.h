#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_28F9E27D_6B37_4EC0_926B_AEE00E72FD24) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_F4E25D79_FE9F_4FB3_92F7_8DFFE42F3A5D) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_AEB4D6CD_1B52_425F_A281_E93BC2B92A9E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_395B6FEC_2BAC_4E59_9681_EC93751E96ED) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_7D75D9E6_4B48_4A54_B1A0_F639C43C443D) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_75675CEF_C0C0_494E_828C_BCFF8455BF8C) },
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
