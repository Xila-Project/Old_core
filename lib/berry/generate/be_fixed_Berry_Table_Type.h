#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_7F58087F_21B5_4479_87A8_FA34001102C1) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_AEB5BABF_80EA_466B_A001_8CE941FFB686) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_C03FBD13_729D_4984_952C_1F47EE157A2C) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_42FDB2D6_0E6D_4F0F_987C_CBE8350B9EB9) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_361C8740_E5EA_47FF_B874_177A48417DAB) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_6A4D2CD9_FD87_4BDA_8350_FBCA7838D58B) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_B1B05568_6EC3_44D0_8B2E_ABCCBD3339FC) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_15F959EF_CF34_476B_8074_F10B40FAA1A6) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_EB86017D_7833_47E3_9F4E_B0742666BEA5) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_203889A4_E042_4BDD_BBA1_212E04D42465) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_AD8B1A17_770C_47DB_AA9B_12ACB50B44B3) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_D7FDEE97_8991_43CF_BCEF_E62741BCE048) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_62D582EC_78FB_4C3F_A6CE_B23067B8090D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_FD623429_DE5B_40ED_8514_8828760F131A) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_563A6CBC_E24E_4DC7_A03E_7F0EC05AA29D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_580B0AB2_A3B6_4557_B520_B995E34F2736) },
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
