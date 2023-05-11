#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_96719708_6373_4351_8572_BA61F8BD5F56) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_42008E8F_A877_4F05_AAEF_503D4EA129D3) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_47A8F0C7_BE64_4568_83B1_4BD7B1834872) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_18CC20E4_7136_4B1C_A761_632E26CB2D9F) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_B91591F7_FE27_4F8A_9307_95A413DAC7AF) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_068BEA22_A4F1_4146_93B0_6F3DAD40C99C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_C1E4C0E8_B5B2_4F20_83B6_65C82AE2A611) },
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
