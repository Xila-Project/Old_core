#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_F499E112_C345_4AEB_8F5D_FEA61097F7C4) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_B0FA30A0_A238_4381_BC67_F0094D335006) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_A62231A4_702D_418D_B1DE_2F9D1DC55496) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_CCD9CF97_D1FF_4B6C_92AC_509ACCBEAAF2) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_25AFB19A_381F_4EA9_9194_28C4EC490C8A) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_C04DAAC3_3D3D_4673_971A_CF764309C055) },
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
