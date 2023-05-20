#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_2974B588_6C33_4E37_8400_85122810A51D) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_3635457B_D24B_436F_9D39_ADD4975D08FC) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_00103FD6_C5A4_4038_A221_CD5DB33960C7) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_20E8DAF4_5C9B_495F_9DB4_19FD5C077346) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_520EF4DC_9995_4E6F_A455_43CB80FF8BD0) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_E6A64980_0313_4C1C_BCF3_6BDEA306B952) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_9BE19C5A_3BE6_48C8_A464_CE71CEEEFD11) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_B4B994B4_D02D_4141_B07D_AAF8EA679210) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_B709025E_6EBD_4DAF_8E0B_A25F6AB8A3AA) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_AC006962_0E60_4BCD_B5F0_A6C514B3BBBD) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_25C759CE_2930_4E35_BDC1_007CB5705A06) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_4055E907_697B_4F7B_A677_B168C8684D57) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_A8F7C428_E918_4D76_9850_55F935F52883) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_E22ACCD8_D9BC_4BBD_A930_3501507C2813) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_3CECA556_C520_4A90_8526_D11D27898142) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_FE007816_E033_40CF_AA85_8D81C191BD5A) },
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
