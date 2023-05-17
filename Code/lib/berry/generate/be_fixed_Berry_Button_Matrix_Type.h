#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Matrix_Type_map) {
    { be_const_key(Get_Popovers, 9), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Popovers_CDC0A47F_1535_49AB_BA91_23CCD9DF58EE) },
    { be_const_key(Set_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_One_Checked_4C48AED5_0601_4762_823C_219E448AF879) },
    { be_const_key(Get_Selected_Button, 0), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Selected_Button_C5098F7B_46BF_49F7_986B_2F9BDCFF465E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Initialize_B80EAD9A_09B6_4F87_9A88_DB38C41A52A7) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Create_53DD0824_17D9_426B_B441_BDAEACC9907B) },
    { be_const_key(Has_Button_Control, 1), be_const_ctype_func(Berry_Button_Matrix_Class_Has_Button_Control_71E35FE3_8EF3_48BD_A5FC_A81580681B1B) },
    { be_const_key(Set_Selected_Button, 12), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Selected_Button_5572A1E4_AB37_42DC_A399_1F53A24E55FC) },
    { be_const_key(Set_Button_Width, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Width_EC4EE2FF_66D5_4174_BBA3_4281F2BF995A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Deinitialize_C84318FC_900C_4AC2_B0FD_D4B69173D626) },
    { be_const_key(Clear_All_Buttons_Control, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_All_Buttons_Control_40F4E04D_B6E8_458D_820E_8A5C406048DB) },
    { be_const_key(_p, 11), be_const_var(0) },
    { be_const_key(Get_Button_Text, 15), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Button_Text_0C9B6634_DC52_4F79_8240_4C5D1E770254) },
    { be_const_key(Set_Button_Control, 5), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_373C145D_1CF4_460D_A012_77066AF23A75) },
    { be_const_key(Clear_Button_Control, 4), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_Button_Control_E2A19F75_82B1_4294_9B81_8F832E9982BD) },
    { be_const_key(Set_Button_Control_All, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_All_5166AF94_B4AB_4BD8_9BDB_9B27F91D64B9) },
    { be_const_key(Get_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_One_Checked_8C809928_78C5_4C5D_A8C6_C2AE8F8F3860) },
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
