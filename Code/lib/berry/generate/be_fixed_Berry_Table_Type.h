#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_0F06B131_3A72_42B0_B98F_9ACCA42CD03A) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_7525A5BD_D7C8_4FFB_B588_F54835ABC3DB) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_A14BB2F2_79CF_4453_BEC0_FAD0EF55069C) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_AD0CF4D3_FD44_48A7_8032_60EDA09EE630) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_A9A2AF36_3A85_44AE_BFCE_24FB5B0BC325) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_38A8EF63_D5BB_4F80_9CE0_7F3D99AFF849) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_95819666_2ADB_4E9C_9E24_16C8AEF9DB65) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_80DE6E3F_9B7C_4CBE_9062_7CA7C6C27FE7) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_CB6B7B19_F819_44F5_A07C_0B77D18A4452) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_7151D005_19FF_4B45_8023_0E4DC9C5D847) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_C8E402CD_3156_4D60_B348_05386978DC1D) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_C10988F4_3916_4CD2_9544_CFE71F610D95) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_F6E27754_F7DF_4FC5_98E4_6CDA6A7677C8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_181A50FC_CDDA_4DBB_916E_8D16557036E2) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_1937CD3B_E28A_4E29_8FD5_0DAC00588666) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_38217C6D_C49C_4435_A692_57BA889F524C) },
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
