#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_03B3B326_89D5_45E7_9EB6_1AC081D02B1C) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_3B8D5037_AB09_4740_9764_5EFB1397873D) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_8E848153_A826_4F5A_890C_ADD3710DEDDC) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_F7211530_0E7F_4B60_AAE3_BB102C4C0DD2) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_6836EAE9_B552_4D0A_ABF8_20AFF800102B) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_4C6C9AB0_96CD_4328_8B9D_9F6DB7D75E18) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_88E48C86_794A_453F_935B_FA696F128B55) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_0E2B056D_096B_4390_B3A8_B92CFCF8654A) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_AFD40AFB_8055_4673_BD52_D3D731E39BC4) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_FA44B330_0E20_43EE_84B4_1D2A01298576) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_0C6C3CD3_96EB_4662_8A63_158C8C73C096) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_19D39A74_8241_4D97_85D6_FD82D0388A81) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_4CD4031E_17D3_4DB4_9F2D_51B4D66D46CA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_AFA2A933_B124_4059_9C20_4B53BEFB9528) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_41572DE4_B008_4A64_AC8A_9A55CD2D50F2) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_9C29A914_109C_41BB_A06D_9A3358FD4D25) },
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
