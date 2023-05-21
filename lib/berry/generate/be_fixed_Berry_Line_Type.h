#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_90ADD196_0311_436D_B537_8DB5C1B8B231) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_C6F8F356_499C_41C6_B976_B6F03A3861BD) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_D7ECF841_B642_4C5F_8673_BE475325B3F5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_931120CF_F7DB_4A52_B6E7_04E51E33EADC) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_1C4CE665_8D0F_411D_B030_D3960DDB7AFB) },
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
