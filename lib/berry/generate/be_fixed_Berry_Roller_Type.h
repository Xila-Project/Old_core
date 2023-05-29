#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_EC5651E3_C427_4300_95C7_EB744E8E2732) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_D7A9A026_45FD_446E_9947_BC31147B4B16) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_79EDC691_0B76_41A1_B16D_723F94999195) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_3325D7B0_DF20_4DD0_BBE8_DA722C4625A5) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_7B0755FF_9C66_4549_9954_F1F1D70B5B45) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_C398ED15_7620_4CEE_87E5_F265D56D6E95) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_3C3F0EB1_A80F_4E6B_AC20_0D44E78E7A71) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_BC1B47DB_ABD7_4EB4_B9CA_0DCA4F6EFD0A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_EC0DA026_DD0D_4157_B360_51E605FEC7C9) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_FF2290FA_02D1_4149_965B_0209834EE75D) },
};

static be_define_const_map(
    Berry_Roller_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Roller_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Roller_Type
);
