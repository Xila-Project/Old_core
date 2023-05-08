#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Matrix_Type_map) {
    { be_const_key(Get_Popovers, 9), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Popovers_AC802ACC_3ABC_4FC6_83FF_DA43288CB7FC) },
    { be_const_key(Set_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_One_Checked_48178D58_13B5_489E_B707_52B32341105F) },
    { be_const_key(Get_Selected_Button, 0), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Selected_Button_D822E4C8_7161_498B_BC55_712FCACBF6CE) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Initialize_8653D4E6_0E7D_4D18_A1C1_207287FE45BE) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Create_00BC2D5E_5506_4344_9CD2_0550CEC1BA44) },
    { be_const_key(Has_Button_Control, 1), be_const_ctype_func(Berry_Button_Matrix_Class_Has_Button_Control_5964E2C8_9CE7_4811_B149_54EBC2845B62) },
    { be_const_key(Set_Selected_Button, 12), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Selected_Button_3042EC7C_9301_4373_A9D8_39290484F10F) },
    { be_const_key(Set_Button_Width, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Width_6EA11B37_041D_4C46_9E82_24662DB3304A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Deinitialize_1EF9D8D3_9DDD_4DA7_91E9_37F8A71A9A3C) },
    { be_const_key(Clear_All_Buttons_Control, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_All_Buttons_Control_3A1DF5EA_2E98_4476_97C0_C4E6BAD7B016) },
    { be_const_key(_p, 11), be_const_var(0) },
    { be_const_key(Get_Button_Text, 15), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Button_Text_7761F70D_3669_471D_8CC5_EA2B12F30E41) },
    { be_const_key(Set_Button_Control, 5), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_DDB76E2F_085B_485E_B72B_A6C9AE10BEA3) },
    { be_const_key(Clear_Button_Control, 4), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_Button_Control_8E4D37C9_55C1_46F2_BDD0_5E25B75A0964) },
    { be_const_key(Set_Button_Control_All, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_All_A273855F_F94D_4983_B09E_C1CC4D572D7C) },
    { be_const_key(Get_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_One_Checked_B30EBE58_356F_4291_AAEB_D8C124B2E156) },
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
