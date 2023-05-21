#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_AF27D37F_B9B7_4E40_8923_5CB81EFD1846) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_28334545_0D1F_45FC_99CF_59FFF17023FA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_651F194A_2735_4A43_81EC_962CB6145D44) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_23DE9C02_28D5_446B_84D1_08293FBA4478) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_E08C9BAC_ED6D_4A53_BB6D_24C346287E5A) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_D0304E23_0A4D_4163_A12E_D1C945B11757) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_11B5601F_3AAA_440C_9A6A_84E204E550E0) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_B47BDD17_5ED0_4D2E_8E8A_E8AED97550AE) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_8838E944_6A04_418F_914A_6B12324070E5) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_B559F449_6191_4DFC_AF7B_8802E4B174D7) },
};

static be_define_const_map(
    Berry_Roller_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Roller_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Roller_Type
);
