#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_C1D5AC8F_2901_470D_A489_E976433F0304) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_B76CA354_381B_4C65_B462_453D82BD82AA) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_766822D2_17CA_4F5D_8F08_1EEC3848F31E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_21B6F691_7085_47DF_90E9_37793F525709) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_507D540F_95A3_4352_85AD_2D11433FD3A1) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_79680A70_F99B_4427_91F6_5AFB54F4F66D) },
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
