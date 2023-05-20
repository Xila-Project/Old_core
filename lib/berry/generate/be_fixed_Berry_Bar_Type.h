#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_71FBF5CD_F2BE_4552_B859_4B06390777C3) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_8239BEBC_DB05_456A_8D12_DEEAA2A592A7) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_76393B48_92BC_4A63_8CEF_CC79FB8178A2) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_35FD0753_D182_4BAB_A6D3_F20B377F4814) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_99E07E10_99CA_4397_BF44_FE7588AF27DC) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_37E06965_52E2_4398_80D5_C543B1BCB174) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_41BC8FD6_EB86_4C0F_BA71_C2C99ADDB85A) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_EC98E188_FA77_4AAD_96B4_0D898A3A9819) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_9148FFEC_0951_4499_9CBF_13E740612AE6) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_45AC2099_170C_4ABE_A54D_10AF6478EE61) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_A6B6876E_4059_4511_AA0B_0136FD7D4A56) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_5DECC9AC_148C_4AD6_94FD_D21740C703B6) },
};

static be_define_const_map(
    Berry_Bar_Type_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Bar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Bar_Type
);
