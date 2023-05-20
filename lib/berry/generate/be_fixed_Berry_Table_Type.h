#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_5332F633_C5D8_4DB0_8FD6_40F24753C359) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_BBDEDAEF_68D9_4B3D_A352_6366CF858A57) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_66520388_38FA_4E8C_A88A_2D2490745351) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_9B078C75_6D29_425F_8432_677310163A94) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_84D05A4D_9F24_4864_B17F_D194BE53BADE) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_4DB31369_4296_4FB5_B564_54AB065C7B51) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_DBE449D2_7406_43A6_88C4_70DDDBF8C4ED) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_523D62DE_FEA3_42D1_8074_97E5C76EF5F0) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_A0BE89BD_7667_4786_96B2_FC0A24AF8FA8) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_F2AFB6F5_E8B0_4690_9953_E6CB632E17CA) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_C3EC437A_CE90_437E_97B5_3A63255078BD) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_2DAAC9A7_3D21_42FC_AF77_3CF91BF6198D) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_953836A4_895B_4572_A91E_543987DA8399) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_A9DA38F0_2437_4971_B998_981D12CEBDC9) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_73A9EB5E_3375_4C13_A683_0EDF7801E997) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_91B67892_FDEA_40F3_A3CA_73EA16996092) },
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
