#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_647CA66D_9AC4_4581_8DB6_DA7192464E1B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_DA8BB06B_8EA3_4F7A_A6CA_E5982357FD67) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_91541F3F_3C89_43CF_B786_F0FE00F7FCEA) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_425982B7_F22C_4DE1_9E45_3AF6628F59A6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_724E636D_CF54_41B2_9A6F_461A5FBABD58) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_1F66439D_FDA9_4740_A26D_B0C11A72ED06) },
};

static be_define_const_map(
    Berry_Stream_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Stream_Type,
    1,
    NULL,
    Stream_Type
);
