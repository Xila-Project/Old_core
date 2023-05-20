#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_2FE11A1A_0C78_464C_8DA1_AB040F6D7E3F) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_D0C1F146_0FF7_41E5_8431_D0FD2A617CAF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_475C2FA9_56D4_4B2A_81CE_D326D9B7DD6E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_5C2E31DF_BBFF_4B81_AEF7_8AD0ED920EA4) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_7BDAF428_44CA_4B22_92C7_084EB55353F4) },
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
