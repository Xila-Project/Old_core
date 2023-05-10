#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_1533B64C_6CA6_4E38_91E2_D75F52F1A543) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_CA2D83D3_EAD3_4444_80D6_6BF260CAAF18) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_1F18BA49_5735_4886_9894_F624AB0F556C) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_6A9AC1F4_702D_4F71_A035_5DEE0FB31164) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_681F1DDD_10F2_479D_A61C_A0622875C172) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_90C3DA6B_3B66_4F79_B9BF_0D96D358C6A8) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_AC4B0A48_E1C8_4F21_8891_A79AFBD8B72A) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_CB916F56_6FBE_4521_9C95_967806AEC501) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_E69D7B5F_E852_4AAB_AB23_C5DDBE62CA33) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_B787FFE3_74C1_4746_82AC_E27D05EAC467) },
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
