#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_91F1C884_F317_41E1_B2DB_0415AC7E4EB8) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_2EE400A8_51A6_4006_B471_188E7E9474CE) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_4A495957_B985_4EBE_BCFD_7820133FA473) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_1F8E3325_19CC_4FBB_9371_8AEBDBBB35DA) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_C0D0AD30_B493_416A_B4A1_89BDD65EBF38) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_144C342C_D123_409F_8A65_C352888BFB3D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_07109497_7E8B_4017_8C6C_E089FCF8C39D) },
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
