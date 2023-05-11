#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Matrix_Type_map) {
    { be_const_key(Get_Popovers, 9), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Popovers_A243BF11_E7C4_4B77_97BC_79321A08B6C5) },
    { be_const_key(Set_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_One_Checked_C59B8E7D_9FA7_41BC_9010_1EBAAEF5AA2F) },
    { be_const_key(Get_Selected_Button, 0), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Selected_Button_F43B5FF5_DFD0_457E_A83D_4BEF79937B8C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Initialize_2AC32D84_AAAF_425B_8FF3_5732BD42DA48) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Create_C92018C5_751A_452F_9A6A_093612E5FD55) },
    { be_const_key(Has_Button_Control, 1), be_const_ctype_func(Berry_Button_Matrix_Class_Has_Button_Control_E443F847_D27E_4F99_86C0_E50844604C89) },
    { be_const_key(Set_Selected_Button, 12), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Selected_Button_17CD6F11_2C19_4A1A_95F5_A20B80FDF9BC) },
    { be_const_key(Set_Button_Width, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Width_C5A7D351_EB67_4331_BDE0_365547D2B608) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Deinitialize_547C1E60_38A3_46CF_B2B3_027B1E07D4A5) },
    { be_const_key(Clear_All_Buttons_Control, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_All_Buttons_Control_E8B122F8_4A2C_4F0D_920E_FD74DBA624BD) },
    { be_const_key(_p, 11), be_const_var(0) },
    { be_const_key(Get_Button_Text, 15), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Button_Text_C133DF06_8772_4043_BEFC_EBF8F3518AFA) },
    { be_const_key(Set_Button_Control, 5), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_8A49C07B_B85B_44E1_ACA9_2D19B764B065) },
    { be_const_key(Clear_Button_Control, 4), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_Button_Control_EC00E941_4D4F_48FF_94AC_A58FA454102E) },
    { be_const_key(Set_Button_Control_All, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_All_DDD0F431_C8DC_4E88_8B5D_455EF901364D) },
    { be_const_key(Get_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_One_Checked_69F9B529_C6C2_4866_99CF_F60C39BD7F43) },
};

static be_define_const_map(
    Berry_Button_Matrix_Type_map,
    16
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Button_Matrix_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Button_Matrix_Type
);
