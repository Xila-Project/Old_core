#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_263F47B3_0B11_4053_BE53_DAF9FFD8CE8B) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_938527AE_F9C8_4E4A_BC63_60DD9A64AC2E) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_659E262D_5D87_4EED_9380_458FD8A27EEF) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_B6DF9274_63D3_4A7D_84D5_251E5D13C5F2) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_31534A52_0C02_4F94_9B08_52687ED8793E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_03891EA9_5B30_4946_BE0B_845B64EABD01) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_AED4BB80_7340_4EEA_866F_40B547CFE6BB) },
};

static be_define_const_map(
    Berry_Screen_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Screen_Type
);
