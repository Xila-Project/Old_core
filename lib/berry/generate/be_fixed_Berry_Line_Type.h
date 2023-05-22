#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_02784EC0_B8C1_4016_8D91_3CD1E46B0F32) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_A05816A5_97D0_4F81_AD18_D75265063ECE) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_12DB4610_558D_4D1B_ADF0_A6C941B14AF5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_F2605A4E_FB3A_49D1_987B_B4A4245662B9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_C8DEC2FB_F970_408E_ACAC_64C4A842A6A3) },
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
