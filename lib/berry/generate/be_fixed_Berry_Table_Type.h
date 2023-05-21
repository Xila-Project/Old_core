#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_28B7B28B_8038_489C_9E8B_6EC8675C9200) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_34312BED_6784_4908_8726_8A91807D6F15) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_6CEEFD48_0214_45B4_B31E_0E0490E74932) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_7B627F6A_39F1_4D38_814B_47AE594FC215) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_A8868CD5_1D66_46E0_B4A4_7BFAAD423F5D) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_33FD3F99_1910_41A2_B676_E0950142EB42) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_F87B5219_7C07_4D2C_B817_1E0D1E43C297) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_8994720C_F440_45AD_96C0_D81762E60ADA) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_971B5D67_A871_4C70_8630_420F08FC4BA7) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_F4AECD74_48DF_470F_88EC_45542E7A4437) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_641F70E4_07BD_4A13_829D_F2FE90616101) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_2CA5AA1B_20B4_41EE_9510_76F06A66D3EF) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_6DEF759C_CF09_4E5C_8178_75FA010E904E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_C336ADE4_B92F_4CA7_A8B7_9C7E90778720) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_268BA491_9E70_465B_B03F_8B32E22A42FA) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_ACAAC98C_9467_40AD_BCA7_805DA4AC66AE) },
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
