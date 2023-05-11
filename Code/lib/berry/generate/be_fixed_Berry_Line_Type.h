#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_048A37E3_D275_4808_925F_ADB3AAD809F0) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_C5E02023_1BCE_4A74_A7E4_7A1C4C5FD51B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_EC2E1171_5D96_4229_A582_C060994D229F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_52DE395F_1956_4981_A035_223AC31FF5BE) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_305DE471_0C90_4147_9A7D_C7FB6D399FA8) },
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
