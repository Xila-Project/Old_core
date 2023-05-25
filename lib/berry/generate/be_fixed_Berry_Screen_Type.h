#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_37AE3EC7_D13A_44B5_82B0_AFF5FD6FC603) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_6F2BD98D_270E_46DC_9670_24B4BEFC278A) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_C4CF7C82_532E_49EB_84E0_D8AAA80AC56A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_8D433444_D6D8_44F2_B234_EF278D5DD41E) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_5DADA6CD_D4DB_40A9_9ADE_2EFF82EDEF43) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_97B368F5_6E50_4986_A376_CB3BE775C2B0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_D5F7B933_03F2_4F72_9CED_147921F307EE) },
};

static be_define_const_map(
    Berry_Screen_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Screen_Type
);
