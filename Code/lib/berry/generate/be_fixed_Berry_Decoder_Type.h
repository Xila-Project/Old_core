#include "be_constobj.h"

static be_define_const_map_slots(Berry_Decoder_Type_map) {
    { be_const_key(Get_Configuration, -1), be_const_ctype_func(Berry_Decoder_Class_Get_Configuration_7AED5CAD_9C75_41BD_BC5B_0A0E2CD3390D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Decoder_Class_Deinitialize_4312DA0C_4943_42A2_BE35_B60EED4C3CB6) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Decoder_Type_map,
    3
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Decoder_Type,
    1,
    NULL,
    Decoder_Type
);
