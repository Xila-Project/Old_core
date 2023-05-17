#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_97E60A43_AB4A_4DBC_9420_3DC86622192C) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_2394B48B_3081_4D14_80E7_21DB044A35C0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_20EA81C8_DAD3_4C5F_A9E2_0298EEFDD8C4) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_03C7B176_227D_46C7_B5EB_A59E00986EF7) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_55FAABF6_BB8F_4B07_935E_40E994F0C03F) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_E5188E98_0B36_4B08_8394_D01CA0310F96) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_67CDD832_2F04_4E68_B8C8_173A160636BE) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_62A96988_6CE5_4F64_AA4E_9AC927D81DD0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_8BFD1BE0_4E0E_402B_95A3_BDA93A9FE414) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_0E10B269_22D5_41C6_8BB5_52B7AEF8A61B) },
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
