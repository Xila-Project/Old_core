#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_AD18236E_509F_4676_A70D_F19E5D472827) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_64613940_E1FD_4AF2_8D96_AF548C8568C2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_2016ED34_0052_44DF_BB68_95D4B03A817B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_0A04EFAB_55B7_4CFA_A309_302CB88E18EC) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_42EE213E_AAD8_4569_9F1B_4A5657B41969) },
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
