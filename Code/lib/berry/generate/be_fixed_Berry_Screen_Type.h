#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_137237C9_355B_4A5B_AA9C_AB7BBC9693BD) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_0994D41E_2432_4545_9ACE_7B4E2895E611) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_A5F69254_B755_443E_BA4F_67682141D5F6) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_456BFA75_88C9_49B5_AEB3_F629DE89CFC5) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_7011F6F3_21CA_4EF0_AD41_48C1D0177D6B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_C8B47DBF_6155_4E61_A9B8_000E2C47D09E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_152FD048_8EFA_4FB6_B797_8F65EC05260E) },
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
