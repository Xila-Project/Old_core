#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_DB15094C_90E8_4327_91C5_B567FE4991F0) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_BD1753B0_8049_43E2_B106_6EFD36BB4BC9) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_C8446DD0_0E85_41E2_879A_3F7ACE3819EF) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_74B38C73_BDCE_4A68_B2AB_E4D9CBDD3B09) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_4D4ECCC8_B4CD_4634_8473_87146D088350) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_7E860049_FEFE_4D53_9D8A_1203449714C9) },
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
