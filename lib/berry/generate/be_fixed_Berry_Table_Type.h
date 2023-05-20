#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_03EAD742_A43F_493D_A779_D9B3389C8A6F) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_E03DB54D_49E7_43D6_82E3_36CD745F5757) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_DBC68D3B_ACFB_4482_BB87_6DC55CDA295E) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_86849383_53F3_4D2C_AA61_880B5B726774) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_FD2332E1_DD83_44EC_AD00_97CA1AD2B0A8) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_4AE369AE_6CA2_4A29_8F8B_425AB92286B9) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_B5687B08_2091_41F1_B041_B0721F9ABF4F) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_87FB64C2_9E10_4F37_B7CF_D0C9E11E7612) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_8BE5ACB5_4C10_4D20_94E5_7F8E01219229) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_AFDC168F_53B0_4C9E_9634_8AE20760AC10) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_1301F05F_3F67_4C48_92E9_A5858BD5AE8C) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_08610AAB_7069_445F_ABBA_79C6072CBD07) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_48898F7F_0774_4FCC_85E6_53F5189C3800) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_968A91D9_3FB1_45CD_99C6_7958644D04E0) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_58F851E9_7E88_4BE8_9543_E86D466423B1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_7893BB9B_16C7_4DA5_B92B_2FCDEECB92D0) },
};

static be_define_const_map(
    Berry_Table_Type_map,
    17
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Table_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Table_Type
);
