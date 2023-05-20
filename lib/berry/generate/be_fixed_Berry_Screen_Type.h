#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_FA388722_57C7_451D_9325_5BC178176E01) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_AA0BA567_9198_4FB8_A0CD_8B5C50B3E292) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_9421E579_A73F_46BE_A0E7_3065A32CC588) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_5EDFCCE5_0BE1_432E_88E9_18DFC4F82FD3) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_C787DFD0_F5A2_4A89_8027_284A75105598) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_D5293DA0_EBBB_4BB4_BFC8_9979991377CF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_76AEAA4D_B9BD_432F_B4AB_E133D43878E4) },
};

static be_define_const_map(
    Berry_Screen_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Screen_Type
);
