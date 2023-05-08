#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_DEDCD7FA_E745_420A_BF2A_68124F99F9D4) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_01F8AE4F_34E4_48B5_A72F_C43EA0F0F453) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_93CC0F96_D89D_4E79_9BDB_4B6E99B6FF62) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_C05EB45B_64EA_4072_854B_A9812A03415E) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_C628BF4B_6435_43D4_9EA3_DDCEEFF4D31E) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_07A90AC8_D79F_42EE_AC8A_65C88C68D39B) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_2DE6601D_08ED_4773_AF67_7C31373DEAA6) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_AB3C8C7A_86B3_4097_8ACB_E787E349DA3F) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_53CF2F7C_7E90_4AB6_9E31_81E7783195CA) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_AF40B725_9B45_40C8_91C0_A2D976F02E2E) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_8E74C4CF_4050_477E_AA58_E95B903A14FF) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_FEFF25E3_4A6E_46BF_A5AC_539EC132E806) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_93B410D8_B06E_4A36_9851_8D7AC5B0FCC3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_E9ACE2A4_6EC6_481B_B161_C9C800C8346A) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_21E873A7_C2A5_4C7F_BCDD_3CDA5DAC3B23) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_36FFA68D_9889_495A_903E_E303532505A2) },
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
