#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_FE8A821E_6D8A_4462_9547_A76427A26E08) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_218E8512_5558_485B_8B11_B646C47B68C7) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_92C59135_E754_47EE_AB80_578A03F4E7AA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_87DBF8E9_B4AC_4E10_AB85_D904E14FC6D2) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_19A3547C_CFAB_4BB6_A375_478C8DE9DCDA) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_DF78FC2F_FBAE_480A_ABB6_F1CF9FA47785) },
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
