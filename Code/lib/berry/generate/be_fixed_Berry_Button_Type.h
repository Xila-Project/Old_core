#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_46BC30E1_D9D6_4822_ACA5_BA5B2E23EA04) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_CC6A66D0_3F14_467F_A277_2A9AABAD44F3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_0EF85A32_FA6B_46CE_A05C_837A451315CD) },
};

static be_define_const_map(
    Berry_Button_Type_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Button_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Button_Type
);
