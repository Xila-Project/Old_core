#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_07C8FBE6_5D07_4524_ACE0_F26DCA0557D7) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_407D9F3F_F0C4_498D_9634_3AAA2EC1949A) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_45291EBD_8027_4109_9BBE_9F14AFB79BF0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_63476578_F6F3_45C0_8BEC_B4B72B974AC4) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_EB0D80FE_9D37_4F65_A332_CEAF0BF51405) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_B3AAB7EA_1D5F_4559_9FE2_D5D8B93FF900) },
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
