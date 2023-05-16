#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_DA41A793_7F2D_40F0_AD7C_A6E266B63B25) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_C9B50BD4_0053_4A31_A626_D96C95D214CF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_F1E61EF8_2C2B_445B_BD4A_98B04751A635) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_838A0408_6026_4C81_91D5_238536DF4F90) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_4F293749_D330_4F83_84BA_9B7BBDB6257D) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_E4E4898E_D12F_4CC1_813B_3D85BB9744F2) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_7AF201FF_4928_47D7_9F51_4E044E6D2DA3) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_5A214728_7E48_44C8_A885_7FA088816F7D) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_28F1B7B5_1C93_48A6_950E_93B9DA9FF68E) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_C5EC3BFA_8560_43DD_81DB_3EB6BE7DA202) },
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
