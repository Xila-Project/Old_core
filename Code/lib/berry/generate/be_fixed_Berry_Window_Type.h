#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_9EBA0FBA_CF7D_47A9_B8F7_877E418338DC) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_DD688CE6_085C_4033_9B8D_AC04405F503D) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_A8A5C057_9267_462E_8700_EFAE0BEE957C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_5B679931_6A8F_436C_A553_1C84E784B48F) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_5C60F450_E492_4EF7_929A_87F503523578) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_79C08C41_8F4D_411F_BE68_9FF24772C489) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_BEEB7606_7FA1_489B_BE09_83FBC1F86461) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_7D09343E_8099_4558_8787_18FAC1BEC520) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_66900E0B_50AB_4BA5_9E04_A15A1FAFC945) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_2DCB3216_177D_45E1_98A2_2C8C8A241986) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_5A2966F9_8B34_4FEB_BEE1_0B8F391E7ABA) },
};

static be_define_const_map(
    Berry_Window_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Window_Type
);
