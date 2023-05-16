#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_C847F9EF_2F71_4BBF_B405_E6ED62D2C4F1) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_4A117ED7_10D8_430F_8E15_966550C5E743) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_F679E665_2CD0_4328_BE08_4C289A0353A1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_FAEE3994_E425_46D3_BF22_7D717A39BCC8) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_1071C588_11F9_45A2_B352_E9D3BF413682) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_F0A21CD4_4874_4D28_A15B_A70BF1E6CF0A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_D3399178_CE7B_4001_9141_86BD567D4FF9) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_9A46AF2A_CEE3_40E8_AFC4_E8098558EB38) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_ED005F2B_BE90_457C_82C5_E13E5D983947) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_6B2185B0_D755_4B2A_BCFD_BAEB9D1AFFC8) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_A6F77AD8_9829_4CF7_B9C1_6BA2C078F122) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_0E32D755_42E5_4E2B_840A_71D0B2DEBA86) },
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
