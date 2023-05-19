#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Matrix_Type_map) {
    { be_const_key(Get_Popovers, 9), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Popovers_631C275D_842F_488B_B50E_8F7D3A31C01F) },
    { be_const_key(Set_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_One_Checked_E0AF76C1_3423_449E_A100_1B26D771B637) },
    { be_const_key(Get_Selected_Button, 0), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Selected_Button_7E4F55F3_4EA3_4F4C_8C26_FC7A94916E6B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Initialize_F6ADBEC3_2609_4658_AF36_B8859D58BF74) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Create_B270E696_ECBA_44D6_88B9_BB79A0612629) },
    { be_const_key(Has_Button_Control, 1), be_const_ctype_func(Berry_Button_Matrix_Class_Has_Button_Control_9ECB880C_67BA_45DD_A2A4_263436A7BF61) },
    { be_const_key(Set_Selected_Button, 12), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Selected_Button_A7318272_F587_4A15_9D61_1BA98DFE31B1) },
    { be_const_key(Set_Button_Width, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Width_674A9729_D1BC_444C_B2E1_F5D703CA2BD5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Deinitialize_10658B86_922A_4B2F_8BC1_77B241550453) },
    { be_const_key(Clear_All_Buttons_Control, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_All_Buttons_Control_8976F9E6_5940_49FE_AE64_AA3C4B979011) },
    { be_const_key(_p, 11), be_const_var(0) },
    { be_const_key(Get_Button_Text, 15), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Button_Text_6BEB4253_4EC0_4A4E_888D_2DCAD62ABDE9) },
    { be_const_key(Set_Button_Control, 5), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_74C280FF_2528_49A8_99E1_9B28AE6FDA3D) },
    { be_const_key(Clear_Button_Control, 4), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_Button_Control_E5A31C57_F2EF_4E10_9E3B_94BF45DFADF8) },
    { be_const_key(Set_Button_Control_All, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_All_CDF37B57_67A9_474F_B5B7_81D8C21C3C3C) },
    { be_const_key(Get_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_One_Checked_95788086_947D_46CB_8273_A4D7ABCC5697) },
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
