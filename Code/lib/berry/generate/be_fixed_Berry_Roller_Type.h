#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_205509D1_8354_4A51_B8AB_AC38B53EBF96) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_0319C018_4048_4499_A0D3_33B25F30B21D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_840E1FC2_03CD_4DDB_B8B9_8D0392612030) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_F0AE8687_F173_479A_99B8_D42A09F319F3) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_DC9DEE2E_9C77_4CFA_BC2B_F8BF6000B7FD) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_04328C24_3168_4F7D_9A31_3CBE15E741C1) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_90F02FB0_4B14_428C_B5A4_83F66B287C11) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_82F3203A_E7A0_4A3E_958D_9714D3C0F1AB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_AC3C20F2_A7A9_45C0_AE94_6A079005DFCF) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_5F2F67FA_5BF4_4233_A5C3_BB30E8244A88) },
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
