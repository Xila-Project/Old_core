#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_3DCB45B3_E66B_444F_AED6_E02246CC420B) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_38C6120E_8263_418D_8827_611D118D6CEB) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_6A808004_B0F1_4F48_919E_4020F896B96F) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_CF6293E5_61E4_4561_B790_BA94E60052F1) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_C5EFEABA_6767_4DEB_9BAF_8E10EE668B12) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_C9E0A265_5A22_4521_AE56_9ADD37BA4B0B) },
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
