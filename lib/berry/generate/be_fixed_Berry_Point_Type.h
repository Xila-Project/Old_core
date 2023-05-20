#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_B9775460_0C07_4D7C_9A22_A01E1DDB3DA0) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_A0DBBA44_8107_4E22_8CD1_63239620F6F0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_A5A8F068_8F00_43AB_B6D2_056804604C04) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_CA74B4D4_53FF_4455_B209_1BD20B3F6314) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_6D990B41_E4CD_4F19_AA6F_9FFC0595517A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_FA7AF602_8A38_4D3F_877E_AC143885EEC8) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_42A13DB8_856C_49D5_A9FA_C33865F9D848) },
};

static be_define_const_map(
    Berry_Point_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Point_Type,
    1,
    NULL,
    Point_Type
);
