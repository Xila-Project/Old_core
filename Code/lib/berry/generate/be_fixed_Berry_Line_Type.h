#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_AB72A010_0B0E_4C2C_989D_40518CE2406D) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_1EB0BF0B_0E51_4087_A5B9_DA2591067EC5) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_AC48692A_5220_4889_AC40_9BD7A03A113D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_1375D306_F030_4AA0_B52B_807E985E7868) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_6E9FD7EE_D4DD_4AA6_B286_4D7339C25B5E) },
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
