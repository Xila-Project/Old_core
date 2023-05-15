#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_3A883913_F16F_47BA_9B72_B85FC429F353) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_6327CE98_6119_4B26_B018_3D9292651A35) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_1DF8B07B_CB75_4ECF_9BE2_999C75ACFCCB) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_BDEB280C_874B_474E_A536_3E6754380273) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_4ADF6B57_0D2B_4018_889D_49BF39DC3960) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_3F4246E0_6CE3_41BC_BFE2_F447D02E3229) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_03174E01_B87A_401B_821F_20A162CC45CE) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_9A336AF0_BD28_4459_9DB3_646290018D0B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_A8C0FF2F_0256_48F6_B17C_CE848BE9B176) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_68E65FCB_96D1_44D3_B161_157329C66903) },
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
