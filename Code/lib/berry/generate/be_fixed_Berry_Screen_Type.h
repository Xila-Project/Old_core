#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_BBD90AF0_2987_45D5_8A5F_6B3525154FD3) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_7CF1486E_8C08_44B2_8D09_B45906BBB4B5) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_84059C0F_434B_4388_8896_7AA9D7C1BA8E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_19AA27F5_39E3_4FA1_B381_E512E48B4169) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_D127FA45_5E63_4440_BCC0_2C9CBB2D7B6C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_2A22EA33_B4CD_462F_BDF9_9260B9E34B41) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_46D1F901_BED0_4F8D_AF9A_B3CF021FF9B0) },
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
