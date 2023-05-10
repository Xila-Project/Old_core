#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_38A97127_2C1C_4E00_8A9D_F198BA2D3F7F) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_6FDF0EC7_BCDA_4877_BC52_70EBE91D96C0) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_7B45CE87_1A2B_45EE_9344_5FD2158FF904) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_D7BF81D4_C568_488D_BB13_C84FA0BEBCD9) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_21B0F3CD_AEDB_462A_87A4_1440AD007CA6) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_82C3B25A_A75E_4215_88B4_1A19CD7AA4DB) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_4BF9772F_A364_4484_8203_3C3F254B5C78) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_21652C90_8D5A_4025_8EF9_DCDDCA7EA07E) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_7758FDAD_0B9E_475B_8ECC_98D9E01D84BB) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_06E8F0E3_39FE_4E70_9FD8_032897C55D81) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_6D8B6C4F_E78B_4DCA_A210_B75C68DDDF7B) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_BB101551_DE66_4B1D_A31C_BC943A83B884) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_B9753C88_CF41_4088_8DD2_8D2D13ACA5AA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_44A1D894_1E5D_4D8A_ACCF_5E4B0327397F) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_3F6393F2_3D3B_441E_A33C_F324C45E83A9) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_8F1E3E0C_A61E_4A25_94CD_6206CB7E88F8) },
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
