#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_59C4DB3F_EECD_41E4_A8F1_6F051349BD3E) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_421DFE86_8FC1_4156_9451_B5391924CBDE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_AB4DB5D6_A876_45B2_91DC_010317566656) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_4326D91B_3DA5_49E1_952F_B39F325F5FA8) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_728DE4E1_6905_4E5A_BD69_AD5FBAD06585) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_CC4CBCB3_D264_4246_A790_E5E790CEEE5B) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_8F2DE8A2_0E94_485B_B16A_B6E1E35AF389) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_DB9CD82A_5D19_453E_B107_444DA8CFAB94) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_55584500_F3A3_4C4B_90AB_92BA9F03C786) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_5A92B234_E1C6_4828_B46B_B3F2F13A0D20) },
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
