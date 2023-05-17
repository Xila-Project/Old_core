#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_0C5DFD0E_E028_47ED_8409_5D377BBEADC5) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_72BB05CF_268D_4EB7_94F3_5DC603F2087C) },
    { be_const_key(Is_Equal, 6), be_const_ctype_func(Berry_Software_Handle_Class_Is_Equal_3D69DAFD_8494_4542_92DC_FC461D776E04) },
    { be_const_key(Get_Name, 5), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_07ADD7FB_BD12_4430_9DC6_1F34B6EBCB69) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_65CA9ABC_BADF_4B14_83D6_B649C9A6CD8C) },
    { be_const_key(_X21_X3D, 4), be_const_ctype_func(Berry_Software_Handle_Class_Operator_263272C6_D3DA_4A06_8662_5F34EC966408) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Software_Handle_Class_Operator_EF94F61A_29B4_4A01_B151_F2F66FAC2563) },
};

static be_define_const_map(
    Berry_Software_Handle_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Software_Handle_Type,
    1,
    NULL,
    Software_Handle_Type
);
