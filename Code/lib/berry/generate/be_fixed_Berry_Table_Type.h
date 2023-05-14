#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_FEF76F55_009B_4087_8859_3C0FC3177881) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_2B013C0A_F488_4DDC_8606_BAE97B669A08) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_0DBC6D8F_3186_4C27_AEA3_0A59886DC62B) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_9A5675B7_DB5A_45AE_B4C1_770F9236E6AC) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_D49DCAD7_2E18_4270_AC7B_A54FA3ED2568) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_31D6A502_AD8A_496D_AE17_7C4679BF1B07) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_6B585159_5043_4466_A5CA_BBFC27BF5B82) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_9AE7A7BC_1C0E_4180_B901_63A629599A1E) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_3E45B7C4_3159_4F2B_BD23_A60C708B2E7F) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_CFE7742D_BFF6_4757_8E58_CD6B75DC1CB8) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_2546DCFC_AAF5_4322_8E83_BAB7D40A7341) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_61E3386D_BFDA_438D_AD08_50EC35C98955) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_53592872_EF4B_4FF5_B602_6075D6C27AA7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_7345B801_619F_4537_822F_A28E7514FE70) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_55D99404_CFB6_480E_8F53_F9FEEEAFBA18) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_F29E9C46_68A3_427C_86FA_B92F162830C1) },
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
