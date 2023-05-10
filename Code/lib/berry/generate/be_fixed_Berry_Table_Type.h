#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_0DD6D2AF_B8F9_42CB_981A_F6BF7FDE11D6) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_833DD6A3_69C8_4914_8046_BECA9D959001) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_5C212812_68DD_4318_901C_2E735FE9D5CD) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_19068A83_6387_4CFE_A01F_40650118CB9F) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_19E76346_9B02_4508_B573_7B440B66E98E) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_24D6B230_F910_4B21_849B_4229E75C163B) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_D6AEE42A_79CE_4114_A0EB_125659DE2421) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_ECBE33F0_F305_424F_872F_435E4AD010B1) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_A1293170_52BA_405D_8CCA_2D2BA4D53E2C) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_4E7232EE_3D41_4024_96CB_DD1517E729D2) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_CCEFF28C_7471_4B14_8405_C2243365458E) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_AA4E863B_DE19_42D5_AFEA_C9AC4AE9D0F8) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_EF3B384D_8E91_40AD_ABD0_B22B099E69A5) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_2A10D48E_BAEA_4D04_9049_0120DDE99D08) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_54DEC582_1B37_41FC_BE24_7527CF6F6521) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_9406FFCA_9163_441F_AF68_82B4FD44B372) },
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
