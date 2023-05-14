#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_BD7E3324_B5EF_4CC3_9793_68A49872C201) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_D182EDF9_1DF1_4571_A53F_819E5DB3CE8A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_B4D221AC_6D1C_4791_B5FE_27075F242ABD) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_F3E40B22_4095_4603_B1B7_CFD83A4ABEFF) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_9A4DBD7D_14C5_4C0E_A1C9_237AEEEACB2D) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_F8106B5C_7B2F_444B_A8AE_926C38B5D19B) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_CA5F3455_AAB8_46E2_A720_27C2F190A5AD) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_6CFAF6C2_79E1_4E90_A40B_3321FBAB1644) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_D7930A03_E78A_4FC1_9B73_B74E0220ACA0) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_50A68CEE_6D4F_4E2E_A894_97BDB54C5EA1) },
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
