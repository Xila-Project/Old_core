#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(Get_Name, 1), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_CF9D9436_59E2_4D75_A58E_AE71ACB03683) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_8CA984CF_C20A_417D_B9F1_1BEDCF363728) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_B06FF740_B03D_4648_ADAC_385EF1C60F01) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_AB7FD077_7B7A_4F15_819F_0614C016165E) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Software_Handle_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Software_Handle_Type,
    1,
    NULL,
    Software_Handle_Type
);
