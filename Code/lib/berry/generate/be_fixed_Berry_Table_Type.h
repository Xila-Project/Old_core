#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_CE313C02_5631_44EA_B7BF_1470616A7126) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_08CEFE02_F81E_4AC0_8FFA_8A016F2D5F6D) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_54CB04EB_503A_44EB_8066_814C49B66F86) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_BBBB5420_8CEF_4377_92BE_C55F3F93EFCD) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_C4C563C1_4B55_4497_9FCB_FE70325D04F1) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_35BC7F12_B91A_436A_B890_A11244BAC223) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_15F0CC0F_4B64_4D68_B10B_C2FEEC667B5A) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_342EEE27_B15F_4083_AEA6_0186378DAAB9) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_B45C78C9_78A3_4C9B_888A_E7DF98E1F781) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_DC3DA0E2_2C30_47B1_973D_2269002A6B88) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_7950CC3E_0924_44F7_BE99_81E730C9719F) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_19E0B0BA_AC4D_479E_B7D6_1369D9A81485) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_606BD2D6_90CF_4617_9697_7A061534E90B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_D14299B0_8A9F_44F8_8714_C29704267FB4) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_ABE30165_8D98_4862_A721_C9A2DEC54B19) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_0D2D6A59_1758_4759_8221_B550F1C1EC32) },
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
