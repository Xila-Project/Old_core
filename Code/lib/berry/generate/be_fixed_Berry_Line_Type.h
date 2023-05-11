#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_C5EDF697_5544_4019_90F6_475570D6FFBF) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_CB85DF52_F829_482D_892A_4211F793A275) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_377799C8_8EF5_4342_9C5D_1C7B73E9E438) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_A7E54A45_3E14_43CD_A908_79409FDF1FD7) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_8CFA8615_0133_4838_9FAE_82D84278F161) },
};

static be_define_const_map(
    Berry_Line_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Line_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Line_Type
);
