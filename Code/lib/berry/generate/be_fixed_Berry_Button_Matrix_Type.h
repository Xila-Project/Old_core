#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Matrix_Type_map) {
    { be_const_key(Get_Popovers, 9), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Popovers_64B17586_F588_43B0_A323_B50E7D12E0E8) },
    { be_const_key(Set_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_One_Checked_CD3A1E5D_5557_469F_B994_2F6C2C2BEE0B) },
    { be_const_key(Get_Selected_Button, 0), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Selected_Button_44DB5FC8_2494_4CDF_8EC5_B78F03CA3835) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Initialize_248DBA02_5947_4A2E_A025_449DB9253523) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Create_5BC9E7BC_F19A_42CB_A313_C0C3CEFC0CB1) },
    { be_const_key(Has_Button_Control, 1), be_const_ctype_func(Berry_Button_Matrix_Class_Has_Button_Control_7A660501_25A9_4442_AFAE_0BBA7507DC3B) },
    { be_const_key(Set_Selected_Button, 12), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Selected_Button_71C813E3_6FD6_48FC_BA99_D9E065F58C48) },
    { be_const_key(Set_Button_Width, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Width_6C5689ED_6469_4C1D_A14B_565B9830BE12) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Deinitialize_CB5AE8BD_1D6F_404C_BC43_E1EAACA33332) },
    { be_const_key(Clear_All_Buttons_Control, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_All_Buttons_Control_1DDA0614_AFAD_46A7_A892_C79EDC4F2411) },
    { be_const_key(_p, 11), be_const_var(0) },
    { be_const_key(Get_Button_Text, 15), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Button_Text_0343E062_07D6_46C2_BCFA_3FEBAC64684F) },
    { be_const_key(Set_Button_Control, 5), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_28CED42E_4D98_488A_9E36_935C6FA8C28F) },
    { be_const_key(Clear_Button_Control, 4), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_Button_Control_65966306_C277_4451_A09F_CDAB001E8656) },
    { be_const_key(Set_Button_Control_All, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_All_86810C24_2553_4E2F_A8BE_499D70034E27) },
    { be_const_key(Get_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_One_Checked_7059A7B8_B403_4E61_8E6C_B0809EBF9283) },
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
