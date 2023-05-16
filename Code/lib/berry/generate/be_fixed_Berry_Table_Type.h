#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_C7EBBF0C_EF70_4EF6_B78A_CF0AA20713E9) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_0D949197_3FBB_4B6C_ADF4_6E14450ACEF7) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_DAA42C34_7438_4F9C_8106_324A92E3FAD4) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_CE4BB4DB_2184_4AA1_969E_52AD9E28093F) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_E37798FC_D5C3_41A6_9E11_FB964CD729CC) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_657CC747_9AA1_4CD7_8436_ACBBBAE0E05E) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_B3C4F9DD_4B9A_4EA4_B884_9F17AE65A3F6) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_3529BF92_6CA6_4CB3_A8E2_C3747331571E) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_199C28A6_B741_4C21_9B76_8529FB94A14F) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_04BD98E6_8573_45D5_8666_FBA6ED1F9738) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_724D795E_0393_43E0_B0FB_96F9ED5338E4) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_C63FF5D6_4D1A_4C42_8A07_5B8E59BCFD45) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_E3268E69_227C_4AFF_B279_D4E3500320E7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_2B0813D8_60B8_4670_A20A_CE5A08618779) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_FBA18C17_AD3B_4861_B97E_439A00631E01) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_CAD34C59_8FC4_4055_A0CD_91E9B78B3902) },
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
