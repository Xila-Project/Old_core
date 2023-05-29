#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_20211610_56E6_4B16_90E9_C43E9FC4A47A) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_0F5F04DE_C957_4550_96CD_2931D853B398) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_7F2D8410_B1C2_4AD8_A413_12890FD3529C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_1BD31F6D_0D9B_4AFF_A00B_8CEC8581FED0) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_24E53D74_EE65_4409_81D7_34892D0231CF) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_61EA4FBF_3F5C_43A9_B91D_6DD5FDAF0943) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_62A415C5_9356_49C1_8717_8BDCBF36AF86) },
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
