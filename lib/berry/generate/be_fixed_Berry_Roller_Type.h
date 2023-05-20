#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_A54BED1E_5181_404B_AB5F_927F8FCA8F8E) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_95CBA3DF_C74B_4A1F_A074_06A0983FE3F9) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_0079A8D5_D652_4F62_8CEC_334AFBE1C83A) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_F514FC46_5E7C_4964_B54A_1134EAC11B9C) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_B3826C43_B44D_4831_858E_70890873FDCA) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_086AE94F_A901_4D3F_A9E6_963EE313FDD6) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_5E896517_E8C1_4B8A_AF4F_2C9278696DA1) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_DC014B28_5549_4A42_B85E_B636DC832F28) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_45ADFF20_8C3F_4B3C_B918_FD05FC6BE569) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_F6C13BD0_277C_4DA6_A67B_6F8B6828B70E) },
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
