#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(Get_Name, 1), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_CACE01A7_3CC1_49D6_8F94_EA627E78D49B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_BCF1AE68_93CA_48DD_9EF9_D8F4385BF925) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_561BE87A_3F75_4AEB_A337_EEB0038A3CAE) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_8C28BBF6_F7D3_4A3F_B3FE_27E170F681BF) },
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
