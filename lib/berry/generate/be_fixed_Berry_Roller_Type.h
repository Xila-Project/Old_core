#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_1AA05626_17FA_4537_91BB_712BBA165FAE) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_CC18E6E5_6619_4A54_9966_765987F7E5C3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_AAD62CA8_414E_40AE_968E_DE7FB630590F) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_C1CDA972_38EA_4DBE_840A_C5213F2443B3) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_12001823_3F1B_43EF_A98D_B176850F6076) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_18D19575_DFAF_411A_AF7C_18679E5AC711) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_7B0F0A9D_3380_4FA5_8027_99E4882C5792) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_6EF541E8_EAD5_41BF_AF9E_FA28ACEA1EBB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_D7790506_1844_4D85_A279_414062EEA40D) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_FD15AB57_547C_42C3_AF57_DC2A8B3294EF) },
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
