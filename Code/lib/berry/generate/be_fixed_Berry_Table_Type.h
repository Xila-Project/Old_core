#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_E66569D9_F0C8_4C5F_9CBF_746C98161195) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_EEB855DD_541F_42D0_B682_5F6F7E11EE06) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_9D818EE1_DAB0_4DE7_9139_DD9F77A7C317) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_66D218CC_66FC_4369_8565_AD44DEDD685B) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_E05604CC_BA60_4C0E_98A8_07C518206679) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_AFBDC551_3001_49B1_89F3_44BA8DDE56AB) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_51FDCB8B_56E0_4E7F_8D59_E9C19DE507A6) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_C038FF6E_5C72_4B4E_BAAC_E696CD1F8007) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_44E45B9B_7659_48AF_A8BE_C0F3D61C7FF1) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_6E303BEC_A3DA_4F94_8CDB_6A12EECB44A6) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_33D58931_2A28_4417_B8BA_3AC6D759D70B) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_8E20F578_CD03_448F_B03F_63C016C7C0F6) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_7855B5A3_02F8_469C_B36F_84841B3AADAE) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_01E68A81_1925_4E2C_A709_0F5C0BF80016) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_5C949FE5_D422_45E9_A736_57B3C66211B8) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_DC3A4778_2A27_4463_A6A5_743BFF70724B) },
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
