#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_662D3654_2FCD_4133_8D93_C1B78E6D9205) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_31E9881C_BABA_4E70_91E9_9AB11C722000) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_64E711FB_407D_4949_AEC6_A06EC0F0CBE3) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_12FC695F_7FB2_40AC_9505_70D721BB31EA) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_CA74CDAE_0043_49DE_A6D1_06BFFB67622B) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_A791ECDB_2E7E_4A4E_8B6E_19FB01E67FD6) },
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
