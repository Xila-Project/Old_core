#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_047B4292_CED8_4AF4_801E_827789BF7BBD) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_D5A35605_7473_435D_9C88_4A89975E0516) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_F02926C9_5E4B_4517_B8A7_398275E7DAD9) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_44EB7DD6_845F_46C8_9118_AAB61E93AE8C) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_D1242AA6_42E5_43F5_A391_E9C2DD960D70) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_A2C287DF_4B88_4D63_B789_62E927A09FF6) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_B1E4B5D2_D0EF_427D_B9AC_F07BE7D6E0C9) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_8C33D0DD_E015_42A5_9639_8E4FADC05F74) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_0F64E4E4_C2D6_4744_93F5_C2A2D974F327) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_C9300570_2C2A_4D50_B228_DDDDD8679FFC) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_A936DD2F_6640_42A2_BDAB_C8D92C59918F) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_260D5DF7_6DE8_43B5_9456_B7D27703EBEC) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_6992E93A_5F7E_41E8_B01E_9FE49A76F59F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_31FE2A6D_4681_4F16_A566_D310A7C182DA) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_2E04DEC5_B897_45C1_A89C_978C468E16AE) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_5BBA5D40_DDD8_43D0_935B_A504175832C2) },
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
